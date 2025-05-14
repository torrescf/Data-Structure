#include <iostream>
using namespace std;

class noh{
	friend class listaDup;
	private:
		noh* proximo;
		noh* anterior;
		int dado;
	
	public:
		noh(int d);
	
	};

	noh::noh(int d){
		dado= d;
		proximo =NULL;
		anterior =NULL;
		
		}

class listaDup{
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanhoLista;
	
	public:
		listaDup();
		~listaDup();
		bool listaVazia();
		void insereVazio(int valorInserido);
		void insereInicio(int valor);
		void insereFim(int valor);
		void inserePosicaoDesejada(int posicaoDesejada, int valor);
		void removeInicio();
		void removeFim();
		void removePosicaoEspecifica(int posicaoEspecifica);
		void imprime();
		int procura(int posicao);
		int retornoProximo(int t);
		void ordenaListaParte1();
		void SelectionSort(int t, int v1[]);
		
	};


	listaDup::listaDup(){
		primeiro=NULL;
		ultimo=NULL;
		tamanhoLista=0;
		}
	
	listaDup::~listaDup(){
		while(! listaVazia()){
			removeInicio();
			}
		}
	
	bool listaDup::listaVazia(){
		return ((tamanhoLista==0) or (primeiro==NULL));
		}
		
	void listaDup::insereVazio(int valorInserido){
		noh* novo= new noh(valorInserido);
		primeiro =novo;
		ultimo=novo;
		tamanhoLista++;
		}
	
	void listaDup::insereInicio(int valor){
		if(listaVazia()){
			insereVazio(valor);
			}else{
				noh* novo= new noh(valor);
				novo -> proximo = primeiro;
				primeiro -> anterior = novo;
				primeiro = novo;
				tamanhoLista++;
				}
		}
	
	void listaDup::insereFim(int valor){
		if(listaVazia()){
			insereVazio(valor);
			}else{
				noh* novo= new noh(valor);
				novo->anterior=ultimo;
				ultimo->proximo=novo;
				ultimo=novo;
				tamanhoLista++;
				}
		}
	
	void listaDup::inserePosicaoDesejada(int posicaoDesejada, int valor){
		if(listaVazia()){
			insereVazio(valor);
			}else{
				int tamAux=0;
				if(posicaoDesejada==0){
					insereInicio(valor);
					}else if(posicaoDesejada == tamanhoLista){
						insereFim(valor);
						}else{
							noh* novo= new noh(valor);
							noh* aux= primeiro;
							while(tamAux!= (posicaoDesejada-1)){
									aux= aux->proximo;
									tamAux++;
							}
							novo -> proximo = aux-> proximo;
							novo->anterior=aux;
							aux->proximo->anterior=novo;
							aux -> proximo= novo;
						}
						tamanhoLista++;
					}
		}
	
	void listaDup::removeInicio(){
		if(listaVazia()){
			cout << "Erro: lista vazia\n";
			}else{
				noh* aux = primeiro;
				primeiro= primeiro->proximo;
				delete aux;
				tamanhoLista--;
				}
		}
	
	void listaDup::removeFim(){
		if(listaVazia()){
			cout << "Erro: lista vazia\n";
			}else if(tamanhoLista==1){
				delete ultimo;
				primeiro=NULL;
				ultimo=NULL;
				tamanhoLista=0;
				}
			else{
				noh* aux = ultimo;
				ultimo= ultimo->anterior;
				ultimo->proximo=NULL;
				delete aux;
				tamanhoLista--;
				}
		}
	
	void listaDup::removePosicaoEspecifica(int posicaoEspecifica){
		if(listaVazia()){
			cout << "Erro: lista vazia\n";
			}else{
				if(posicaoEspecifica==0){
					removeInicio();
					}else if(posicaoEspecifica==tamanhoLista){
						removeFim();
						}else{
							noh* aux= primeiro;
							int tamAux=0;
							while(tamAux!= posicaoEspecifica-1){
								aux->anterior=aux;
								aux= aux->proximo;
								tamAux++;
								}
								aux->anterior->proximo=aux->proximo;
								ultimo->proximo=NULL;
								delete aux;
								tamanhoLista--;
							}
				}
		
		}
	
	void listaDup::imprime(){
		if(listaVazia()){
			cout << "Erro: lista vazia\n";
			}else{
				noh* aux= primeiro;
				cout << "Lista: ";
				while(aux!=NULL){
					cout << aux->dado << " ";
					aux = aux->proximo;
					}
					cout << endl;
				}
		}
	
	int listaDup::procura(int posicao){
		if(listaVazia()){
			cout << "Lista vazia\n";
			return 0;
			}else{
				noh* aux= primeiro;
				int tamAux=0;
				
				while(tamAux!=posicao){
					aux=aux->proximo;
					tamAux++;
					}
				return aux->dado;
				}
		}

	int listaDup::retornoProximo(int t){
		int tamAux=0;
		noh* aux = primeiro;
		
		while(tamAux !=t){
			aux= aux->proximo;
			tamAux++;
			}
		return aux->dado;
		}

	void listaDup::SelectionSort(int t, int vet[]) {
    int menor, aux;
    for (int i = 0; i < t - 1; i++) {
        menor = i;
        for (int j = i + 1; j < t; j++) {
            if (vet[j] < vet[menor]) {
                menor = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}

	void listaDup::ordenaListaParte1(){
		int v1[tamanhoLista];
    	noh* aux = primeiro;

    	for (int i = 0; i < tamanhoLista; i++){
    	v1[i] = aux->dado;
   		aux = aux->proximo;
    }
  
    SelectionSort(tamanhoLista, v1);
	
	aux= primeiro;
	for(int i=0; i<tamanhoLista ; i++){
		aux -> dado = v1[i];
		aux= aux -> proximo;


	}

}



int main (){
	listaDup l1;
	
	int resposta=0;
	int tamanho=0;
	
	do{
		cout << "-------------------------------------------------------------" << endl;
		cout << "1)Inserir no inicio\n2)Inserir no fim\n3)Inserir na posicao desejada\n\n4)Remover no inicio\n5)Remover no fim\n6)Remover uma posicao desejada\n7)Procurar por uma posicao\n8)Ordenar a lista\n9)Imprimir lista\n10)Fim\n";
		cout << "-------------------------------------------------------------" << endl;
		cin >> resposta;
		switch(resposta){
			case 1:
				cout << "Elemento: ";
				int elemento;
				cin >> elemento;
				l1.insereInicio(elemento);
				cout << "Elemento inserido no inicio\n";
				tamanho++;
				break;
			
			case 2:
				cout << "Elemento: ";
				int elemento2;
				cin >> elemento2;
				l1.insereFim(elemento2);
				cout << "Elemento inserido no fim\n";
				tamanho++;
				break;
			
			case 3:
				cout << "Posicao: ";
				int posicao1;
				cin >> posicao1;
				if((posicao1>tamanho) or (posicao1<0)){
					cout << "Erro: posicao invalida\n";
					}else{
						cout << "Elemento: ";
						int elemento3;
						cin >> elemento3;
						l1.inserePosicaoDesejada(posicao1-1, elemento3);
						tamanho++;
						}
				break;
			
			case 4:
				if(! l1.listaVazia()){
					l1.removeInicio();
					tamanho--;
					cout << "elemento removido no inicio\n";
					}else{
						cout << "Erro: lista vazia!\n";
						}
				break;
			
			case 5:
				if(! l1.listaVazia()){
					l1.removeFim();
					tamanho--;
					cout << "elemento removido no fim\n";
					}else{
						cout << "Erro: lista vazia!\n";
						}
				break;
			
			case 6:
				if(! l1.listaVazia()){
					cout << "Posicao: ";
					int posicao2;
					cin >> posicao2;
					if((posicao2>tamanho) or (posicao2<0)){
						cout << "Erro: posicao invalida\n";
						}else{
							l1.removePosicaoEspecifica(posicao2);
							tamanho--;
							cout << "elemento na posicao " << posicao2 <<" removido no fim\n";
							}
					}else{
						cout << "Erro: lista vazia!\n";
						}
						break;
			
			case 7: // procura um elemento na posicao desejada
				if(l1.listaVazia()){
					cout << "Erro: lista vazia\n";
					}else{
						cout << "Posicao: ";
						int posicao3;
						cin >> posicao3;
						if((posicao3>tamanho) or (posicao3<0)){
							cout << "Erro: posicao invalida\n";
							}else{
								cout << "Elemento na posicao " << posicao3 << ": "<<  l1.procura(posicao3-1) << endl;
								}
						}
				break;
				
			case 8:{
				cout << "\nLista Ordenada:\n";
				l1.ordenaListaParte1();
				break;
			}
			case 9:{
				l1.imprime();
				listaDup listaAux;
				
				int num; //l1.retornoPrimeiro();
				int tam=0;
				while(tam!=tamanho){
					num = l1.retornoProximo(tam);
					listaAux.insereInicio(num);
					tam++;
					
					}
				listaAux.imprime();
				break;
			}
			case 10:{
				cout << "\nFim do programa\n";
				l1.imprime();
				break;
			}

			default: 
				cout << "Erro: opcao invalida\n";	
				break;
			}
		}while(resposta!=10);
	
	
	return 0;
	}
