#include <iostream>
using namespace std;

int main () {
	
	int numIngredientesA;
	cin >> numIngredientesA;
	
	string* listaA= new string[numIngredientesA];
	for(int i=0; i<numIngredientesA ; i++){
		cin >> listaA[i];
		}
	
	int numIngredientesB;
	cin >> numIngredientesB;
	
	string* listaB= new string[numIngredientesB];
	for(int i=0; i<numIngredientesB ; i++){
		cin >> listaB[i];
		}
	
	//todos os itens q estao na listaA e nao estao na ListaB;
	//int numIngredientesDiferentes= numIngredientesA;
	//string *listaDiferentes= new string[numIngredientesDiferentes];
	
	int contador=numIngredientesA;
	for(int i=0; i<numIngredientesA; i++){
		for(int j=0; j<numIngredientesB; j++){
			if(listaA[i]==listaB[j]){
				listaA[i]= "Ambas";
				contador--;
				}
			}
		}
	if(contador!=0){
		int numIngredientesDiferentes= contador;
		string *listaDiferentes= new string[numIngredientesDiferentes];
		int aux=0;
		for(int i=0; i<numIngredientesA ; i++){
			if(listaA[i]!= "Ambas"){
				listaDiferentes[aux]= listaA[i];
				aux++;
				}
			}	
		for(int i=0; i<numIngredientesDiferentes ; i++){
				cout << listaDiferentes[i] << " ";
				}	
			}else{
				cout << "NADA" << endl;
				}
	
	
	
	return 0;
	}
