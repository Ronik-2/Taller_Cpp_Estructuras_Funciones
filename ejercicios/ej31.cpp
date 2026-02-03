#include <iostream>
using namespace std;
int main() {
    int m[4][4];
    int pos = 0, neg = 0, ceros = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> m[i][j];
            if (m[i][j] > 0) pos++;
            else if (m[i][j] < 0) neg++;
            else ceros++;
        }
    }
    cout << "Positivos: " << pos << endl;
    cout << "Negativos: " << neg << endl;
    cout << "Ceros: " << ceros;

    return 0;
}
