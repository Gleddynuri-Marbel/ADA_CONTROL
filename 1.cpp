#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> eliminarDuplicados(vector<int>& v) {
    sort(v.begin(), v.end());  // Ordenamiento

    // Elimina los elementos duplicados
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());

    return v;
}
int main() {
    vector<int> v = {4, 2, 4, 6, 8, 7, 3, 2, 1, 8};

    cout << "Vector original: ";
    for (const auto& num : v) {
        cout << num << " ";
    }
    cout << endl;

    eliminarDuplicados(v);

    cout << "Vector sin duplicados: ";
    for (const auto& num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
