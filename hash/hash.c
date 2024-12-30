#include "hash.h"

hashCerrado_t *crearHashCerrado(tipo_t tipo_clave, funcionClonar_t *clonador, funcionEliminar_t *destructor){
    hashCerrado_t *hash = malloc(sizeof(hashCerrado_t));
    celdaHash_t *tabla = calloc((sizeof(celdaHash_t))*TAM_INICIAL);
    
    hash->cantidad = 0;
    hash->borrados = 0;
    hash->tabla = tabla;
    hash->tam = TAM_INICIAL;
    hash->tipo_clave = tipo_clave;
    hash->clonador = clonador;
    hash->destructor = destructor;

    return hash;
}

bool hashEstaVacio(hashCerrado_t *hash){
    return hash->cantidad == 0;
}

uint32_t hashCantidad(hashCerrado_t *hash){
    return hash->cantidad;
}

void hashGuardar(hashCerrado_t *hash, void *clave, void *dato){
    celdaHash_t celda;
    
    celda.clave = clave;
    celda.dato = dato;
    celda.estado = EstadoOcupado;    

    int indice = obtener_indice(hash, clave);
    hash->tabla[indice] = celda;
    (hash->cantidad)++;

    if(factor_carga(hash, true) >= FACTOR_CARGA_MAXIMO){
        _hashRedimensionar(hash, 2*hash->cantidad);
    }
}

bool hashPertenece(hashCerrado_t *hash, void* clave){
    int indice = _obtener_indice(hash, clave);
    return hash->tabla[indice].estado == EstadoOcupado;
}

float _factor_carga(hashCerrado_t *hash, bool contarBorrados){
    uint32_t coeficiente_n = hash->cantidad;
    if(contarBorrados){
        coeficiente_n += hash->borrados;
    }
    return coeficiente_n / hash->tam;
}

int _obtener_indice(hashCerrado_t *hash, void* clave){
    uint32_t indice = (uint32_t)_hashear((char*)clave) % hash->tam;

    while(!(hash->tabla)[indice].estado == EstadoVacio){
        if(hash->tabla[indice].clave == clave){
            return indice;
        }
        if(indice == hash->tam){
            indice = -1;
        }
        indice++;
    }

    return indice;
}

void _hashRedimensionar(hashCerrado_t *hash, int nuevoTamanio){
    celdaHash_t *nuevaTabla = calloc(sizeof(celdaHash_t)*nuevoTamanio);

    for(int i = 0; i < hash->tam; i++){
        celdaHash_t celda = hash->tabla[i];
        if(celda.estado == EstadoOcupado){
            int nuevoIndice = _hashear((char*)celda.clave) % nuevoTamanio;
            nuevaTabla[nuevoIndice] = celda;
        }
    }

    hash->tabla = nuevaTabla;
    hash->tam = nuevoTamanio;
    hash->borrados = 0;
}

int _hashear(char *str){
    int hash = 0;
    int c;

    while (c = *str++){
        hash = c + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}