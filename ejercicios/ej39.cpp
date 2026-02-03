#include <iostream>
#include <vector>
using namespace std;
int calcularSuma(vector<int> v) {
    int suma = 0;
    for (int x : v) {
        suma += x;
    }
    return suma;
}

double calcularPromedio(vector<int> v) {
    int suma = calcularSuma(v);
    return (double)suma / v.size();
}
void contarParImpar(vector<int> v, int &pares, int &impares) {
    pares = 0;
    impares = 0;

    for (int x : v) {
        if (x % 2 == 0)
            pares++;
        else
            impares++;
    }
}
int main() {
    vector<int> numeros;
    int n;

    for (int i = 0; i < 10; i++) {
        cout << "Ingrese numero " << i + 1 << ": ";
        cin >> n;
        numeros.push_back(n);
    }

    int suma = calcularSuma(numeros);
    double promedio = calcularPromedio(numeros);

    int pares, impares;
    contarParImpar(numeros, pares, impares);

    cout << "\nResultados:\n";
    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Pares: " << pares << endl;
    cout << "Impares: " << impares << endl;

    return 0;
}
