#ifndef CONSTANTE_ARREGLO
#define CONSTANTE_ARREGLO

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

// Constantes
#define TAM_INICIAL 4

/* Definicion como tipos de punteros a funciones */
typedef void* (funcionClonar_t)(void*);
typedef void (funcionEliminar_t)(void*);
typedef void (funcionImprimir_t)(FILE*, void*);

/*Estructura para la implementacion del arreglo generico redimensionable*/
typedef struct s_arreglo{
    uint32_t cantidad;
    uint32_t tam;
    void** datos;
    funcionClonar_t *clonador;
    funcionEliminar_t *destructor;
} arreglo_t;


// Primitivas
/*Crea y devuelve un arreglo generico redimensionable*/
arreglo_t *crearArregloGenerico(funcionClonar_t*, funcionEliminar_t*);

/*Devuelve true si el arreglo esta vacio, o false en caso contrario*/
bool arrEstaVacio(arreglo_t *arreglo);

/*Devuelve la cantidad de elementos insertados en el arreglo*/
uint32_t arrCantidad(arreglo_t *arreglo);

/*Inserta una copia del elemento enviado por parametro en el arreglo*/
void arrInsertarUltimo(arreglo_t *arreglo, void *elemento);

/*Devuelve el elemento en la posicion indicada **como puntero** */
void *arrObtener(arreglo_t *arreglo, uint32_t indice);

/*Imprime el arreglo en el archivo especificado con el formato [elem1, elem2] */
void arrImprimir(arreglo_t *arreglo, FILE *archivo, funcionImprimir_t *impresor);

/*Libera toda la memoria ocupada por el arreglo y sus elementos*/
void arrEliminar(arreglo_t *arreglo);

/*Elimina y devuelve el ultimo elemento del arreglo*/
void *arrBorrarUltimo(arreglo_t *arreglo);

/* Funciones auxiliares */
/*Cambia el tamaño del arreglo por el enviado por parametro. Los elementos se mantienen*/
void _arrRedimensionar(arreglo_t *arreglo, uint32_t nuevoTam);

#endif