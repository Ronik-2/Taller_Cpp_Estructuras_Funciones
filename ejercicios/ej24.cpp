#include <iostream>
using namespace std;
int main() {
    float sueldos[10], suma = 0;
    int arriba = 0, abajo = 0;
    for (int i = 0; i < 10; i++) {
        cin >> sueldos[i];
        suma += sueldos[i];
    }
    float prom = suma / 10;
    for (int i = 0; i < 10; i++) {
        if (sueldos[i] > prom)
            arriba++;
        else
            abajo++;
    }
    cout << "Promedio: " << prom << endl;
    cout << "Sueldos arriba del promedio: " << arriba << endl;
    cout << "Sueldos debajo del promedio: " << abajo;
    return 0;
}
