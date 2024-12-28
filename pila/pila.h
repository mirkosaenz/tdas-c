#ifndef CONSTANTE_PILA
#define CONSTANTE_PILA

#include <stdint.h>
#include <stdbool.h>
#include "../arreglo/arreglo.h"
#include <stdlib.h>

typedef struct s_pilaDinamica{
    arreglo_t *datos;
} pilaDinamica_t;

/*Primitivas*/
pilaDinamica_t *crearPilaDinamica(tipo_t tipo);
bool pilaEstaVacia(pilaDinamica_t *pila);
void* pilaVerTope(pilaDinamica_t *pila);
void pilaApilar(pilaDinamica_t *pila, void *elemento);
void* pilaDesapilar(pilaDinamica_t *pila);
void pilaEliminar(pilaDinamica_t *pila);

#endif