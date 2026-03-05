%{
#include <stdio.h>
%}

%option noyywrap
%option yylineno

%%

/* Reconoce líneas completas usando un patrón mayor que carácter por carácter */
[^\n]*\n   {
    printf("Linea %d: %s", yylineno, yytext);
}

/* Caso especial: última línea sin salto de línea */
[^\n]+ {
    printf("Linea final (sin salto): %s\n", yytext);
}

%%

int main() {
    printf("Ingrese texto (Ctrl+D para terminar):\n\n");
    yylex();
    return 0;
}
