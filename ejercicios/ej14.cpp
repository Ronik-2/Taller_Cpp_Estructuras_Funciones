#include <iostream>
using namespace std;
int main() {
    float notas[10], suma = 0;
    int apr = 0, rep = 0;
    for (int i = 0; i < 10; i++) {
        cout<<"Ingrese la califacion = ";
        cin >> notas[i];
        suma += notas[i];
        if (notas[i] >= 7)
            apr++;
        else
            rep++;
    }
    cout << "Promedio: " << suma / 10 << endl;
    cout << "Aprobados: " << apr << endl;
    cout << "Reprobados: " << rep;

    return 0;
}
