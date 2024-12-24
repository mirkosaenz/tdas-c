#ifndef CONSTANTE_ARREGLO
#define CONSTANTE_ARREGLO

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

// Constantes
#define TAM_INICIAL 4

// Structs
/*Enumerador para tipos de datos*/
typedef enum e_tipo{
    TipoInt = 0,
    TipoString = 1
} tipo_t;

/*Estructura para la implementacion del arreglo generico redimensionable*/
typedef struct s_arreglo{
    uint32_t cantidad;
    uint32_t tam;
    void** datos;
    tipo_t tipo;
} arreglo_t;

/* Definicion como tipos de punteros a funciones */
typedef void* (funcClone_t)(void*);
typedef void (funcPrint_t)(FILE* archivo, void* elemento);

// Primitivas
/*Crea y devuelve un arreglo generico redimensionable*/
arreglo_t *crearArregloGenerico(tipo_t tipo);

/*Devuelve true si el arreglo esta vacio, o false en caso contrario*/
bool arrEstaVacio(arreglo_t *arreglo);

/*Devuelve la cantidad de elementos insertados en el arreglo*/
uint32_t arrCantidad(arreglo_t *arreglo);

/*Inserta una copia del elemento enviado por parametro en el arreglo*/
void arrInsertarUltimo(arreglo_t *arreglo, void *elemento);

/*Devuelve el elemento en la posicion indicada **como puntero** */
void *arrObtener(arreglo_t *arreglo, uint32_t indice);

/*Imprime el arreglo en el archivo especificado con el formato [elem1, elem2] */
void arrImprimir(arreglo_t *arreglo, FILE *archivo);

/* Funciones auxiliares */
/*Cambia el tamaño del arreglo por el enviado por parametro. Los elementos se mantienen*/
void _arrRedimensionar(arreglo_t *arreglo, uint32_t nuevoTam);

/*Devuelve un puntero a una funcion para clonar un dato del tipo enviado por parametro*/
funcClone_t *obtenerClonador(tipo_t tipo);

/*Devuelve un puntero a una funcion para imprimir un dato del tipo enviado por parametro*/
funcPrint_t *obtenerImpresor(tipo_t tipo);

/*Devuelve un clon de la cadena enviada por parametro*/
char *strClone(char *cadena);

/*Devuelve un clon del puntero a numero enviado por parametro*/
int *intClone(int *numero);

/*Imprime el numero enviado como puntero en el archivo especificado*/
void intPrint(FILE *archivo, int *numero);

/*Imprime la cadena enviada como puntero en el archivo especificado*/
void strPrint(FILE *archivo, char **cadena);

#endif