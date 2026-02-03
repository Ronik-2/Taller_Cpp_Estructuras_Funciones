#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> edades(10);
    int suma = 0, mayores = 0, menoresIgual = 0;
    for (int i = 0; i < 10; i++) {
        cin >> edades[i];
        suma += edades[i];
    }
    float prom = suma / 10.0;
    for (int i = 0; i < 10; i++) {
        if (edades[i] > prom)
            mayores++;
        else
            menoresIgual++;
    }
    cout << "Promedio: " << prom << endl;
    cout << "Mayores al promedio: " << mayores << endl;
    cout << "Menores o iguales: " << menoresIgual;

    return 0;
}
