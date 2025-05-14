#include <iostream>
using namespace std;

struct Dados{
	
	float tempo;
	};

int main () {
	
	Dados* atleta = new Dados[8];
	
	for(int i=0; i<8 ;i++){
		cin >> atleta[i].tempo;
		}
		
		int posMenor=0;
		float menor=atleta[0].tempo;
		for(int i=0; i<8 ; i++){
			if(atleta[i].tempo<menor){
				menor = atleta[i].tempo;
				posMenor= i;
				}
			}
	
	for(int i=0; i<8 ; i++){
		if(i!=posMenor){
			atleta[i].tempo-=menor;
			}
		}
	
	for(int i=0 ; i<8 ;i++){
		cout << atleta[i].tempo << endl;
		}
	
	delete[] atleta;
	
	return 0;
	}
