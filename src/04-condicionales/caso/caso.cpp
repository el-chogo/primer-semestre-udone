#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
    int numero;

    cout << "Introduzca un numero: ";
    cin >> numero;

    switch (numero) {
    case 0:
        cout << "Numero neutro con respecto a la suma" << endl;
        break;
    case 1:
        cout << "Numero neutro con respecto a la multiplicacion" << endl;
        break;
    case 2:
        cout << "Base del sistema binario" << endl;
        break;
    case 3:
        cout << "Lados del triangulo" << endl;
        break;
    case 4:
        cout << "Casas de Hogwarts" << endl;
        break;
    case 5:
        cout << "Puntas de una estrella" << endl;
        break;
    case 6:
        cout << "Primer numero perfecto" << endl;
        break;
    case 7:
        cout << "Numero magico" << endl;
        break;
    default:
        cout << "Solo se imprimen resultados para numeros del 0 al 7" << endl;
    }

    return 0;
}
