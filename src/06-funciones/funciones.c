#include <stdio.h>
#include <string.h>

char * capitalizar(char nombre[]) {
    int contador;
    int capitalizarActual = 1;

    for(contador = 0; nombre[contador] != '\0'; contador++) {
        if (capitalizarActual == 1 && nombre[contador] != ' ') {
            nombre[contador] = nombre[contador] - 32;
            capitalizarActual = 0;
        }
        if (nombre[contador] == ' ') {
            capitalizarActual = 1;
        }
    }
    nombre[contador - 1] = '\0';
    return nombre;
}

void saludar(char nombre[]) {
    char * nombreCapitalizado = capitalizar(nombre);
    printf("Hola %s!\n", nombreCapitalizado);
}

int main(int argc, char *argv[]) {
    char nombre[30];
    
    printf("Introduzca su nombre completo: ");
    fgets(nombre, sizeof(nombre), stdin);

    saludar(nombre);

    return 0;
}
