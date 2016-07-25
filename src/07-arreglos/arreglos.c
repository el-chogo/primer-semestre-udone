#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ELEMENT(TYPE)                           \
    struct TYPE ## ElementoContenedor

#define MAKE_CONTAINER_ELEMENT(TYPE)            \
    ELEMENT(TYPE) {                             \
        TYPE elemento;                          \
        ELEMENT(TYPE) * siguiente;              \
    };

#define MAKE_CONTAINER(TYPE)                    \
    MAKE_CONTAINER_ELEMENT(TYPE)                \
    struct TYPE ## Contenedor {                 \
        ELEMENT(TYPE)  * primero;               \
        int containerSize;                      \
    };

#define CONTAINER(TYPE)                         \
    struct TYPE ## Contenedor

#define ALLOC_CONTAINER(TYPE)                   \
    malloc(sizeof(CONTAINER(TYPE) *))

#define ALLOC_ELEMENT(TYPE)                     \
    malloc(sizeof(ELEMENT(TYPE) *))

#define MAP_FUNCTION_NAME(TYPE_A, TYPE_B)       \
    mapear_ ## TYPE_A ## _ ## TYPE_B

#define MAP_FUNCTION_SIG(TYPE_A, TYPE_B)        \
    (CONTAINER(TYPE_A) xs, TYPE_B (*f)(TYPE_A))

#define MAP(TYPE_A, TYPE_B)                                             \
    CONTAINER(TYPE_B) * MAP_FUNCTION_NAME(TYPE_A, TYPE_B) MAP_FUNCTION_SIG(TYPE_A, TYPE_B) { \
        CONTAINER(TYPE_B) * ys = ALLOC_CONTAINER(TYPE_B);               \
        ys->primero = NULL;                                             \
        ELEMENT(TYPE_A) * curX = xs.primero;                            \
        ELEMENT(TYPE_B) ** curY;                                        \
                                                                        \
        if (curX == NULL) {                                             \
            return NULL;                                                \
        }                                                               \
                                                                        \
        curY = &(ys->primero);                                          \
                                                                        \
        while (curX != NULL) {                                          \
            *curY = ALLOC_ELEMENT(TYPE_B);                              \
            (*curY)->elemento = f(curX->elemento);                      \
            (*curY)->siguiente = NULL;                                  \
            curX = curX->siguiente;                                     \
        }                                                               \
        return ys;                                                      \
    }


MAKE_CONTAINER(int)
MAKE_CONTAINER(char)
MAP(int,char)

char desdeA(int n) {
    return 97 + n;
}

int main(int argc, char *argv[]) {
    CONTAINER(int) listaNumeros;
    listaNumeros.primero = ALLOC_ELEMENT(char);
    listaNumeros.primero->elemento = 2;
    listaNumeros.primero->siguiente = NULL;

    CONTAINER(char) * listaLetras;
    listaLetras = mapear_int_char(listaNumeros, &desdeA);

    printf("%i\n", listaLetras->primero->elemento);

    free(listaLetras->primero);
    free(listaLetras);
}
