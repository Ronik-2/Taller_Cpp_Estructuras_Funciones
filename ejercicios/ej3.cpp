#include <iostream>
using namespace std;

int main() {
    int contador = 0;
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
        contador++;
    }
    cout << "\nCantidad: " << contador;
    return 0;
}