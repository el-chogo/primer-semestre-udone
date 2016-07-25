#include <iostream>
#include <vector>
#include <functional>
#include <cstring>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::function;

template<typename De, typename A>
vector<A> mapear(function<A(De)> f, vector<De> xs) {
    vector<A> ys;
    for (auto x : xs) {
        ys.push_back(f(x));
    }
    return ys;
}

template<typename De, typename A>
function<A(De)> siempre(const A x) {
    return [x](De y) { return x; };
}

template<typename T>
T reducir(function<T(T,T)> f, vector<T> xs, T inicial) {
    T resultado = inicial;
    for (auto x: xs) {
        resultado = f(resultado, x);
    }

    return resultado;
}

template<typename T>
vector<T> voltear(vector<T> xs) {
    vector<T> ys;
    for (auto x : xs) {
        ys.insert(ys.begin(), x);
    }
    return ys;
}

template<typename T>
vector<T> tomar(int n, vector<T> xs) {
    vector<T> ys;
    int contador = 0;

    for(auto x : xs) {
        if (contador < n) {
            ys.push_back(x);
            contador++;
        } else {
            break;
        }
    }

    return ys;
}

template <typename T>
vector<T> imprimirVector(vector<T> xs) {
    cout << "[";
    for(auto x: xs) {
        cout << " " << x;
    }
    cout << " ]" << endl;
    return xs;
}

char minuscula(char a) {
    return (a >= 65 && a <= 90) ? a - 32 : a;
}

vector<char> cadenaAVector(string cadena) {
    vector<char> res;
    for(auto x: cadena) {
        res.push_back(x);
    }
    return res;
}

string vectorACadena(vector<char> cadena) {
    string res;
    for (auto x: cadena) {
        res += x;
    }
    return res;
}

bool esPalindromo(string cadena) {
    string cadenaMinuscula;

    function<char(char)> minusculas = minuscula;

    cadenaMinuscula = vectorACadena(mapear(minusculas, cadenaAVector(cadena)));

    return cadenaMinuscula == vectorACadena(voltear(cadenaAVector(cadenaMinuscula)));
}

int sumar(int a, int b) {
    return a + b;
}


int main(int argc, char *argv[]) {
    function<bool(int)> siempreVerdad = siempre<int, bool>(false);

    vector<int> numeros = {1,2,3,4,5};
    vector<bool> resultado;
    int resultadoReducir;
    function<int(int,int)> fSumar = sumar;
    vector<int> volteados;
    vector<int> resultadoTomar;
    vector<int> resultadoTomarNada;
    string palabra;
    bool palindromo;

    resultado = mapear<int,bool>(siempreVerdad, numeros);

    cout << "Resultado de mapear [1,2,3,4,5] con f :: Int -> Bool" << endl;
    imprimirVector<bool>(resultado);

    resultadoReducir = reducir<int>(fSumar, numeros, 0);

    cout << "Resultado de reducir [1,2,3,4,5] con f :: Int -> Int -> Int" << endl;
    cout << resultadoReducir << endl;

    cout << "Resultado de voltear [1,2,3,4,5]" << endl;
    volteados = voltear<int>(numeros);
    imprimirVector<int>(volteados);

    cout << "Resultado de tomar 2 [1,2,3,4,5]" << endl;
    resultadoTomar = tomar<int>(2, numeros);
    imprimirVector<int>(resultadoTomar);

    cout << "Resultado de tomar 0 [1,2,3,4,5]" << endl;
    resultadoTomarNada = tomar<int>(0, numeros);
    imprimirVector<int>(resultadoTomarNada);

    cout << "Introduzca una palabra: ";
    cin >> palabra;
    cout << "Vectorizada: " << endl;
    imprimirVector<char>(cadenaAVector(palabra));

    palindromo = esPalindromo(palabra);

    if (palindromo) {
        cout << "La palabra introducida es un palindromo" << endl;
    } else {
        cout << "La palabra introducida no es un palindromo" << endl;
    }

    return 0;
}
