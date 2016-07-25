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
        if (*cur == NULL) {                                     \
            return;                                             \
        }                                                       \
                                                                \
        while (*cur != NULL) {                                  \
            tmp = (*cur)->siguiente;                            \
            free(*cur);                                         \
            cur = &tmp;                                         \
        }                                                       \
        free(*xs);                                              \
    }

#define FREE_CONTAINER(TYPE, XS)                \
    free_ ## TYPE ## _container(XS)

#define MAKE_ARRAY_TO_CONTAINER(TYPE)                                   \
    CONTAINER(TYPE) * array_to_ ## TYPE ## _container(TYPE xs[], int tamano) { \
        int contador;                                                   \
        CONTAINER(TYPE) * ys = ALLOC_CONTAINER(TYPE);                   \
        ELEMENT(TYPE) ** cur = &(ys->primero);                          \
                                                                        \
        for (contador = 0; contador < tamano; contador++) {             \
            *cur = ALLOC_ELEMENT(TYPE);                                 \
            (*cur)->elemento = xs[contador];                            \
            (*cur)->siguiente = NULL;                                   \
            cur = &((*cur)->siguiente);                                 \
        }                                                               \
                                                                        \
        return ys;                                                      \
    }

#define SETUP_CONTAINER(TYPE)                   \
    MAKE_CONTAINER(TYPE)                        \
    MAKE_CONTAINER_FREE(TYPE)                   \
    MAKE_ARRAY_TO_CONTAINER(TYPE)

#define MAKE_TRACE(TYPE, PRINTF_MOD)            \
    TYPE trace_ ## TYPE (TYPE x) {              \
        printf(PRINTF_MOD, x);                  \
        return x;                               \
    }

#define TRACE(TYPE, x)                          \
    trace_ ## TYPE(x)

#define ARRAY_TO_CONTAINER(TYPE, xs, n)         \
    array_to_ ## TYPE ## _container(xs, n)

SETUP_CONTAINER(int)
SETUP_CONTAINER(char)
MAP(int,char)
MAP(char, char)
MAKE_TRACE(char, "%c\n");

char desdeA(int n) {
    return 97 + n;
}

int main(int argc, char *argv[]) {
    CONTAINER(int) listaNumeros;
    listaNumeros.primero = ALLOC_ELEMENT(char);
    listaNumeros.primero->elemento = 2;
    listaNumeros.primero->siguiente = NULL;

    CONTAINER(char) * listaLetras;
    CONTAINER(char) * otraListaLetras;

    listaLetras = mapear_int_char(listaNumeros, &desdeA);

    printf("%i\n", listaLetras->primero->elemento);

    FREE_CONTAINER(char, &listaLetras);

    char arregloLetras[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    otraListaLetras = ARRAY_TO_CONTAINER(char, arregloLetras, 6);
    mapear_char_char(*otraListaLetras, &trace_char);

    FREE_CONTAINER(char, &otraListaLetras);
}
