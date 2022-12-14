/*****************************************************************************/
/**   Ejemplo de un posible fichero de cabeceras donde situar las           **/
/** definiciones de constantes, variables y estructuras para MenosC. Los    **/
/** alumnos deberan adaptarlo al desarrollo de su propio compilador.    **/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0

#define T_NOT 0
#define T_MAS 1
#define T_MENOS 2
#define T_POR 3
#define T_DIV 4
#define T_INCR 5
#define T_DECR 6
#define T_MAYOR 7
#define T_MENOR 8
#define T_MAYORIG 9
#define T_MENORIG 10
#define T_IGUAL 11
#define T_NOTIGUAL 12
#define T_OR 13
#define T_AND 14

#define TALLA_TIPO_SIMPLE 1 /* Talla asociada a los tipos simples */
#define TALLA_SEGENLACES 2 /* Talla del segmento de Enlaces de Control */

typedef struct lista{
    int ref;
    int talla;
} Lista;

/************************ Variables externas definidas en Programa Principal */
extern int verTdS; /* Flag para saber si mostrar la TdS */
/***************************** Variables externas definidas en las librer ́ıas */
extern int dvar; /* Desplazamiento en el Segmento de Variables */
extern int niv; /* Nivel de anidamiento "global" o "local" */
/
/
/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();

extern FILE *yyin;                           /* Fichero de entrada           */
extern int   yylineno;                       /* Contador del numero de linea */
extern char *yytext;                         /* Patron detectado             */
/********* Funciones y variables externas definidas en el Programa Principal */
extern void yyerror(const char * msg) ;   /* Tratamiento de errores          */

extern int verbosidad;                   /* Flag si se desea una traza       */
extern int numErrores;              /* Contador del numero de errores        */

#endif  /* _HEADER_H */
/*****************************************************************************/
