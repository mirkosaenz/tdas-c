#ifndef CONSTANTE_PILA
#define CONSTANTE_PILA

#include <stdint.h>
#include <stdbool.h>
#include "../arreglo/arreglo.h"
#include <stdlib.h>

/*Estructura usada para implementar la pila*/
typedef struct s_pilaDinamica{
    arreglo_t *datos;
} pilaDinamica_t;

/*Primitivas*/
/*Crea y devuelve una pila dinamica*/
pilaDinamica_t *crearPilaDinamica(tipo_t tipo);

/* Devuelve true si la pila esta vacia. False en caso contrario */
bool pilaEstaVacia(pilaDinamica_t *pila);

/*Devuelve la cantidad de elementos que estan en la pila*/
uint32_t pilaCantidad(pilaDinamica_t *pila);

/*Devuelve el tope actual de la pila como puntero*/
void* pilaVerTope(pilaDinamica_t *pila);

/*Apila el elemento en la pila*/
void pilaApilar(pilaDinamica_t *pila, void *elemento);

/*Desapila y devuelve (como puntero) el tope de la pila*/
void* pilaDesapilar(pilaDinamica_t *pila);

/*Elimina y libera la memoria ocupada por la pila y sus elementos*/
void pilaEliminar(pilaDinamica_t *pila);

#endif