#include <iostream>
using namespace std;

struct acao{
	int identificador;
    string nomeAcao;
    int tempoExecucao; 
    int tempoConsumido;
	};

class noh{
	friend class listaDup;
	private:
		noh* proximo;
		noh* anterior;
		acao dado;
	
	public:
		noh(acao d);
	
	};

	noh::noh(acao d){
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
		void insereVazio(acao valorInserido);
		void insereInicio(acao valor);
		void insereFim(acao valor);
		void inserePosicaoDesejada(int posicaoDesejada, acao valor);
		void removeInicio();
		void removeFim();
		void removePosicaoEspecifica(int posicaoEspecifica);
		void imprime();
		int procura(string nomeDesejado);
		acao retornoProximo(int t);
		void removeMaiorExec();
		void imprimePosDesejada(int posDesejada);
	
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
		
	void listaDup::insereVazio(acao valorInserido){
		noh* novo= new noh(valorInserido);
		primeiro = novo;
		ultimo=novo;
		tamanhoLista++;
		}
	
	void listaDup::insereInicio(acao valor){
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
	
	void listaDup::insereFim(acao valor){
		if(listaVazia()){
			insereVazio(valor);
			}else{
				noh* novo= new noh(valor);
				novo->anterior=ultimo;
				ultimo->proximo=novo;
				ultimo=novo;
				tamanhoLista++;
				cout << "\nTAMANHO: " << tamanhoLista << endl;
				}
		}
	
	void listaDup::inserePosicaoDesejada(int posicaoDesejada, acao valor){
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
							novo -> proximo = aux->proximo;
							novo->anterior=aux;
							aux->proximo->anterior=novo;
							aux -> proximo= novo;
						}
						tamanhoLista++;
						cout << "\nTAMANHO: " << tamanhoLista << endl;
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
					}else if(posicaoEspecifica==tamanhoLista-1){
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
				while(aux!=NULL){
					cout << aux->dado.identificador << " " << aux->dado.nomeAcao << " " << aux->dado.tempoExecucao << " " << aux->dado.tempoConsumido << endl;
					aux = aux->proximo;
					}
					cout << endl;
				}
		}
	
	int listaDup:: procura(string nomeDesejado){
		if(listaVazia()){
			cout << "Lista vazia\n";
			return 0;
			}else{
				noh* aux= primeiro;
				int tamAux=0;
				
				while(aux->dado.nomeAcao !=nomeDesejado){
					aux=aux->proximo;
					tamAux++;
					}
				return tamAux;
				}
		}
		
	acao listaDup::retornoProximo(int t){
		int tamAux=0;
		noh* aux = primeiro;
		
		while(tamAux !=t){
			aux= aux->proximo;
			tamAux++;
			}
		return aux->dado;
		}
		
	void listaDup::imprimePosDesejada(int posDesejada){
		int tam=0;
		noh* temp= primeiro;
		
		while(tam!=posDesejada){
			temp=temp->proximo;
			tam++;
			}
		
		cout << "(" << temp->dado.identificador << ", " << temp->dado.nomeAcao << ", " << temp->dado.tempoExecucao << ", " << temp->dado.tempoConsumido << ")" << endl;
		}
		
		
	void listaDup::removeMaiorExec(){
		noh* aux=primeiro;
		int maiorTempoExec=0;
		int pos=0;
		int tamAux=0;
		
		while(aux!=NULL){
			if(maiorTempoExec < (aux->dado.tempoExecucao)){
				maiorTempoExec = aux->dado.tempoExecucao;
				pos= tamAux;
				}
			aux=aux->proximo;
			tamAux++;
			}
		cout << "Maior tempo de execucao: " << maiorTempoExec << endl;
		cout << "Posicao: " << pos << endl;
		cout << "\nTAMANHO: " << tamanhoLista << endl;
		imprimePosDesejada(pos);
		removePosicaoEspecifica(pos);
		cout << "\nTAMANHO: " << tamanhoLista << endl;
		//tamanhoLista--;
		cout << "Elemento removido\n";
		
		}
		
		
int main (){
	listaDup l1;
	acao info;
	
	int resposta=0;
	int tamanho=0;
	
	do{
		cout << "-------------------------------------------------------------" << endl;
		cout << "1)Inserir no inicio\n2)Inserir no fim\n3)Inserir na posicao desejada\n\n4)Remover no inicio\n5)Remover no fim\n6)Remover uma posicao desejada\n7)Procurar por um nome \n8)Imprimir lista\n9)Remover o elemento com maior tempo de execucao \n10)Fim\n";
		cout << "-------------------------------------------------------------" << endl;
		cin >> resposta;
		switch(resposta){
			case 1:
				cout << "Elemento: ";
				cin >> info.identificador;
				cout << "Acao: ";
				cin >> info.nomeAcao;
				cout << "Tempo de execucao: ";
				cin >> info.tempoExecucao;
				cout << "Tempo de consumo: ";
				cin >> info.tempoConsumido;
				
				l1.insereInicio(info);
				cout << "Elemento inserido no inicio\n";
				tamanho++;
				cout << "\nTAMANHO: " << tamanho << endl;
				break;
			
			case 2:
				cout << "Elemento: ";
				cin >> info.identificador;
				cout << "Acao: ";
				cin >> info.nomeAcao;
				cout << "Tempo de execucao: ";
				cin >> info.tempoExecucao;
				cout << "Tempo de consumo: ";
				cin >> info.tempoConsumido;
				
				l1.insereFim(info);
				cout << "Elemento inserido no fim\n";
				tamanho++;
				cout << "\nTAMANHO: " << tamanho << endl;
				break;
			
			case 3:
				cout << "Posicao: ";
				int posicao1;
				cin >> posicao1;
				if((posicao1>tamanho) or (posicao1<0)){
					cout << "Erro: posicao invalida\n";
					}else{
						cout << "Elemento: ";
						cin >> info.identificador;
						cout << "Acao: ";
						cin >> info.nomeAcao;
						cout << "Tempo de execucao: ";
						cin >> info.tempoExecucao;
						cout << "Tempo de consumo: ";
						cin >> info.tempoConsumido;
						l1.inserePosicaoDesejada(posicao1-1, info);
						cout << "\nElemento inserido na posicao " << posicao1 <<  endl;
						tamanho++;
						cout << "\nTAMANHO: " << tamanho << endl;
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
							cout << "elemento na posicao " << posicao2 << " removido no fim\n";
							}
					}else{
						cout << "Erro: lista vazia!\n";
						}
						break;
			
			case 7:
				if(l1.listaVazia()){
					cout << "Erro: lista vazia\n";
					}else{
						cout << "Nome: ";
						string nome;
						cin >> nome;
						cout << "Elemento " << "' " << nome << " '" << " na posicao:  " << l1.procura(nome) << endl;
						
						}
				break;
				
			case 8:{
				cout << "Lista: " << endl;
				l1.imprime();
				
				listaDup listaAux;
				acao num;
				int tam=0;
				
				while(tam!=tamanho){
					num = l1.retornoProximo(tam);
					listaAux.insereInicio(num);
					tam++;
					}
				cout << "Lista Reversa: " << endl;
				listaAux.imprime();
				break;
			}
			case 9:
				l1.removeMaiorExec();
				break;
				
			case 10:
				cout << "\nFim do programa\n";
				l1.imprime();
				break;
			
			default: 
				cout << "Erro: opcao invalida\n";	
				
			}
		}while(resposta!=10);
	
	
	return 0;
	}

