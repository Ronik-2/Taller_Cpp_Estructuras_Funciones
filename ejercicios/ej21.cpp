#include <iostream>
using namespace std;

int main() {
    int a[10], dentro = 0, fuera = 0;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
        if (a[i] >= 20 && a[i] <= 80)
            dentro++;
        else
            fuera++;
    }
    cout << "Dentro del rango: " << dentro << endl;
    cout << "Fuera del rango: " << fuera << endl;
    cout << "Porcentaje dentro: " << dentro * 100.0 / 10 << "%" << endl;
    cout << "Porcentaje fuera: " << fuera * 100.0 / 10 << "%";

    return 0;
}
