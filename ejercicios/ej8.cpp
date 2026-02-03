#include <iostream>
using namespace std;
int main() {
    int n, pos = 0, neg = 0, cero = 0;

    for (int i = 1; i <= 10; i++) {
        cout<<"Ingrese numero = ";
        cin >> n;
        if (n > 0) pos++;
        else if (n < 0) neg++;
        else cero++;
    }

    cout << "Positivos: " << pos << endl;
    cout << "Negativos: " << neg << endl;
    cout << "Ceros: " << cero;
    return 0;
}
