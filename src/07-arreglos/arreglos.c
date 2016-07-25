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

#define CONTAINER(TYPE)                         \
    struct TYPE ## Contenedor

#define MAKE_CONTAINER(TYPE)                    \
    MAKE_CONTAINER_ELEMENT(TYPE)                \
    CONTAINER(TYPE) {                           \
        ELEMENT(TYPE)  * primero;               \
        int containerSize;                      \
    };

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

#define MAKE_CONTAINER_FREE(TYPE)                               \
    void free_ ## TYPE ## _container(CONTAINER(TYPE) ** xs) {   \
        ELEMENT(TYPE) ** cur = &((*xs)->primero);               \
        ELEMENT(TYPE) * tmp;                                    \
                                                                \
        printf("Hola\n");                                       \
        if (*cur == NULL) {                                     \
            return;                                             \
        }                                                       \
                                                                \
        while (*cur != NULL) {                                  \
            tmp = (*cur)->siguiente;                            \
            free(*cur);                                          \
            cur = &tmp;                                         \
        }                                                       \
        free(*xs); \
    }

#define FREE_CONTAINER(TYPE, XS)                \
    free_ ## TYPE ## _container(XS)

#define SETUP_CONTAINER(TYPE) \
    MAKE_CONTAINER(TYPE) \
    MAKE_CONTAINER_FREE(TYPE)

SETUP_CONTAINER(int)
SETUP_CONTAINER(char)
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

    FREE_CONTAINER(char, &listaLetras);
}
