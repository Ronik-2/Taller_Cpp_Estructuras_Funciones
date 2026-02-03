#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v(15);
    int m3 = 0, m5 = 0, ambos = 0;
    for (int i = 0; i < 15; i++) {
        cin >> v[i];
        if (v[i] % 3 == 0) m3++;
        if (v[i] % 5 == 0) m5++;
        if (v[i] % 3 == 0 && v[i] % 5 == 0) ambos++;
    }
    cout << "Multiplos de 3: " << m3 << endl;
    cout << "Multiplos de 5: " << m5 << endl;
    cout << "Multiplos de ambos: " << ambos;
    return 0;
}
