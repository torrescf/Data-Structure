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
	
	

class tabelaH{
	friend class aluno;
	
	private:
		int funcaoHash(aluno estudante); // transforma a chave em um valor inteiro indicando a posicao, cada chave eh um aluno
		int tamanhoTH; // itens ques estao na tabela
		int capacidade; // capacidade maxima de itens que podem ser inseridos na tabela
		aluno* estrutura;
		
	public:
		tabelaH(int cap);
		~tabelaH();
		bool tabelaCheia();
		int retornoTamanho();
		void insere(aluno dado);
		void remove(aluno dado);
		void imprime();
		void procura(aluno& dado); // passagem por referencia(tudo que mudar na classe tabelaH, em relacao as variaveis declaradas, tambem vai mudar na main)
		
	};
	
	int tabelaH::funcaoHash(aluno estudante){ // retornar o modulo da matricula do aluno em relacao ao capacidade da tabela, dando a posicao na tabela(matr%capacidade)
		
		return (estudante.recebeMatr() % capacidade);
		
		}
	
	tabelaH::tabelaH(int cap){
		tamanhoTH=0;
		capacidade = cap;
		estrutura = new aluno[cap];
		
		}
	
	tabelaH::~tabelaH(){
		delete[] estrutura;
		
		}
	
	bool tabelaH::tabelaCheia(){
		return (tamanhoTH == capacidade);
		}
	
	int tabelaH::retornoTamanho(){
		return tamanhoTH;
		}
	
	void tabelaH::insere(aluno dado){//usar a funcao hash para achar o local onde o aluno sera inserido na tabela, se nao estiver cheia
		int local= funcaoHash(dado);
		//inserir no "local"
		if(! tabelaCheia()){
		estrutura[local] = dado; // sem colisao
		tamanhoTH++;	
		}else{
			cout << "Erro: Tabela Cheia\n";
			}
		}
	
	void tabelaH::remove(aluno dado){
		int local=funcaoHash(dado);
		if(estrutura[local].recebeMatr()!= -1){
			estrutura[local] = aluno(-1,"zeNinguem");
			tamanhoTH--;
			}else{
				cout << "Erro: Posicao na tabela Hash vazia\n";
				}
		}
	
	void tabelaH::imprime(){
		cout << "Tabela Hash\n";
		for(int a=0; a<capacidade ; a++){
			//if(estrutura[a].recebeMatr() != -1){
				cout << a <<"-> ";
				cout << estrutura[a].recebeMatr() << ", " << estrutura[a].recebeNome() << endl;
				//}
			}
		}
	
	void tabelaH::procura(aluno& dado){
		int local = funcaoHash(dado);
		aluno aux = estrutura[local];
		
		if(dado.recebeMatr() == aux.recebeMatr() ){
			dado = aux;
			cout << "Aluno encontrado na posicao " << local << endl;
			}else{
				cout << "Erro: aluno nao encontrado na tabela\n";
				}
		
		
		}
	

int main (){
	cout << "Capacidade: ";
	int cap;
	cin >> cap;
	
	tabelaH th(cap);
	//aluno info;
	
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
		
		switch(resposta){
			
			case 1:
				if(th.tabelaCheia()){
					cout << "Erro: tabela hash cheia, impossivel adicionar novos dados(tabela sem colisoes)\n";
					}else{
						cout << "Matricula: ";
						cin >> matricula;
						cout << "Nome: ";
						cin >> nome;
						aluno info(matricula,nome);
						th.insere(info);
						cout  << "				Aluno inserido\n";
						tamanho++;
						}
				break;
			
			case 2:
				if(tamanho ==0){
					cout << "Erro: tabela hash vazia, impossivel remover dados(tabela sem colisoes)\n";
					}else{
						cout << "Matricula: ";
						cin >> matricula;
						cout << "Nome: ";
						cin >> nome;
						aluno info(matricula,nome);
						th.remove(info);
						cout  << "				Aluno removido\n";
						tamanho--;
						}
				
				
				break;
			
			case 3:
				if(tamanho==0){
					cout << "Erro: tabela hash vazia, impossivel procurar dados(tabela sem colisoes)\n";
					}else{
						cout << "Matricula: ";
						cin >> matricula;
						//cout << "Nome: ";
						//cin >> nome;
						aluno info(matricula," ");
						th.procura(info);
						
						}
				
				
				break;
			
			case 4:
				th.imprime();
				
				break;
			
			case 5:
				cout << "Fim do programa\n";
				th.imprime();
				break;
			
			default:
				cout << "Opcao invalida \n";
				break;
				
			}
		
		}while(resposta!=5);
	
	return 0;
	}
