#include <iostream>
using namespace std;
int main() {
    int op, a = 0, b = 0;
    do {
        cout << "\n1. Ingresar dos numeros";
        cout << "\n2. Mostrar suma y resta";
        cout << "\n3. Mostrar el mayor";
        cout << "\n4. Salir\n";
        cin >> op;
        switch (op) {
            case 1:
                cin >> a >> b;
                break;
            case 2:
                cout << "Suma: " << a + b << endl;
                cout << "Resta: " << a - b << endl;
                break;
            case 3:
                cout << "Mayor: " << (a > b ? a : b) << endl;
                break;
        }
    } while (op != 4);
    return 0;
}
