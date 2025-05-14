#include <iostream>
using namespace std;

struct noh{
	int dado;
	noh* proximo;
	
	};

class pilha{
	private:
		noh* topo;	
	
	public:
		pilha();
		~pilha();
		void empilha(int valorInserido);
		int desempilha();
		bool pilhaVazia();
		void inverte();
	
	};
	
	pilha::pilha(){
		topo = NULL;
		}
	
	
	pilha::~pilha(){
		while(! pilhaVazia()){
			noh* temp = topo;
			topo= topo -> proximo;
			delete temp;
			
			}
		cout << "\nDesempilhamento feito com sucesso!" << endl;
		}
	
	
	void pilha::empilha(int valorInserido){
		noh* novoNoh = new noh;
		novoNoh -> dado = valorInserido;
		novoNoh -> proximo = topo;
		topo = novoNoh;
		
		}
	
	
	int pilha::desempilha(){
		if(pilhaVazia()){
			cout << "ERRO, pilha vazia \n nao foi possivel desempilhar o dado no topo \n";
			return 0;
			}else{
				noh* aux = topo;
				int valorRemovido = aux -> dado;
				topo = topo -> proximo;
				
				delete aux;
				return valorRemovido;
				}
		}
	
	bool pilha::pilhaVazia(){
		return (topo == NULL);
		
		}
		
	void pilha::inverte(){
		
			pilha auxiliar;
    
			while (!pilhaVazia()) {
			auxiliar.empilha(desempilha());
			}
    
			while (!auxiliar.pilhaVazia()) {
				empilha(auxiliar.desempilha());
				}
		
		}	
	

int main () {
	pilha p1;
	
	int tamanho;
	cout << "Insira o tamanho da Pilha: ";
	cin >> tamanho;
		for(int i=0; i< tamanho; i++){
			
			int num;
			cout << "\nInsira o numero: ";
			cin >> num;
			p1.empilha (num);
			cout << "\nValor enfileirado com sucesso \n";
			
			}
		
		
	p1.inverte();
		
	cout << "\nPilha Invertida: " << endl;
	while(! p1.pilhaVazia()){
		cout << p1.desempilha() << endl;
		
		}
	
	return 0;
	}

