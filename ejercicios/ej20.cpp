#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v(10);
    int sumaCuad = 0;
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
        sumaCuad += v[i] * v[i];
    }
    cout << "Suma de cuadrados: " << sumaCuad << endl;
    cout << "Promedio de cuadrados: " << sumaCuad / 10.0;

    return 0;
}
