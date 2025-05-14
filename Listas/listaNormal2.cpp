#include <iostream>

using namespace std;

class noh{
	friend class lista;
	private:
		noh* proximo;
		int dado;
	
	public:
		noh(int dado);
	};
	
	noh::noh(int valorInserido){
		dado = valorInserido;
		proximo = NULL;
		}

class lista{
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanhoLista;
	
	public:
		lista();
		~lista();
		void insereInicio(int valorInserido);
		void insereFim(int valorInserido);
		void inserePosicaoDesejada(int valorInserido, int posicao);
		void procura(int valorProcurado);
		void imprime();
		bool listaVazia();
		
	};
	
	lista::lista(){
		primeiro = NULL;
		ultimo = NULL;
		tamanhoLista =0;
		}
	
	lista::~lista(){
		
		
		}
	
	bool lista::listaVazia(){
		return ((tamanhoLista==0) or (primeiro==NULL));
		
		}	
	
	void lista::insereInicio(int valorInserido){
		noh* novo = new noh(valorInserido);
		if(listaVazia()){
			primeiro = novo;
			ultimo = novo;
			}else{
				novo->proximo=primeiro;
				primeiro=novo;
				}
		tamanhoLista++;
		}
	
	void lista::insereFim(int valorInserido){
		noh* novo = new noh(valorInserido);
		if(listaVazia()){
			primeiro = novo;
			ultimo = novo;
			}else{
				novo->proximo=ultimo;
				ultimo=novo;
				
				}
			tamanhoLista++;
		}
	
	void lista::inserePosicaoDesejada(int valorDesejado, int posicao){
		
		if((posicao<=tamanhoLista)and(posicao>0)){
			noh* novo = new noh(valorDesejado);
			if(listaVazia()){
				primeiro=novo;
				ultimo=novo;
				}else if(posicao==0){//primeiro
					insereInicio(valorDesejado);
					
					}else if(posicao==tamanhoLista){//ultimo
						insereFim(valorDesejado);
						}else{
							noh* aux= primeiro;
							int contadorAux=0;
							while(contadorAux!= (posicao-1)){
								primeiro=primeiro->proximo;
								contadorAux++;
								}
								novo->proximo= aux->proximo;
								aux->proximo=novo;
							}
							tamanhoLista++;
			}else{
				cerr << "Erro: Posicao invalida";
				}
		
		}
	
	void lista::procura(int valorProcurado){
		noh* aux = primeiro;
		int contadorAux=0;
		
		while((aux!= NULL) and (aux->dado != valorProcurado)){
			aux = aux -> proximo;
			contadorAux++;
			}
		if(aux==NULL){
			cerr << "Erro: Valor nao encontrado na lista\n";
			}else{
				cout << "Posicao do numero " << valorProcurado << " :" << contadorAux++ << endl;
				}	
		}
	
	void lista::imprime(){
		noh* aux=primeiro;
		
		while(aux!=NULL){
			cout << aux->dado << " ";
			aux= aux->proximo;
			}
		
		}
	

int main(){
	lista l1;
	int tamanho;
	cout << "Insira o tamanho da lista: ";
	cin >> tamanho;
	
	for(int i=0; i<tamanho; i++){
		cout << "1)Inserir no inicio\n2)Inserir no fim\n3)Inserir na posicao desejada\n";
		int resposta;
		cin >> resposta;
		if(resposta==1){
			int valor;
			cout << "Insira o valor: ";
			cin >> valor;
			l1.insereInicio(valor);
			cout << "\nValor inserido com sucesso" << endl;
			
			}else if(resposta==2){
				int valor;
				cout << "Insira o valor: ";
				cin >> valor;
				l1.insereFim(valor);
				cout << "\nValor inserido com sucesso" << endl;
				
				}else if(resposta==3){
					int valor;
					cout << "Insira o valor: ";
					cin>> valor;
					int posicaoD;
					cout << "Insira a posicao: ";
					cin >> posicaoD;
					l1.inserePosicaoDesejada(valor,posicaoD);
					cout << "\nValor inserido com sucesso" << endl;
					}
		
		}
	int resp;
	
	do{
		cout << endl << "1)Procurar a posicao de um elemento\n2)Imprimir a lista\n3)Remover elemento" << endl;
		cin >> resp;
		if(resp==1){
			cout << "Insira o valor que deseja procurar: ";
			int valorDesejado;
			cin  >> valorDesejado;
			l1.procura(valorDesejado);
			
			}else if(resp==2){
				l1.imprime();
				
				}else if(resp!=1 and resp!=2 and resp!=3){
					cerr << "Erro: Resposta invalida\n";
					}
		
		
		}while(resp!=3);	
		
		cout << "\n PROGRAMA FINALIZADO\n";
	
	return 0;
	}
