#include "stdio.h"

int main(int argc, char *argv[]) {
    // En C no hay un tipo de datos cadena, una émula de éste tipo es
    // una secuencia o arreglo de caracteres.
    char nombre[20]; //Establecemos un limite de 19 caracteres para el nombre

    printf("Cual es tu nombre?\n");

    /* Mediante fgets obtenemos datos de un medio de entrada, en éste caso
       de stdin (STanDard INput o Entrada estandar)

       Es importante notar como el resultado de esta operación no se asigna,
       en cambio, la operación misma se encarga de modificar nuestra variable
    */
    fgets(nombre, sizeof(nombre), stdin);

    printf("Hola %s!\n", nombre);

    return 0;
}
