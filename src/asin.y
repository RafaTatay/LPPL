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
%token CTE_ ID_
/********/
%token <cent> CTE_
%token <*ident> ID_
%type <cent> const tipoSimp
%%
programa      :    listDecla
              ;

listDecla     :     decla
              |     listDecla decla        
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
              |      tipoSimp ID_ CORCHETE1_ CTE_ CORCHETE2_ PUNTOCOMA_       
              ;

const         :      CTE_ {$$ = T_ ENTERO;}                              
              |      TRUE_ {$$ = T_LOGICO;}
              |      FALSE_ {$$ = T_LOGICO;}
              ;

tipoSimp      :      INT_ {$$ = T_ENTERO;}
              |      BOOL_ {$$ = T_LOGICO;}
              ;

declaFunc     :      tipoSimp ID_ PARENTESIS1_ paramForm PARENTESIS2_ bloque
              ;
              
paramForm     :      
              |      listParamForm     
              ;

listParamForm :      tipoSimp ID_
              |      tipoSimp ID_ COMA_ listParamForm
              ;

bloque        :      LLAVE1_ declaVarLocal listInst RETURN_ expre PUNTOCOMA_ LLAVE2_
              ;

declaVarLocal :      
              |      declaVarLocal declaVar
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

instSelec     :      IF_ PARENTESIS1_ expre PARENTESIS2_ inst ELSE_ inst
              ;

instIter      :      FOR_ PARENTESIS1_ expreOp PUNTOCOMA_ expre PUNTOCOMA_ expreOp PARENTESIS2_ inst
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
----------
expreAd       :      expreMul
              |      expreAd opAd expreMul
              ;

expreMul      :      expreUna
              |      expreMul opMul expreUna
              ;

expreUna      :      expreSufi
              |      opUna expreUna
              ;

expreSufi     :      const
              |      PARENTESIS1_ expre PARENTESIS2_
              |      ID_ 
              |      ID_ CORCHETE1_ expre CORCHETE2_
              |      ID_ PARENTESIS1_ paramAct PARENTESIS2_   
              ;

paramAct      :      
              |      listParamAct
              ;

listParamAct  :      expre
              |      expre COMA_ listParamAct
              ;

opLogic       :      AND_
              |      OR_
              ;

opIgual       :      IGUAL_
              |      NOTIGUAL_
              ;

opRel         :      MAYOR_
              |      MENOR_
              |      MAYORIG_
              |      MENORIG_
              ;

opAd          :      MAS_
              |      MENOS_
              ;

opMul         :      POR_
              |      DIV_
              ;

opUna         :      MAS_
              |      MENOS_
              |      NOT_
              ;


%%
/*****************************************************************************/
/*****AQUI IRIA EL MAIN PERO LO TENEMOS A APARTE: PRINCIPAL.C*********/
