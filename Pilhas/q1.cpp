#include <iostream>
using namespace std;

struct node{//guarda o valor inserido e o endereco do proximo item da pilha
	string nome;
	char tipo;
	int valor;
	node* proximo;
	};

class pilhaNome{
	private:
		node* topoPilha; // acessar o topo d pilha pra colocar novos elementos
	
	public:
		pilhaNome(); // construtor
		~pilhaNome(); //destrutor
		void empilhaNome(string nomeInserido);
		string desempilhaNome();
		bool pilhaVaziaNome();
		bool pilhaCheiaNome();
		void imprimeNome();
		void imprimeTopoNome();
	
	};
	
	pilhaNome::pilhaNome(){
		topoPilha = NULL;
		}
		
	pilhaNome::~pilhaNome()
	{
		node* temp2;
		while(topoPilha!= NULL){
			temp2 = topoPilha;
			topoPilha= topoPilha->proximo;
			delete temp2;
			}
		
	}	
		
	void pilhaNome::empilhaNome(string nomeInserido)
	{
		if(pilhaCheiaNome()){
			cout << "pilha Esta cheia!, nao foi possivel colocar o elemento" << endl;
			}else{
				node* nohNovo = new node;
				nohNovo-> nome = nomeInserido;	
				nohNovo-> proximo = topoPilha;
				topoPilha = nohNovo;
				
				}
	}
		
	string pilhaNome::desempilhaNome(){
		
		if(pilhaVaziaNome()){
			cout << "Pilha Vazia!" << endl;
			return 0;
			}else{
				
				node* aux = topoPilha; // declarando q o aux esta apontando para o topo da pilha
				string dado= topoPilha -> nome; // dado tera o valor do antigo topo
				
				topoPilha = topoPilha-> proximo ; // declarando que o novo topo sera o valor embaixo do topo antigo
				
				delete aux; // deletando o valor do antigo tamanho
								
				return dado;
				}
		
		
		
		}
	
	bool pilhaNome::pilhaVaziaNome(){ // retornara o valor somente se o topo for nulo(nao tiver mais ninguem na pilha)
		return (topoPilha==NULL);
		
		
		}		
	
	bool pilhaNome::pilhaCheiaNome(){ // tentar criar um novo no, se conseguir ira retornar que esta vazio, se nao conseguir ira retornar que esta cheio
		node* novo;
		
		try{
			novo =new node;
			delete novo;
			return false;
			
			}catch(bad_alloc exception){
				return true;
				
				}
		
		}
	
	void pilhaNome::imprimeNome(){
		
		node* temp = topoPilha;
		cout << "Pilha: " << endl;
		while(temp!= NULL){
			cout << temp-> nome << " ";
			temp= temp -> proximo; // apontar para o proximo valor
			
			}
			cout << endl;
		}
	
	void pilhaNome::imprimeTopoNome(){
		
		if(pilhaVaziaNome()){
			cout << "Erro: pilha vazia!" << endl;;
			}else{
		
		node* temp = topoPilha;
		cout << "Nome: ";
		cout << temp->nome << " ";
		}
		}
	
	
	
	




class pilhaTipo{
	private:
		node* topoPilha; // acessar o topo d pilha pra colocar novos elementos
	
	public:
		pilhaTipo(); // construtor
		~pilhaTipo(); //destrutor
		void empilhaTipo(char tipoInserido);
		char desempilhaTipo();
		bool pilhaVaziaTipo();
		bool pilhaCheiaTipo();
		void imprimeTipo();
		void imprimeTopoTipo();
	
	};
	
	pilhaTipo::pilhaTipo(){
		topoPilha = NULL;
		}
		
	pilhaTipo::~pilhaTipo()
	{
		node* temp2;
		while(topoPilha!= NULL){
			temp2 = topoPilha;
			topoPilha= topoPilha->proximo;
			delete temp2;
			}
		
	}	
		
	void pilhaTipo::empilhaTipo(char tipoInserido)
	{
		if(pilhaCheiaTipo()){
			cout << "pilha Esta cheia!, nao foi possivel colocar o elemento" << endl;
			}else{
				node* nohNovo = new node;
				nohNovo-> tipo = tipoInserido;	
				nohNovo-> proximo = topoPilha;
				topoPilha = nohNovo;
				
				}
	}
		
	char pilhaTipo::desempilhaTipo(){
		
		if(pilhaVaziaTipo()){
			cout << "Pilha Vazia!" << endl;
			return 0;
			}else{
				
				node* aux = topoPilha; // declarando q o aux esta apontando para o topo da pilha
				char dado= topoPilha -> tipo; // dado tera o valor do antigo topo
				
				topoPilha = topoPilha-> proximo ; // declarando que o novo topo sera o valor embaixo do topo antigo
				
				delete aux; // deletando o valor do antigo tamanho
								
				return dado;
				}
		
		
		
		}
	
	bool pilhaTipo::pilhaVaziaTipo(){ // retornara o valor somente se o topo for nulo(nao tiver mais ninguem na pilha)
		return (topoPilha==NULL);
		
		
		}		
	
	bool pilhaTipo::pilhaCheiaTipo(){ // tentar criar um novo no, se conseguir ira retornar que esta vazio, se nao conseguir ira retornar que esta cheio
		node* novo;
		
		try{
			novo =new node;
			delete novo;
			return false;
			
			}catch(bad_alloc exception){
				return true;
				
				}
		
		}
	
	void pilhaTipo::imprimeTipo(){
		
		node* temp = topoPilha;
		cout << "Pilha: " << endl;
		while(temp!= NULL){
			cout << temp->tipo << " ";
			temp= temp -> proximo; // apontar para o proximo valor
			
			}
			cout << endl;
		}
	
	void pilhaTipo::imprimeTopoTipo(){
		
		if(pilhaVaziaTipo()){
			cout << "Erro: pilha vazia!" << endl;;
			}else{
		
		node* temp = topoPilha;
		cout << "Tipo: ";
		cout << temp->tipo << " ";
		}
	
}

	
	
	
	

class pilhaValor{
	private:
		node* topoPilha; // acessar o topo d pilha pra colocar novos elementos
	
	public:
		pilhaValor(); // construtor
		~pilhaValor(); //destrutor
		void empilha(int numeroInserido);
		int desempilha();
		bool pilhaVazia();
		bool pilhaCheia();
		void imprime();
		void imprimeTopo();
	
	};
	
	pilhaValor::pilhaValor(){
		topoPilha = NULL;
		}
		
	pilhaValor::~pilhaValor()
	{
		node* temp2;
		while(topoPilha!= NULL){
			temp2 = topoPilha;
			topoPilha= topoPilha->proximo;
			delete temp2;
			}
		
	}	
		
	void pilhaValor::empilha(int numeroInserido)
	{
		if(pilhaCheia()){
			cout << "pilha Esta cheia!, nao foi possivel colocar o elemento" << endl;
			}else{
				node* nohNovo = new node;
				nohNovo-> valor = numeroInserido;	
				nohNovo-> proximo = topoPilha;
				topoPilha = nohNovo;
				
				}
	}
		
	int pilhaValor::desempilha(){
		
		if(pilhaVazia()){
			cout << "Pilha Vazia!" << endl;
			return 0;
			}else{
				
				node* aux = topoPilha; // declarando q o aux esta apontando para o topo da pilha
				int dado= topoPilha -> valor; // dado tera o valor do antigo topo
				
				topoPilha = topoPilha-> proximo ; // declarando que o novo topo sera o valor embaixo do topo antigo
				
				delete aux; // deletando o valor do antigo tamanho
								
				return dado;
				}
		
		
		
		}
	
	bool pilhaValor::pilhaVazia(){ // retornara o valor somente se o topo for nulo(nao tiver mais ninguem na pilha)
		return (topoPilha==NULL);
		
		
		}		
	
	bool pilhaValor::pilhaCheia(){ // tentar criar um novo no, se conseguir ira retornar que esta vazio, se nao conseguir ira retornar que esta cheio
		node* novo;
		
		try{
			novo =new node;
			delete novo;
			return false;
			
			}catch(bad_alloc exception){
				return true;
				
				}
		
		}
	
	void pilhaValor::imprime(){
		
		node* temp = topoPilha;
		cout << "Pilha: " << endl;
		while(temp!= NULL){
			cout << temp->valor << " ";
			temp= temp -> proximo; // apontar para o proximo valor
			
			}
			cout << endl;
		}
	
	void pilhaValor::imprimeTopo(){
		
		if(pilhaVazia()){
			cout << "Erro: pilha vazia!" << endl;;
			}else{
		
		node* temp = topoPilha;
		cout << "Valor: ";
		cout << temp->valor << " ";
		}
	}
	

int main () {
	
	pilhaValor pV;
	pilhaNome pN;
	pilhaTipo pT;
	
	//cout << " i) Inserir elementos\n r)Remover elemento\n e)Espiar topo\n f)Finalizar o Programa " << endl;
	
	char resposta;
	
	do{
		cin >> resposta;
		if(resposta=='i'){ // adicionar um novo valor
			//cout << "Insira o nome: ";
			string nomeItem;
			cin >> nomeItem;
			pN.empilhaNome(nomeItem);
			
			//cout << "Insira o tipo: ";
			char tipoI;
			cin >> tipoI;
			pT.empilhaTipo(tipoI);
			
			//cout << "Insira o valor: ";
			int valorI;
			cin >> valorI;
			pV.empilha(valorI);
			
			
			}else if(resposta=='r'){ // remover um elemento
				cout << "Nome: " << pN.desempilhaNome() << " ";
				cout << "Tipo: " << pT.desempilhaTipo() << " ";
				cout << "Valor: "<< pV.desempilha() << endl;
				}else if(resposta == 'e'){
					pN.imprimeTopoNome();
					pT.imprimeTopoTipo();
					pV.imprimeTopo();
					}
		
		}while(resposta!='f');
		
		cout << "Pilha resultante: " << endl;
		
		while(! pN.pilhaVaziaNome() and ! pT.pilhaVaziaTipo()and ! pV.pilhaVazia()){
		cout << "Nome: "<<pN.desempilhaNome() << " ";
		cout << "Tipo: "<<pT.desempilhaTipo() << " ";
		cout << "Valor: "<< pV.desempilha() << endl;
		cout << endl;
		}
	
	return 0;
	}
