#include <iostream>

using namespace std;

struct aluno{
	string nome;
	string matricula;
	};


class noh{
	friend class listaDE;
	
	private:
		noh* proximo;
		noh* anterior;
		aluno informacoes;
	
	public:
		noh(aluno d);
};


noh::noh(aluno d){
	proximo = nullptr;
	anterior = nullptr;
	informacoes = d;
	}

class listaDE{
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanhoLista;
		
	
	public:
		listaDE();
		~listaDE();
		bool listaVazia();
		
		void insereListaVazia(aluno dados);
		void insereInicioLista(aluno dados);
		void insereFimLista(aluno dados);
		void inserePosicaoDesejadaLista(aluno dados, int posicaoInsercao);
		
		void removeInicioLista();
		void removeFimLista();
		void removePosicaoDesejadaLista(int posicaoRemocao);
		
		void imprime();
		void imprimeReverso();
		void procuraAluno(string matriculaDesejada);
		aluno retornaProximo(int tam);
	
	
};

listaDE::listaDE(){
	primeiro = nullptr;
	ultimo = nullptr;
	tamanhoLista = 0;
}
	
listaDE::~listaDE(){
	while(! listaVazia()){
		removeInicioLista();
		}
	tamanhoLista =0;
}
	
bool listaDE::listaVazia(){
	return (tamanhoLista == 0) or (primeiro==nullptr);
}

void listaDE::insereListaVazia(aluno dados){
	noh* novo = new noh(dados);
	primeiro=novo;
	ultimo=novo;
	tamanhoLista++;
	cout << "\nAluno inserido em uma lista vazia\n";
	
}
void listaDE::insereInicioLista(aluno dados){
	if(listaVazia()){
		insereListaVazia(dados);
		}else{
			noh* novo = new noh(dados);
			
			novo -> proximo = primeiro;
			primeiro -> anterior = novo;
			primeiro = novo;
			
			tamanhoLista++;
			cout << "\nAluno inserido no inicio da lista\n";
			}
}
void listaDE::insereFimLista(aluno dados){
	if(listaVazia()){
		insereListaVazia(dados);
		}else{
			noh* novo = new noh(dados);
			
			novo -> anterior = ultimo;
			ultimo -> proximo = novo;
			ultimo = novo;
			
			tamanhoLista++;
			cout << "\nAluno inserido no fim da lista\n";
			}
}
void listaDE::inserePosicaoDesejadaLista(aluno dados, int posicaoInsercao){
	if(listaVazia()){
		insereListaVazia(dados);
		}else{
			int tamAux=0;
			if(posicaoInsercao == 0){
				insereInicioLista(dados);
				}else if(posicaoInsercao == tamanhoLista){
					insereFimLista(dados);
					}else{
						noh* novo= new noh(dados);
						noh* aux= primeiro;
						while(tamAux!= (posicaoInsercao-1)){
							aux= aux->proximo;
							tamAux++;
							}
							novo -> proximo = aux->proximo;
							novo->anterior=aux;
							aux->proximo->anterior=novo;
							aux -> proximo= novo;
							tamanhoLista++;
						}
			}
}

void listaDE::removeInicioLista(){
	if(listaVazia()){
		cout << "Erro: lista vazia, impossivel remover elemento no inicio da propria\n";
		}else{
			noh* aux = primeiro;
			primeiro = primeiro -> proximo;
			primeiro->anterior= nullptr;
			cout << "\nAluno " << aux->informacoes.nome << " de matricula " << aux->informacoes.matricula << " Removido da lista\n";
			delete aux;
			tamanhoLista--;
			}
	
}

void listaDE::removeFimLista(){
	if(listaVazia()){
		cout << "Erro: lista vazia, impossivel remover elemento no fim da propria\n";
		}else if(tamanhoLista==1){
			delete ultimo;
			primeiro=nullptr;
			ultimo=nullptr;
			tamanhoLista=0;
			
			}else{
				noh* aux = ultimo;
				ultimo = ultimo -> anterior;
				ultimo->proximo = nullptr;
				cout << "\nAluno " << aux->informacoes.nome << " de matricula " << aux->informacoes.matricula << " Removido da lista\n";
				delete aux;
				tamanhoLista--;
				}
	
}

void listaDE::removePosicaoDesejadaLista(int posicaoRemocao){
	if(listaVazia()){
		cout << "Erro: remocao em lista vazia\n";
		}else{
			noh* aux = primeiro;
			int tamAux=0;
			
			while((aux != nullptr) and (tamAux != posicaoRemocao)){
				aux = aux->proximo;
				tamAux++;
				}

			if(aux==nullptr){
				cout << "Erro: posicao fora do intervalo\n";
				}else{
					if(posicaoRemocao==0){
					removeInicioLista();
					}else if(posicaoRemocao==tamanhoLista-1){
						removeFimLista();
						}else{
							noh* aux= primeiro;
							int tamAux=0;
							while(tamAux!= posicaoRemocao-1){
								aux->anterior=aux;
								aux= aux->proximo;
								tamAux++;
								}
								aux->anterior->proximo=aux->proximo;
								ultimo->proximo=NULL;
								delete aux;
								tamanhoLista--;
							}
					}
			}
}

void listaDE::imprime(){
	noh* temp = primeiro;
	while(temp != nullptr){
		cout << "[ " << temp->informacoes.nome << "/" << temp->informacoes.matricula << " ]";
		cout << endl;
		temp = temp -> proximo;
		}
}

void listaDE::imprimeReverso(){
	noh* temp = ultimo;
	while(temp != nullptr){
		cout << "[ " << temp->informacoes.nome << "/" << temp->informacoes.matricula << " ]";
		cout << endl;
		temp =temp -> anterior;
		}
	}

void listaDE::procuraAluno(string matriculaDesejada){
	noh* aux= primeiro;
	int posAux=0;
	
	while((aux!=nullptr) and (aux->informacoes.matricula != matriculaDesejada)){
		aux= aux -> proximo;
		posAux++;
		}
	if(aux==nullptr){
		cout << "Erro: matricula nao encontrada na lista\n";
		}else{
			cout << "Matricula encontrada na posicao " << posAux << " da lista\n";
			cout << "[ " << aux->informacoes.nome << "/" << aux->informacoes.matricula << " ]";
			}
}

aluno listaDE::retornaProximo(int tam){
	
	noh* aux= primeiro;
	int tamAux=0;
	
	while(tamAux != tam){
	aux=aux->proximo;
	tamAux++;
		}
	return aux->informacoes;
	
	}
	

void menu();

int main (){
	listaDE l1;
	aluno info;
	
	int tamanho=0;
	
	int resposta;
	
	do{
		menu();
		cin >> resposta;
		
		switch(resposta){
			case 1:{ // inserirInicio
				cout << "\nNome: ";
				cin >> info.nome;
				cout << "Matricula: ";
				cin >> info.matricula;
				
				l1.insereInicioLista(info);
				tamanho++;
				
				break;
				}
			case 2:{ // inserirFim
				cout << "\nNome: ";
				cin >> info.nome;
				cout << "Matricula: ";
				cin >> info.matricula;
				
				l1.insereFimLista(info);
				tamanho++;
				
				break;
				}
			case 3:{ // inserirPosicaoDesejada
				int posicaoDesejada;
				cout << "\nPosicao: ";
				cin >> posicaoDesejada;
				
				if(posicaoDesejada<=0 or posicaoDesejada>tamanho+1){
					cout << "\nErro: posicao fora do intervalo de validade\n";
					}else{
						cout << "Nome: ";
						cin >> info.nome;
						cout << "Matricula: ";
						cin >> info.matricula;
						
						l1.inserePosicaoDesejadaLista(info, posicaoDesejada-1);
						tamanho++;	
						}
				
				break;
				}
			case 4:{ // RemoverInicio
				if(tamanho==0){
					cout << "\nErro: remocao em lista vazia\n";
					}else{
						l1.removeInicioLista();
						tamanho--;
						}
				
				break;
				}
			case 5:{ // removerFim
				if(tamanho==0){
					cout << "\nErro: remocao em lista vazia\n";
					}else{
						l1.removeFimLista();
						tamanho--;
						}
				
				break;
				}
			case 6:{ // removerPosicaoDesejada
				if(tamanho==0){
					cout << "\nErro: remocao em lista vazia\n";
					}else{
						int posicaoDesejada;
						cout << "\nPosicao: ";
						cin >> posicaoDesejada;
						
						l1.removePosicaoDesejadaLista(posicaoDesejada-1);
						tamanho--;
						}
				break;
				}
			case 7:{ // Procurar por uma matricula
				cout << "Matricula: ";
				cin >> info.matricula;
				
				l1.procuraAluno(info.matricula);
				
				break;
				}
			case 8:{ //Imprimri lista
				if(tamanho==0){
					cout << "\nErro: lista vazia\n"; 
					}else{
						cout << "Lista:\n";
						l1.imprime();
						cout << "Lista Inversa:\n";
						l1.imprimeReverso();
						}
				break;
				}
			case 9:{ // FIM
				cout << "Programa finalizado =)\n";
				cout << "\n				Lista:\n";
				l1.imprime();
				
				break;
				}
			default:{
				cout << "Erro: resposta fora do intervalo\n";
				break;
				}
			}
		
		}while(resposta !=9);
		
	return 0;
	}


void menu(){
	cout << "\n					<Lista Dupla Encadeada>\n";
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "1)Inserir no inicio\n";
	cout << "2)Inserir no fim\n";
	cout << "3)Inserir em uma posicao desejada\n";
	cout << endl;
	cout << "4)Remover no inicio\n";
	cout << "5)Remover no fim\n";
	cout << "6)Remover em uma posicao desejada\n";
	cout << endl;
	cout << "7)Procurar por uma matricula\n";
	cout << "8)Imprimir a lista\n";
	cout << "9)Fim\n";
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Resposta(1 ate 9): ";
	}
