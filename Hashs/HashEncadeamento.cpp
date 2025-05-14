#include <iostream>
using namespace std;

class tabelaH{
	friend class noh;
	friend class listaDup;
	private:
		int capacidade;
		int chave;
		listaDup * th;
		int funcaoHash(int c){
			return c % capacidade;
		};  


	public:	
		tabelaH(int c, int key);
		~tabelaH();
		void inserirTH(int c);
		void removerTH(int c);



};

tabelaH::tabelaH(int c, int key){
	capacidade = c;
	chave = key;
	th = new listaDup[capacidade];
	cout << "\nTabela construida\n";

}  		

tabelaH::~tabelaH(){
	delete[] th;
	cout << "\nTabela deletada\n";

}


void tabelaH::inserirTH(int c){
	int local = funcaoHash(c);
	th[local]->insereLista	



}


void tabelaH::removerTH(int c){}

struct aluno{
	int matricula;//chave
	string primeiroNome;

};

class noh{
	friend class listaDup;
	private:
		noh* proximo;
		aluno informacoes;


	public:
		noh(aluno d);

};

noh::noh(aluno d){
	proximo = NULL;
	//anterior = NULL;
	informacoes = d;
	
}

class listaDup{
	private:
		int tamanhoLista;
		noh* primeiro;
		//noh* ultimo;

	public:
		listaDup();
		~listaDup();
		void insereLista(int chave, aluno dados);//inicio 
		void remove();//inicio
		bool listaVazia();
		void imprime();

}; 

listaDup::listaDup(){
	tamanhoLista = 0;
	primeiro = NULL;
	cout << "Lista construida\n";

}

listaDup::~listaDup(){
	noh* temp = primeiro;
	while(! listaVazia()){
		primeiro = primeiro -> proximo;
		delete temp;
	}
} 

bool listaDup::listaVazia(){
	return (tamanhoLista == 0);
	}

void listaDup::insereLista(int chave, aluno dados){
	noh* novo = new noh(dados);
	tabelaH * valor;
	valor->chave = valor;

	if(listaVazia()){
		primeiro = novo;
	}else{
		novo -> proximo = primeiro;
		primeiro = novo; 
	}
	tamanhoLista++;
	cout << "Aluno inserido na lista\n"; 
}

void listaDup::remove(){
	if(listaVazia()){
		cout << "Erro, lista na posicao tal Vazia\n";
	}else{
		noh* aux = primeiro;
		primeiro = primeiro -> proximo;
		delete aux;
	}
}

void listaDup::imprime(){
	noh* temp =primeiro;

	while(temp!= NULL){
		cout << "[ "<<temp->informacoes.matricula << " / " << temp->informacoes.primeiroNome << " ]\n";
		temp = temp->proximo;
	}
	cout << endl;
}

int main(){

	int capacidadeTabela;
	cout << "Capacidade da Tabela Hash:  ";
	cin >> capacidadeTabela;



	return 0;
}
