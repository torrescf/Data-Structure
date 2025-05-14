#include <iostream>
#include <fstream>
using namespace std;

int main () {
	
	string nomeArq;
	cin >> nomeArq;
	int tam;
	
	ifstream entrada (nomeArq);
	entrada >> tam;
	
	float *numeros = new float[tam];
	for(int i=0; i<tam; i++){
		entrada >> numeros[i];
		}
		
	int novoTam;
	if(tam%2==0){ // par
		novoTam=tam/2;
		int contador=0;
		
		float *novoNumeros = new float[novoTam];
		for(int i=0; i<novoTam; i++){
			novoNumeros[i]=(numeros[contador]+numeros[contador+1])/2;
			contador+=2;
			}
		delete [] numeros;
		numeros = novoNumeros;
		tam= novoTam;
		
		}else{
			novoTam=(tam/2)+1;
			int contador=0;
		
			float *novoNumeros = new float[novoTam];
			for(int i=0; i<tam/2; i++){
				novoNumeros[i]=(numeros[contador]+numeros[contador+1])/2;
				contador+=2;
				}
				novoNumeros[novoTam-1]=numeros[tam-1];
		
			delete [] numeros;
			numeros = novoNumeros;
			tam= novoTam;
			}
			
	for(int i=tam-1; i>=0 ; i--){
		cout << numeros[i] << " "; 
		}
	
	return 0;
	}
