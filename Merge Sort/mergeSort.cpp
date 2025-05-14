// conquistar para conquistar
//ordenar por juncao
//juntar 2 partes para ordenar
//separar a lista em variuas mini listas e depois unir ordenando-as
#include <iostream>
using namespace std;


void mergeSort(int v[], int inicio, int fim);

int main(){
	
	int tam = 10;
	int vetor[tam]{6,5,3,2,7,1,4,8,10,9};
	
	mergeSort(vetor, 0, tam-1);
	
	for(int i=0;i<tam;i++){
		cout << vetor[i] << " ";
		}
	
	return 0;
	}



void mergeSort(int v[], int inicio, int fim){
	if(inicio<fim){ // possui mais de um elemento o vetor
		int meio = (inicio+fim)/2;
		//dividir o vetor em 2 vetores menores
		mergeSort(v, inicio, meio);
		mergeSort(v, meio + 1, fim);
		//juntar as partes e ordena-las
		
		int i= inicio;
		int j = meio+1;
		int k = inicio;
		
		int aux[fim+1];
		
		while((i<=inicio) and (j<=fim)){
			if(v[i] < v[j]){
				aux[k]= v[i];
				i++;
				}else{
					aux[k] = v[j];
					j++;
					}
				k++;
			}
		while(i <= meio){// o vetor finalizado foi o da segunda metade, entao ainda ha elementos na primeira metade para serem copiados 
			aux[k]= v[i];
			i++;
			k++;
			// percorrer a primeira metade copiando oq falta
			}
		while(j<=fim){// o vetor finalizado foi o da primeira metade, entao ainda ha elementos na segunda metade para serem copiados 
			aux[k]=v[j];
			j++;
			k++;
			//percorrer a segunda metade copiando oq falta 
			}
			for(int i=inicio; i<=fim ;i++){
				v[i]=aux[i];
				}
		}
	}
