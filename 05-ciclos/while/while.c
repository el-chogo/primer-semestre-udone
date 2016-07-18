#include "stdio.h"

int main(int argc, char *argv[]) {
    char numeroStr[4];
    char potenciaStr[4];

    int numero, potencia, resultado;

    resultado = 1;

    printf("Introduzca un numero: ");
    fgets(numeroStr, sizeof(numeroStr), stdin):

    printf("Introduzca una potencia: ");
    fgets(potenciaStr, sizeof(potenciaStr), stdin);

    while (potencia > 0) {
        resultado = numero * resultado;
        potencia = potencia - 1;
    }

    printf("%i\n", resultado);

    return 0;
}
