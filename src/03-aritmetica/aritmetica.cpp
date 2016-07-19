#include <iostream>
using std::cout;
using std::cin; 
using std::endl;

int main(int argc, char *argv[]) {
    float a, b;
    float suma, producto, cocienteBA, cocienteAB;

    cout << "Ingrese un valor para a: ";
    cin >> a;

    cout << "Ingrese un valor para b: ";
    cin >> b;

    suma = a + b;
    producto = a * b;
    cocienteAB = a / b;
    cocienteBA = b / a;

    cout << "a + b = " << suma << endl;
    cout << "a * b = " << producto << endl;
    cout << "a / b = " << cocienteAB << endl;
    cout << "b / a = " << cocienteBA << endl;

    return 0;
}
