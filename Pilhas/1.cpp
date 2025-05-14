#include <iostream>
using namespace std;

struct nohNome{
	string valorInseridoNome;
	nohNome *proximoValorNome;
	
	};
	
struct nohTipo{
	char valorInseridoTipo;
	nohTipo*proximoValorTipo;
	
	};

struct nohValor{
	int valorInseridoValor;
	nohValor *proximoValorValor;
	
	};	

class PilhaTipo{
	private:
		nohTipo *topoTipo;
		string proximoT;
		
	public:
		PilhaTipo();
		void empilharTipo(char vT); // valor inserido
		char desempilharTipo();
		void imprimirTopoTipo();// "Erro: pilha vazia!" se a pilha ja estiver vazia
		void limparTipo(); // "Erro: pilha vazia!" se a pilha ja estiver vazia
		bool pilhaVaziaTipo();
	
	};

class PilhaValor{
	private:
		nohValor *topoValor;
		string proximoV;
		
	public:
		PilhaValor();
		void empilharValor(int vV); // valor inserido
		int desempilharValor();
		void imprimirTopoValor();// "Erro: pilha vazia!" se a pilha ja estiver vazia
		void limparValor(); // "Erro: pilha vazia!" se a pilha ja estiver vazia
		bool pilhaVaziaValor();
	
	};

class PilhaNome{
	private:
		nohNome *topoNome;
		string proximoN;
		
	public:
		PilhaNome();
		void empilharNome(string vN); // valor inserido
		string desempilharNome();
		void imprimirTopoNome();// "Erro: pilha vazia!" se a pilha ja estiver vazia
		void limparNome(); // "Erro: pilha vazia!" se a pilha ja estiver vazia
		bool pilhaVaziaNome();
	};

	PilhaNome::PilhaNome(){// inicializar a pilha
		topoNome = NULL;
		}

	void PilhaNome::empilharNome(string vN){
		nohNome *novoN = new nohNome;
		novoN -> valorInseridoNome = vN;
		novoN -> proximoValorNome = topoNome;
		topoNome = novoN;
		}
	
	string PilhaNome::desempilharNome(){
		nohNome *auxNome= topoNome;
		if(topoNome != NULL){
			string retornoNome;
			retornoNome= topoNome->valorInseridoNome;
			topoNome= auxNome -> proximoValorNome;
			auxNome-> proximoValorNome= NULL;
			delete auxNome;
			return retornoNome;
			
			
			}else {
				return "Erro: pilha vazia!";
				}
		return "a";
		}
		
	void PilhaNome::limparNome(){
		if(topoNome != NULL){
			while (topoNome != NULL) {
				desempilharNome();
				}
			}else{
				cout << "Erro: pilha vazia!" << endl;
				
				}
		}
	
	bool PilhaNome::pilhaVaziaNome(){
		return topoNome==0;
		
		}
	void PilhaNome::imprimirTopoNome(){
		if(topoNome != NULL){
			cout << "Nome: "<< topoNome->valorInseridoNome << endl;
			}else{
				cout << "Erro: pilha vazia!" << endl;
				}
		
		}
	
	
	PilhaTipo::PilhaTipo(){// inicializar a pilha
		topoTipo = NULL;
		}

	void PilhaTipo::empilharTipo(char vT){
		nohTipo *novoT = new nohTipo;
		novoT -> valorInseridoTipo = vT;
		novoT -> proximoValorTipo = topoTipo;
		topoTipo = novoT;		
		}
	
	char PilhaTipo::desempilharTipo(){
		nohTipo *auxTipo= topoTipo;
		if(topoTipo != NULL){
			char retornoTipo;
			retornoTipo= topoTipo->valorInseridoTipo;
			topoTipo= auxTipo -> proximoValorTipo;
			auxTipo-> proximoValorTipo= NULL;
			delete auxTipo;
			return retornoTipo;
			}else{
				return 'z';
				}
				
		return -1;
		}
		
	void PilhaTipo::limparTipo(){
		if(topoTipo != NULL){
			while (topoTipo != NULL) {
				desempilharTipo();
				}
			}else{
				cout << "Erro: pilha vazia!" << endl;
				
				}
		}
	
	bool PilhaTipo::pilhaVaziaTipo(){
		return topoTipo== 0;
		
	}
	void PilhaTipo::imprimirTopoTipo(){
		if(topoTipo != NULL){
			cout << "Tipo: "<< topoTipo-> valorInseridoTipo << endl;
			}else{
				cout << "Erro: pilha vazia!" << endl;
				}
		
		
		}
	
		
	PilhaValor::PilhaValor(){// inicializar a pilha
		topoValor = NULL;
		}

	void PilhaValor::empilharValor(int vV){
		nohValor *novoV = new nohValor;
		novoV -> valorInseridoValor = vV;
		novoV -> proximoValorValor = topoValor;
		topoValor = novoV;		
		}
	
	int PilhaValor::desempilharValor(){
		nohValor *auxValor= topoValor;
		if(topoValor != NULL){
			int retornoValor;
			retornoValor= topoValor->valorInseridoValor;
			topoValor= auxValor -> proximoValorValor;
			auxValor-> proximoValorValor= NULL;
			delete auxValor;
			return retornoValor;
			}else{
				return -1;
				
				}
		return -1;
		}
	
	void PilhaValor::limparValor(){
		if(topoValor != NULL){
			while (topoValor != NULL) {
				desempilharValor();
				}
			}else{
				cout << "Erro: pilha vazia!" << endl;		
				}
		}
	bool PilhaValor::pilhaVaziaValor(){
		return topoValor==0;
		}
		
	void PilhaValor::imprimirTopoValor(){
		if(topoValor != NULL){
			cout << "Valor: "<< topoValor->valorInseridoValor << endl;
			}else{
				cout << "Erro: pilha vazia!" << endl;
				}
		
		
		}

void menu(){
	
	cout << "						INVENTARIO" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << " i)Insirir itens no inventario empilhado\n r)Remover itens do inventario empilhado\n l)limpar pilha\n e)Espiar ultimo item da pilhar\n f)Finalizar programa" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	};

int main (){
	PilhaNome pN;
	PilhaTipo pT;
	PilhaValor pV;
	
	menu();
	
	char acao= 'z';
	while(acao!='f'){
	cin >> acao;
	if(acao=='i'){ // inserir itens
		string nome;
		char tipo;
		int valor;
		
		cout << "Nome: ";
		cin >> nome;
		pN.empilharNome(nome);
		
		cout << "Tipo: ";
		cin >> tipo;
		pT.empilharTipo(tipo);
		
		cout << "Valor: ";
		cin >> valor;
		pV.empilharValor(valor);
		
		cout << "Item empilhado com sucesso!" << endl;
		
		}else if(acao=='r'){ // remover um item do inventario
			
			}else if(acao=='l'){ // limpar a pilha
				pN.limparNome();
				pT.limparTipo();
				pV.limparValor();
				
				cout << "Pilha limpada com sucesso!" << endl;
				
				}else if(acao=='e'){ // escrever apenas o item no topo 
					cout << "Item do topo da pilha: " << endl;
					pN.imprimirTopoNome();
					pT.imprimirTopoTipo();
					pV.imprimirTopoValor();
					
					}else if(acao=='f'){ // fim do programa
						cout << "FIM" << endl;
						}else {
						cout << "Acao invalida!" << endl << endl;
						}
}	cout << "---------------------------------------------------------------------------------" << endl;
	cout << endl << "INVENTARIO" << endl << endl;
	int contador=1;
	while(! pN.pilhaVaziaNome() and ! pT.pilhaVaziaTipo()and ! pV.pilhaVaziaValor()){
		cout << "Item " << contador << ": "<<endl;
		cout << "Nome: "<< pN.desempilharNome() << endl;
		cout << "Tipo: "<< pT.desempilharTipo() << endl;
		cout << "Valor: "  << pV.desempilharValor() << endl;
		cout << endl;
		contador++;
		}
		
	cout << "---------------------------------------------------------------------------------" << endl;
	
	return 0;
	}
