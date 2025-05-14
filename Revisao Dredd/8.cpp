#include <iostream>
using namespace std;

int main () {
	
	int l=10,c=10;
	int matriz[l][c];
	for(int i=0; i<l ; i++){
		for(int j=0; j<c ; j++){
			cin >> matriz[i][j];
			}
		}
	
	int maiorElemento=matriz[0][0], linhaMinimax=0;
	for(int i=0; i<l ; i++){
		for(int j=0; j<c ; j++){
			if(matriz[i][j] > maiorElemento){
				maiorElemento= matriz[i][j];
				linhaMinimax = i;
				}
			}
		}
	int colunaMenor;
	int menorElemento = maiorElemento;
	for(int i=0; i<c ; i++){
		if(matriz[linhaMinimax][i]< menorElemento){
			menorElemento = matriz[linhaMinimax][i];
			colunaMenor= i;
			}
		}
		
		cout << menorElemento << endl << linhaMinimax << " " << colunaMenor << endl;
	
	return 0;
	}
