#include <iostream>
#include <fstream>
using namespace std;

int main (){
	
	ifstream entrada ("entrada.txt");
	int tamanho=1;
	int *vetor=new int[tamanho];
	int contador=0;
	
	while(entrada){
		if(contador>=tamanho){ // redimensionar o vetor
			int tamanhoNovo = tamanho+1;
			int *NovoVetor = new int[tamanhoNovo];
			for(int i=0; i<tamanho ; i++){
				NovoVetor[i]=vetor[i];
				}
				delete [] vetor;
				vetor = NovoVetor;
				tamanho = tamanhoNovo;
		}else{
			entrada >> vetor[contador];
			contador++;
			}
	
		}
	tamanho= contador-1; // valor do tamanho do vetor
	
	ofstream saida ("saida.txt");
	for(int i=tamanho-1; i>=0 ; i--){
		saida << vetor[i] << " ";
		}
	
	return 0;
	}
