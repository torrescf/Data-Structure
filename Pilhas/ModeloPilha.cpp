#include <iostream>
using namespace std;

struct node{//guarda o valor inserido e o endereco do proximo item da pilha
	int valor;
	node* proximo;
	};



class pilha{
	private:
		node* topoPilha; // acessar o topo d pilha pra colocar novos elementos
	
	public:
		pilha(); // construtor
		~pilha(); //destrutor
		void empilha(int numeroInserido);
		int desempilha();
		bool pilhaVazia();
		bool pilhaCheia();
		void imprime();
	
	};
	
	pilha::pilha(){
		topoPilha = NULL;
		}
		
	pilha::~pilha()
	{
		node* temp2;
		while(topoPilha!= NULL){
			temp2 = topoPilha;
			topoPilha= topoPilha->proximo;
			delete temp2;
			}
		
	}	
		
	void pilha::empilha(int numeroInserido)
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
		
	int pilha::desempilha(){
		
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
	
	bool pilha::pilhaVazia(){ // retornara o valor somente se o topo for nulo(nao tiver mais ninguem na pilha)
		return (topoPilha==NULL);
		
		
		}		
	
	bool pilha::pilhaCheia(){ // tentar criar um novo no, se conseguir ira retornar que esta vazio, se nao conseguir ira retornar que esta cheio
		node* novo;
		
		try{
			novo =new node;
			delete novo;
			return false;
			
			}catch(bad_alloc exception){
				return true;
				
				}
		
		}
	
	void pilha::imprime(){
		
		node* temp = topoPilha;
		cout << "Pilha: " << endl;
		while(temp!= NULL){
			cout << temp->valor << " ";
			temp= temp -> proximo; // apontar para o proximo valor
			
			}
			cout << endl;
		}
	

int main () {
	
	pilha p1;
	
	cout << " i) Inserir elementos\n r)Remover elemento\n f)Finalizar o Programa " << endl;
	
	char resposta;
	
	do{
		cin >> resposta;
		if(resposta=='i'){ // adicionar um novo valor
			cout << "Insira o valor: ";
			int numero;
			cin >> numero;
			p1.empilha(numero);
			
			
			}else if(resposta=='r'){ // remover um elemento
				cout << p1.desempilha()<< endl;
				}
			
		
		
		}while(resposta!='f');
	
	p1.imprime();
	
	
	return 0;
	}
