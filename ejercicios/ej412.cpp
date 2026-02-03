#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void ingresarVentas(vector<double> &ventas) {
    double v;
    for (int i = 0; i < 5; i++) {
        cout << "Ingrese venta " << i + 1 << ": ";
        cin >> v;
        ventas.push_back(v);
    }
}
void guardarVentas(const vector<double> &ventas) {
    ofstream archivo("ventas.txt");
    for (double v : ventas) {
        archivo << v << endl;
    }
    archivo.close();
}
vector<double> leerVentas() {
    vector<double> ventas;
    ifstream archivo("ventas.txt");
    double v;

    while (archivo >> v) {
        ventas.push_back(v);
    }
    archivo.close();
    return ventas;
}

double calcularTotal(const vector<double> &ventas) {
    double total = 0;
    for (double v : ventas) {
        total += v;
    }
    return total;
}

void contarPromedio(const vector<double> &ventas, double promedio,
                    int &mayores, int &menores) {
    mayores = menores = 0;
    for (double v : ventas) {
        if (v > promedio)
            mayores++;
        else
            menores++;
    }
}
int main() {
    vector<double> ventas;

    ingresarVentas(ventas);
    guardarVentas(ventas);

    vector<double> ventasArchivo = leerVentas();

    double total = calcularTotal(ventasArchivo);
    double promedio = total / ventasArchivo.size();

    int mayores, menores;
    contarPromedio(ventasArchivo, promedio, mayores, menores);

    cout << "\nResultados:\n";
    cout << "Total ventas: " << total << endl;
    cout << "Promedio ventas: " << promedio << endl;
    cout << "Ventas mayores al promedio: " << mayores << endl;
    cout << "Ventas menores o iguales al promedio: " << menores << endl;

    return 0;
}
