#include <iostream>
using namespace std;

int main () {
	
	int qntPalavrasA;
	cin >> qntPalavrasA;
	
	string* palavrasA = new string[qntPalavrasA];
	for(int i=0; i<qntPalavrasA ; i++){
		cin >> palavrasA[i];
		}
	
	int qntPalavrasB;
	cin >> qntPalavrasB;
	
	string* palavrasB = new string[qntPalavrasB];
	for(int i=0; i<qntPalavrasB ; i++){
		cin >> palavrasB[i];
		}	
	
	int qntPalavrasC;
	cin >> qntPalavrasC;
	
	string* palavrasC = new string[qntPalavrasC];
	for(int i=0; i<qntPalavrasC ; i++){
		cin >> palavrasC[i];
		}
	
	for(int i=0; i<qntPalavrasC ; i++){
		int contador=0;
		for(int j=0 ; j<qntPalavrasA ; j++){
			if(palavrasC[i]==palavrasA[j]){
				contador++;
				}
			}
		for(int k=0; k<qntPalavrasB ; k++){
			if(palavrasC[i]==palavrasB[k]){
				contador++;
				}
			}
		cout << contador << " ";
		
		}	
	
	delete [] palavrasA;
	delete [] palavrasB;
	delete [] palavrasC;
	
	
	return 0;
	}
