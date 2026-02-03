#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    string nombre;
    float n1, n2, n3;
};

int main() {
    ofstream archivo("estudiantes.txt");
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        Estudiante e;
        cin >> e.nombre >> e.n1 >> e.n2 >> e.n3;
        archivo << e.nombre << " " << e.n1 << " " << e.n2 << " " << e.n3 << endl;
    }
    archivo.close();

    ifstream leer("estudiantes.txt");
    string buscar;
    cout << "Buscar estudiante: ";
    cin >> buscar;

    Estudiante e;
    bool encontrado = false;

    while (leer >> e.nombre >> e.n1 >> e.n2 >> e.n3) {
        if (e.nombre == buscar) {
            float prom = (e.n1 + e.n2 + e.n3) / 3;
            cout << "Promedio: " << prom << endl;
            if (prom >= 7)
                cout << "Aprueba";
            else
                cout << "Reprueba";
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "Estudiante no encontrado";

    leer.close();
    return 0;
}
