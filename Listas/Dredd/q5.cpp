#include <iostream>
using namespace std;

struct acao{
	int identificador;
    string nomeAcao;
    int tempoExecucao; 
    int tempoConsumido;
	};

class noh{
	friend class deque;
	private:
		noh* proximo;
		noh* anterior;
		acao dado;
	
	public:
		noh(acao d);
	
	};

	noh::noh(acao d){
		dado= d;
		proximo = NULL;
		anterior = NULL;
		
		}

class deque{
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanhoLista;
	
	public:
		deque();
		~deque();
		bool listaVazia();
		void insereVazio(acao valorInserido);
		void insereInicio(acao valor);
		void insereFim(acao valor);
		void inserePosicaoDesejada();
		void removeInicio();
		void removeFim();
		void imprime();
		void procura(string nomeDesejado);
		void imprimeReverso();
	
	};

	deque::deque(){
		primeiro=NULL;
		ultimo=NULL;
		tamanhoLista=0;
		}
	
	deque::~deque(){
		while(! listaVazia()){
			removeInicio();
			}
		}
	
	bool deque::listaVazia(){
		return ((tamanhoLista==0) or (primeiro==NULL));
		}
		
	void deque::insereVazio(acao valorInserido){
		noh* novo= new noh(valorInserido);
		primeiro =novo;
		ultimo=novo;
		tamanhoLista++;
		}
	
	void deque::insereInicio(acao valor){
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
	
	void deque::insereFim(acao valor){
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
	
	void deque::inserePosicaoDesejada(){
		cout << " Procedimento não é permitido" << endl;
		}
	
	void deque::removeInicio(){
		if(listaVazia()){
			cout << "Erro: lista vazia\n";
			}else{
				noh* aux = primeiro;
				primeiro= primeiro->proximo;
				delete aux;
				tamanhoLista--;
				}
		}
	
	void deque::removeFim(){
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
	
	
	void deque::imprime(){
		if(listaVazia()){
			cout << "Erro: lista vazia\n";
			}else{
				noh* aux= primeiro;
				cout << "Lista: ";
				while(aux!=NULL){
					cout << aux->dado.identificador << " " << aux->dado.nomeAcao << " " << aux->dado.tempoConsumido << " " << aux->dado.tempoExecucao << endl;
					aux = aux-> proximo;
					}
					cout << endl;
				}
			//imprimeReverso();
		}
	
	void deque::procura(string nomeDesejado){
		if(listaVazia()){
			cout << "Lista vazia\n";
			}else{
				noh* aux= primeiro;
				int tamAux=0;
				
				while(aux->dado.nomeAcao != nomeDesejado){
					aux=aux->proximo;
					tamAux++;
					}
				cout << "Posicao: " << tamAux << endl;
				}
		}
	/*	
	void listaDup::imprimeReverso(){
		if(listaVazia()){
			cout << "Erro: lista vazia"<< endl;
			}else{
				noh* aux = ultimo;
				cout << "Lista reversa: ";
				while(aux!=NULL){
					cout << aux->dado << " ";
					aux= aux->anterior;
					}
				cout << endl;
				}
		}	
	*/

int main (){
	deque l1;
	deque listaAux;
	acao info;
	
	char resposta;
	int tamanho=0;
	
	do{
		cout << "-------------------------------------------------------------" << endl;
		cout << "i)Inserir no inicio\nh)Inserir no fim\nm)Inserir na posicao desejada\n\nr)Remover no inicio\na)Remover no fim\ns)Procurar por uma posicao\np)Imprimir lista\nf)Fim\n";
		cout << "-------------------------------------------------------------" << endl;
		cin >> resposta;
		switch(resposta){
			case 'i':
				cout << "Elemento: ";
				cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
				l1.insereInicio(info);
				cout << "Elemento inserido no inicio\n";
				tamanho++;
				break;
			
			case 'h':
				cout << "Elemento: ";
				cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
				l1.insereFim(info);
				cout << "Elemento inserido no fim\n";
				tamanho++;
				break;
			
			case 'm':
					l1.inserePosicaoDesejada();
					
					
				break;
			
			case 'r':
				if(! l1.listaVazia()){
					l1.removeInicio();
					tamanho--;
					cout << "elemento removido no inicio\n";
					}else{
						cout << "Erro: lista vazia!\n";
						}
				break;
			
			case 'a':
				if(! l1.listaVazia()){
					l1.removeFim();
					tamanho--;
					cout << "elemento removido no fim\n";
					}else{
						cout << "Erro: lista vazia!\n";
						}
				break;
			
			case 's':
				if(l1.listaVazia()){
					cout << "Erro: lista vazia\n";
					}else{
						cout << "Nome: ";
						string nomeDesejado;
						cin >> nomeDesejado;
						l1.procura(nomeDesejado);
						}
				break;
				
			case 'p':{
				l1.imprime();
				break;
			}
			case 'f':
				cout << "\nFim do programa\n";
				l1.imprime();
				break;
			
			default: 
				cout << "Erro: opcao invalida\n";
				
			}
		}while(resposta!='f');
	
	
	return 0;
	}
