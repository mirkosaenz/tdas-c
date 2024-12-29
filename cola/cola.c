#include "cola.h"

cola_t *crearColaEnlazada(funcDestruir_t *destructor, funcClonar_t *clonador){
    cola_t *cola = malloc(sizeof(cola_t));
    cola->primero = NULL;
    cola->ultimo = NULL;
    cola->destructor = destructor;
    cola->clonador = clonador;
    return cola;
}

bool colaEstaVacia(cola_t *cola){
    return cola->primero == NULL && cola->ultimo == NULL;
}

void colaEncolar(cola_t *cola, void *dato){
    elemCola_t *nuevo = malloc(sizeof(elemCola_t));
    void* datoClonado = (cola->clonador)(dato);
    nuevo->dato = datoClonado;
    
    if(cola->primero == NULL){
        cola->primero = nuevo;
    }
    if(cola->ultimo != NULL){
        (cola->ultimo)->siguiente = nuevo;
    }

    cola->ultimo = nuevo;
}

void* colaDesencolar(cola_t *cola){
    elemCola_t *primero = cola->primero;
    void* dato = primero->dato;

    cola->primero = primero->siguiente;
    if(cola->primero == NULL){
        cola->ultimo = NULL;
    }

    free(primero);
    return dato;
}

void* colaVerPrimero(cola_t *cola){
    return (cola->primero)->dato;
}

void colaEliminar(cola_t *cola){
    elemCola_t *actual = cola->primero;

    while(actual != NULL){
        elemCola_t *siguiente = actual->siguiente;
        (cola->destructor)(actual->dato);

        free(actual);
        actual = siguiente;
    }

    free(cola);
}