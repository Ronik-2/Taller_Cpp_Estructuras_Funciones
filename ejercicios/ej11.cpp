#include <iostream>
using namespace std;
int main() {
    int a[10];
    int suma = 0, pos = 0, neg = 0;
    cout<<"Ingresa 10 numeros = ";
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
        suma += a[i];
        if (a[i] > 0) pos++;
        else if (a[i] < 0) neg++;
    }

    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << suma / 10.0 << endl;
    cout << "Porcentaje positivos: " << (pos * 100.0 / 10) << "%" << endl;
    cout << "Porcentaje negativos: " << (neg * 100.0 / 10) << "%";

    return 0;
}
