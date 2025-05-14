#include <iostream>
using namespace std;

int main (){
	
	int tamA;
	cin >> tamA;
	
	char *vetA=new char[tamA];
	for(int i=0; i<tamA; i++){
		cin >> vetA[i];
		}
	
	int tamB;
	cin >> tamB;
	
	char *vetB=new char[tamB];
	for(int i=0; i<tamB; i++){
		cin >> vetB[i];
		}
	
	int tamR=0 , aux=0;
	char * vetR= new char[tamR];
	vetR[0]= 'a';
	
	for(int i=0; i<tamA; i++){
		int contador=0;
		for(int j=0; j<tamB ;j++){
			if(vetA[i]==vetB[j]){
				contador++;
				}
			}
			if(contador==0){ // nao esta presente no vetB
				int novoTam = tamR+1;
				char *novoVetor= new char[novoTam];
				for(int i=0; i<tamR; i++){
					novoVetor[i]=vetR[i];
					}
					delete[] vetR;
					vetR= novoVetor;
					tamR= novoTam;
					vetR[aux]=vetA[i];
					aux++;
				}
		}
		
		for(int i=0 ; i<tamR; i++){
			cout << vetR[i] << " ";
			}
	
	delete[] vetA;
	delete[] vetB;
	delete[] vetR;
	
	return 0;
	}
