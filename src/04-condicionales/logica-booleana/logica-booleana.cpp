#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    cout << "Verdadero y Falso: " << (true && false) << endl;
    cout << "Falso y Verdadero: " << (false && true) << endl;
    cout << "Verdadero y Verdadero: " << (true && true) << endl;
    cout << "Falso y Falso: " << (false && false) << endl;

    cout << endl << endl;

    cout << "Verdadero o Falso: " << (true || false) << endl;
    cout << "Falso o Verdadero: " << (false || true) << endl;
    cout << "Verdadero o Verdadero: " << (true || true) << endl;
    cout << "Falso o Falso: " << (false || false) << endl;

    return 0;
}
