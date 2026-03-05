#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101

struct nodo {
    char *palabra;
    struct nodo *sig;
};

struct nodo *tabla[HASHSIZE];

/* Hash ignorando mayúsculas */
unsigned symhash(char *s) {
    unsigned hash = 0;

    while (*s)
        hash = hash * 9 ^ tolower(*s++);

    return hash % HASHSIZE;
}

void insertar(char *pal) {
    unsigned h = symhash(pal);
    struct nodo *np;

    /* Buscar si ya existe ignorando mayúsculas */
    for (np = tabla[h]; np; np = np->sig) {
        if (strcasecmp(np->palabra, pal) == 0)
            return;
    }

    np = malloc(sizeof(*np));
    np->palabra = strdup(pal);
    np->sig = tabla[h];
    tabla[h] = np;
}

int main() {

    char palabra[100];

    printf("Ingrese palabras (Ctrl+D para terminar):\n");

    while (scanf("%s", palabra) != EOF)
        insertar(palabra);

    printf("\nPalabras almacenadas:\n");

    for (int i = 0; i < HASHSIZE; i++) {
        struct nodo *np = tabla[i];

        while (np) {
            printf("%s\n", np->palabra);
            np = np->sig;
        }
    }

    return 0;
}
