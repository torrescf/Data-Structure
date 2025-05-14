#include <iostream> 
using namespace std;

struct noh{
	int valorInserido;
	noh * proximoElementoFila;
	
	};

class fila{
	private:
	int tamanhoFila;
	noh* inicioFila;
	noh* fimFila;
	
	
	public:
	
	fila();
	//~fila();
	void enfileirar(int dado);
	int desenfileirar();
	bool vazia();
	
	};

	fila::fila(){
		inicioFila = NULL;
		fimFila = NULL;
		tamanhoFila = 0;
		}
	
	
	bool fila::vazia(){
		return (tamanhoFila ==0 );
		}
	
	void fila::enfileirar(int dado){
		noh* novoNoh = new noh(valorInserido);
		if(fimFila != NULL){
			novoNoh -> valorInserido = dado;
			fimFila = novoNoh;
			}
			tamanhoFila++;
		
		}
	
	int fila::desenfileirar(){
		if(vazia()){
			cout << endl << "Fila VAZIA!" << endl;
			}
			int dadoRetirado = inicioFila -> valorInserido;
			noh* aux = inicioFila;
			inicioFila = inicioFila -> proximoElementoFila;
			delete aux;
			tamanhoFila--;
			return dadoRetirado; 
		}

int main () {
	/*
	programa deve conter: 
		-construtor (informar quando for chamado)
		- destrutor (informar quando for chamado)
		- enfileirador
		- desenfileirador retornando os valores
		- verificador de fila vazia
		- inserir dados
	*/
	fila f1;
	cout << "Insira os valores da fila" << endl;
	
	int numero;
	
	cin >> numero;
	
	while(numero>=0){
		f1.enfileirar(numero);
		cin >> numero;
		}
	
	cout << endl << "Fila: " << endl; 
	while(! vazia()){
		
		cout << f1.desenfileirar << " " << endl;
		}
		cout << endl;
	
	return 0;
	}
