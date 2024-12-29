#include "../test_utils/utils.h"
#include "cola.h"

void destruir_int(int *numero){
    free(numero);
}

void* clonar_int(int* numero){
    int *nuevoInt = malloc(sizeof(int));
    *nuevoInt = *numero;
    return nuevoInt;
}

void testColaVacia(){
    cola_t *cola = crearColaEnlazada(
        (funcDestruir_t*)&(destruir_int), 
        (funcClonar_t*)&(clonar_int)
    ); //Casteo &(destruir_int) al tipo puntero a funcDestruir_t. Idem clonar
    
    assert(colaEstaVacia(cola) == true);
    printTestExito("Una cola recien creada esta vacia");

    for(int i = 0; i < CANTIDAD_ITERACIONES; i++){
        colaEncolar(cola, &i);
    }
    for(int i = 0; i < CANTIDAD_ITERACIONES; i++){
        colaDesencolar(cola);
    }

    assert(colaEstaVacia(cola) == true);
    colaEliminar(cola);
    printTestExito("Una cola a la que se le desencolo hasta vaciarla se comporta como vacia");
}

void testEncolar(){
    cola_t *cola = crearColaEnlazada(
        (funcDestruir_t*)&(destruir_int), 
        (funcClonar_t*)&(clonar_int)
    );

    for(int i = 0; i < CANTIDAD_ITERACIONES; i++){
        colaEncolar(cola, &i);
    }

    int* primero = colaVerPrimero(cola);
    assert(*primero == 0);
    printTestExito("Los elementos se encolan correctamente");
}

void testDesencolar(){
    cola_t *cola = crearColaEnlazada(
        (funcDestruir_t*)&(destruir_int), 
        (funcClonar_t*)&(clonar_int)
    );

    for(int i = 0; i < CANTIDAD_ITERACIONES; i++){
        colaEncolar(cola, &i);
    }

    for(int i = 0; i < CANTIDAD_ITERACIONES; i++){
        int *desencolado = colaDesencolar(cola);
        assert(*desencolado == i);
    }

    assert(colaEstaVacia(cola) == true);
    printTestExito("Los elementos se desencolan correctamente");
}

void testVerPrimero(){
    cola_t *cola = crearColaEnlazada(
        (funcDestruir_t*)&(destruir_int), 
        (funcClonar_t*)&(clonar_int)
    );

    for(int i = 0; i < CANTIDAD_ITERACIONES; i++){
        colaEncolar(cola, &i);
    }

    for(int i = 0; i < CANTIDAD_ITERACIONES; i++){
        int *primero = colaVerPrimero(cola);
        int *desencolado = colaDesencolar(cola);
        assert(*primero == *desencolado);
    }

    printTestExito("El primer elemento de la cola se muestra correctamente");
}

void testVolumen(){
    cola_t *cola = crearColaEnlazada(
        (funcDestruir_t*)&(destruir_int), 
        (funcClonar_t*)&(clonar_int)
    );

    for(int i = 0; i < CANTIDAD_VOLUMEN; i++){
        colaEncolar(cola, &i);
    }
    for(int i = 0; i < CANTIDAD_VOLUMEN; i++){
        int *desencolado = colaDesencolar(cola);
        assert(*desencolado == i);
    }

    assert(colaEstaVacia(cola) == true);
    colaEliminar(cola);
    printTestExito("Los elementos se encolan y desencolan en el orden correcto (FIFO)");
}

void main(){
    testColaVacia();
    testEncolar();
    testDesencolar();
    testVerPrimero();
    testVolumen();
}