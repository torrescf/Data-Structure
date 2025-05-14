#include <iostream>
using namespace std;
//possuem apenas esquerda ou direita
/*
 * 
 * 
 * 						A			0
 * 					  /   \
 * 					 B     C		1
 * 					/ \   / \
 * 				   D   E F   G		2
 * 
 * A -> Raiz
 * B,C -> Nohs intermediarios
 * D, E, F, G-> Folhas
 * Altura total da arvore = 2
 * */
// ponteiros para esquerda e direita

class noh{
	friend class ABB;
	private:
		noh* filhoEsquerda;
		noh* filhoDireita;
		int dado;
		
	public:
		noh(int d);
		
		
	};
	
noh::noh(int d){
	
	dado = d;
	filhoEsquerda = nullptr;
	filhoDireita = nullptr;
	
	}

class ABB{ // ABB ou BST
	private:
		noh* raiz; // primeiro
		
	public:
		ABB();
		~ABB();
		void deletarArvore(noh* auxAtual);
		noh* obterRaiz();
		
		bool arvoreCheia();
		bool arvoreVazia();
		
		void insereNaArvore(int valor);
		void removeNaArvore(int valorRemocao);
		void acharSucessor(int& numSucessor,noh* temp);
		void removeBusca(int numeroDesejado, noh*& atual);
		void deletarNoh(noh*& atual);
		void procuraNoh(int valor);
		
		void imprimePreOrdem(noh* atual, int nivel);
		void imprimeEmOrdem(noh* atual, int nivel);
		void imprimePosOrdem(noh* atual);
		
	};
	
ABB::ABB(){
	raiz = nullptr;
	
	}

ABB::~ABB(){
	deletarArvore(raiz);
	
	}

void ABB::deletarArvore(noh* auxAtual){
	if(auxAtual != nullptr){
		deletarArvore(auxAtual->filhoEsquerda);
		deletarArvore(auxAtual->filhoDireita);
		
		delete auxAtual;
		
		}
	
	}

noh* ABB::obterRaiz(){
	return raiz;
	}
/*
bool ABB::arvoreCheia(){
	
	try{
		noh* temp = new noh;
		delete temp;
		return false;// ainda nao estao cheio, pois foi possivel criar um novo noh
		
		}catch(bad_alloc exception){
			return true; // nao foi possivel criar um novo noh, entao esta cheia a arvore
			}
	
	}
	*/
bool ABB::arvoreVazia(){
	return (raiz == nullptr);
	}

void ABB::insereNaArvore(int valor){
	noh* novo = new noh(valor);
	bool elementoInserido = false;
	
	novo -> filhoDireita = nullptr;
	novo -> filhoEsquerda = nullptr;
	
	if(arvoreVazia()){
		raiz = novo;
		cout << "\nElemento inserido na raiz\n";
		}else{
			noh* aux = raiz;
			while(aux != nullptr and elementoInserido== false){
				if(valor < aux->dado){// ir para a esquerda do noh
					if(aux->filhoEsquerda == nullptr){
						aux->filhoEsquerda = novo;
						elementoInserido = true;
						cout << "\nElemento inserido na esquerda\n";
						}else{
							aux = aux->filhoEsquerda;
							}
					}else{ // ir para a direita do noh
						if(aux->filhoDireita == nullptr){
							aux->filhoDireita = novo;
							elementoInserido = true;
							cout << "\nElemento inserido na direita\n";
							}else{
								aux = aux->filhoDireita;
								}
						}
				}
			}
	}
	
void ABB::removeNaArvore(int valorRemocao){
	if(arvoreVazia()){
		cout << "\nErro: removendo em uma arvore binaria vazia\n";
		}else{
			removeBusca(valorRemocao, raiz);
			}
	}
	
void ABB::removeBusca(int numeroDesejado, noh*& atual){
	
	if(atual== nullptr){
		cout << "Erro: elemento nao encontrado na arvore\n";
		}else{
	
			if(atual->dado > numeroDesejado){
			removeBusca(numeroDesejado, atual->filhoEsquerda);
			
			}else if(atual->dado < numeroDesejado){
			removeBusca(numeroDesejado, atual->filhoDireita);
			
			}else{// numero achado
				deletarNoh(atual);
				}
		}
	}
	
void ABB::deletarNoh(noh*& aux){
	noh* temp = aux;
	if(aux->filhoEsquerda == nullptr){// funciona tanto para noh sem filhos como c 1 filho
		aux = aux -> filhoDireita;
		delete temp;
		
	}else if(aux->filhoDireita == nullptr){
		aux = aux->filhoEsquerda;
		delete temp;
		
	}else{// nenhum dos 2 filhos serao nulos(remocao de um noh com 2 filhos)
		int numSucessor;
		
		acharSucessor(numSucessor, aux);
		aux->dado = numSucessor;
		
		removeBusca(numSucessor, aux->filhoDireita);//remover o sucessor do local de origem dele
		//como o sucessor nunca vai ter 2 filhos, ele vai ser deletado nas 2 primeiras funcoes de deletarNoh
		}
	}
	
void ABB::acharSucessor(int& numSucessor,noh* temp){
	
	temp= temp->filhoDireita;
	while(temp->filhoEsquerda != nullptr){
		temp =temp->filhoDireita;
		}
		
	numSucessor = temp->dado;
	}


void ABB::procuraNoh(int valor){
	if(arvoreVazia()){
		cout << "\nErro: procurando em uma arvore binaria vazia\n";
		}else{
			if(valor == raiz->dado){
				cout << "\nValor " << valor <<" encontrado na raiz\n";
				}else{
					noh* aux = raiz;
					
					while((aux != nullptr) and (aux->dado != valor)){
						if(valor < aux->dado){ // aux vai para a esquerda do noh
							aux = aux->filhoEsquerda;
							}else{ // aux vai para a direita do noh
								aux = aux->filhoDireita;
								}
						}
					if(aux == nullptr){
						cout << "\nErro: valor nao encontrado na arvore binaria\n";
						}else{
							if(aux->filhoDireita == nullptr and aux->filhoEsquerda == nullptr){// elemento esta em uma folha da arvore
								cout << "\nValor " << valor << " encontrado em uma folha da arvore\n";
								}else{
									cout << "\nValor " << valor << " encontrado em um noh intermediario da arvore\n";
									}
							}
					}
			}
	}

	
void ABB::imprimePreOrdem(noh* atual, int nivel){
	if(atual != nullptr){
		cout << atual->dado << "/" << nivel <<  " ";
		
		imprimePreOrdem(atual->filhoEsquerda, nivel+1);
		
		imprimePreOrdem(atual->filhoDireita, nivel+1);
		}
	
	
	}

void ABB::imprimeEmOrdem(noh* atual, int nivel){
	
	if(atual != nullptr){
		imprimeEmOrdem(atual->filhoEsquerda, nivel+1);
		
		cout << atual->dado << "/" << nivel << " ";
		
		imprimeEmOrdem(atual->filhoDireita, nivel+1);
		}
	}

void menu();

void mensagemErro();

int main(){
	char resposta;
	int valorDesejado;
	ABB a1;
	
	do{
		menu();
		
		cin >> resposta;
		
		switch(resposta){
			case 'i':{ // inserir
				cout << "Valor para insercao: ";
				cin >> valorDesejado;
				a1.insereNaArvore(valorDesejado);
				break;
				}
			case'r':{ // remover
				cout << "Valor para remocao: ";
				cin >> valorDesejado;
				a1.removeNaArvore(valorDesejado);
				break;
				}
			case 'o':{// imprimir em ordem
				cout << "Arvore em Ordem:\n";
				a1.imprimeEmOrdem(a1.obterRaiz(),0);
				break;
				}
			case 'p':{// imprimir em Pre Ordem
				cout << "Arvore em Pre Ordem:\n";
				a1.imprimePreOrdem(a1.obterRaiz(),0);
				break;
				}
			case 'f':{// finalizar programa
				cout << "Programa Finalizado\n";
				break;
				}
			default:{
				mensagemErro();
				}
			}
		}while(resposta!= 4);
	
	return 0;
	}

void menu(){
	
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	cout << "\nArvore Binaria de Busca\n";
	cout << "\ni) Inserir\n";
	cout << "r) Remover\n";
	cout << "o) Imprimir em Ordem\n";
	cout << "p) Imprimr em Pre Ordem\n";
	cout << "f) Sair\n";
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	cout << "Resposta: ";
	
	}
	
void mensagemErro(){
	
	cout << "\nErro: opcao fora do intervalo de validade\n";
	}
