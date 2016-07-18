#include <stdio.h>

int main(int argc, char *argv[]) {
    int numero;
    char numeroStr[2];

    printf("Introduzca un numero: ");
    fgets(numeroStr, sizeof(numeroStr), stdin);

    switch (numero) {
        case 0:
            printf("Numero neutro con respecto a la suma\n");
            break;
        case 1:
            printf("Numero neutro con respecto a la multiplicacion\n");
            break;
        case 2:
            printf("Base del sistema binario\n");
            break;
        case 3:
            printf("Lados del triangulo\n");
            break;
        case 4:
            printf("Casas de Hogwarts\n");
            break;
        case 5:
            printf("Puntas de una estrella\n");
            break;
        case 6:
            printf("Primer numero perfecto\n");
            break;
        case 7:
            printf("Numero magico\n");
            break;
        default:
            printf("Solo se imprimen resultados para numeros del 0 al 7\n");
    }
}
