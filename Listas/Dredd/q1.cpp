#include <iostream>
using namespace std;

struct equipe{
    string nomeEquipe;
    string lider;
    string linguagem; 
    int qtdMembros;
};

struct noh{
	equipe informacoes;
	noh* proximo;

};

class lista{
	private:
		noh* primeiro;
		noh* ultimo;
		void removeTodos();


	public:
		lista();
		~lista();
		void insere(equipe informacoes);
		void insereFim(equipe informacoes);
		void insereInicio(equipe informacoes);
		void inserePosicaoDesejada(int posicaoDesejada, equipe informacoes);
		void procura(string informacoes);
		void imprime();
		bool listaVazia();
		void removeInicio();
		void removeFim();
		int imprimeTamanho();

};
	
	lista::lista()
	{
		primeiro = NULL;
		ultimo = NULL;
		//tamanhoLista = 0;
	}
	
	lista::~lista()
	{
	 removeTodos();
	
	}
	
	int lista::imprimeTamanho(){
		noh* aux=primeiro;
		int tamAux=0;
		while(aux!=NULL){
			aux=aux->proximo;
			tamAux++;
			}
		return tamAux;
			
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

		//tamanhoLista=0;
		primeiro =NULL;
		ultimo = NULL;

	}

	void lista::insere(equipe valorInserido)
	{
		insereFim(valorInserido);
	
	}

	void lista::insereFim(equipe valorInserido)
	{
		noh* novoNoh = new noh;
		novoNoh->informacoes=valorInserido;
		novoNoh->proximo = NULL;
		if(listaVazia()){
			primeiro=novoNoh;
			ultimo=novoNoh;
		}else{
			ultimo->proximo=novoNoh;
			ultimo=novoNoh;
		}
			//tamanhoLista++;
	}

	void lista::insereInicio(equipe valorInserido)
	{
		noh* novoNoh = new noh;
		novoNoh->informacoes=valorInserido;
		novoNoh->proximo =NULL;
		if(listaVazia()){
			primeiro=novoNoh;
			ultimo=novoNoh;
		}else{
			novoNoh->proximo=primeiro;
			primeiro = novoNoh;
		}
		//tamanhoLista++;
	}

	void lista::inserePosicaoDesejada(int posicaoDesejada,equipe valorInserido)
	{
		noh*novoNoh= new noh;
		novoNoh->informacoes=valorInserido;
		novoNoh->proximo= NULL;
		int tam = imprimeTamanho();
		if((posicaoDesejada <= tam) and (posicaoDesejada >= 0)){
			if(listaVazia()){
				primeiro=novoNoh;
				ultimo=novoNoh;
			}else if(posicaoDesejada==0){
				insereInicio(valorInserido);
				
			}else if(posicaoDesejada==tam){
				insereFim(valorInserido);	
			}else{
				noh* aux = primeiro;
				noh* anterior =NULL;
				int posAux=0;

				while(posAux != (posicaoDesejada)){
					anterior = aux;
					aux=aux->proximo;
					posAux++;
				}
				novoNoh->proximo = aux;
				anterior->proximo= novoNoh;
			}
			//tamanhoLista++;
		
		}else{
			cout << "\nErro: Posicao Invalida!\n";
			}
	
	}

	void lista::procura(string valorDesejado)
	{
		if(listaVazia()){
			cout << "Lista vazia!\n";
			}else{
		
		noh* aux = primeiro;
		int posAux= 0;
		
		while((aux !=NULL) and (aux->informacoes.nomeEquipe != valorDesejado)){
			posAux++;
			aux= aux->proximo;
			}
		if(aux == NULL){
			cout << "Nao encontrado\n";
			}else{
				cout << posAux << endl;
				}
			}
	}

	void lista::imprime()
	{
		noh* aux= primeiro;
		if(listaVazia()){
			cout << "Lista vazia!" << endl;
			}else{
		//cout << "Lista: ";
		while(aux!=NULL){
			cout <<"(" << aux -> informacoes.nomeEquipe << ", ";
			cout << aux-> informacoes.lider << ", ";
			cout << aux->informacoes.linguagem << ", ";
			cout << aux-> informacoes.qtdMembros << ")" << endl;
			aux= aux->proximo;
			}
		
	}
	}

	bool lista::listaVazia()
	{
		int tam = imprimeTamanho();
		return ((tam==0) or (primeiro==NULL));
	}
	
	void lista::removeInicio()
	{
		if(listaVazia()){
			cout << "Remoção em lista vazia!\n";
		}
		else
		{
			noh* aux = primeiro;
			primeiro = primeiro -> proximo;
			delete aux;
			//tamanhoLista--;
		}
		
	}
	
		void lista::removeFim(){
			int tam = imprimeTamanho();
			if(listaVazia()){
				cout << "Remoção em lista vazia!\n";
				}else if(tam==1){
					removeInicio();
					}else{
						noh* aux = primeiro;
						noh* anterior=NULL;
						
						while(aux->proximo!=NULL){
							anterior=aux;
							aux=aux->proximo;
							
							}
						anterior->proximo= NULL;
						//tamanhoLista--;
						}
		}
	
	
	

int main () {
	lista l1;
	equipe info;
	string nomeEquipe;
	
	char resposta;
	do{
		cin >> resposta;
		
		switch(resposta){
			case 'i':
				cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
				l1.insereInicio(info);
				
				break;
			case 'h':
				cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
				l1.insereFim(info);
				
				break;
			case 'm':
				int posicao;
				cin >> posicao;
				cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
				l1.inserePosicaoDesejada(posicao,info);
				
				break;
			case 'r':
				l1.removeInicio();
				
				break;
			case 'a':
				l1.removeFim();
				
				break;
			case 'p':
				l1.imprime();
				
				break;
			case 's':
				cin >> nomeEquipe;
				l1.procura(nomeEquipe);
				
				break;
			case 't':{
				int tamanho = l1.imprimeTamanho();
				cout << tamanho << endl;
				}
			case 'f':
				break;
			}
		
	}while(resposta != 'f');


return 0;
}

