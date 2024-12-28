#include <stdlib.h>
#include "arreglo.h"

arreglo_t *crearArregloGenerico(tipo_t tipo){
    arreglo_t *arreglo = malloc(sizeof(arreglo_t));
    void** datos = malloc(sizeof(void*)*TAM_INICIAL);
    
    arreglo->cantidad = 0;
    arreglo->tipo = tipo;
    arreglo->tam = TAM_INICIAL;
    arreglo->datos = datos;

    return arreglo;
}

bool arrEstaVacio(arreglo_t *arreglo){
    return arreglo->cantidad == 0;
}

uint32_t arrCantidad(arreglo_t *arreglo){
    return arreglo->cantidad;
}

void arrInsertarUltimo(arreglo_t *arreglo, void* elemento){
    void* copia = obtenerClonador(arreglo->tipo)(elemento);
    
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

void arrImprimir(arreglo_t *arreglo, FILE *archivo){
    fprintf(archivo, "[");
    for(int i = 0; i < arreglo->cantidad - 1; i++){
        obtenerImpresor(arreglo->tipo)(archivo, arreglo->datos[i]);
        fprintf(archivo, ",");
    }
    obtenerImpresor(arreglo->tipo)(archivo, arreglo->datos[arreglo->cantidad - 1]);
    fprintf(archivo, "]\n");
}

void *arrObtener(arreglo_t *arreglo, uint32_t posicion){
    return arreglo->datos[posicion];
}

void arrEliminar(arreglo_t *arreglo){
    void** datos = arreglo->datos;
    for(uint32_t i = 0; i < arreglo->cantidad; i++){
        free(datos[i]);
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

funcClone_t *obtenerClonador(tipo_t tipo){
    switch(tipo){
        case TipoInt: 
            return (funcClone_t*)&intClone; 
            break;
        case TipoString:
            return (funcClone_t*)&strClone;
    }
}

funcPrint_t *obtenerImpresor(tipo_t tipo){
    switch(tipo){
        case TipoInt:
            return (funcPrint_t*)&intPrint;
            break;
        case TipoString:
            return (funcPrint_t*)&strPrint;
    }
}

void intPrint(FILE *archivo, int *numero){
    fprintf(archivo, "%d", *numero);
}

void strPrint(FILE *archivo, char **cadena){
    fprintf(archivo, "%s", *cadena);
}

int *intClone(int *numero){
    int *copia = malloc(sizeof(int));
    *copia = *numero;
    return copia;
}

char *strClone(char *cadena){
    int cantidad = 0;
    while(cadena[cantidad] != '\0'){
        cantidad++;
    }

    char *cadenaNueva = malloc(sizeof(char*)*cantidad);
    for(int i = 0; i < cantidad; i++){
        cadenaNueva[i] = cadena[i];
    }

    return cadenaNueva;
}