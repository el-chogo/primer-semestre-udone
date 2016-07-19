#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
    char nombre[9];

    cout << "Introduzca su nombre: ";
    cin >> nombre;

    // http://en.cppreference.com/w/cpp/string/basic_string
    if (nombre == "Napoleon") {
        cout << "Su apellido es Bonaparte!" << endl;
    } else {
        cout << "No se ha podido determinar su apellido" << endl;
    }

    return 0;
}
