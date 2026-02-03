#include <iostream>
using namespace std;
int main() {
    int n, dentro = 0, fuera = 0;
    cout<<"Ingrese 15 numeros = ";
    for (int i = 1; i <= 15; i++) {
        cin >> n;
        if (n >= 20 && n <= 80)
            dentro++;
        else
            fuera++;
    }

    cout << "Dentro del rango: " << dentro << endl;
    cout << "Fuera del rango: " << fuera;
    return 0;
}
