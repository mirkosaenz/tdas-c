#include "../test_utils/utils.h"
#include "arreglo.h"

//Testea que el arreglo se cree correctamente
void testCrearArreglo(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);

    assert(arreglo != NULL);
    arrEliminar(arreglo);
    printTestExito("El arreglo se crea correctamente");
}

void testCantidadArregloVacio(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);
    
    assert(arrCantidad(arreglo) == 0);
    arrEliminar(arreglo);
    printTestExito("La cantidad de un arreglo vacio es 0");
}

void testArregloEstaVacio(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);

    assert(arrEstaVacio(arreglo) == true);
    arrEliminar(arreglo);
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

    arrEliminar(arreglo);
    printTestExito("Los elementos se insertan al final correctamente");
}

void testArrPrint(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);
    int numero = 4;
    
    for(int i = 1; i <= 4; i++){
        arrInsertarUltimo(arreglo, &numero);
    }
    
    FILE* archivo = fopen("./salida.txt", "w");
    arrImprimir(arreglo, archivo);
    fclose(archivo);

    FILE* archivoLectura = fopen("./salida.txt", "r");
    char salida[100];
    fgets(salida, 100, archivoLectura);
    fclose(archivoLectura);
    remove("./salida.txt");

    assert(strcmp(salida, "[4,4,4,4]\n") == 0);
    arrEliminar(arreglo);
    printTestExito("El arreglo se imprime correctamente");
}

void testObtener(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);

    for(int i = 0; i < 101; i++){
        int numero = i;
        arrInsertarUltimo(arreglo, &numero);
    }

    assert(*(int*)arrObtener(arreglo, 100) == 100);
    arrEliminar(arreglo);
    printTestExito("Se obtiene correctamente el elemento en la posicion indicada");
}

void testArrEliminar(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);
    
    for(int i = 0; i < 101; i++){
        int numero = i;
        arrInsertarUltimo(arreglo, &numero);
    }

    arrEliminar(arreglo);
    printTestExito("La memoria del arreglo se libera correctamente");
}

void testArrBorrarUltimo(){
    arreglo_t *arreglo = crearArregloGenerico(TipoInt);

    for(int i = 0; i < 11; i++){
        int numero = i;
        arrInsertarUltimo(arreglo, &numero);
    }
    int *ultimo = arrBorrarUltimo(arreglo);
    assert(*ultimo == 10);
    printTestExito("El ultimo elemento del arreglo se borra y devuelve correctamente");
}

void main(){
    testCrearArreglo();
    testCantidadArregloVacio();
    testArregloEstaVacio();
    testInsertarUltimo();
    testArrPrint();
    testObtener();
    testArrEliminar();
    testArrBorrarUltimo();
}