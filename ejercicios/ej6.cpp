#include <iostream>
using namespace std;
int main() {
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0)
            cout << i << " es par\n";
        else
            cout << i << " es impar\n";
    }
    return 0;
}
