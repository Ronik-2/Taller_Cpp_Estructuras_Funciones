#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Cliente {
    string nombre;
    int edad;
};

int main() {
    vector<Cliente> clientes;
    int n;
    ofstream archivo("clientes.txt");

    cout << "Cantidad de clientes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Cliente c;
        cin >> c.nombre >> c.edad;
        clientes.push_back(c);
        archivo << c.nombre << " " << c.edad << endl;
    }

    archivo.close();

    ifstream leer("clientes.txt");
    string buscar;
    bool encontrado = false;
    cout << "Nombre a buscar: ";
    cin >> buscar;
    Cliente c;
    while (leer >> c.nombre >> c.edad) {
        if (c.nombre == buscar) {
            cout << "Edad: " << c.edad << endl;
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << "Cliente no encontrado";

    leer.close();
    return 0;
}
