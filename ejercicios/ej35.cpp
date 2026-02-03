#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Cliente {
    string nombre;
    int edad;
    double consumo;
};

int main() {
    vector<Cliente> clientes;
    ofstream archivo("consumos.txt");

    int n;
    cout<<"Elemenots a ingresar = ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Cliente c;
        cin >> c.nombre >> c.edad >> c.consumo;
        archivo << c.nombre << " " << c.edad << " " << c.consumo << endl;
    }

    archivo.close();

    ifstream leer("consumos.txt");
    Cliente c;
    double total = 0;
    Cliente mayor;

    bool primero = true;

    while (leer >> c.nombre >> c.edad >> c.consumo) {
        clientes.push_back(c);
        total += c.consumo;

        if (primero || c.consumo > mayor.consumo) {
            mayor = c;
            primero = false;
        }
    }

    leer.close();

    cout << "Consumo total: " << total << endl;
    cout << "Consumo promedio: " << total / clientes.size() << endl;
    cout << "Mayor consumo: " << mayor.nombre << endl;

    return 0;
}
