#include <iostream>
using namespace std;

void SelectionSort(int t,Dados vet[]){
	int maior, aux;
	for(int i=0; i<t-1 ; i++){
		maior= i;
		for(int j=i+1 ; j<t ; j++){
			if(vet[j] < vet[maior]){
				maior = j;
				}
			}
		aux=vet[i];
		vet[i]=vet[maior];
		vet[maior]=aux;
		
		
		//for(int k=0; k<t ; k++){
			//cout << vet[k] << " ";
			//}
		//	cout << endl;
		}
	
	for(int i=0; i<t ; i++){
		cout << vet[i] << " ";
		}
	
	}

struct Dados{
	
	string nome;
	float media;
	int numFaltas;
	};

int main () {
	
	int tamanho;
	cin >> tamanho;
	
	Dados *aluno=new Dados[tamanho];
	
	for(int i=0; i<tamanho; i++){
		cin >> aluno[i].nome;
		cin >> aluno[i].media;
		cin >> aluno[i].numFaltas;
		}
		
	SelectionSort(tamanho,aluno[]);
	
	delete[] aluno;
	
	return 0;
	}
