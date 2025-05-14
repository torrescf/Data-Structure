#include <iostream>
using namespace std;

class aluno{
	private:
	int matr;
		string nome;
        
	
	public:
		aluno();//construtor padrao 
		aluno(int m, string n); // construtor para as entradas de aluno
		int recebeMatr();
		string recebeNome();
	};
	
	aluno::aluno(){
		matr = -1;
		nome = "zeNinguem";
		}
	
	aluno::aluno(int m, string n){
		matr = m;
		nome = n;
		}
	
	int aluno::recebeMatr(){
		return matr;
		}
	
	string aluno::recebeNome(){
		return nome;
		}
	
class noh{
	friend class lista;
    friend class tabelaH;
	private:
		noh* proximo;
		aluno informacoes;

	public:
		noh(aluno d);

};

noh::noh(aluno d){
	proximo = NULL;
	informacoes = d;
	
}

class lista{
    friend class tabelaH;
	private:
		noh* primeiro;

	public:
		lista();
		~lista();
		void insereLista(aluno dados);//inicio 
		bool removeLista(int matricula);//inicio
		void imprime();
		bool listaVazia();
        aluno* procuraLista(int matricula);

}; 

lista::lista(){
	primeiro = NULL;
	//cout << "Lista construida\n";
}

lista::~lista(){
	noh* temp = primeiro;
	while(temp != NULL){
		noh* aux = temp;
		temp = temp -> proximo;
		delete aux;
	}
}

bool lista::listaVazia(){
	 return (primeiro =NULL);
}

void lista::insereLista(aluno dados){
	noh* novo = new noh(dados);
	novo -> proximo = primeiro;
	primeiro = novo;
	cout << "Aluno inserido na lista\n"; 
}

bool lista::removeLista(int matricula){
	noh* aux= primeiro;
    noh* anterior = NULL;

    while(aux!= NULL and aux->informacoes.recebeMatr() != matricula){
        anterior = aux;
        aux= aux->proximo;
        }
    //achou a matricula desejada
    if(aux == NULL){
        cout << "Erro: matricula nao cadastrada na tabela\n";
		return false;
        }
    if(anterior == NULL){// a matricula desejada eh a primeira
        primeiro = aux->proximo;
    }else{
        anterior->proximo = aux->proximo;
    }
    delete aux;
	return true;
}

void lista::imprime(){
	noh* temp =primeiro;

	while(temp!= NULL){
		cout << "[ "<<temp->informacoes.recebeMatr() << " / " << temp->informacoes.recebeNome() << "] ";
		temp = temp->proximo;
	}
	cout << endl;
}

aluno* lista::procuraLista(int matricula){
	noh* aux = primeiro;

	while(aux !=NULL){
	if(aux->informacoes.recebeMatr() == matricula){
	return &aux->informacoes;

		}
	aux= aux->proximo;

	}
	return NULL;
}

class tabelaH{
	private:
		int funcaoHash(int chave); // transforma a chave em um valor inteiro indicando a posicao, cada chave eh um aluno
		int capacidade; // capacidade maxima de itens que podem ser inseridos na tabela
		lista* tabela;
		
	public:
		tabelaH(int cap);
		~tabelaH();
		void insere(aluno dado);
		void remove(int matricula);
		void imprime();
		void procura(int matricula); // passagem por referencia(tudo que mudar na classe tabelaH, em relacao as variaveis declaradas, tambem vai mudar na main)
		
	};
	
	tabelaH::tabelaH(int cap) {
		capacidade = cap;
		tabela = new lista[cap];
		}
	
	tabelaH::~tabelaH(){
        delete[] tabela;
		}

	int tabelaH::funcaoHash(int chave){ // retornar o modulo da matricula do aluno em relacao ao capacidade da tabela, dando a posicao na tabela(matr%capacidade)
		return (chave % capacidade);
		}
	
    void tabelaH::insere(aluno dado){//usar a funcao hash para achar o local onde o aluno sera inserido na tabela, se nao estiver cheia
		int local= funcaoHash(dado.recebeMatr());
		tabela[local].insereLista(dado);
		}
	
	void tabelaH::remove(int matricula) {
    int local = funcaoHash(matricula);
    if (!tabela[local].removeLista(matricula)) {
        cout << "Erro: Aluno não encontrado.\n";
    }
}
	
	void tabelaH::imprime(){
		cout << "Tabela Hash\n";
		for(int a=0; a<capacidade ; a++){
				cout << a <<"-> ";
				tabela[a].imprime();
			}
		}
	
	void tabelaH::procura(int matricula){
		int local = funcaoHash(matricula);
		aluno* encontrado = tabela[local].procuraLista(matricula);
		if(encontrado != NULL){
			cout << "Encontrado: " << "["<< encontrado->recebeMatr() << "/" << encontrado->recebeNome() << "]"<< endl;
			}else{ 
				cout << "Erro: aluno nao encontrado na tabela\n";
				}
		}



int main (){
	cout << "Capacidade: ";
	int cap;
	cin >> cap;
	
	tabelaH th(cap);
	
	int tamanho=0;
	int resposta;
	
	do{
		cout << "------------------------------------------------\n";
		cout << "1)Inserir \n2)Remover\n3)Procurar\n4)Imprimir\n5)Fim\n";
		cout << "------------------------------------------------\n";
		cout << "Resposta: ";
		cin>> resposta;
		string nome;
		int matricula;
		
		if(resposta == 1){
			cout << "Matricula: ";
			cin >> matricula;
			cout << "Nome: ";
			cin >> nome;
			aluno novo(matricula,nome);
			th.insere(novo);
			tamanho++;
						


		}else if(resposta==2){
			if(tamanho ==0){
				cout << "Erro: tabela hash vazia, impossivel remover dados\n";
				}else{
					cout << "Matricula: ";
					cin >> matricula;
					th.remove(matricula);
					cout  << "				Aluno removido\n";
					tamanho--;
					}
		}else if(resposta==3){
			if(tamanho==0){
				cout << "Erro: tabela hash vazia, impossivel procurar dados\n";
				}else{
					cout << "Matricula: ";
					cin >> matricula;
					th.procura(matricula);
					}
		}else if(resposta==4){
			th.imprime();
		}else if(resposta == 5){
			cout << "Fim do programa\n";
			th.imprime();
		}else{
			cout << "Erro: resposta fora do intervalo de validade\n";
		}
		}while(resposta!=5);
	
	return 0;
	}
