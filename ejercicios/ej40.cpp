#include <iostream>
using namespace std;
const int TAM = 10;
int obtenerMayor(int v[], int n) {
    int mayor = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > mayor) {
            mayor = v[i];
        }
    }
    return mayor;
}
int obtenerMenor(int v[], int n) {
    int menor = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < menor) {
            menor = v[i];
        }
    }
    return menor;
}
void contarValores(int v[], int n, int &pos, int &neg, int &ceros) {
    pos =0;
    neg =0;
    ceros =0;
    for (int i = 0; i < n; i++) {
        if (v[i] > 0)
            pos++;
        else if (v[i] < 0)
            neg++;
        else
            ceros++;
    }
}

int main() {
    int numeros[TAM];
    for (int i = 0; i < TAM; i++) {
        cout << "Ingrese numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
    int mayor = obtenerMayor(numeros, TAM);
    int menor = obtenerMenor(numeros, TAM);
    int positivos, negativos, ceros;
    contarValores(numeros, TAM, positivos, negativos, ceros);
    cout << "\nResultados:\n";
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
    cout << "Positivos: " << positivos << endl;
    cout << "Negativos: " << negativos << endl;
    cout << "Ceros: " << ceros << endl;

    return 0;
}
