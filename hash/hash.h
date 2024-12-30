#ifndef CONSTANTE_HASH
#define CONSTANTE_HASH

#include <stdint.h>
#include <stdbool.h>

#define TAM_INICIAL 4
#define FACTOR_CARGA_MAXIMO 0.7

typedef void* (funcionClonar_t)(void*);
typedef void (funcionEliminar_t)(void*);

/*Enumerador para tipos de datos*/
typedef enum e_tipo{
    TipoInt = 0,
    TipoString = 1
} tipo_t;

typedef enum e_estadoCelda{
    EstadoVacio = 0,
    EstadoOcupado = 1,
    EstadoBorrado = 2
} estadoCelda_t;

typedef struct s_celdaHash{
    void* clave;
    void* dato;
    estadoCelda_t estado;
} celdaHash_t;

typedef struct s_hashCerrado{
    celdaHash_t *tabla;
    uint32_t borrados;
    uint32_t cantidad;
    uint32_t tam; 
    tipo_t tipo_clave;
    funcionClonar_t *clonador;
    funcionEliminar_t *destructor;
} hashCerrado_t;

hashCerrado_t *crearHashCerrado(tipo_t tipo_clave, funcionClonar_t *clonador, funcionEliminar_t *destructor);
bool hashEstaVacio(hashCerrado_t *hash);
uint32_t hashCantidad(hashCerrado_t *hash);
void hashGuardar(hashCerrado_t *hash, void* clave, void* dato);
bool hashPertenece(hashCerrado_t *hash, void* clave);
void *hashObtener(hashCerrado_t *hash, void* clave);
void *hashBorrar(hashCerrado_t *hash, void* clave);

#endif