#include <iostream>
#include <fstream>
using namespace std;

int main () {
	
	int tam;
	ifstream entrada ("entrada.txt");
	entrada >> tam;
	int *vetor= new int[tam];
	for(int i=0; i<tam ; i++){
		entrada >> vetor[i];
		}
	
	int contador= tam;
	for(int i=0; i<tam; i++){
		//int aux=0;
		for(int j=0; j<tam; j++){
			if(i!=j){
				if(vetor[i]==vetor[j] and vetor[j]!=-1){
					vetor[j]=-1;
					contador--;
					}
				}
			}
		}
		int aux=0;
		int *novoVetor= new int[contador];
		for(int i=0; i<tam; i++){
			if(vetor[i]!=-1 and aux<contador){
				novoVetor[aux]=vetor[i];
				aux++;
				}
			}
		delete[] vetor;
		vetor=novoVetor;
		tam=contador;
		
		ofstream saida ("saida.txt");
		
		for(int i=0; i<tam ; i++){
			saida << vetor[i] << " ";
			}
	
	delete[] vetor;
	
	return 0;
	}
