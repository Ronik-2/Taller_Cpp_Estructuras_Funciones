#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v(10);
    int suma = 0, mayores = 0;

    for (int i = 0; i < 10; i++) {
        cin >> v[i];
        suma += v[i];
    }

    float promedio = suma / 10.0;

    for (int i = 0; i < 10; i++) {
        if (v[i] > promedio)
            mayores++;
    }

    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Mayores al promedio: " << mayores;

    return 0;
}
