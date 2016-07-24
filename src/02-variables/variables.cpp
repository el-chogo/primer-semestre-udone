#include <iostream>
/* 
    "Importamos" cout, cin y endl para poder usarlos sin el
    operador de resolucion
*/
using std::cout;
using std::cin; 
using std::endl;

int main(int argc, char *argv[]) {
    char nombre[20];

    cout << "Cual es tu nombre?" << endl;

    /* El flujo de entrada `cin` junto al operador >> es usado para obtener
       datos de la entrada estandar
    */

    cin >> nombre;

    cout << "Hola " << nombre << "!" << endl;

    return 0;
}
