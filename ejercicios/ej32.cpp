#include <iostream>
#include <vector>
using namespace std;

struct Cliente {
    string nombre;
    int edad;
};
int main() {
    vector<Cliente> clientes;
    int n;
    cout << "Cantidad de clientes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Cliente c;
        cin >> c.nombre >> c.edad;
        clientes.push_back(c);
    }
    for (int i = 0; i < clientes.size(); i++) {
        cout << clientes[i].nombre << " - " << clientes[i].edad << endl;
    }
    return 0;
}
