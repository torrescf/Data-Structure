#include <iostream>
using namespace std;

struct noh{
	int dado;
	noh* proximoValor;
	
	};


class fila{
	private:
		noh* fimFila;
		noh* inicioFila;
	
	public:
		fila();
		~fila();
		void enfileira(int valorInserido);
		int desenfileira();
		bool vazio();
		//bool cheio();
		void imprime();
		void imprimeInicio();
		
		
	};

	fila::fila(){
		fimFila = NULL;
		inicioFila= NULL;
		}
		
	fila::~fila(){
		{
		noh* temp2;
		while(inicioFila!= NULL){
			temp2 = inicioFila;
			inicioFila= inicioFila->proximoValor;
			delete temp2;
			}
		
	}	
		
		}
	
	void fila::enfileira(int valorInserido){
				noh* novoNoh = new noh;
				novoNoh->dado = valorInserido;
				novoNoh->proximoValor = NULL;
				
				if(! vazio()){ // nao ha nenhum valor na fila
					fimFila -> proximoValor = novoNoh;
				}else if(vazio()){
					inicioFila = novoNoh;
					}	
					fimFila = novoNoh;
		}		
	
	int fila::desenfileira(){
		if(vazio()){
			cout << "Fila vazia!\n nao foi possivel desempilhar" << endl;
			return 0;
			}else{
				noh* aux = inicioFila;
				int dadoRemovido = inicioFila -> dado;
				inicioFila= inicioFila -> proximoValor;
				
				if (inicioFila == NULL) {
					fimFila = NULL;
					}
				
				delete aux;
				return dadoRemovido;
				
				}
		}
	
	bool fila::vazio(){
		return (inicioFila == NULL);
		}
	
	void fila::imprime(){
		noh* temporario = inicioFila;
		cout << endl << "Fila: " << endl;
		while(temporario != NULL){
			cout << temporario-> dado << " ";
			temporario = temporario -> proximoValor;
			
			}
		cout << endl;
		}
		
	void fila::imprimeInicio(){
		   if (!vazio()) {
				cout << "Ultimo elemento da fila: " << inicioFila->dado << endl;
			} else {
				cout << "A fila esta vazia." << endl;
				}
		}	
	
int main () {
	fila f1;
	
	cout << "							FILA" << endl;
	
	cout << " e) Enfileirar \n d) Desenfileirar \n i) EspiarTopo \n f) Finalizar Programa " << endl;
	char resposta; 
	cin >> resposta;
	int contador=1;
	
	while(resposta!='f'){
		if(resposta=='e'){ //enfileirar
			int numero;
			cout << "Insira o elemento " << contador << " da fila: ";
			cin >> numero;
			f1.enfileira(numero);
			cout << endl << "elemento cadastrado com sucesso! " << endl;
			contador++;
			
			}else if(resposta== 'd'){ // desenfileirar
				cout << "Elemento Removido: "<< f1.desenfileira() << endl;
				contador--;
				
				}else if(resposta == 'i'){ // esppiar inicio da fila
					 f1.imprimeInicio();
					
					}
		cin >> resposta;
		}
		cout << "Fila resultante: " << endl;
		
	//while(! f1.vazio()){
		f1.imprime();
		//}	
	
	return 0;
	}
