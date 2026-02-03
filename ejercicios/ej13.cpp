#include <iostream>
using namespace std;
int main() {
    int a[12], sumaPar = 0, sumaImpar = 0;
    cout<<"Ingrese 12 numeros = ";
    for (int i = 0; i < 12; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0)
            sumaPar += a[i];
        else
            sumaImpar += a[i];
    }

    cout << "Suma pares: " << sumaPar << endl;
    cout << "Suma impares: " << sumaImpar << endl;

    if (sumaPar > sumaImpar)
        cout << "Mayor suma: pares";
    else
        cout << "Mayor suma: impares";

    return 0;
}
