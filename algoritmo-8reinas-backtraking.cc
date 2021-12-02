#include <iostream>
#include<math.h>
#include<stdio.h>

using namespace std; 
int x = 0; 

bool comprobar(int reinas[], int n, int k){
	int i;
	for(i = 0; i < k; i++){
		if( (reinas[i] == reinas[k]) or (abs(k - i) == abs(reinas[k] - reinas[i]))){
			return false;
		}
	}
	return true;
}
	
void Nreinas(int reinas[], int n, int k){
	
	if(k == n){
		x++;
		cout << "Solucion " << x << ": ";
		for(int i = 0; i < n; i++){
			cout << reinas[i] <<" , ";
		}
		cout << endl;
	}

	//aun quedan reinas por colocar y el algoritmo debe seguir buscando
	else{
		for(reinas[k] = 0; reinas[k] < n; reinas[k]++){
			if(comprobar(reinas, n, k)){
				Nreinas(reinas, n, k + 1);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int k = 0;
	int cant = 8;

	int *reinas = new int[cant];
	system("cls");
	cout<< "\nA continuacion se muestra las soluciones de las posibles 8 reinas:\n" << endl;

	for(int i = 0; i < cant; i++){
		reinas[i] =- 1;
	}

	Nreinas(reinas, cant, k);
	 
	cout << "\nFin de la solucion\n" << endl;

	return 0;
}