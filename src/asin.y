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
  Expresion expresion; /*Para guardar tipo y posicion de simbolos no terminales*/
  Ifelse ifelse; /*Para el ifelse ahcerlo igual que en las transparencias*/
  Forexpre forexpre; /*Para hace rel for igual que en las transparencias*/
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
%type <cent> tipoSimp listDecla decla declaFunc declaVarLocal declaVar listParamAct paramAct
%type <cent> instEntSal   
%type <cent>     
%type <cent> opMul opUna opRel opAd opIgual opLogic 
%type <lista> paramForm listParamForm 
%type <expresion> const expre expreLogic expreSufi expreMul
                  expreUna expreAd expreOp expreIgual expreRel
%type <ifelse> instSelec
%type <forexpre> instIter
%%
programa      :     {       
                            si = 0; /* Se refiere a la Siguiente Instrucción*/
		              niv = 0;   /* Nivel de anidamiento "global" o "local" */
                            dvar = 0;  /* Desplazamiento en el Segmento de Variables */
                            cargaContexto(niv);
		       }
                    listDecla
                    {
		              if(verTdS)
		                     mostrarTdS(); 
                            if($2 == 0)
		                     yyerror("No hay main en el programa");
                            else if ($2 > 1)
                                   yyerror("El programa tiene más de un main");
                              
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
		                     yyerror("Identificador de variable repetido");
		              else
		                     dvar += TALLA_TIPO_SIMPLE;
		       }
              |      tipoSimp ID_ ASIGNAR_ const  PUNTOCOMA_
                     {
		              if(!insTdS($2, VARIABLE, $1, niv, dvar, -1))
		                     yyerror("Ya existe una variable con el mismo identificador.");
                            else if (! (((($1 == T_ENTERO) && ($4.tipo == T_ENTERO))) || (($1 == T_LOGICO) && ($4.tipo == T_LOGICO))))
                                   yyerror("Error de tipos en la inicialización de variables");
		              else
		                     dvar += TALLA_TIPO_SIMPLE;
                            /*No tengo la posicion de ID:Voy a la TdS y usando sim obtengo su posicion*/ 
                            SIMB sim = obtTdS($2); /* Esto accede a la TdS y obtiene la info de $3 que es ID_ */
                            emite(EASIG,crArgEnt($4.pos) , crArgNul(),crArgPos(sim.n,sim.d));
                            /*NOTA: Cuando use sim.d para cargar el nivel usa sim.n */
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
                                   yyerror ("Identificador del array repetido");
                            else dvar += numelem * TALLA_TIPO_SIMPLE;
                     }
              ;

const         :      CTE_
                     /* Para poder acceder a const cuando se hace un crArgEnt, vamos a crear una 
                     estructura para guardar el tipo(T_ENTERO) y el valor ($$.pos = $1)
                     {
                      $$.tipo = T_ENTERO; /*Antes era solo $$ = T_ENTERO-> añadimos expresion a header.h y modificamos type de cent en union*/
                      $$.pos = $1;
                     }                              
              |      TRUE_ {$$.tipo = T_LOGICO; $$.pos = TRUE;}
              |      FALSE_ {$$.tipo = T_LOGICO; $$.pos = FALSE;}
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

                            if(!insTdS($2, FUNCION, $1, niv-1, si, $5.ref)) 
                            /* Al poner si, nos guardamos la linea de codigo en 
                                                 la que empieza la función - Se usa en los CALL*/
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
			       dvar = $<cent>3;
			}
              ;
              
paramForm     :      {$$.ref = insTdD(-1, T_VACIO);    $$.talla = 0;}  
              |      listParamForm  
                     {$$.ref = $1.ref;    $$.talla = $1.talla;}   
              ;

listParamForm :      tipoSimp ID_
                     {
                            $$.ref = insTdD(-1, $1);   
                            $$.talla = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE; /* El más a la derecha del todo */
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

bloque        :      {
                     /*********** Cargar los enlaces de control */
                     emite(PUSHFP, crArgNul(),crArgNul(),crArgNul());
                     emite(FPTOP, crArgNul(),crArgNul(),crArgNul());
                     
                     /*********** Reservar de espacio para variables locales y temporales */
                     /*Para hacer los que en las transpas ahcen con D.d = creaLans(Omega) hacemos*/
                     $<cent>$ = creaLans(si); /* D.d = CreaLans(Omega)
                     emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1)); /*-1 correpsonde a el circulo con x que usabamos en teoria */
                     
                     }  
                     
                     LLAVE1_ declaVarLocal listInst RETURN_ expre
                     {
                            INF inf = obtTdD(-1);
			       if (inf.tipo != T_ERROR) {
				       if (inf.tipo != $5) {
					       yyerror("Error de tipos en el return"); 
				       }                                       
			       }
                            else if( inf.tipo == T_ERROR){
                                   yyerror("En la declaracion de la funcion");
                            } 
                     }
                     PUNTOCOMA_ LLAVE2_ 
                     {
                     /****** Completar la reserva para las variables locales y temporales */
                     completaLans($<cent>1, crArgEnt(dvar));
                     /****** Guardar el valor de retorno */
                     int dret = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE + inf.tsp;
                     emite(EASIG, crArgPos(niv, $6.pos), crArgNul(), crArgPos(niv, -dret)); /* Para obtener el valor del return*/
                     /****** Liberar el segmento de variables locales y temporales */
                     emite(TOPFP, crArgNul(), crArgNul(), crArgNul() );
                     /****** Descargar los enlaces de control */
                     emite(FPPOP, crArgNul(), crArgNul(), crArgNul() );
                     /****** Emitir FIN si es ‘‘main’’ y RETURN si no es */
                     if (strcmp(inf.nom,"main") == 0) { emite(FIN, crArgNul(), crArgNul(), crArgNul()); 
                     }else { emite(RET, crArgNul(), crArgNul(), crArgNul()); }
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
                            SIMB sim = obtTdS($3); /* Esto accede a la TdS y obtiene la info de $3 que es ID_ */
                            if(sim.t == T_ERROR){ yyerror("No esta declarada");}
                            else if(sim.t != T_ENTERO){ yyerror("El argumento del 'Read' debe ser 'entero'");}
                            emite(EREAD, crArgNul(), crArgNul(),crArgPos(sim.n, sim.d) );
                     }
              |      PRINT_ PARENTESIS1_ expre PARENTESIS2_ PUNTOCOMA_
                     {
                            if($3 != T_ENTERO){ yyerror("La expresion del 'print' debe ser 'entera'");}
                            /*Ahora mismo expre solo guarda el tipo, habrá que hacer con expre y todas las expre lo mismo que con const*/
                            /*Así tednrá tipo y posicion*/
                            emite(EWRITE, crArgNul(), crArgNul(),crArgPos(niv, $3) ); /*Cambiar expre por expre.pos*/
                            /*NOTA: CAMBIA TODOS LOS USOS DE EXPRE CON $i por $i.tipo al meterlo como const*/
                     }
              ;

instSelec     :      IF_ PARENTESIS1_ expre PARENTESIS2_
                     {
                            if($3 != T_ERROR && $3.tipo != T_LOGICO) { yyerror("La expresion del `if' debe ser 'logico'");}
                            /*USamos $<ifelse>$.lf y no $$.lf porque el instSelec (Estrucutra IF)*/
                            /*aun no se ha termiando de procesar, sol opuedo hacer $$.lf si estuviese al final*/
                            $<ifelse>$.lf = creaLans(si));
                            emite(EIGUAL, expresion.pos, crArgEnt(0), crArgEnt(-1));
                     }
                     inst 
                     {
                            $<ifelse>$.fin = creaLans(si)); 
                            emite(GOTOS, crArgNul(),crArgNul(),crArgEnt(-1));
                            completaLans($<ifelse>$.lf,crArgEtq(si));
                     } 
                     ELSE_ inst
                     {
                            completaLans($<ifelse>$.fin,crArgEtq(si));
                     } 
              ;

instIter      :      FOR_ PARENTESIS1_ expreOp PUNTOCOMA_
                     {
                            $<forexpre>$.ini = si; /*NOTA: METER COSAS EN MITAD REGLA HACE QUE SEA UN $ más -> cambiar refenrencias anteriores*/
                            /*$5 ahora sera $6 y $7 sera $9(porque hay 2 por medio) */ 
                     } 
                     expre PUNTOCOMA_ 
                     {
                            $<forexpre>$.lv = creaLans(si); 
                            emite(EIGUAL, expresion.pos, crArgEnt(1), crArgEnt(-1));
                            $<forexpre>$.lf = creaLans(si);
                            emite(GOTOS, crArgNul(),crArgNul(),crArgEnt(-1));
                            $<forexpre>$.aux = si;
                     } 
                     expreOp PARENTESIS2_ 
                     {
                            
                            if ($3 != T_ERROR && $6 != T_ERROR && $9 != T_ERROR){
                                   if ($3 != T_VACIO && $3 != T_ENTERO && $3 != T_LOGICO) {
                                          yyerror("Las expresiones opcionales han de ser de tipo simple. ");
                                   }
                                   else if ($9 != T_VACIO && $9 != T_ENTERO && $9 != T_LOGICO) {
                                          yyerror("Las expresiones opcionales han de ser de tipo simple. ");
                                   } 
                                   else if ($6!=T_LOGICO) yyerror("La condicion del for debe ser de tipo logico. ");
                            } 
                            emite(GOTOS, crArgNul(),crArgNul(),crArgEnt($<forexpre>$.ini));
                            completaLans($<ifelse>$.lv,crArgEtq(si));
                     }
                     inst{
                            emite(GOTOS, crArgNul(),crArgNul(),crArgEnt($<forexpre>$.aux));
                            completaLans($<ifelse>$.lf,crArgEtq(si));
                     }
               
              ;

expreOp       :      {$$.tipo = T_VACIO;}
              |      expre  {$$.tipo = $1.tipo;} /*Aqui no*/
              ;

expre         :      expreLogic  {$$.tipo = $1.tipo; $$.pos = $1.pos;} 
              |      ID_ ASIGNAR_ expre
                     {
                     SIMB sim = obtTdS($1);
                     $$.tipo = T_ERROR;
                     if ($3.,tipo != T_ERROR){
                            if(sim.t == T_ERROR){ yyerror("Objeto no declarado");}
                            else if (sim.t == T_ARRAY){ yyerror("La variable debe ser de tipo array");}
                            else if (sim.t != $3){yyerror("En la asignacion a una variable simple");}
                            else{ $$.tipo = $3.tipo;}
                            }
                     emite(EASIG, crArgPos(niv, $3.pos), crArgNul(), crArgPos(sim.n, sim.d));
                     }
              |      ID_ CORCHETE1_ expre CORCHETE2_ ASIGNAR_ expre
                     {
                     SIMB sim = obtTdS($1);
                     $$.tipo = T_ERROR;
                     if($3.tipo != T_ERROR && $6.tipo != T_ERROR){
                            if(sim.t == T_ERROR){ yyerror("Expresion no declarada");}
                            else if(sim.t != T_ARRAY){ yyerror("La variable debe ser de tipo array");}
                            else if ($3.tipo != T_ENTERO){ yyerror("El indice del array debe ser entero");}
                            else{
                                   DIM dim = obtTdA(sim.ref);
                                   if(dim.telem != T_ERROR){
                                          if(dim.telem != $6.tipo){yyerror("Error de tipos en la asignacion a un `array'");}
                                          else{ $$.tipo = $3.tipo;}
                                          }
                                   }
                            }
                     
                     emite(EMULT, crArgPos(niv, $3.pos), crArgEnt(TALLA_TIPO_SIMPLE) , crArgPos(niv, $3.pos));
                     $$.pos = creaVarTemp();
                     emite(EVA, crArgPos(sim.n,sim.d), crArgPos(niv,$3.pos),crArgPos(niv,$6.pos));
                     /*Añado esto porque en todas las asignaciones de expre tengo que hacer esto: a[b=2]=true o a[b[3]=2]=5(el b=2)*/
                     emite(EASIG, crArgPos(niv,$6.pos), crArgNul(),crArgPos(niv, $$.pos));
                     }
              ;

expreLogic    :      expreIgual  {$$.tipo = $1.tipo; $$.pos = $1.pos;}
              |      expreLogic opLogic expreIgual
                     {
                     $$.tipo = T_ERROR;
                     if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                            if($1.tipo != $3.tipo){ yyerror("Error en la expresion logica");}
                            else if($1.tipo != T_LOGICO){ yyerror("La expresion logica debe ser booleana");}
                            else{ $$.tipo = T_LOGICO;}
                            } 
                     $$.pos = creaVarTemp();
                     if ($2 == EMULT){   /* es un AND */
                            emite(EMULT, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, $$.pos));
                     } else{    /* es un OR */
                            emite(ESUM, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, $$.pos));
                            emite(EMENEQ, crArgPos(niv, $$.pos), crArgEnt(1), crArgEtq(si + 2));
                            emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.pos));
                     }               
                     }
              ;

expreIgual    :      expreRel  {$$.tipo = $1.tipo; $$.pos = $1.pos;}
              |      expreIgual opIgual expreRel
                     {
                     $$.tipo = T_ERROR;
                     if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                            if($1.tipo != $3.tipo){ yyerror("Error en la expresion de igualdad");}
                            else if($1.tipo != T_LOGICO){ yyerror("La expresion de igualdad debe ser booleana");}
                            else{ $$.tipo = T_LOGICO;}
                            }
                     $$.pos = creaVarTemp();
                     emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.pos));
                     emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgEtq(si + 2));  /*Puede ser == o !=*/
                     emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.pos));
                     }
              ;

expreRel      :      expreAd  {$$.tipo = $1.tipo; $$.pos = $1.pos;}
              |      expreRel opRel expreAd
                     {
                     $$.tipo = T_ERROR;
                     if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                            if($1.tipo != $3.tipo){ yyerror("Error en la expresion relacional");}
                            else if($1.tipo == T_LOGICO){ yyerror("La expresion relacional debe ser booleana");}
                            else{ $$.tipo = T_LOGICO;}
                     }
                     $$.pos = creaVarTemp();
                     emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.pos));
                     emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgEtq(si + 2));  /*Puede ser == o !=*/
                     emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.pos));
                     }
              ;

expreAd       :      expreMul  {$$.tipo = $1.tipo; $$.pos = $1.pos;}
              |      expreAd opAd expreMul
                     {
                     $$.tipo = T_ERROR;
                     if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                            if($1.tipo != $3.tipo){ yyerror("Error en la expresion aditiva");}
                            else if($1.tipo != T_ENTERO){ yyerror("la expresion aditiva debe ser de tipo entero");}
                            else{ $$.tipo = T_ENTERO;}
                     }
                     $$.pos = creaVarTemp();
                     emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, $$.pos));
                     }
              ;

expreMul      :      expreUna  {$$.tipo = $1.tipo; $$.pos = $1.pos;}
              |      expreMul opMul expreUna
                     {
                     $$.tipo = T_ERROR;
                     if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                            if($1.tipo != $3.tipo){ yyerror("Error en la expresion multiplicativa");}
                            else if($1.tipo != T_ENTERO){ yyerror("La expresion multiplicativa debe ser de tipo entero");}
                            else{ $$.tipo = T_ENTERO;}
                     }
                     $$.pos = creaVarTemp();
                     emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, $$.pos));
                     }
              ;

expreUna      :      expreSufi  {$$.tipo = $1.tipo; $$.pos = $1.pos;}
              |      opUna expreUna
                     {
                     $$.tipo = T_ERROR;
                     if($2.tipo != T_ERROR){
                            if( $2.tipo == T_ENTERO){
                                   if( $1 == EDIF){
                                   yyerror("Error en expresion unaria");
                                   } else{
                                          $$.tipo = T_ENTERO;
                                   }      
                            }else if($2.tipo == T_LOGICO){
                                   if ($1 == EDIF) {
                                          $$.tipo = T_LOGICO;
                                   } else {
                                          yyerror("Operacion entera invalidada en expresion logica");
                                   }
                            } 
                     }
                     $$.pos = creaVarTemp();
                     if ($1 == ESIG) { /*NOT*/
                            emite(EDIF, crArgEnt(1), crArgPos(niv, $2.pos), crArgPos(niv, $$.pos));    
                     } else { /*MAS y MENOS*/
                            emite($1, crArgEnt(0), crArgPos(niv, $2.pos), crArgPos(niv, $$.pos));
                     } 
                     } 
              ;

expreSufi     :      const  /*QUE ES EXPRESUFI*/
                     {
                     $$.tipo = $1.tipo;

                     $$.pos = creaVarTemp();
                     emite(EASIG, crArgEnt($1.pos), crArgNul(), crArgPos(niv, $$.pos));
                     }
              |      PARENTESIS1_ expre PARENTESIS2_  {
                     $$.tipo = $2.tipo;
                     $$.pos = $2.pos;
                     } 
              |      ID_ 
                     { 
                     SIMB sim = obtTdS($1); 
                     $$.tipo = T_ERROR;
                            if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
                            else{$$.tipo = sim.t;} 
                     $$.pos = creaVarTemp();
                     emite(EASIG, crArgPos(sim.n, sim.d), crArgNul(), crArgPos(niv, $$.pos));
                     }      
              |      ID_ CORCHETE1_ expre CORCHETE2_
                     { 
                     SIMB sim = obtTdS($1); 
                     $$.tipo = T_ERROR;
                     if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
                     else{
                     if(sim.t != T_ARRAY){
		              yyerror("ID debe ser de tipo array");
			}else{
				if ($3.tipo != T_ENTERO ) {yyerror("Indice no entero");}
				else {
					DIM dim = obtTdA(sim.ref);
					$$.tipo = dim.telem;
				}
		       }
                     
                     emite(EMULT, crArgPos(niv, $3.pos), crArgEnt(TALLA_TIPO_SIMPLE) , crArgPos(niv, $3.pos));
                     
                     $$.pos = creaVarTemp();
                     emite(EAV, crArgPos(sim.n,sim.d), crArgPos(niv,$3.pos),crArgPos(niv,$$.pos));
	              }
                   
                     } 
              |      ID_ PARENTESIS1_ paramAct PARENTESIS2_  
                     { 
                     SIMB sim = obtTdS($1); 
                     $$.tipo = T_ERROR;
		       if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
		       else{
                            INF inf = obtTdD(sim.ref);
                            
			       if (inf.tipo == T_ERROR) { 
				       yyerror("No se encuentra la función"); 
			       } else { 
                                   $$.tipo = inf.tipo;
                                   if (sim.t != T_ARRAY){ 
                                          INF inf2 = obtTdD(-1);    //la f actual
                                          if (inf2.tipo != inf.tipo){
                                                 yyerror("En el dominio de los parametros actuales");
                                          }
                                   }
                                   
                                    
			       }
                     } 
                     } 
              ;

paramAct      :     {$$ = insTdD(-1,T_VACIO);} 
              |     listParamAct { $$ = $1;}
              ;

listParamAct  :      expre 
              {
                     $$ = insTdD(-1,$1);
                     emite(EPUSH,crArgNul(),crArgNul(),crArgPos(niv, $1.pos));
              }
              |      expre 
              {
                     emite(EPUSH,crArgNul(),crArgNul(),crArgPos(niv, $1.pos));
              }
              COMA_ listParamAct
                     {$$ = insTdD($3,$1);}
              ;

opLogic       :      AND_ {$$ = EMULT;}
              |      OR_ {$$ = ESUM;}
              ;

opIgual       :      IGUAL_ {$$ = EIGUAL;}
              |      NOTIGUAL_ {$$ = EDIST;}
              ;

opRel         :      MAYOR_ {$$ = EMAY;}
              |      MENOR_ {$$ = EMEN;}
              |      MAYORIG_ {$$ = EMAYEQ;}
              |      MENORIG_ {$$ = EMENEQ;}
              ;

opAd          :      MAS_ {$$ = ESUM;}
              |      MENOS_ {$$ = EDIF;}
              ;

opMul         :      POR_ {$$ = EMULT;}
              |      DIV_ {$$ = EDIVI;}
              ;

opUna         :      MAS_ {$$ = ESUM;}
              |      MENOS_ {$$ = EDIF;}
              |      NOT_  {$$ = ESIG;}
              ;

              ;


%%
/*****************************************************************************/
/*****AQUI IRIA EL MAIN PERO LO TENEMOS A APARTE: PRINCIPAL.C*********/