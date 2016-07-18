#include "stdio.h"
#include "stdlib.h" //Libreria estandar del lenguaje STanDardLIB

int main(int argc, char *argv[]) {
    float a,b;

    char aInput[4], bInput[4]; // Valores de 3 digitos

    float suma, producto;
    float cocienteAB, cocienteBA;

    printf("Introduzca un valor para a: ");
    fgets(aInput, sizeof(a), stdin);

    printf("Introduzca un valor para b: ");
    fgets(bInput, sizeof(b), stdin);

    a = atof(aInput); //Convertir la cadena a real
    b = atof(bInput);

    suma = a + b;
    producto = a * b;
    cocienteAB = a / b;
    cocienteBA = b / a;

    printf("a + b = %f\n", suma);
    printf("a * b = %f\n", producto);
    printf("a / b = %f\n", cocienteAB);
    printf("b / a = %f\n", cocienteBA);

    return 0;
}
