#include <iostream>
using namespace std;
int main() {
    float precios[10], subtotal = 0;
    for (int i = 0; i < 10; i++) {
        cin >> precios[i];
        subtotal += precios[i];
    }
    float iva = subtotal * 0.12;
    float total = subtotal + iva;

    cout << "Subtotal: " << subtotal << endl;
    cout << "IVA: " << iva << endl;
    cout << "Total a pagar: " << total;

    return 0;
}
