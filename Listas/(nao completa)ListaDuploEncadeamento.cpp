#include <iostream>
using namespace std;

struct acao{
	int identificador;
	string nomeAcao;
	int tempoExecucao;
	int tempoConsumo;
	
	};

class noh{
	friend class listaDuplo;
	private:
		noh* anterior;
		noh* proximo;
		acao informacoes;
		
	public:
	noh(acao d);
	};
	
	noh::noh(acao d){
		anterior =NULL;
		proximo= NULL;
		informacoes = d;
		
		}
	

class listaDuplo{
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanhoLista;
		
		
	public:
		listaDuplo();
		~listaDuplo();
		void insereFim(acao info);
		void insereInicio(acao info);
		void inserePosicaoDesejada(int posicao, acao info);
		bool listaVazia();
		void removeInicio();
		void removeFim();
		void procura(string nome);
		void removePosicaoEspecifica(int posicaoDesejada);
		
	};
	
	listaDuplo::listaDuplo(){
		
		primeiro =NULL;
		ultimo=NULL;
		tamanhoLista=0;
		
		}
	
	listaDuplo::~listaDuplo(){
		noh* aux = primeiro;
		noh* temp;
		while(aux!=NULL){
			temp=aux;
			aux = aux -> proximo;
			delete temp;
			}
		cout << "\nDeletado com sucesso\n";
		}
	
	bool listaDuplo::listaVazia(){
		return ((tamanhoLista==0)or(primeiro==NULL));
		
		}
	
	void listaDuplo::insereFim(acao info){
		noh* novo = new noh(info);
		if(listaVazia()){
			primeiro= novo;
			ultimo= novo;
			}else{
				novo->proximo=ultimo;
				ultimo=novo;
				}
		tamanhoLista++;
		
		}
	
	void listaDuplo::insereInicio(acao info){
		noh* novo = new noh(info);
		if(listaVazia()){
			primeiro= novo;
			ultimo= novo;
			}else{
				novo->proximo=primeiro;
				primeiro=novo;
				}
		tamanhoLista++;
		}
	
	void listaDuplo::inserePosicaoDesejada(int posicao, acao info){
		noh* novo = new noh(info);
		if((posicao > tamanhoLista) or (posicao<0)){
			cout << "Erro: posicao invalida\n";
			}else{
				if(listaVazia()){
					cout << "Erro: Lista Vazia\n";
					}else if(posicao==0){//inicio
							insereInicio(info);
						}else if(posicao==tamanhoLista){//fim
								insereFim(info);
							}else{
								noh* aux= primeiro;
								int contAux=0;
								while(contAux<posicao){
								aux= aux->proximo;
								contAux++;
								}
								novo->proximo=aux;
								aux->anterior=novo; 
							}
				
					}
		
		}
	
	void listaDuplo::removeInicio(){}
	
	void listaDuplo::removeFim(){}
	
	void listaDuplo::removePosicaoEspecifica(int posicaoDesejada){}
	
	void listaDuplo::procura(string nome){}
	

int main (){
	
	
	
	return 0;
	}
