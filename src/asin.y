/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2          2022-2023 <jbenedi@dsic.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
extern int yylineno;
%}

%union {
  int   cent;  /* Para el terminal "cte" entera: creo un atr que es un entero             */
  char *ident; /* Nombre del identificador */
  Lista lista;

}


%token MAS_ MENOS_ POR_ DIV_
%token AND_ OR_ 
%token ASIGNAR_ NOT_
%token IGUAL_ NOTIGUAL_
%token MAYOR_ MENOR_ MAYORIG_ MENORIG_
%token LLAVE1_ LLAVE2_ PARENTESIS1_ PARENTESIS2_ CORCHETE1_ CORCHETE2_ PUNTOCOMA_ COMA_
%token FOR_ IF_ ELSE_ 
%token INT_ BOOL_
%token READ_ PRINT_ RETURN_
%token TRUE_ FALSE_

/********/
%token <cent> CTE_
%token <*ident> ID_
%type <cent> const tipoSimp listDecla decla declaVar declaFunc declaVarLocal
%type <lista> paramForm listParamForm 
%%
programa      :     {
		              niv = 0;   /* Nivel de anidamiento "global" o "local" */
                            dvar = 0;  /* Desplazamiento en el Segmento de Variables */
                            cargaContexto(niv);
		       }
                    listDecla
                    {
		              if(verTdS)
		                     mostrarTdS(); 
                            if($2 == 0)
		                     yyerror("no hay main en el programa");
                            else if ($2 >= 1)
                                   yyerror("el programa tiene más de un main");
                            
                            descargaContexto(niv);   
		       }
              ;

listDecla     :     decla
              |     listDecla decla   
                     {
		              $$ = $1 + $2;    
		       }    
              ;

decla         :      declaVar
              |      declaFunc       
              ;

declaVar      :      tipoSimp ID_ PUNTOCOMA_
		      {
		              if(!insTdS($2, VARIABLE, $1, niv, dvar, -1))
		                     yyerror("Ya existe una variable con el mismo identificador.");
		              else
		                     dvar += TALLA_TIPO_SIMPLE;
		       }
              |      tipoSimp ID_ ASIGNAR_ const  PUNTOCOMA_
                     {
		              if(!insTdS($2, VARIABLE, $1, niv, dvar, -1))
		                     yyerror("Ya existe una variable con el mismo identificador.");
                            else if (! ((($1 == T_ENTERO) && ($4 == T_ENTERO)) || ($1 == T_LOGICO) && ($4 == T_LOGICO))) )
                                   yyerror("Error de tipos en la declaracion de variables");
		              else
		                     dvar += TALLA_TIPO_SIMPLE;
		       }
              |      tipoSimp ID_ CORCHETE1_ CTE_ CORCHETE2_ PUNTOCOMA_    
                     {    
                            int numelem = $4;
                            if ($4 <= 0) {
                                   yyerror("Talla inapropiada del array");
                                   numelem = 0;
                            }        
                            int refe = insTdA($1, numelem);
                            if ( ! insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe) )
                                   yyerror ("Identificador repetido");
                            else dvar += numelem * TALLA_TIPO_SIMPLE;
                     }
              ;

const         :      CTE_ {$$ = T_ ENTERO;}                              
              |      TRUE_ {$$ = T_LOGICO;}
              |      FALSE_ {$$ = T_LOGICO;}
              ;

tipoSimp      :      INT_ {$$ = T_ENTERO;}
              |      BOOL_ {$$ = T_LOGICO;}
              ;

declaFunc     :      tipoSimp ID_ 
                     { /* Gestion del contexto y guardar ‘‘dvar’’ */ 
                            niv++;
                            cargaContexto(niv);
                            $<cent>$ = dvar;
                            dvar = 0;
                     }
                     PARENTESIS1_ paramForm PARENTESIS2_ 
                     { /* Insertar informacion de la funcion en la TdS */ 

                            if(!insTdS($2, FUNCION, $1, niv-1, -1, $5.ref))
		                     yyerror("Ya existe una funcion con el mismo identificador.");
                             
                     }
                     bloque
                     {/* Mostrar la informacion de la funcion en la TdS */
                            if(strcmp($2, "main\0") == 0){   /* los dominios coinciden */
                                   $$ = 1;
                            }
                            else { $$ = 0;} 
                            if(verTdS)
		                     mostrarTdS();
                      /* Gestion del contexto y recuperar ‘‘dvar’’ */
                            descargaContexto(niv); 
			       niv--; 
			       dvar = $<cent>2;
			}
              ;
              
paramForm     :      {$$.ref = insTdD(-1, T_VACIO);    $$.talla = 0;}  
              |      listParamForm  
                     {$$.ref = $1.ref;    $$.talla = $1.talla;}   
              ;

listParamForm :      tipoSimp ID_
                     {
                            $$.ref = insTdD(-1, $1);   
                            $$.talla = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE;
                            if ( ! insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1) )     /* Los parametros se ordenan en orden inverso */
                                   yyerror ("La función ya tiene un parámetro con el mismo identificador");
                     }
              |      tipoSimp ID_ COMA_ listParamForm
                     {
                            $$.ref = insTdD($4.ref, $1);   
                            $$.talla = TALLA_TIPO_SIMPLE + $4.talla;
                            if ( ! insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1) )
                                   yyerror ("La función ya tiene un parámetro con el mismo identificador");
                     }
              ;

bloque        :      LLAVE1_ declaVarLocal listInst RETURN_ expre PUNTOCOMA_ LLAVE2_
                     {
                            INF inf = obtTdD(-1);
			       if (inf.tipo != T_ERROR) {
				       if (inf.tipo != $5.tipo) {
					       yyerror("Incompatibilidad de tipos en el bloque de la función"); 
				       }     
			       }
                     }
              ;

declaVarLocal :      {$$ = T_ VACIO;}
              |      declaVarLocal declaVar
                     {$$ = $1 + $2;}
              ;
----------------------------------------------
listInst      :
              | listInst inst
              ;

inst          :      LLAVE1_ listInst LLAVE2_
              |      instExpre
              |      instEntSal   
              |      instSelec
              |      instIter   
              ;

instExpre     :      expre PUNTOCOMA_
              |      PUNTOCOMA_
              ;

instEntSal    :      READ_ PARENTESIS1_ ID_ PARENTESIS2_ PUNTOCOMA_
                     {
                            SIMB sim = obtTdS($3);
                            if(sim.t == T_ERROR){ yyerror(E_UNDECLARED);}
                            else if(sim.y != T_ENTERO){ yyerror("Entrada Read debe ser entero");}
                     }
              |      PRINT_ PARENTESIS1_ expre PARENTESIS2_ PUNTOCOMA_
                     {
                            if($3 != T_ENTERO){ yyerror("Entrada Print debe ser entero");}
                     }
              ;

instSelec     :      IF_ PARENTESIS1_ expre PARENTESIS2_ inst ELSE_ inst
                     {
                            if($3.tipo != T_ERROR && $3.tipo != T_LOGICO) { yyerror(E_IF_LOGICAL);}
                     }
              ;

instIter      :      FOR_ PARENTESIS1_ expreOp PUNTOCOMA_ expre PUNTOCOMA_ expreOp PARENTESIS2_ inst
                     {
                            if($5.tipo != T_ERROR && $5.tipo != T_LOGICO) { yyerror(E_FOR_LOGICAL);}
                     }
              ;

expreOp       :      {$$ = T_VACIO;}
              |      expre  {$$ = $1;}
              ;

expre         :      expreLogic  {$$ = $1;}
              |      ID_ ASIGNAR_ expre
                     {
                     SIMB sim = obtTdS($1);
                     $$ = T_ERROR;
                     if ($3 != T_ERROR){
                            if(sim.t == T_ERROR){ yyerror(E_UNDECLARED);}
                            else if (sim.t == T_ARRAY){ yyerror(E_ARRAY_WO_INDEX);}
                            else if (sim.t != $3){yyerror(E_TYPES_ASIGNACION);}
                            else{ $$ = $3;}
                            }
                     }
              |      ID_ CORCHETE1_ expre CORCHETE2_ ASIGNAR_ expre
                     {
                     SIMB sim = obtTdS($1);
                     $$ = T_ERROR;
                     if($3 != T_ERROR && $6 != T_ERROR){
                            if(sim.t == T_ERROR){ yyerror(E_UNDECLARED);}
                            else if(sim.t != T_ARRAY){ yyerror(E_VAR_WITH_INDEX);}
                            else if ($3 != T_ENTERO){ yyerror(E_ARRAY_INDEX_TYPE);}
                            else{
                                   DIM dim = obtTdA(sim.ref);
                                   if(dim.telem != T_ERROR){
                                          if(dim.telem != $6.tipo){yyerror(E_TYPES_ASIGNACION);}
                                          else{ $$ = $3.tipo;}
                                          }
                                   }
                            }
                     }
              ;

expreLogic    :      expreIgual  {$$ = $1;}
              |      expreLogic opLogic expreIgual
                     {
                     $$ = T_ERROR
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror(E_TYPES_LOGICA);}
                            else if($1 != T_LOGICO){ yyerror("NO es booleana la expresion");}
                            else{ $$ = T_LOGICO;}
                            }         
                     }
              ;

expreIgual    :      expreRel  {$$ = $1;}
              |      expreIgual opIgual expreRel
                     {
                     $$ = T_ERROR
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror(E_TYPES_MISMATCH);}
                            else if($1 != T_LOGICO){ yyerror("NO es booleana la expresion");}
                            else{ $$ = T_LOGICO;}
                            }
                     }
              ;

expreRel      :      expreAd  {$$ = $1;}
              |      expreRel opRel expreAd
                     {
                     $$ = T_ERROR
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror(E_TYPES_MISMATCH);}
                            else if($1 != T_LOGICO){ yyerror("OpRel solo acepta args lógicos");}
                            else{ $$ = T_LOGICO;}
                     }
                     }
              ;

expreAd       :      expreMul  {$$ = $1;}
              |      expreAd opAd expreMul
                     {
                     $$ = T_ERROR
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror(E_TYPES_MISMATCH);}
                            else if($1 != T_ENTERO){ yyerror("OpAd solo acepta args enteros");}
                            else{ $$ = T_ENTERO;}
                     }
                     }
              ;

expreMul      :      expreUna  {$$ = $1;}
              |      expreMul opMul expreUna
                     {
                     $$ = T_ERROR
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror(E_TYPES_MISMATCH);}
                            else if($1 != T_ENTERO){ yyerror("OpMul solo acepta args enteros");}
                            else{ $$ = T_ENTERO;}
                     }
                     }
              ;

expreUna      :      expreSufi  {$$ = $1;}
              |      opUna expreUna
                     {
                     $$ = T_ERROR
                     if($2 != T_ERROR){
                            if($1 != T_LOGICO){ yyerror("Las expresiones unitarias solo aceptan args lógicos");}
                            else{ $$ = T_LOGICO;}
                     }
                     }
              ;

expreSufi     :      const  {$$ = $1;}
              |      PARENTESIS1_ expre PARENTESIS2_  {$$ = $2;}
              |      ID_ 
                     { 
                     SIMB sim = obtTdS($1); 
                     $$ = T_ERROR;
		              if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
		              else{$$ = sim.t;} 
                     }      
              |      ID_ CORCHETE1_ expre CORCHETE2_
                     { 
                     SIMB sim = obtTdS($1); 
                     $$ = T_ERROR;
		              if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
		              else{
                     if(sim.t != T_ARRAY){
		              yyerror("ID debe ser de tipo array");
			}else{
				if ($3 != T_ENTERO ) {yyerror("Indice no entero");}
				else {
					DIM dim = obtTdA(sim.ref);
					if($3 < 0 || $3 > dim.nelem){
					       yyerror("Indice fuera de rango.");
                     		}else{ $$ = dim.telem;}
				}
		       }
	              }
                   
              } 
              |      ID_ PARENTESIS1_ paramAct PARENTESIS2_  
                     { 
                     SIMB sim = obtTdS($1); 
                     $$ = T_ERROR;
		       if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
		       else{
                            INF inf = obtTdD(sim.ref);
			       if (inf.tipo == T_ERROR) { 
				       yyerror("No se encuentra la función"); 
			       } else {
				       $$ = inf.tipo;
			       }
                     } 
                     } 
=======
instEntSal    : READ_ PARENTESIS1_ ID_ PARENTESIS2_ PUNTOCOMA_
                {
                  SIMB sim = obtTdS($3);
                  if(sim.t == T_ERROR){ yyerror(E_UNDECLARED);}
                  else if(sim.y != T_ENTERO){ yyerror("Entrada Read debe ser entero");}
                }
              | PRINT_ PARENTESIS1_ expre PARENTESIS2_ PUNTOCOMA_
                {
                  if($3 != T_ENTERO){ yyerror("Entrada Print debe ser entero");}
                }
              ;

instSelec     : IF_ PARENTESIS1_ expre PARENTESIS2_ inst ELSE_ inst
                {
                  if($3.tipo != T_ERROR && $3.tipo != T_LOGICO) { yyerror(E_IF_LOGICAL);}
                }
              ;

instIter      : FOR_ PARENTESIS1_ expreOp PUNTOCOMA_ expre PUNTOCOMA_ expreOp PARENTESIS2_ inst
                {
                  if($5.tipo != T_ERROR && $5.tipo != T_LOGICO) { yyerror(E_FOR_LOGICAL);}
                }
              ;

expreOp       : {$$ = T_VACIO;}
              | expre {$$ = $1;}
              ;

expre         : expreLogic {$$ = $1}
              | ID_ ASIGNAR_ expre
                {
                  SIMB sim = obtTdS($1);
                  $$ = T_ERROR;
                  if ($3 != T_ERROR){
                    if(sim.t == T_ERROR){ yyerror(E_UNDECLARED);}
                    else if (sim.t == T_ARRAY){ yyerror(E_ARRAY_WO_INDEX);}
                    else if (sim.t != $3){yyerror(E_TYPES_ASIGNACION);}
                    else{ $$ = $3;}
                  }
                }
              | ID_ CORCHETE1_ expre CORCHETE2_ ASIGNAR_ expre
                {
                  SIMB sim = obtTdS($1);
                  $$ = T_ERROR;
                  if($3 != T_ERROR && $6 != T_ERROR){
                    if(sim.t == T_ERROR){ yyerror(E_UNDECLARED);}
                    else if(sim.t != T_ARRAY){ yyerror(E_VAR_WITH_INDEX);}
                    else if ($3 != T_ENTERO){ yyerror(E_ARRAY_INDEX_TYPE);}
                    else{
                      DIM dim = obtTdA(sim.ref);
                      if(dim.telem != T_ERROR){
                        if(dim.telem != $6.tipo){yyerror(E_TYPES_ASIGNACION);}
                        else{ $$ = $3.tipo;}
                      }
                    }
                  }
                }
              ;

expreLogic    : expreIgual {$$ = $1}
              | expreLogic opLogic expreIgual
                {
                  $$ = T_ERROR
                  if($1 != T_ERROR && $3 != T_ERROR){
                    if($1 != $3){ yyerror(E_TYPES_LOGICA);}
                    else if($1 != T_LOGICO){ yyerror("NO es booleana la expresion");}
                    else{ $$ = T_LOGICO;}
                  }
                }
              ;

expreIgual    : expreRel {$$ = $1}
              | expreIgual opIgual expreRel
               {
                  $$ = T_ERROR
                  if($1 != T_ERROR && $3 != T_ERROR){
                    if($1 != $3){ yyerror(E_TYPES_MISMATCH);}
                    else if($1 != T_LOGICO){ yyerror("NO es booleana la expresion");}
                    else{ $$ = T_LOGICO;}
                  }
                }
              ;

expreRel      : expreAd {$$ = $1}
              | expreRel opRel expreAd
               {
                  $$ = T_ERROR
                  if($1 != T_ERROR && $3 != T_ERROR){
                    if($1 != $3){ yyerror(E_TYPES_MISMATCH);}
                    else if($1 != T_LOGICO){ yyerror("OpRel solo acepta args lógicos");}
                    else{ $$ = T_LOGICO;}
                  }
                }
              ;

expreAd       :      expreMul {$$ = $1;}
              |      expreAd opAd expreMul
              {
                  $$ = T_ERROR
                  if($1 != T_ERROR && $3 != T_ERROR){
                    if($1 != $3){ yyerror(E_TYPES_MISMATCH);}
                    else if($1 != T_ENTERO){ yyerror("OpAd solo acepta args enteros");}
                    else{ $$ = T_ENTERO;}
                  }
                }
              ;

expreMul      :      expreUna {$$ = $1;}
              |      expreMul opMul expreUna
              {
                  $$ = T_ERROR
                  if($1 != T_ERROR && $3 != T_ERROR){
                    if($1 != $3){ yyerror(E_TYPES_MISMATCH);}
                    else if($1 != T_ENTERO){ yyerror("OpMul solo acepta args enteros");}
                    else{ $$ = T_ENTERO;}
                  }
                }
              ;

expreUna      :      expreSufi {$$ = $1;}
              |      opUna expreUna 
              {
                  $$ = T_ERROR
                  if($2 != T_ERROR){
                    if($1 != T_LOGICO){ yyerror("Las expresiones unitarias solo aceptan args lógicos");}
                    else{ $$ = T_LOGICO;}
                  }
                }
              ;

expreSufi     :      const {$$ = $1;}
              |      PARENTESIS1_ expre PARENTESIS2_ {$$ = $2;}
              |      ID_ 
              { 
                  SIMB sim = obtTdS($1); 
                  $$ = T_ERROR;
		              if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
		              else{$$ = sim.t;} 
              } 
              |      ID_ CORCHETE1_ expre CORCHETE2_
              { 
                  SIMB sim = obtTdS($1); 
                  $$ = T_ERROR;
		              if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
		              else{
                      if(sim.t != T_ARRAY){
		                      yyerror("ID debe ser de tipo array");
			                }else{
				                  if ($3 != T_ENTERO ) {yyerror("Indice no entero");}
				                  else {
					                    DIM dim = obtTdA(sim.ref);
					                    if($3 < 0 || $3 > dim.nelem){
					                        yyerror("Indice fuera de rango.");
                     					}else{ $$ = dim.telem;}
				                  	  }
		                   		 }
	                    }
                   
              } 
              |      ID_ PARENTESIS1_ paramAct PARENTESIS2_   
              { 
                  SIMB sim = obtTdS($1); 
                  $$ = T_ERROR;
		              if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
		              else{
                     INF inf = obtTdD(sim.ref);
			               if (inf.tipo == T_ERROR) { 
				                 yyerror("No se encuentra la función"); 
			               } else {
				                 $$ = inf.tipo;
			               }
                  } 
              }
              ;

paramAct      :      
              |      listParamAct 
              ;

listParamAct  :      expre 
              |      expre COMA_ listParamAct
              ;

opLogic       :      AND_ {$$ = T_AND;}
              |      OR_ {$$ = T_OR;}
              ;

opIgual       :      IGUAL_ {$$ = T_IGUAL;}
              |      NOTIGUAL_ {$$ = T_NOTIGUAL;}
              ;

opRel         :      MAYOR_ {$$ = T_MAYOR;}
              |      MENOR_ {$$ = T_MENOR;}
              |      MAYORIG_ {$$ = T_MAYORIG;}
              |      MENORIG_ {$$ = T_MENORIG;}
              ;

opAd          :      MAS_ {$$ = T_MAS;}
              |      MENOS_ {$$ = T_MENOS;}
              ;

opMul         :      POR_ {$$ = T_POR;}
              |      DIV_ {$$ = T_DIV;}
              ;

opUna         :      MAS_ {$$ = T_MAS;}
              |      MENOS_ {$$ = T_MENOS;}
              |      NOT_  {$$ = T_NOT;}
              ;


%%
/*****************************************************************************/
/*****AQUI IRIA EL MAIN PERO LO TENEMOS A APARTE: PRINCIPAL.C*********/
