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
		int espiarTopo();
		bool pilhaVazia();
	
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
		cout << "\n Pilha Desempilhada com sucesso!" << endl;
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
	
	int pilha::espiarTopo(){
		if(pilhaVazia()){
			cout << "ERRO, pilha vazia \n nao foi possivel espiar o topo \n";
			return 0;
			}else{
				int valorRemovido = topo -> dado;
				return valorRemovido;
				}
		}
	

int main () {
	pilha p1;
	
	cout << " i)empilhar \n r)remover \n e) espiarTopo \n f) finalizar \n";
	char resposta;
	cin >> resposta;
	
	while(resposta !='f'){
		if(resposta== 'i'){
			int num;
			cout << "Insira o numero: ";
			cin >> num;
			p1.empilha (num);
			cout << "\n valor enfileirado com sucesso \n";
			
			}else if(resposta== 'r'){
				cout << "\n Desempilhado: " << p1.desempilha() << endl;
				
				}else if(resposta == 'e'){
					cout << "\n Topo: " << p1.espiarTopo() << endl;
					
					}
		
		
		cin >> resposta;
		}
		
	cout << "\n Pilha Resultante: " << endl;
	while(! p1.pilhaVazia()){
		cout << p1.desempilha() << endl;
		
		}
	
	return 0;
	}
