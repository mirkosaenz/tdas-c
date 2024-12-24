#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "arreglo.h"

#define TEST_OK "OK"
#define TEST_FAIL "FAILED"

void printTestExito(char* mensaje){
    printf("%s -> %s\n", mensaje, TEST_OK);
}

//Testea que el arreglo se cree correctamente
void testCrearArreglo(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);

    assert(arreglo != NULL);
    printTestExito("El arreglo se crea correctamente");
}

void testCantidadArregloVacio(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);
    
    assert(arrCantidad(arreglo) == 0);
    printTestExito("La cantidad de un arreglo vacio es 0");
}

void testArregloEstaVacio(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);

    assert(arrEstaVacio(arreglo) == true);
    printTestExito("Un arreglo recien creado esta vacio");
}

void testInsertarUltimo(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);
    int numero = 4;
    arrInsertarUltimo(arreglo, &numero);

    assert(arrEstaVacio(arreglo) == false);
    assert(arrCantidad(arreglo) == 1);

    for(int i = 0; i < 99; i++){
        arrInsertarUltimo(arreglo, &numero);
    }

    assert(arrEstaVacio(arreglo) == false);
    assert(arrCantidad(arreglo) == 100);

    printTestExito("Los elementos se insertan al final correctamente");
}

void testArrPrint(){
    //Hacer
    return;
}

void testObtener(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);

    for(int i = 0; i < 101; i++){
        int numero = i;
        arrInsertarUltimo(arreglo, &numero);
    }

    assert(*(int*)arrObtener(arreglo, 100) == 100);
    printTestExito("Se obtiene correctamente el elemento en la posicion indicada");
}

void main(){
    testCrearArreglo();
    testCantidadArregloVacio();
    testArregloEstaVacio();
    testInsertarUltimo();
    testArrPrint();
    testObtener();
}