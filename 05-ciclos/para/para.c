#include <stdio.h>

int main(int argc, char *argv[]) {
    char numeroStr[3]; // 2 digitos + caracter terminal \0
    int contador, numero;

    printf("Introduzca un numero: ");
    fgets(numeroStr, sizeof(numeroStr), stdin);

    for (contador = 1; contador <= numero; contador++ ) {
        if (contador % 2 == 0) {
            printf("%i es un numero par!", contador);
        } else {
            printf("%i es un numero impar!", contador);
        }
    }

    return 0;
}
