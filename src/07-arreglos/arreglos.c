#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ELEMENT(SYN)                            \
    struct SYN ## ElementoContenedor

#define MAKE_CONTAINER_ELEMENT(TYPE, SYN)       \
    ELEMENT(SYN) {                              \
        TYPE elemento;                          \
        ELEMENT(SYN) * siguiente;              \
    };

#define CONTAINER(SYN)                          \
    struct SYN ## Contenedor

#define MAKE_CONTAINER(TYPE, SYN)               \
    MAKE_CONTAINER_ELEMENT(TYPE, SYN)           \
    CONTAINER(SYN) {                            \
        ELEMENT(SYN)  * primero;                \
        int containerSize;                      \
    };

#define ALLOC_CONTAINER(TYPE)                   \
    malloc(sizeof(CONTAINER(TYPE) *))

#define ALLOC_ELEMENT(TYPE)                     \
    malloc(sizeof(ELEMENT(TYPE) *))

#define MAP_FUNCTION_NAME(SYN_A, SYN_B)         \
    mapear_ ## SYN_A ## _ ## SYN_B

#define MAP_FUNCTION_SIG(TYPE_A, TYPE_B, SYN_A) \
    (CONTAINER(SYN_A) xs, TYPE_B (*f)(TYPE_A))

#define MAP(TYPE_A, TYPE_B, SYN_A, SYN_B)                               \
    CONTAINER(SYN_B) * MAP_FUNCTION_NAME(SYN_A, SYN_B) MAP_FUNCTION_SIG(TYPE_A, TYPE_B, SYN_A) { \
        CONTAINER(SYN_B) * ys = ALLOC_CONTAINER(SYN_B);                 \
        ys->primero = NULL;                                             \
        ELEMENT(SYN_A) * curX = xs.primero;                             \
        ELEMENT(SYN_B) ** curY;                                         \
                                                                        \
        if (curX == NULL) {                                             \
            return NULL;                                                \
        }                                                               \
                                                                        \
        curY = &(ys->primero);                                          \
                                                                        \
        while (curX != NULL) {                                          \
            *curY = ALLOC_ELEMENT(SYN_B);                               \
            (*curY)->elemento = f(curX->elemento);                      \
            (*curY)->siguiente = NULL;                                  \
            curX = curX->siguiente;                                     \
        }                                                               \
        return ys;                                                      \
    }

#define MAKE_CONTAINER_FREE(SYN)                                \
    void free_ ## SYN ## _container(CONTAINER(SYN) ** xs) {     \
        ELEMENT(SYN) ** cur = &((*xs)->primero);                \
        ELEMENT(SYN) * tmp;                                     \
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

#define FREE_CONTAINER(SYN, XS)                 \
    free_ ## SYN ## _container(XS)

#define MAKE_ARRAY_TO_CONTAINER(TYPE, SYN)                              \
    CONTAINER(SYN) * array_to_ ## SYN ## _container(TYPE xs[], int tamano) { \
        int contador;                                                   \
        CONTAINER(SYN) * ys = ALLOC_CONTAINER(SYN);                     \
        ELEMENT(SYN) ** cur = &(ys->primero);                           \
                                                                        \
        for (contador = 0; contador < tamano; contador++) {             \
            *cur = ALLOC_ELEMENT(SYN);                                  \
            (*cur)->elemento = xs[contador];                            \
            (*cur)->siguiente = NULL;                                   \
            cur = &((*cur)->siguiente);                                 \
        }                                                               \
                                                                        \
        return ys;                                                      \
    }

#define SETUP_CONTAINER(TYPE, SYN)              \
    MAKE_CONTAINER(TYPE, SYN)                   \
    MAKE_CONTAINER_FREE(SYN)                    \
    MAKE_ARRAY_TO_CONTAINER(TYPE, SYN)

#define MAKE_TRACE(TYPE, PRINTF)                \
    TYPE trace_ ## TYPE (TYPE x) {              \
        PRINTF;                                 \
        return x;                               \
    }

#define TRACE(TYPE, x)                          \
    trace_ ## TYPE(x)

#define ARRAY_TO_CONTAINER(SYN, xs, n)          \
    array_to_ ## SYN ## _container(xs, n)

#define REGISTER_ALL_TYPES                      \
    SETUP_CONTAINER(int, int)                   \
    SETUP_CONTAINER(char, char)                 \
    SETUP_CONTAINER(double, double)             \
    SETUP_CONTAINER(float, float)

typedef struct TelefonoS {
    int id;
    char *nombre;
} Telefono;


REGISTER_ALL_TYPES
SETUP_CONTAINER(Telefono, Telefono)
MAP(int,char,int,char)
MAP(char,int,char,int)
MAP(char,char,char,char)
MAP(Telefono, Telefono, Telefono, Telefono)
MAKE_TRACE(char, printf("%c\n", x))
MAKE_TRACE(Telefono, printf("ID: %i\nCedula: %s\n", x.id, x.nombre))

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

    Telefono agenda[] = {
        {0, "Carlos Gottberg"},
        {1, "Lelouch Lamperouge"}
    };

    CONTAINER(Telefono) *listaTelefonos;
    listaTelefonos = ARRAY_TO_CONTAINER(Telefono, agenda, 2);
    mapear_Telefono_Telefono(*listaTelefonos, &trace_Telefono);

    return 0;
}
