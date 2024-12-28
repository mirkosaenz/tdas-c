#include "../test_utils/utils.h"
#include "pila.h"

void testPilaVacia(){
    pilaDinamica_t *pila = crearPilaDinamica(TipoInt);
    
    assert(pilaEstaVacia(pila) == true);
    pilaEliminar(pila);
    printTestExito("Una pila recien creada se comporta como vacia");
}

void testPilaCantidad(){
    pilaDinamica_t *pila = crearPilaDinamica(TipoInt);

    for(int i = 0; i < 10; i++){
        pilaApilar(pila, &i);
    }

    assert(pilaCantidad(pila) == 10);
    pilaEliminar(pila);
    printTestExito("La cantidad de la pila se imprime correctamente");
}

void testPilaApilar(){
    pilaDinamica_t *pila = crearPilaDinamica(TipoInt);

    for(int i = 0; i < 11; i++){
        pilaApilar(pila, &i);
    }

    int* tope = pilaVerTope(pila);
    assert(*tope == 10);
    
    pilaEliminar(pila);
    printTestExito("Los elementos se apilan correctamente");
}

void testPilaDesapilar(){
    pilaDinamica_t *pila = crearPilaDinamica(TipoInt);

    for(int i = 0; i < 11; i++){
        pilaApilar(pila, &i);
    }

    int *desapilado = pilaDesapilar(pila);
    int *tope = pilaVerTope(pila);
    assert(*desapilado == 10);
    assert(*tope == 9);

    pilaEliminar(pila);
    printTestExito("Los elementos se desapilan correctamente");
}

void testPilaApilarDesapilar(){
    pilaDinamica_t *pila = crearPilaDinamica(TipoInt);

    for(int i = 1; i <= CANTIDAD_VOLUMEN; i++){
        pilaApilar(pila, &i);
        int *desapilado = pilaDesapilar(pila);

        assert(*desapilado == i);
    }
    assert(pilaEstaVacia(pila) == true);
    printTestExito("Apilar y desapilar continuamente no rompe el funcionamiento");

    for(int i = 1; i <= CANTIDAD_VOLUMEN; i++){
        pilaApilar(pila, &i);
    }
    for(int i = CANTIDAD_VOLUMEN; i >= 1; i--){
        int *desapilado = pilaDesapilar(pila);
        assert(*desapilado == i);
    }
    assert(pilaEstaVacia(pila) == true);
    pilaEliminar(pila);
    printTestExito("Los elementos se apilan y desapilan en el orden correcto (LIFO)");
}

void main(){
    testPilaVacia();
    testPilaCantidad();
    testPilaApilar();
    testPilaDesapilar();
    testPilaApilarDesapilar();
}