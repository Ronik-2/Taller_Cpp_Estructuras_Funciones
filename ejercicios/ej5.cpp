#include <iostream>
using namespace std;
int main() {
    int n, suma = 0;
    cout<<"Ingresa un numero positivo";
    cin >> n;
    for (int i = 1; i <= 10; i++) {
        int r = n * i;
        cout << n << " x " << i << " = " << r << endl;
        suma += r;
    }

    cout << "Suma total: " << suma;
    return 0;
}
