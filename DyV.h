#include <iostream>
#include <vector.h>
#include <chrono>
#include <algorithm>
template <typename T>
using namespace std;

int busquedaBinaria( T val, vector& v,int ini, int fin){
       if (ini > fin){
       		cout << "No se encuentra el array" << endl;}
	int medio = (ini + fin) / 2;
 	if (v[medio] == val){
		return medio;}
	else if(v[medio] < val){
		return busquedaBinaria(val, v, ini, medio-1);}
	else{
		return busquedaBinaria(val, v, medio + 1, fin);}
}

void quickSort(vector& v, int ini, int fin){
	if (ini < fin){
		int pivot = partition(v, ini, fin);
		quickSort(v, ini, pivot-1);
		quickSort(v, pivot+1, fin);}
}

int partition(vector& v, int ini, int fin){
	T val = v[fin];
	int i = ini;
	for(int j=ini ; j<fin ; j++){
		if(v[j] <= val){
			swap(v[i], v[j]);
			i++;}}
	swap(v[i], v[fin]);
	return i;
}

