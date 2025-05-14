#include <iostream>
#include <fstream>
using namespace std;

int main (){
	
	ifstream entrada ("palavras.txt");
	int tamPalavras=0;
	int contador=0;
	string *palavras= new string[tamPalavras];
	
	while(entrada){
		if(contador>=tamPalavras){
			int tamNovo= tamPalavras+1;
			string *NovoPalavras= new string[tamNovo];
			for(int i=0; i<tamPalavras ;i++){
				NovoPalavras[i]= palavras[i];
				}
				delete[] palavras;
				palavras = NovoPalavras;
				tamPalavras  = tamNovo;
			}else{
				entrada >> palavras[contador];
				contador++;
				}
		}
	tamPalavras =contador-1;
	
	ifstream entrada2 ("numeros.txt");
	int qntNum=0,contador2=0;
	int *vetorNum = new int[qntNum];
	
	while (entrada2){
		if(contador2>=qntNum){
			int novaQntNum= qntNum+1;
			int *NovoVetor= new int[novaQntNum];
			for(int i=0; i<qntNum; i++){
				NovoVetor[i]= vetorNum[i];
				}
				delete[] vetorNum;
				vetorNum= NovoVetor;
				qntNum = novaQntNum;
			}else{
				entrada2 >> vetorNum[contador2];
				contador2++;
				}
		}
	qntNum=contador2-1;
	
	ofstream saida ("frase.txt");
	
	for(int i=0; i<qntNum; i++){
		saida << palavras[vetorNum[i]-1] << " "; 
		}	
	
	return 0;
	}
