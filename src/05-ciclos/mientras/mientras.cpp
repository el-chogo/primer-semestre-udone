#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char *argv[]) {
    int numero;
    int potencia;
    int contador = 0;
    int resultado = 1;

    cout << "Introduzca un numero: ";
    cin >> numero;

    cout << "Introduzca un exponente: ";
    cin >> potencia;

    while (contador < potencia) {
        resultado = resultado * numero;
        contador++;
    }

    cout << numero << "^" << potencia << " = " << resultado << endl;

    return 0;
}
