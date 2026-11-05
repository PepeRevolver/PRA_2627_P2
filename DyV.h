#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

template <typename T>
int partition(vector<T>& v, int ini, int fin);

template <typename T>
int busquedaBinaria(T val, vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        cout << "No se encuentra el elemento en el array" << endl;
        return -1;
    }
    
    int medio = (ini + fin) / 2;
    
    if (v[medio] == val) {
        return medio;
    } else if (v[medio] < val) {
        
        return busquedaBinaria(val, v, medio + 1, fin);
    } else {
        
        return busquedaBinaria(val, v, ini, medio - 1);
    }
}

template <typename T>
void quickSort(vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = partition(v, ini, fin);
        quickSort(v, ini, pivot - 1);
        quickSort(v, pivot + 1, fin);
    }
}

template <typename T>
int partition(vector<T>& v, int ini, int fin) {
    T val = v[fin];
    int i = ini;
    for (int j = ini; j < fin; j++) {
        if (v[j] <= val) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[fin]);
    return i;
}

