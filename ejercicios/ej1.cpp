#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;
    if (num >= 10 && num <= 50) {
        cout << "El numero esta dentro del rango (10 a 50)";
    } else {
        cout << "El numero no esta dentro del rango";
    }
    return 0;
}
