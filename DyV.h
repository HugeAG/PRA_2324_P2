#include <vector>



template<typename t> int BusquedaBinaria( t x, std::vector<t>& V, int ini, int fin){
	if(ini > fin){
		return -1;
	}
	int medio = (ini + fin) / 2;
	if(V[medio] == x){
		return medio;
	}
	if(V[medio] > x){
		return BusquedaBinaria(x, V, ini, (medio - 1));
	} else {
		return BusquedaBinaria(x, V, (medio + 1), fin);
	}
}

template<typename t> int BusquedaBinaria_Inv( t x, std::vector<t>& V, int ini, int fin){
	if(ini > fin){
		return -1;
	}
	int medio = (ini + fin) / 2;
	if(V[medio] == x){
		return medio;
	}
	if(V[medio] < x){
		return BusquedaBinaria(x, V, ini, (medio - 1));
	} else {
		return BusquedaBinaria(x, V, (medio + 1), fin);
	}
}


template<typename t> int Partition( std::vector<t>& V, int ini, int fin){
	t x = V[fin];
	int i = ini;
	for( int j = ini; j < fin; j++){
		if(V[j] <= x){
			t aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			i++;
		}
	}
	int aux2 = V[i];
	V[i] = V[fin];
	V[fin] = aux2;
	return i;
}

template<typename t> void QuickSort( std::vector<t>& V, int ini, int fin){
	if(ini < fin){
		int piv = Partition(V, ini, fin);
		QuickSort(V, ini, (piv -1 ));
		QuickSort(V, (piv + 1), fin);
	}
}
