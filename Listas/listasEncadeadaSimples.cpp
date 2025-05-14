//cada posicao da lista aponta para o proximo elemento da lista 
//ultimo elemento apontam para NULL
// 1->2->3->4->5->NULL (1- primeiro 5- ultimo)
//ponteiros para o inicio e o fim
//facilita o redimensionamento de um vetor
//pilhas e filas sao tipos especiais de listas
//inserir no inicio,fim ou meio(percorrer ate a posicao)
//remover no inicio, fim ou meio(percorrer ate a posicao)
#include <iostream>
using namespace std;

struct noh{
	int dado;
	noh* proximo;

};

class lista{
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanhoLista;
		void removeTodos();
		//void imprimeReverso(noh* node);


	public:
		lista();
		~lista();
		void insere(int valorInserido);
		void insereFim(int valorInserido);
		void insereInicio(int valorInserido);
		void inserePosicaoDesejada(int posicaoDesejada, int valorInserido);
		void procura(int valorDesejado);
		void imprime();
		//void imprimeReverso();
		bool listaVazia();
		void removeInicio();
		void removeFim();
		void removeNumeroEspecifico(int numeroEspecifico);
		void removePosicaoEspecifica(int posicaoDesejada);

};
	
	lista::lista()
	{
		primeiro = NULL;
		ultimo = NULL;
		tamanhoLista = 0;
	}
	
	lista::~lista()
	{
	 removeTodos();
	
	}

	void lista::removeTodos()
	{
		noh* aux= primeiro;
		noh* temp;

		while(aux != NULL){
			temp= aux;
			aux= aux->proximo;
			delete temp;
		}

		tamanhoLista=0;
		primeiro =NULL;
		ultimo = NULL;

		cout << "\nLista Removida com Sucesso!\n";

	}

	void lista::insere(int valorInserido)
	{
		insereFim(valorInserido);
	
	}

	void lista::insereFim(int valorInserido)
	{
		noh* novoNoh = new noh;
		novoNoh->dado=valorInserido;
		novoNoh->proximo = NULL;
		if(listaVazia()){
			primeiro=novoNoh;
			ultimo=novoNoh;
			cout <<  "\nValor Inserido com sucesso\n";
			imprime();
		}else{ // insere no final da lista (insere no ultimo)
			ultimo->proximo=novoNoh;
			ultimo=novoNoh;
			cout <<  "\nValor Inserido com sucesso\n";
			imprime();
		}
			tamanhoLista++;
	}

	void lista::insereInicio(int valorInserido)
	{
		noh* novoNoh = new noh;
		novoNoh->dado=valorInserido;
		novoNoh->proximo =NULL;
		if(listaVazia()){
			primeiro=novoNoh;
			ultimo=novoNoh;
			cout <<  "\nValor Inserido com sucesso\n";
			imprime();
		}else{
			novoNoh->proximo=primeiro;
			primeiro = novoNoh;
			cout <<  "\nValor Inserido com sucesso\n";
			imprime();
		}
		tamanhoLista++;
	}

	void lista::inserePosicaoDesejada(int valorInserido,int posicaoDesejada)
	{
		noh*novoNoh= new noh;
		novoNoh->dado=valorInserido;
		novoNoh->proximo= NULL;
		if((posicaoDesejada <= tamanhoLista) and (posicaoDesejada >= 0)){
			if(listaVazia()){
				primeiro=novoNoh;
				ultimo=novoNoh;
			}else if(posicaoDesejada==0){//inicio
				//novoNoh->proximo=primeiro;
				//primeiro=novoNoh;
				insereInicio(valorInserido);
				//cout <<  "\nValor Inserido com sucesso\n";
			}else if(posicaoDesejada==tamanhoLista){//ultimo
				//ultimo->proximo=novoNoh;
				//ultimo=novoNoh;
				//cout <<  "\nValor Inserido com sucesso\n";
				insereFim(valorInserido);
			}else{
				noh* aux = primeiro;
				int posAux=0;

				while(posAux != (posicaoDesejada-2)){ //precisa parar 1 antes da posicao desejada
					aux=aux->proximo;
					posAux++;
				}
				//chegou na posicao
				novoNoh->proximo = aux->proximo;
				aux->proximo= novoNoh;
				cout <<  "\nValor Inserido com sucesso\n";
				imprime();
			}
			tamanhoLista++;
		
		}else{
			cout << "\nErro: Posicao Invalida!\n";
			}
	
	}

	void lista::procura(int valorDesejado)
	{ // mesma coisa de inserir numa posicao aleatoria da lista
		noh* aux = primeiro;
		int posAux= 0;
		
		while((aux !=NULL) and (aux->dado != valorDesejado)){
			posAux++;
			aux= aux->proximo;
			}
		if(aux == NULL){
			cout << "\nErro: Valor nao encontrado na lista\n";
			}else{
				cout << "\nPosicao: " << posAux+1 << endl;
				}
	}

	void lista::imprime()
	{
		noh* aux= primeiro;
		
		cout << "Lista: ";
		while(aux!=NULL){
			
			cout << aux -> dado << " ";
			aux= aux->proximo;
			}
		cout << endl;
	}

	bool lista::listaVazia()
	{
		return ((tamanhoLista==0) or (primeiro==NULL));
	}
	
	void lista::removeInicio()
	{
		if(listaVazia())
		{
			cout << "\nErro: lista vazia\n";
		}
		else
		{
			noh* aux = primeiro;
			primeiro = primeiro -> proximo;
			delete aux;
			tamanhoLista--;
			cout << "Elemento removido\n";
			tamanhoLista--;
		}
		
	}
	
		void lista::removeFim(){
			if(listaVazia()){
				cout << "\nErro: lista vazia\n";
				}else if(tamanhoLista==1){
					removeInicio();
					}else{//remove no fim
						noh* aux = primeiro;
						noh* anterior;
						int tamAux = 0;
						
						while((aux!=NULL) and (tamAux!= (tamanhoLista-1))){
							aux=aux->proximo;
							anterior=aux;
							tamAux++;
							
							}
						anterior->proximo= aux->proximo;
						delete aux;
						cout << "Elemento"<< aux->dado << "removido\n";
						tamanhoLista--;
						}
		}
		
		void lista::removeNumeroEspecifico(int numeroEspecifico)
		{
			noh* aux = primeiro;
			noh* anterior=NULL;
			int tamAux=0;
			
			while(aux !=NULL){
				anterior = aux;
				aux= aux -> proximo;  
				tamAux++;
				}if(aux==primeiro){
					removeInicio();
					}else if(aux==ultimo){
						removeFim();
						}else if(aux==NULL){
							cout << "Erro: numero nao encontrado\n";
							
							}else{
							anterior->proximo =NULL;
							cout << "Elemento "<< aux->dado <<" removido\n";
							delete aux;
							tamanhoLista--;
							}
			}
		void lista::removePosicaoEspecifica(int posicaoDesejada){
			
			noh* aux =primeiro;
			noh* anterior= NULL;
			int tamanhoAux=0;
			
			while(tamanhoAux!=(posicaoDesejada-1) and (aux!=NULL)){
				
				aux= aux -> proximo;
				anterior = aux;
				tamanhoAux++;
				
				}
				anterior -> proximo= aux -> proximo;
				cout << "Elemento" << aux->dado << " na posicao " << posicaoDesejada << " removido\n";
				delete aux;
				delete anterior;
			}
	

int main () {
	lista l1;
	int tamanho=0;
	for(int i=0; i< tamanho; i++){
		cout << endl <<"-------------------------------------------------------------------" << endl;
		cout << "\n1)Inserir no inicio\n2)Inserir no Fim \n3)Posicao Desejada\n\n4)Remover no Inicio\n5)Remover no Fim\n6)Remover em um numero desejado\n7)Remover uma posicao desejada\n";
		cout << endl <<"-------------------------------------------------------------------" << endl;
		cout << "Resposta: ";
		int resposta;
		cin >> resposta;
		
		switch(resposta){
			case 1:
				cout << "\nValor(numero): ";
				int valor1;
				cin >> valor1;
				l1.insereInicio(valor1);
				break;
			case 2:
				cout << "\nValor(numero): ";
				int valor2;
				cin >> valor2;
				l1.insereFim(valor2);
				break;
			case 3:
				cout << "\nPosicao: ";
				int posicao;
				cin >> posicao;
				if(posicao>tamanho){
					cout << "\nErro: Posicao invalida\n";
					i--;
					}else{
						cout << "\nValor(numero): ";
						int valor3;
						cin >> valor3;
						l1.inserePosicaoDesejada(valor3,posicao-1);
				}
				break;
			case 4:
				l1.removeInicio();
				i--;
				break;
			case 5:
				l1.removeFim();
				i--;
				break;
			case 6: 
				if(l1.listaVazia()){
					cout << "\nErro: lista vazia\n";
					i--;
					}else{
						cout << "Numero: ";
						int num;
						cin >> num;
						l1.removeNumeroEspecifico(num);
						i--;
				}
				break;
			case 7:
				if(l1.listaVazia()){
				cout << "\nErro: lista vazia\n";
				i--;
				}else{
					cout << "Posicao: ";
					int posicaoDesejada;
					cin >> posicaoDesejada;
					if((posicaoDesejada > tamanho) or (posicaoDesejada < 0)){
						cout << "\n Erro: posicao inexistente\n";
						}else{
							l1.removePosicaoEspecifica(posicaoDesejada-1);
							}
							i--;
				}
				break;
			}
		
		}
		cout << "\n					_Insercao Completa_\n";
		int resposta2;
		do{
			cout << "-----------------------------------";
			cout << "\n1)Procurar Elementos\n2)Imprimir a Lista\n3)Finalizar\n";
			cout << "-----------------------------------" << endl;
			cin >> resposta2;
			
			switch(resposta2){
				case 1:
					cout << "\nValor: ";
					int valor;
					cin >> valor;
					l1.procura(valor);
					
					break;
				case 2:
					l1.imprime();
					break;
				case 3:
					cout << "Lista: ";
					l1.imprime();
					cout << "\nPrograma finalizado\n";
					break;
				default:
					cout << "\nErro: Posicao Invalida\n ";
					break;
				}
			}while(resposta2!=3);
	
		


return 0;
}




