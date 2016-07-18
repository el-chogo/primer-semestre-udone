#include "stdio.h"

int main(int argc, char *argv[]) {
    char nombre[20]; //Establecemos un limite de 19 caracteres para el nombre

    printf("Cual es tu nombre?\n");
    
    fgets(nombre, sizeof(nombre), stdin);

    printf("Hola %s!\n", nombre);

    return 0;
}
