#include <iostream>
using namespace std;

struct Dados{
	
	string sobrenome;
	int idade[3];
	};

int main () {
	
	int numFamilias=3;
	Dados familia[numFamilias];
	
	int resposta=-1,contador=0;
	while(resposta != 0){
		while(contador<tamanho){
			cin >> familia[i].sobrenome;
			if(familia[i].sobrenome== "Fim"){
				resposta =0;
				}
			for(int j=0; j<3 ; j++){
				cin >> familia[i].idade[j];
				}
				contador++;
			
			}
		if(contador==tamanho){
		   	
			}	
		
		
		}
	
	
	return 0;
	}
