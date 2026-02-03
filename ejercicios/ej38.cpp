#include <iostream>
using namespace std;
const int TAM = 10;
void llenarArreglo(double ventas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese venta " << i + 1 << ": ";
        cin >> ventas[i];
    }
}
double calcularTotal(double ventas[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += ventas[i];
    }
    return total;
}
double calcularPromedio(double total, int n) {
    return total / n;
}

int contarMayores(double ventas[], int n, double promedio) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (ventas[i] > promedio) {
            contador++;
        }
    }
    return contador;
}
int main() {
    double ventas[TAM];
    llenarArreglo(ventas, TAM);

    double total = calcularTotal(ventas, TAM);
    double promedio = calcularPromedio(total, TAM);
    int mayores = contarMayores(ventas, TAM, promedio);

    cout << "\nResultados:\n";
    cout << "Total de ventas: " << total << endl;
    cout << "Promedio de ventas: " << promedio << endl;
    cout << "Ventas mayores al promedio: " << mayores << endl;

    return 0;
}
