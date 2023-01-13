/*****************************************************************************/
/**  Ejemplo de FLEX: S E M - 1           2022-2023 <jmbenedi@prhlt.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"

#define  retornar(x) {if (verbosidad) ECHO; return(x);}
%}
/*-----------------------------------------------------------------------------
  Estas opciones evitan "warnings" innecesarios y permiten obtener el
  numero de linea actual en la variable global "yylineno".
-----------------------------------------------------------------------------*/
%option noinput       
%option nounput     

   
%option yylineno  

letra           	[a-zA-Z]
digito          	[0-9]
delimitador     	[\n]
blanco			[ \t]+
comentario      	"//".*\n
entero          	{digito}+
constante       	{entero}"."?|{entero}?"."{entero}
identificador  	{letra}({letra}|{digito}|_)*

%%
{delimitador}  		{ if (verbosidad) ECHO; fprintf(stdout,"%d.- ", yylineno);}
{comentario}			{ if (verbosidad) ECHO; fprintf(stdout,"%d.- ", yylineno);}
{blanco} 			{ if (verbosidad) ECHO;}
"+"				{ retornar(MAS_); }
"-"				{ retornar(MENOS_); }
"*"				{ retornar(POR_); }
"/"				{ retornar(DIV_); }

"&&"				{ retornar(AND_); }
"||"				{ retornar(OR_); }


"="				{ retornar(ASIGNAR_); }
"!"				{ retornar(NOT_); }

"=="				{ retornar(IGUAL_); }
"!="				{ retornar(NOTIGUAL_); }

">"				{ retornar(MAYOR_); }
"<"				{ retornar(MENOR_); }
">="				{ retornar(MAYORIG_); }
"<="				{ retornar(MENORIG_); }

"{"				{ retornar(LLAVE1_); }
"}"				{ retornar(LLAVE2_); }
"("				{ retornar(PARENTESIS1_); }
")"				{ retornar(PARENTESIS2_); }
"["				{ retornar(CORCHETE1_); }
"]"				{ retornar(CORCHETE2_); }
","				{ retornar(COMA_); }
";"				{ retornar(PUNTOCOMA_); }

"for"				{ retornar(FOR_); }
"if"				{ retornar(IF_); }
"else"				{ retornar(ELSE_); }

"int"				{ retornar(INT_); }
"bool"				{ retornar(BOOL_); }

"read"				{ retornar(READ_); }
"print"			{ retornar(PRINT_); }
"return"			{ retornar(RETURN_); }

"true"				{ retornar(TRUE_); }
"false"			{ retornar(FALSE_); }

{constante}			{ yylval.cent= atoi(yytext); return(CTE_); }
{identificador} 		{ yylval.ident = strdup(yytext); return(ID_); }

.	       { yyerror("Caracter desconocido"); }

%%
/*****************************************************************************/
