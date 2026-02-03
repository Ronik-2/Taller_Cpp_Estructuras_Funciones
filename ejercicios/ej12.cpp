#include <iostream>
using namespace std;
int main() {
    int a[8];
    for (int i = 0; i < 8; i++){
        cout<<"Ingresa un numero = ";
        cin >> a[i];}
    int mayor = a[0], menor = a[0];
    for (int i = 1; i < 8; i++) {
        if (a[i] > mayor) mayor = a[i];
        if (a[i] < menor) menor = a[i];
    }
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
    cout << "Diferencia: " << mayor - menor;
    return 0;
}
