#include <stdlib.h>
#include "arreglo.h"

arreglo_t *crearArregloGenerico(funcionClonar_t *clonador, funcionEliminar_t *destructor){
    arreglo_t *arreglo = malloc(sizeof(arreglo_t));
    void** datos = malloc(sizeof(void*)*TAM_INICIAL);
    
    arreglo->cantidad = 0;
    arreglo->tam = TAM_INICIAL;
    arreglo->datos = datos;
    arreglo->clonador = clonador;
    arreglo->destructor = destructor;

    return arreglo;
}

bool arrEstaVacio(arreglo_t *arreglo){
    return arreglo->cantidad == 0;
}

uint32_t arrCantidad(arreglo_t *arreglo){
    return arreglo->cantidad;
}

void arrInsertarUltimo(arreglo_t *arreglo, void* elemento){
    void* copia = (arreglo->clonador)(elemento);
    
    (arreglo->datos)[arreglo->cantidad] = copia;
    arreglo->cantidad += 1;

    if(arreglo->cantidad == arreglo->tam){
        _arrRedimensionar(arreglo, 2*(arreglo->cantidad));
    }
}

void* arrBorrarUltimo(arreglo_t *arreglo){
    if(arreglo->cantidad == 0){
        return NULL; //hacer comprobacion de errores
    }

    (arreglo->cantidad)--;
    return arreglo->datos[arreglo->cantidad];
}

void arrImprimir(arreglo_t *arreglo, FILE *archivo, funcionImprimir_t *impresor){
    fprintf(archivo, "[");
    for(int i = 0; i < arreglo->cantidad - 1; i++){
        impresor(archivo, arreglo->datos[i]);
        fprintf(archivo, ",");
    }
    impresor(archivo, arreglo->datos[arreglo->cantidad - 1]);
    fprintf(archivo, "]\n");
}

void *arrObtener(arreglo_t *arreglo, uint32_t posicion){
    return arreglo->datos[posicion];
}

void arrEliminar(arreglo_t *arreglo){
    void** datos = arreglo->datos;
    for(uint32_t i = 0; i < arreglo->cantidad; i++){
        (arreglo->destructor)(datos[i]);
    }
    free(datos);
    free(arreglo);
}

void _arrRedimensionar(arreglo_t *arreglo, uint32_t nuevoTam){
    void** nuevosDatos = malloc(sizeof(void*)*nuevoTam);

    for(uint32_t i = 0; i < arreglo->cantidad; i++){
        nuevosDatos[i] = arreglo->datos[i];
    }

    free(arreglo->datos);
    arreglo->datos = nuevosDatos;
    arreglo->tam = nuevoTam;
}