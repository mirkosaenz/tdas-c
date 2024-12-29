#ifndef CONSTANTE_COLA
#define CONSTANTE_COLA

#include <stdbool.h>
#include <stdlib.h>

//Auxiliares
typedef void (funcDestruir_t)(void*);
typedef void* (funcClonar_t)(void*);

typedef struct s_elemCola{
    void* dato;
    struct s_elemCola *siguiente;
} elemCola_t;

typedef struct s_cola{
    elemCola_t *primero;
    elemCola_t *ultimo;
    funcDestruir_t *destructor;
    funcClonar_t *clonador;
} cola_t;

//Primitivas
cola_t *crearColaEnlazada(funcDestruir_t *destructor, funcClonar_t *clonador);
bool colaEstaVacia(cola_t *cola);
void colaEncolar(cola_t *cola, void* dato);
void* colaDesencolar(cola_t *cola);
void* colaVerPrimero(cola_t *cola);
void colaEliminar(cola_t *cola);

#endif