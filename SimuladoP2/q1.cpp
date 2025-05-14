#include <iostream>

using namespace std;

class noh{
	friend class lista;
	private:
		noh* proximo;
		noh* anterior;
		int dado;
	
	public:
		noh(int d);
	
	};
	
noh::noh(int d){
	dado = d;
	proximo = nullptr;
	anterior = nullptr;
	
	}

class lista{
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanhoLista;
		
	public:
		lista();
		~lista();
		void insereInicio(int num);
		void insereFim(int num);
		void removeInicio();
		void removeFim();
		void imprime();
		bool listaVazia();
		void divide(int pos, lista& listaAux);
	};
	
lista::lista(){
	primeiro = nullptr;
	ultimo = nullptr;
	tamanhoLista =0;
	
	}

lista::~lista(){
	while(! listaVazia()){
		removeInicio();
		}
	}

bool lista::listaVazia(){
	return ((tamanhoLista==0) or (primeiro==nullptr));
	}
	
void lista::insereInicio(int num){
	noh* novoNoh = new noh(num);
	if(listaVazia()){
		primeiro = novoNoh;
		ultimo = novoNoh;
		
		}else{
			novoNoh -> proximo = primeiro;
			primeiro -> anterior = novoNoh;
			primeiro = novoNoh;
			}
	tamanhoLista++;
	}

void lista::insereFim(int num){
	noh* novoNoh = new noh(num);
	
	if(listaVazia()){
		primeiro = novoNoh;
		ultimo =novoNoh;
		}else{
			novoNoh->anterior = ultimo;
			ultimo->proximo = novoNoh;
			ultimo = novoNoh;
			}
	tamanhoLista++;
	}

void lista::removeInicio(){
	if(listaVazia()){
		cout << "\nErro: remocao em lista vazia\n";
		}else{
			if(primeiro==ultimo){
				primeiro = nullptr;
				ultimo =nullptr;
				tamanhoLista=0;
				}else{
					noh* aux = primeiro;
			
					primeiro = primeiro -> proximo;
					primeiro->anterior =nullptr;
			
					delete aux;
				}
			tamanhoLista--;
			}
	}

void lista::removeFim(){
	if(listaVazia()){
		cout << "\nErro: remocao em lista vazia\n";
		}else{
			if(primeiro==ultimo){
				primeiro = nullptr;
				ultimo = nullptr;
				tamanhoLista =0;
				}else{
					noh* aux=ultimo;
			
					ultimo = ultimo->anterior;
					ultimo -> proximo = nullptr;
			
					delete aux;
					}
			tamanhoLista--;
			}
	}

void lista::divide(int pos, lista& listaAux){
	
	noh* aux= primeiro;
	
	for(int i=0;i<pos ; i++){
		aux = aux->proximo;
		}
	while(aux != nullptr){
		listaAux.insereFim(aux->dado);
		aux = aux->proximo;
		}
	
	delete aux;
	
	while(tamanhoLista > pos){
		removeFim();
		}
	
	}

void lista::imprime(){
	noh* aux=primeiro;
	while(aux!= NULL){
		cout << aux->dado << " ";
		aux = aux->proximo;
		}
	}


int main(){
	lista l1;
	
	int tamanho1;
	
	cout << "Tamanho: ";
	cin >> tamanho1;
	
	int n;
	
	for(int i=0; i<tamanho1 ; i++){
		cout << "Insira o valor " << i+1 << " da lista: ";
		cin >> n;
		l1.insereFim(n);
		}
	
	cout << "Posica de divisao\n";
	int posicaoDesejada;
	cin>>posicaoDesejada;
	
	if(posicaoDesejada+1>tamanho1){
		l1.imprime();
		cout << "\n-1" << endl;
		
		}else if(posicaoDesejada+1==tamanho1){
			l1.imprime();
			cout << endl;
			}else{
				lista l2;
				l1.divide(posicaoDesejada+1, l2);
				
				cout << "Divisao da lista em 2 partes: \n";
				cout << "Lista 1: ";
				
				l1.imprime();
				cout << endl;
				cout << "Lista 2: ";
				l2.imprime();
				
				}
	
	
	
	return 0;
	}
