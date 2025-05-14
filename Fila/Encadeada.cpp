	#include <iostream>
	using namespace std;

	class noh{
		friend class fila;
		private:
		int dadoInserido; // dado inserido pelo usuario para ser implementado na fila no final dela
		noh* proximo;
		
		public:
		noh(int dadoInserido);
		
		
		};
		
	noh::noh(int dado) {
    dadoInserido = dado;
    proximo = NULL;	
	}

	class fila{
		private:
		int tamanhoFila;
		noh* inicioFila; // apontara para o inicio da fila
		noh* fimFila; // apontara para o fim da fila
		
		public:
		
		fila(); // construtor
		//~fila(); // destrutor
		void enfileirar(int dado);
		int desenfileirar();
		void limparFila(); // desenfileirar
		bool vazia();
		int tamanho();
		};


		fila::fila(){ //apontar o inicio e fim da fila para nulo
			inicioFila = NULL;
			fimFila = NULL;
			tamanhoFila= 0;
			}
			
		void fila::limparFila(){
			while(tamanhoFila>0){
				desenfileirar();
				}
			}
		
		int fila::tamanho(){
			return tamanhoFila;
			}
		
		bool fila::vazia(){
			return (tamanhoFila ==0);
			}	
		
			
		void fila::enfileirar(int dado){ //criar um novo noh com o dadoInserido e armazenar o novo noh no final da fila, passando o fim para o novo elemento inserido
			noh* novoNoh =new noh(dado);
			if (fimFila != NULL) {
			fimFila -> proximo= novoNoh; // o novo fim da fila sera o novo valor a ser inserido pelo usuario
			fimFila = novoNoh; //
			}else{
				inicioFila = novoNoh;
				fimFila = novoNoh;
				}
			tamanhoFila++; // comportar mais elementos
			}
			
			
		int fila::desenfileirar(){ // "remover" o dado mais proximo do inicio da fila e falar que o anterior a ele sera o novo incio e dar saida no dadoRetirado
			if(vazia()){
				cout << "Pilha vazia! " << endl;
				}
			int dadoRetirado = inicioFila ->dadoInserido;
			noh* aux = inicioFila;
			inicioFila = inicioFila -> proximo; // fila com -1 dado
			if (inicioFila == NULL) {
        fimFila = NULL;
    }
			delete aux;
			tamanhoFila--; // fila com -1 dado
			return dadoRetirado; // em tese, seria o dado mais proximo do inicio da fila
			}		

	int main () {
		/*
		por meio de nos
		cada noh possui o dado a ser armazenado na fila e aponta para o proximo, o ultimo(primeiro elemento inserido) aponta para nulo
		 um apontador para o inicio e outra para o fim da fila
		*/
		
		fila f1;
		int numInserido;
		cout << "Insira os numero que deseja enfileirar, caso deseje terminar, insira '-1' " << endl;
		cin >> numInserido;
		
		while(numInserido>0){
			f1.enfileirar(numInserido);
			cin >> numInserido;
			}
			
		cout << endl <<"Fila: " << endl;
		
		while(! f1.vazia()){
			cout << f1.desenfileirar() << " ";
			}
			cout << endl;
		
		return 0;
		}
