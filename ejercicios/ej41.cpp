#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void ingresarNotas(vector<double> &notas) {
    double n;
    for (int i = 0; i < 5; i++) {
        cout << "Ingrese nota " << i + 1 << ": ";
        cin >> n;
        notas.push_back(n);
    }
}
void guardarArchivo(const vector<double> &notas) {
    ofstream archivo("notas.txt");
    for (double n : notas) {
        archivo << n << endl;
    }
    archivo.close();
}
vector<double> leerArchivo() {
    vector<double> notas;
    ifstream archivo("notas.txt");
    double n;
    while (archivo >> n) {
        notas.push_back(n);
    }
    archivo.close();
    return notas;
}
double calcularTotal(const vector<double> &notas) {
    double total = 0;
    for (double n : notas) {
        total += n;
    }
    return total;
}
void contarRespectoPromedio(const vector<double> &notas, double promedio,
                            int &mayores, int &menores) {
    mayores = menores = 0;
    for (double n : notas) {
        if (n > promedio)
            mayores++;
        else
            menores++;
    }
}

int main() {
    vector<double> notas;

    ingresarNotas(notas);
    guardarArchivo(notas);

    vector<double> notasArchivo = leerArchivo();

    double total = calcularTotal(notasArchivo);
    double promedio = total / notasArchivo.size();

    int mayores, menores;
    contarRespectoPromedio(notasArchivo, promedio, mayores, menores);

    cout << "\nResultados:\n";
    cout << "Total: " << total << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Notas sobre el promedio: " << mayores << endl;
    cout << "Notas bajo o igual al promedio: " << menores << endl;

    return 0;
}
