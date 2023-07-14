
#include <iostream>
#include <vector>
using namespace std;
void mochila(int M, const vector<int>& b, const vector<int>& p, vector<int>& X) {
    int n = b.size();
    X.resize(n);

    for (int i = 0; i < n; i++) {
        X[i] = 0;
    }

    int pesoAct = 0;
    while (pesoAct < M) {
        int mejorObjeto = -1;
        double mejorRatio = 0.0;

        for (int i = 0; i < n; i++) {
            if (X[i] == 0 && (mejorObjeto == -1 || (double)p[i] / b[i] > mejorRatio)) {
                mejorObjeto = i;
                mejorRatio = (double)p[i] / b[i];
            }
        }

        if (pesoAct + b[mejorObjeto] <= M) {
            X[mejorObjeto] = 1;
            pesoAct += b[mejorObjeto];
        } else {
            X[mejorObjeto] = (M - pesoAct) / b[mejorObjeto];
            pesoAct = M;
        }
    }
}

int main() {
    int M = 10; // Capacidad de la mochila
    vector<int> b = {2, 3, 4, 5}; 
    vector<int> p = {1, 2, 3, 4}; 
    vector<int> X; // Array de solución

    mochila(M, b, p, X);

    cout << "Objetos seleccionados:" << endl;
    for (int i = 0; i < X.size(); i++) {
        cout << X[i]<<endl;
    }

    return 0;
}
