#include <iostream>
using namespace std;

void menu(){
	
	cout << "						INVENTARIO						" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "i)Insirir itens no inventario empilhado\n r)Remover itens do inventario empilhado\n l)limpar pilha\n e)Espiar ultimo item da pilhar" << endl;
	
	};


int main () {
	menu();
	int l,c;
	l=c=10;
	int matriz[l][c];
	
	for(int i=0; i<l; i++){ // preenchimento da matriz
		for(int j=0; j<c; j++){
			cin >> matriz[i][j];
			}
		}
		
		
		
	//operacao 1
	//trocar a linha 2 pelos numeros da coluna 8
	cout << "1." << endl;
	
	int matrizAux[l][c];
		for(int i=0; i<l; i++){ // preenchimento da matriz
		for(int j=0; j<c; j++){
			matrizAux[i][j]=matriz[i][j];
			}
		}
	
	int linha1 = 1;
	int coluna1 = 7;
	for(int i=0; i<c; i++){
		matrizAux[linha1][i]=matrizAux[i][coluna1];
		}
	
	for(int i=0; i<l; i++){ // preenchimento da matriz
		for(int j=0; j<c; j++){
			cout << matrizAux[i][j] << " ";
			}
			cout << endl;
		}
	//operacao 2
	// trocar a coluna 4 pelos numeros da coluna 10
	cout << "2." << endl;
	int matrizAux[l][c];
		for(int i=0; i<l; i++){ // preenchimento da matriz
		for(int j=0; j<c; j++){
			matrizAux[i][j]=matriz[i][j];
			}
		}
	
	int coluna2 = 3;
	coluna1 = 9;
	for(int i=0; i<c; i++){
		matriz[i][coluna2]=matriz[i][coluna1];
		}
	
	for(int i=0; i<l; i++){ // preenchimento da matriz
		for(int j=0; j<c; j++){
			cout << matriz[i][j] << " ";
			}
			cout << endl;
		}
		
	return 0;
	}
