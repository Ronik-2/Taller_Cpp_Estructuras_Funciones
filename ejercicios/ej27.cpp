#include <iostream>
using namespace std;
int main() {
    int op, n = 0;
    do {
        cout << "\n1. Ingresar numero";
        cout << "\n2. Verificar rango (1-100)";
        cout << "\n3. Par o impar";
        cout << "\n4. Salir\n";
        cin >> op;

        switch (op) {
            case 1:
                cin >> n;
                break;
            case 2:
                if (n >= 1 && n <= 100)
                    cout << "Dentro del rango\n";
                else
                    cout << "Fuera del rango\n";
                break;
            case 3:
                if (n % 2 == 0)
                    cout << "Par\n";
                else
                    cout << "Impar\n";
                break;
        }
    } while (op != 4);
    return 0;
}
