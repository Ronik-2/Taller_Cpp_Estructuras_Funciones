#include <iostream>
using namespace std;
int main() {
    float notas[10], suma = 0;
    float mayor, menor;
    int apr = 0, rep = 0;
    for (int i = 0; i < 10; i++) {
        cin >> notas[i];
        suma += notas[i];
        if (i == 0) {
            mayor = menor = notas[i];
        } else {
            if (notas[i] > mayor) mayor = notas[i];
            if (notas[i] < menor) menor = notas[i];
        }
        if (notas[i] >= 7) apr++;
        else rep++;
    }
    float prom = suma / 10;

    cout << "Promedio general: " << prom << endl;
    cout << "Nota mas alta: " << mayor << endl;
    cout << "Nota mas baja: " << menor << endl;
    cout << "Porcentaje aprobados: " << apr * 100.0 / 10 << "%" << endl;
    cout << "Porcentaje reprobados: " << rep * 100.0 / 10 << "%";

    return 0;
}
