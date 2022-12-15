/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2          2022-2023 <jbenedi@dsic.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "asin.h"

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
%token <ident> ID_
%type <cent> const tipoSimp listDecla decla declaFunc declaVarLocal declaVar listParamAct paramAct
%type <cent> expre instEntSal instSelec instIter expreOp expreLogic expreIgual expreRel
%type <cent> expreAd expreMul expreUna expreSufi 
%type <cent> opMul opUna opRel opAd opIgual opLogic 
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
                            else if ($2 > 1)
                                   yyerror("el programa tiene más de un main");
                              
		       }
              ;

listDecla     :     decla
              |     listDecla decla   
                     {
		              $$ = $1 + $2;    
		       }    
              ;

decla         :      declaVar { $$ = 0; }
              |      declaFunc       
              ;

declaVar      :      tipoSimp ID_ PUNTOCOMA_
		      {
		              if(!insTdS($2,VARIABLE,$1,niv,dvar,-1))
		                     yyerror("Ya existe una variable con el mismo identificador.");
		              else
		                     dvar += TALLA_TIPO_SIMPLE;
		       }
              |      tipoSimp ID_ ASIGNAR_ const  PUNTOCOMA_
                     {
		              if(!insTdS($2, VARIABLE, $1, niv, dvar, -1))
		                     yyerror("Ya existe una variable con el mismo identificador.");
                            else if (! (((($1 == T_ENTERO) && ($4 == T_ENTERO))) || (($1 == T_LOGICO) && ($4 == T_LOGICO))))
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

const         :      CTE_ {$$ = T_ENTERO;}                              
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
				       if (inf.tipo != $5) {
					       yyerror("Error de tipos en el return"); 
				       }     
			       }
                     }
              ;

declaVarLocal :      {$$ = T_VACIO;}
              |      declaVarLocal declaVar
                     {$$ = $1 + $2;}
              ;

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
                            if(sim.t == T_ERROR){ yyerror("No esta declarada");}
                            else if(sim.t != T_ENTERO){ yyerror("Entrada Read debe ser entero");}
                     }
              |      PRINT_ PARENTESIS1_ expre PARENTESIS2_ PUNTOCOMA_
                     {
                            if($3 != T_ENTERO){ yyerror("Entrada Print debe ser entero");}
                     }
              ;

instSelec     :      IF_ PARENTESIS1_ expre PARENTESIS2_ inst ELSE_ inst
                     {
                            if($3 != T_ERROR && $3 != T_LOGICO) { yyerror("Error en declaracion if");}
                     }
              ;

instIter      :      FOR_ PARENTESIS1_ expreOp PUNTOCOMA_ expre PUNTOCOMA_ expreOp PARENTESIS2_ 
                     {
                            // if(($5 != T_ERROR && $5 != T_LOGICO)) {
                            //        yyerror("expresion debe ser logica");
                            // }else if($3 != T_VACIO && $3 != T_ERROR) { yyerror("No es de tipo simple");}
                            // else if($7 != T_VACIO && $7 != T_ERROR) { yyerror("No es de tipo simple");}    
                            
                            if ($3 != T_ERROR && $5 != T_ERROR && $7 != T_ERROR){
                                   if ($3 != T_VACIO && $3 != T_ENTERO && $3 != T_LOGICO) {
                                          yyerror("Las expresiones opcionales han de ser de tipo simple. ");
                                   }
                                   else if ($7 != T_VACIO && $7 != T_ENTERO && $7 != T_LOGICO) {
                                          yyerror("Las expresiones opcionales han de ser de tipo simple. ");
                                   } 
                                   else if ($5!=T_LOGICO) yyerror("La condicion no es de tipo logico. ");
                            } 
                     }
                     inst{}
               
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
                            if(sim.t == T_ERROR){ yyerror("Expresion no declarada");}
                            else if (sim.t == T_ARRAY){ yyerror("Expresion NO tipo array");}
                            else if (sim.t != $3){yyerror("NO son el mismo tipo al asignar al array");}
                            else{ $$ = $3;}
                            }
                     }
              |      ID_ CORCHETE1_ expre CORCHETE2_ ASIGNAR_ expre
                     {
                     SIMB sim = obtTdS($1);
                     $$ = T_ERROR;
                     if($3 != T_ERROR && $6 != T_ERROR){
                            if(sim.t == T_ERROR){ yyerror("Expresion no declarada");}
                            else if(sim.t != T_ARRAY){ yyerror("Expresion NO tipo array");}
                            else if ($3 != T_ENTERO){ yyerror("Indice del array NO es de tipo entero");}
                            else{
                                   DIM dim = obtTdA(sim.ref);
                                   if(dim.telem != T_ERROR){
                                          if(dim.telem != $6){yyerror("Tipo de array no coincide con el asignado");}
                                          else{ $$ = $3;}
                                          }
                                   }
                            }
                     }
              ;

expreLogic    :      expreIgual  {$$ = $1;}
              |      expreLogic opLogic expreIgual
                     {
                     $$ = T_ERROR;
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror("Expresiones de diferente tipo");}
                            else if($1 != T_LOGICO){ yyerror("NO es booleana la expresion");}
                            else{ $$ = T_LOGICO;}
                            }         
                     }
              ;

expreIgual    :      expreRel  {$$ = $1;}
              |      expreIgual opIgual expreRel
                     {
                     $$ = T_ERROR;
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror("Expresiones de diferente tipo");}
                            else if($1 != T_LOGICO){ yyerror("NO es booleana la expresion");}
                            else{ $$ = T_LOGICO;}
                            }
                     }
              ;

expreRel      :      expreAd  {$$ = $1;}
              |      expreRel opRel expreAd
                     {
                     $$ = T_ERROR;
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror("Expresiones de diferente tipo");}
                            else if($1 == T_LOGICO){ yyerror("OpRel solo acepta args lógicos");}
                            else{ $$ = T_LOGICO;}
                     }
                     }
              ;

expreAd       :      expreMul  {$$ = $1;}
              |      expreAd opAd expreMul
                     {
                     $$ = T_ERROR;
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror("Expresiones de diferente tipo");}
                            else if($1 != T_ENTERO){ yyerror("OpAd solo acepta args enteros");}
                            else{ $$ = T_ENTERO;}
                     }
                     }
              ;

expreMul      :      expreUna  {$$ = $1;}
              |      expreMul opMul expreUna
                     {
                     $$ = T_ERROR;
                     if($1 != T_ERROR && $3 != T_ERROR){
                            if($1 != $3){ yyerror("Expresiones de diferente tipo");}
                            else if($1 != T_ENTERO){ yyerror("OpMul solo acepta args enteros");}
                            else{ $$ = T_ENTERO;}
                     }
                     }
              ;

expreUna      :      expreSufi  {$$ = $1;}
              |      opUna expreUna
                     {
                     $$ = T_ERROR;
                     if($2 != T_ERROR){
                            if( $2 == T_ENTERO){
                                   if( $1 == OP_NOT){
                                   yyerror("Operacion ! invalidada en expresion entera");
                                   } else{
                                          $$ = T_ENTERO;
                                   }      
                            }else if($2 == T_LOGICO){
                                   if ($1 == OP_NOT) {
                                          $$ = T_LOGICO;
                                   } else {
                                          yyerror("Operacion entera invalida en expresion logica");
                                   }
                            } 
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
              ;

paramAct      :     {$$ = insTdD(-1,T_VACIO);} 
              |     listParamAct { $$ = $1;}
              ;

listParamAct  :      expre 
                    // {$$ = insTdD(-1,$1);} 
              |      expre COMA_ listParamAct
                     //{$$ = insTdD($3,$1);}
              ;

opLogic       :      AND_ {$$ = OP_AND;}
              |      OR_ {$$ = OP_OR;}
              ;

opIgual       :      IGUAL_ {$$ = OP_IGUAL;}
              |      NOTIGUAL_ {$$ = OP_NOTIGUAL;}
              ;

opRel         :      MAYOR_ {$$ = OP_MAYOR;}
              |      MENOR_ {$$ = OP_MENOR;}
              |      MAYORIG_ {$$ = OP_MAYORIG;}
              |      MENORIG_ {$$ = OP_MENORIG;}
              ;

opAd          :      MAS_ {$$ = OP_MAS;}
              |      MENOS_ {$$ = OP_MENOS;}
              ;

opMul         :      POR_ {$$ = OP_POR;}
              |      DIV_ {$$ = OP_DIV;}
              ;

opUna         :      MAS_ {$$ = OP_MAS;}
              |      MENOS_ {$$ = OP_MENOS;}
              |      NOT_  {$$ = OP_NOT;}
              ;


%%
/*****************************************************************************/
/*****AQUI IRIA EL MAIN PERO LO TENEMOS A APARTE: PRINCIPAL.C*********/
