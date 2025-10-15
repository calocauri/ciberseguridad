#include <stdio.h>
#include <stdlib.h>

struct Nodo {
int dato;
struct Nodo* siguiente;
struct Nodo* anterior;
};
typedef struct Nodo Nodo;
int main() {
Nodo* nodo1 = (Nodo*)malloc(sizeof(Nodo));
Nodo* nodo2 = (Nodo*)malloc(sizeof(Nodo));
Nodo* nodo3 = (Nodo*)malloc(sizeof(Nodo));

nodo1->dato = 10;
nodo2->dato = 20;
nodo3->dato = 30;

nodo1->siguiente = nodo2;
nodo2->siguiente = nodo3;
nodo3->siguiente = NULL; 

    nodo3->anterior = nodo2;
    nodo2->anterior = nodo1;
    nodo1->anterior = NULL; 

    printf("numeros hacia adelante:\n");
    Nodo* actual = nodo1;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\nnumeros hacia atras:\n");
    actual = nodo3;
    while (actual != NULL) {
    printf("%d ", actual->dato);
        actual = actual->anterior;
    }
    free(nodo1);
    free(nodo2);
    free(nodo3);

    return 0;
}
