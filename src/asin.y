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
programa      :     {
		                    niv = 0;   /* Nivel de anidamiento "global" o "local" */
                        dvar = 0;  /* Desplazamiento en el Segmento de Variables */
                        cargaContexto(niv);
		                }
                    listDecla
                    {
		                    if(verTdS)
		                      mostrarTdS(); 
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
                        else if (! ((($1.t == T_ENTERO) && ($4.t == T_ENTERO)) ||
                                    ($1.t == T_LOGICO) && ($4.t == T_LOGICO))) )
                                    yyerror("Error de tipos en la declaracion de variables");
		                    else
		                        dvar += TALLA_TIPO_SIMPLE;
		                }
              |      tipoSimp ID_ CORCHETE1_ CTE_ CORCHETE2_ PUNTOCOMA_   
                     {    int numelem = $4;
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

                       /* INCOMPLETO (si alguien descubre cómo declarar el tipo de función dentro de insTdS que avise)*/

                        SIMB f = $2, $5.t, $5.talla;
                        if(!insTdS($2, FUNCION, $1, niv-1, $5.talla, dvar))
		                        yyerror("Ya existe una variable con el mismo identificador.");
                        
                     }
                     bloque
                     {/* Mostrar la informacion de la funcion en la TdS */
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
                     {$$.ref = $1.ref;    $$.talla = $1.talla - TALLA_SEGENLACES;}   
              ;

listParamForm :      tipoSimp ID_
                     {$$.ref = insTdD(-1, $1);   
                      $$.talla = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE;
                      if ( ! insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1) )
                             yyerror ("La función ya tiene un parámetro con el mismo identificador");
                     }
              |      tipoSimp ID_ COMA_ listParamForm
                     {$$.ref = insTdD($4.ref, $1);   
                      $$.talla = TALLA_TIPO_SIMPLE + $4.talla;
                      if ( ! insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1) )
                             yyerror ("La función ya tiene un parámetro con el mismo identificador");
                     }
              ;

bloque        :      LLAVE1_ declaVarLocal listInst RETURN_ expre PUNTOCOMA_ LLAVE2_
                     {INF inf = obtTdD(-1);
			                if (inf.t != T_ERROR) {
				                if (inf.t != $5.t) {
					                yyerror("Incompatibilidad de tipos en el bloque de la función"); 
				                }     
			                }
                     }
              ;

declaVarLocal :      {$$ = T_ VACIO;}
              |      declaVarLocal declaVar
                    
              ;

listInst      :      
              |      listInst inst 
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
              |      PRINT_ PARENTESIS1_ expre PARENTESIS2_ PUNTOCOMA_
              ;

instSelec     :      IF_ PARENTESIS1_ expre PARENTESIS2_ inst ELSE_ inst
              ;

instIter      :      FOR_ PARENTESIS1_ expreOp PUNTOCOMA_ expre PUNTOCOMA_ expreOp PARENTESIS2_ inst
              ;

expreOp       :
              |      expre
              ;

expre         :      expreLogic
              |      ID_ ASIGNAR_ expre
              |      ID_ CORCHETE1_ expre CORCHETE2_ ASIGNAR_ expre
              ;

expreLogic    :      expreIgual
              |      expreLogic opLogic expreIgual
              ;

expreIgual    :      expreRel
              |      expreIgual opIgual expreRel
              ;

expreRel      :      expreAd
              |      expreRel opRel expreAd
              ;

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
