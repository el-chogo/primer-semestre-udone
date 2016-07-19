#include <stdio.h>
#include <stdbool.h> // Para usar bool, true y false

int main(int argc, char *argv[]) {
    printf("Verdadero y Falso: %s\n", (true && false) ? "Verdadero" : "Falso");
    printf("Falso y Verdadero: %s\n", (false && true) ? "Verdadero" : "Falso");
    printf("Falso y Falso: %s\n", (false && false) ? "Verdadero" : "Falso" );
    if (true && true) {
        printf("Verdadero y Verdadero: Verdadero\n");
    }

    printf("Verdadero o Falso: %s\n", (true || false) ? "Verdadero" : "Falso");
    printf("Falso o Verdadero: %s\n", (false || true) ? "Verdadero" : "Falso");
    printf("Verdadero o Verdadero: %s\n", (true || true) ? "Verdadero" : "Falso");
    printf("Falso o Falso%s\n", (false || false) ? "Verdadero" : "Falso");

    return 0;
}
