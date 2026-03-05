#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nodo {
    char *palabra;
    struct nodo *sig;
};

struct nodo *tabla[HASHSIZE];

/* Función hash */
unsigned hash(char *s) {

    unsigned h = 0;

    while (*s)
        h = h * 31 + *s++;

    return h % HASHSIZE;
}

/* Inserción usando chaining */
void insertar(char *pal) {

    unsigned h = hash(pal);

    struct nodo *nuevo = malloc(sizeof(struct nodo));

    nuevo->palabra = strdup(pal);
    nuevo->sig = tabla[h];
    tabla[h] = nuevo;
}

void imprimir() {

    printf("\nContenido de la tabla:\n");

    for (int i = 0; i < HASHSIZE; i++) {

        struct nodo *np = tabla[i];

        while (np) {
            printf("%s\n", np->palabra);
            np = np->sig;
        }
    }
}

int main() {

    char palabra[100];

    printf("Ingrese palabras (Ctrl+D para terminar):\n");

    while (scanf("%s", palabra) != EOF)
        insertar(palabra);

    imprimir();

    return 0;
}
