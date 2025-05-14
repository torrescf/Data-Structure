#include <iostream>
using namespace std;

void menu(){
	
	cout << "						INVENTARIO						" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "i)Insirir itens no inventario empilhado\n r)Remover itens do inventario empilhado\n l)limpar pilha\n e)Espiar ultimo item da pilhar" << endl;
	
	};

int main () {
	menu();
	
	int linha;
	cin >> linha;
	int coluna;
	cin >> coluna;
	
	int matriz[linha][coluna];
	for(int i=0; i<linha ; i++){
		for(int j=0; j<coluna ; j++){
			cin >> matriz[i][j];
			}
		}
	
	for(int i=0; i<coluna ; i++){
		for(int j=0; j<linha ; j++){
			cout << matriz[j][i] << " ";
			}
			cout << endl;
		}
	
	return 0;
	}
