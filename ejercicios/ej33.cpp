#include <iostream>
using namespace std;
struct Cliente {
    string nombre;
    int edad;
};
int main() {
    Cliente clientes[3];
    for (int i = 0; i < 3; i++) {
        cout<<"ingrese su nombre = ";
        cin >> clientes[i].nombre;
        cout<<"ingrese su edad = ";
        cin>> clientes[i].edad;
    }

    for (int i = 0; i < 3; i++) {
        if (clientes[i].edad >= 18) {
            cout << clientes[i].nombre << " es mayor de edad\n";
        }
    }

    return 0;
}
