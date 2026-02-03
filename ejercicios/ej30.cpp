#include <iostream>
using namespace std;

int main() {
    int m[2][4];
    int mayor, fila = 0, col = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> m[i][j];
            if (i == 0 && j == 0) {
                mayor = m[i][j];
            } else if (m[i][j] > mayor) {
                mayor = m[i][j];
                fila = i;
                col = j;
            }
        }
    }
    cout << "Mayor: " << mayor << endl;
    cout << "Posicion: fila " << fila << ", columna " << col;

    return 0;
}
