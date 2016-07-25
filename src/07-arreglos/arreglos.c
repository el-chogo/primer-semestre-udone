#include <stdio.h>

#define MAKE_CONTAINER_ELEMENT(TYPE)            \
    struct TYPE ## ElementoContenedor {         \
        TYPE element;                           \
        TYPE ## ElementoContenedor * next;      \
    }

#define MAKE_CONTAINER(TYPE)                    \
    MAKE_CONTAINER_ELEMENT(TYPE);               \
    struct TYPE ## Contenedor {                 \
        TYPE ## ElementoContenedor * first;     \
        int containerSize;                      \
    }

#define CONTAINER(TYPE)                         \
    struct TYPE ## Contenedor

#define ALLOC_CONTAINER(TYPE)                   \
    malloc(sizeof(CONTAINER(TYPE)))

#define MAP_FUNCTION_NAME(TYPE_A, TYPE_B)       \
    mapear_ ## TYPE_A ## _ ## TYPE_B

#define MAP_FUNCTION_SIG(TYPE_A, TYPE_B)        \
    (CONTAINER(TYPE_A), TYPE_B (*f)(TYPE_A))

#define MAP(TYPE_A, TYPE_B)                                             \
    CONTAINER(TYPE_B) * (MAP_FUNCTION_NAME(TYPE_A, TYPE_B) MAP_FUNCTION_SIG(TYPE_A, TYPE_B) { \
            TYPE_B * nuevoContenedor = ALLOC_CONTAINER(TYPE_B);         \
        }

MAP(int, char)
