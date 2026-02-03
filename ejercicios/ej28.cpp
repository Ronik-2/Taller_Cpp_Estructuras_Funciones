#include <iostream>
using namespace std;
int main() {
    int op;
    int a[10];
    bool sihay = false;
    do {
        cout << "\n1. Ingresar 10 numeros";
        cout << "\n2. Mostrar promedio";
        cout << "\n3. Mayor y menor";
        cout << "\n4. Contar positivos y negativos";
        cout << "\n5. Salir\n";
        cin >> op;
        if (op == 1) {
            for (int i = 0; i < 10; i++)
                cin >> a[i];
            sihay = true;
        }
        if (sihay) {
            if (op == 2) {
                int suma = 0;
                for (int i = 0; i < 10; i++) suma += a[i];
                cout << "Promedio: " << suma / 10.0 << endl;
            }

            if (op == 3) {
                int mayor = a[0], menor = a[0];
                for (int i = 1; i < 10; i++) {
                    if (a[i] > mayor) mayor = a[i];
                    if (a[i] < menor) menor = a[i];
                }
                cout << "Mayor: " << mayor << " Menor: " << menor << endl;
            }

            if (op == 4) {
                int pos = 0, neg = 0;
                for (int i = 0; i < 10; i++) {
                    if (a[i] > 0) pos++;
                    else if (a[i] < 0) neg++;
                }
                cout << "Positivos: " << pos << " Negativos: " << neg << endl;
            }
        }

    } while (op != 5);

    return 0;
}
