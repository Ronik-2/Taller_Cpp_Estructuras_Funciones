#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;
    if (num < 10 || num > 50) {
        cout << "el numero essta fuera del rango";
    } else {
        cout << "el numero esta dentro del rango permitido";
    }
    return 0;
}
