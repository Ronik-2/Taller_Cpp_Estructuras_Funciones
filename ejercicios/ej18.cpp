#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    vector<int> v(12);
    int sumaPos = 0, sumaNeg = 0, absTotal = 0;
    for (int i = 0; i < 12; i++) {
        cin >> v[i];
        if (v[i] > 0) sumaPos += v[i];
        else sumaNeg += v[i];
        absTotal += abs(v[i]);
    }
    cout << "Suma positivos: " << sumaPos << endl;
    cout << "Suma negativos: " << sumaNeg << endl;
    cout << "Valor absoluto total: " << absTotal;
    return 0;
}
