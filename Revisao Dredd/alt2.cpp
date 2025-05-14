#include <iostream>
// saber quantos elementos serao inseridos
// colocar eles no vetor uniao
using namespace std;

int main () {
	
	int tamA;
	cin >> tamA;
	
	int *vetA= new int[tamA];
	for(int i=0; i<tamA	; i++){
		cin >> vetA[i]; 
		}	
	
	int tamB;
	cin >> tamB;
	
	int *vetB= new int[tamB];
	for(int i=0; i<tamB ; i++){
		cin >> vetB[i];
		}
	// loop para contar quantos elementos do vetB nao estao presentes no vetA
	int nPresentes=0;
	
	for(int i=0 ; i<tamB; i++){
		int contador=0;
		for(int j=0 ; j<tamA ; j++){
			if(vetB[i]==vetA[j]){
				contador++;
				vetB[i]=-1;
				}
			}
			if(contador==0){ // numero nao esta presente no vetA
				nPresentes++;
				}
		}
	
	
	int tamanho= tamA+nPresentes;
	int *uniao = new int[tamanho];
	for(int i=0; i<tamA; i++){
		uniao[i] = vetA[i];
		}
	
	int aux=tamA;
	 
	for(int i=0; i<tamB ; i++){
		if(vetB[i]!=-1){
			uniao[aux]= vetB[i];
			aux++;
			}
		}	
	
	for(int i=0; i<tamanho; i++){
		cout << uniao[i] << " ";
		}
	
	delete [] vetA;
	delete [] vetB;
	delete [] uniao;
	
	return 0;
	}
