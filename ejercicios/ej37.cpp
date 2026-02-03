#include <iostream>
#include <vector>
using namespace std;
void llenarVector(vector<int> &v) {
    int n;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese numero " << i + 1 << ": ";
        cin >> n;
        v.push_back(n);
    }
}
int calcularSuma(const vector<int> &v) {
    int suma = 0;
    for (int x : v) {
        suma += x;
    }
    return suma;
}
int obtenerMayor(const vector<int> &v) {
    int mayor = v[0];
    for (int x : v) {
        if (x > mayor) {
            mayor = x;
        }
    }
    return mayor;
}
int obtenerMenor(const vector<int> &v) {
    int menor = v[0];
    for (int x : v) {
        if (x < menor) {
            menor = x;
        }
    }
    return menor;
}
int main() {
    vector<int> numeros;

    llenarVector(numeros);
    int suma = calcularSuma(numeros);
    double promedio = (double)suma / numeros.size();
    int mayor = obtenerMayor(numeros);
    int menor = obtenerMenor(numeros);

    cout << "\nResultados:\n";
    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;

    return 0;
}
