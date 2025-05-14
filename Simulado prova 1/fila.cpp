#include <iostream>
using namespace std;

struct noh{
	int dado;
	noh* proximo;
	};

class fila{
	private:
		noh* inicio; //primeiro valor inserido
		noh* fim; // ultimo valor inserido
	
	public:
		fila();
		~fila();
		void enfileira(int valorInserido);
		int desenfileira();
		bool filaVazia();
		void espiarPrimeiro();
		
	};

	fila::fila(){
		inicio = NULL;
		fim = NULL;
		}
	
	fila::~fila(){
		
		while(! filaVazia()){
			noh* temp= inicio;
			inicio= inicio-> proximo;
			delete temp;
			
			}
			cout << endl << "Fila Desennfileirada com sucesso!" << endl;
		}
	
	
	void fila::enfileira(int valorInserido){
		noh* novoNoh= new noh;
		novoNoh->dado= valorInserido;
		novoNoh->proximo= NULL;
		
		if( filaVazia()){
			inicio = novoNoh;
			}else{
				fim-> proximo= novoNoh;
				}
				fim = novoNoh;
		}
	
	
	int fila::desenfileira(){
		if(filaVazia()){
			cout << "ERRO, fila vazia!" << endl;
			return 0;
			}else{
				noh* aux = inicio;
				int dadoRemovido= aux-> dado;
				inicio= inicio-> proximo;
				delete aux;
				return dadoRemovido ;
				
				}
		}
	
	bool fila::filaVazia(){
		return (inicio == NULL);
		}
	
	void fila::espiarPrimeiro(){
		if(filaVazia()){
			cout << "ERRO, fila vazia!" << endl;
			}else{
				int dadoRemovido= inicio -> dado;
				cout << dadoRemovido << endl;
				}
		}

int main () {
	fila f1;
	
	cout << " e) enfileirar \n d) desenfileirar \n p) espiar inicio \n f) finalizar programa \n";
	char resposta;
	
	cin >> resposta;
	while(resposta!= 'f'){
		if(resposta == 'e'){
			int num;
			cout << "\n Insira o numero que deseja enfileirar: ";
			cin >> num;
			f1.enfileira(num);
			cout << "\n elemento enfileirado com sucesso \n";
			
			}else if(resposta == 'd'){
				cout << "\n Elemento desenfileirado: ";
				cout << f1.desenfileira() << endl;
				
				}else if(resposta == 'p'){
					cout << "\n Primeiro elemento: ";
					f1.espiarPrimeiro();
					cout << endl;
				}
			cin >> resposta;
		}
	
	cout << "Fila: ";
	while(! f1.filaVazia()){
		cout << f1.desenfileira() << " ";
		}
	
	
	return 0;
	}
