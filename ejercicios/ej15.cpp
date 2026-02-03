#include <iostream>
using namespace std;
int main() {
    int a[15];
    int sumaPos = 0, sumaNeg = 0;
    float contPos = 0;
    float contNeg = 0;
    cout<<"Ingrese 15  numeros = ";
    for (int i = 0; i < 15; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            sumaPos += a[i];
            contPos++;
        } else if (a[i] < 0) {
            sumaNeg += a[i];
            contNeg++;
        }
    }
    if (contPos > 0)
        cout << "Promedio positivos: " << sumaPos / contPos << endl;
    if (contNeg > 0)
        cout << "Promedio negativos: " << sumaNeg / contNeg;

    return 0;
}
