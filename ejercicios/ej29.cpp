#include <iostream>
using namespace std;

int main() {
    int m[3][3];
    int sumaTotal = 0;

    for (int i = 0; i < 3; i++) {
        int sumaFila = 0;
        for (int j = 0; j < 3; j++) {
            cin >> m[i][j];
            sumaFila += m[i][j];
            sumaTotal += m[i][j];
        }
        cout << "Suma fila " << i + 1 << ": " << sumaFila << endl;
    }

    cout << "Suma total: " << sumaTotal;
    return 0;
}
