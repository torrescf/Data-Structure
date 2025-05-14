#include <iostream>
using namespace std;
//linha vezes coluna
int main () {
	
	int linhaA=4;
	int colunaA=5;
	int matrizA[linhaA][colunaA];
	
	for(int i=0; i<linhaA; i++){
		for(int j=0; j<colunaA ; j++){
			cin >> matrizA[i][j];
			}
		}
		
	int linhaB=5;
	int colunaB=2;
	int matrizA[linhaB][colunaB];
	
	for(int i=0; i<linhaB; i++){
		for(int j=0; j<colunaB ; j++){
			cin >> matrizB[i][j];
			}
		}
	
	if(colunaA==linhaB){
	int linhaResultado=linhaA;
	int colunaResultado= colunaB;
	int matrizResultado[linhaResultado][colunaResultado];
	
	
	for(int i=0; i<linhaA; i++){
		for(int j=0; j<colunaB; j++){
			matrizResultado[][]= matrizA[]
			}
		}
	
	}
	return 0;
	}
