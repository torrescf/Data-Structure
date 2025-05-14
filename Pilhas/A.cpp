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
int main (){
	PilhaNome pN;
	PilhaTipo pT;
	PilhaValor pV;
	
	
	char acao= 'z';
	while(acao!='f'){
	cin >> acao;
	if(acao=='i'){ // inserir itens
		string nome;
		char tipo;
		int valor;
		
		cin >> nome;
		pN.empilharNome(nome);
	
		cin >> tipo;
		pT.empilharTipo(tipo);
		
		cin >> valor;
		pV.empilharValor(valor);
		
		}else if(acao=='r'){ // remover um item do inventario
			
			}else if(acao=='l'){ // limpar a pilha
				pN.limparNome();
				pT.limparTipo();
				pV.limparValor();
				
				}else if(acao=='e'){ // escrever apenas o item no topo 
					pN.imprimirTopoNome();
					pT.imprimirTopoTipo();
					pV.imprimirTopoValor();
					
					}else {
						cout << "Acao invalida!" << endl << endl;
						}
}
	while(! pN.pilhaVaziaNome() and ! pT.pilhaVaziaTipo()and ! pV.pilhaVaziaValor()){
		cout<< pN.desempilharNome() << endl;
		cout << pT.desempilharTipo() << endl;
		cout << pV.desempilharValor() << endl;
		cout << endl;
		}
		
	return 0;
	}
