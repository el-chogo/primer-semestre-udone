#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[]) {
    char nombre[9]; // Napoleon 8 letras mas el caracter terminal

    printf("Introduzca un nombre: ");
    fgets(nombre, sizeof(nombre), stdin);

    if (strcmp(nombre, "Napoleon") == 0) {
        printf("Su apellido es Bonaparte!\n");
    } else {
        printf("No se ha podido determinar su apellido!\n");
    }
}
