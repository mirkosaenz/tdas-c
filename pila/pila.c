#include "pila.h"
#include "../arreglo/arreglo.h"

pilaDinamica_t *crearPilaDinamica(tipo_t tipo){
    pilaDinamica_t *pila = malloc(sizeof(pilaDinamica_t));
    pila->datos = crearArregloGenerico(tipo);
    
    return pila;
}

bool pilaEstaVacia(pilaDinamica_t *pila){
    return arrEstaVacio(pila->datos);
}

//grande mel :p
uint32_t pilaCantidad(pilaDinamica_t *pila){
    return arrCantidad(pila->datos);
}

void pilaApilar(pilaDinamica_t *pila, void *elemento){
    arrInsertarUltimo(pila->datos, elemento);
}

void *pilaDesapilar(pilaDinamica_t *pila){
    return arrBorrarUltimo(pila->datos);
}

void* pilaVerTope(pilaDinamica_t *pila){
    return arrObtener(pila->datos, arrCantidad(pila->datos)-1);
}

void pilaEliminar(pilaDinamica_t *pila){
    arrEliminar(pila->datos);
    free(pila);
}