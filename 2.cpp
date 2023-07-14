#include <iostream>
#include <vector>

using namespace std;

int encuentraValor(vector<int>& V, int inicio, int fin) {
    if (inicio > fin) {
        return -1;  // Valor no encontrado
    }

    int medio = inicio + (fin - inicio) / 2;

    if (V[medio] == medio) {
        return medio;  // Se encontró el valor
    }
    else if (V[medio] > medio) {
        return encuentraValor(V, medio + 1, fin);  // Busca en la mitad superior
    }
    else {
        return encuentraValor(V, inicio, medio - 1);  // Busca en la mitad inferior
    }
}

int main() {
    vector<int> V = {0, 1, 1, 2, 5, 7, 8, 9};
    int indice = encuentraValor(V, 0, V.size() - 1);

    if (indice != -1) {
        cout << "X[" << indice << "] = " << indice << endl;
    }
    else {
        cout << "No se encontró ningún valor que cumpla la condición X[I] = I." << endl;
    }

    return 0;
}