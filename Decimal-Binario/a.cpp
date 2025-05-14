#include <iostream>
#include <cmath>
using namespace std;

int conversorBD(int numB){
	int resto;
	int n=0;
	int soma=0;
	while(numB>0){
		resto = numB%10;
		soma+= (resto * pow(2,n));
		numB/=10;
		n++;
		}
	return soma;
	};


int main(){
	
	int resposta=1;
	
	while(resposta != 0){
		
		cout << "Binario: ";
		int binario;
		cin >> binario;
		
		cout << "Decimal: " << conversorBD(binario) << endl;
		
		cout << "Deseja converter outro numero? (1-sim, 0-nao)\n";
		cin >> resposta;
		
		}
	
	cout << "\nPrograma Finalizado\n";
	
	
	return 0;
	}
