#include <iostream>
using namespace std;
int main() {
    int mult3 = 0, noMult3 = 0;
    for (int i = 1; i <= 50; i++) {
        if (i % 3 == 0)
            mult3++;
        else
            noMult3++;
    }

    cout << "Multiplos de 3: " << mult3 << endl;
    cout << "No multiplos de 3: " << noMult3;
    return 0;
}
