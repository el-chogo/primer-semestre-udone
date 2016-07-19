#include <iostream>
#include <cstring>
using std::cout;
using std::getline;
using std::endl;
using std::cin;
using std::string;

bool esMinuscula(const char caracter) {
    if (caracter >= 'a' && caracter <= 'z') {
        return true;
    }
    return false;
}

bool esMayuscula(const char caracter) {
    if (caracter >= 'A' && caracter <= 'Z') {
        return true;
    }
    return false;
}

char mayuscula(const char caracter) {
    if (esMinuscula(caracter)) {
        return caracter - 32;
    }
    return caracter;
}

bool esLetra(const char caracter) {
    if (esMinuscula(caracter) || esMayuscula(caracter)) {
        return true;
    }
    return false;
}

bool esDelimitador(const char caracter) {
    if (caracter == '.' || caracter == ' ') {
        return true;
    }
    return false;
}

string capitalizar(const string cadenaOriginal) {
    string cadenaModificada = cadenaOriginal;
    char caracterAnterior = ' ';

    for (char& caracterActual : cadenaModificada) {
        if (esDelimitador(caracterAnterior) && esLetra(caracterActual)) {
            caracterActual = mayuscula(caracterActual);
        }
        caracterAnterior = caracterActual;
    }

    return cadenaModificada;
}

void saludar(const string cadena) {
    cout << "Hola " << capitalizar(cadena) << "!" << endl;
}

int main(int argc, char *argv[]) {
    string cadena;

    cout << "Introduzca una cadena: ";
    getline(cin, cadena);

    saludar(cadena);
}
