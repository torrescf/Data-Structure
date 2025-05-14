#include <iostream>
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
	
	int tamanho = tamA;
	int *uniao= new int[tamanho];
	for(int i=0; i<tamanho; i++){
		uniao[i] = vetA[i]; 
		}	
	
	for(int i=0; i<tamA ; i++){
		int contador=0;
		int numeroDesejado;
		for(int j=0; j<tamB ; j++){
			if(vetB[j]==vetA[i]){
				contador++;
				numeroDesejado= vetB[j+1];
				j=tamB+1; // finalizar a condicao
				}
			}
			if(contador==0){ // elemento nao se encontra no conjunto A, vetor precisa ser realocado
				int tamNovo = tamA+1;
				int *novoVetor= new int[tamNovo];
				for(int i=0; i<tamNovo; i++){
					novoVetor[i]=0;
					}
					for(int i=0; i<tamanho; i++){
						novoVetor[i] = uniao[i];
						}
						novoVetor[tamNovo-1]= numeroDesejado;
						delete[] uniao;
						uniao = novoVetor;
						tamanho = tamNovo;
				}
		}
		
		for(int i=0; i<tamanho ; i++){
			cout << uniao[i] << " ";
			}
	
	
	//delete[] vetA;
	//delete[] vetB;
	
	return 0;
	}
