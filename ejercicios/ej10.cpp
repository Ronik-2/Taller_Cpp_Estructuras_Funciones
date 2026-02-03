#include <iostream>
using namespace std;
int main() {
    int sumaPar = 0, sumaImpar = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0)
            sumaPar += i;
        else
            sumaImpar += i;
    }
    cout << "Suma pares: " << sumaPar << endl;
    cout << "Suma impares: " << sumaImpar << endl;
    if (sumaPar > sumaImpar)
        cout << "Mayor suma: pares";
    else
        cout << "Mayor suma: impares";
    return 0;
}
