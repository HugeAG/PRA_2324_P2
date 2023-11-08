#include <iostream>
#include <algorithm>

int* backpack (int N, int M, int *v, int *p) {
    int** soluciones_matriz = new int*[N+1];
    for (int i = 0; i <= N; i++ ) {
        soluciones_matriz[i] = new int[M+1];
        for (int j = 0; j <= M; j++) {
            if(i == 0) {
                soluciones_matriz[i][j] = 0;
            } else if (j == 0) {
                soluciones_matriz[i][j] = 0;
            } else if (i == 1 && p[0] > j){
                soluciones_matriz[i][j] = 0;
            } else if (i == 1) {
                soluciones_matriz[i][j] = v[0];
            } else if (p[i] > j) {
                soluciones_matriz[i][j] = soluciones_matriz[i-1][j];
            } else {
                soluciones_matriz[i][j] = std::max(soluciones_matriz[i-1][j], v[i-1] + soluciones_matriz[i-1][j-p[i-1]]); // infinito
            }

        }

    }
    for (int i = 0; i <= N; i++ ) {
        for (int j = 0; j <= M; j++) {
            cout << " " << soluciones_matriz[i][j]);
        }
        cout << "\n";
    }

    int i = N;
    int j = M;
    int* x = new int[N];

    while ( i > 0 && j > 0) {
        if (i == 1 && soluciones_matriz[i][j] == v[0]) {
            x[i] = 1;
        } else if (soluciones_matriz[i][j] == (v[i-1] + soluciones_matriz[i-1][j-p[i-1]])) {
            x[i] = 1;
            j -= p[i-1];
        }
        i--;
    }
    return x;

}
int main () {
    int v[3] = {38, 40, 24};
    int p[3] = {9, 6, 5};
    int* valor = backpack(3,15, v, p);
    cout << "Solución: ";
    for (int i = 0; i < 3; i++) {
		cout << " , " << valor[1];
    }
    cout << "\n";
}