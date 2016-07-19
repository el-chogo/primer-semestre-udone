#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    int numero, contador;

    cout << "Introduzca un numero: ";
    cin >> numero;

    for(contador = 0; contador < numero; contador++) {
        if (contador % 2 == 0) {
            cout << contador << " es par!" << endl;
        } else {
            cout << contador << " es impar!" << endl;
        }
    }

    return 0;
}
