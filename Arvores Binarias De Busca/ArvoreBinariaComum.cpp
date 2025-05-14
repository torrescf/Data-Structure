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
		
		void imprimePreOrdem(noh* atual);
		void imprimeEmOrdem(noh* atual);
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

	
void ABB::imprimePreOrdem(noh* atual){
	if(atual != nullptr){
		cout << atual->dado << ", ";
		
		imprimePreOrdem(atual->filhoEsquerda);
		
		imprimePreOrdem(atual->filhoDireita);
		}
	
	
	}

void ABB::imprimeEmOrdem(noh* atual){
	
	
	if(atual != nullptr){
		imprimeEmOrdem(atual->filhoEsquerda);
		
		cout << atual->dado << ", ";
		
		imprimeEmOrdem(atual->filhoDireita);
		}
	}

void ABB::imprimePosOrdem(noh* atual){
	if(atual != nullptr){
		imprimePosOrdem(atual->filhoEsquerda);
		
		imprimePosOrdem(atual->filhoDireita);
		
		cout << atual->dado << ", ";
		
		}
	
	}

void menu();

void mensagemErro();

int main(){
	int resposta;
	int valorDesejado;
	ABB a1;
	
	do{
		menu();
		
		cin >> resposta;
		
		switch(resposta){
			case 1:{ // inserir
				cout << "Valor para insercao: ";
				cin >> valorDesejado;
				a1.insereNaArvore(valorDesejado);
				break;
				}
			case 2:{ // remover
				cout << "Valor para remocao: ";
				cin >> valorDesejado;
				a1.removeNaArvore(valorDesejado);
				break;
				}
			case 3:{// procurar
				cout << "Valor para procura: ";
				cin >> valorDesejado;
				a1.procuraNoh(valorDesejado);
				
				break;
				}
			case 4:{// imprimir
				
				if(a1.arvoreVazia()){
					cout << "Erro: Tentativa de imprimir arvore binaria vazia\n";
					}else{
						int respostaOrdem;
				
						cout << "1) Pre Ordem\n";
						cout << "2) Ordem\n";
						cout << "3) Pos Ordem\n";
						cout << "Resposta: ";
				
						cin >> respostaOrdem;
				
						switch(respostaOrdem){
							case 1:{
								cout << "Impressao em Pre Ordem da Arvore Binaria de Busca:\n" ;
								a1.imprimePreOrdem(a1.obterRaiz());
								break;
								}
							case 2:{
								cout << "Impressao em Ordem da Arvore Binaria de Busca:\n" ;
								a1.imprimeEmOrdem(a1.obterRaiz());
								break;
								}
							case 3:{
								cout << "Impressao em Pos Ordem da Arvore Binaria de Busca:\n" ;
								a1.imprimePosOrdem(a1.obterRaiz());
								break;
								}
						}
					}
				break;
				}
			case 5:{
				cout << "\nFim do programa\n";
				break;
				}
			default:{
				mensagemErro();
				}
			}
		}while(resposta!= 5);
	
	return 0;
	}

void menu(){
	
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	cout << "\nArvore Binaria de Busca\n";
	cout << "\n1) Inserir\n";
	cout << "2) Remover\n";
	cout << "3) Procurar elemento\n";
	cout << "4) Imprimir\n";
	cout << "5) Sair\n";
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	cout << "Resposta: ";
	
	}
	
void mensagemErro(){
	
	cout << "\nErro: opcao fora do intervalo de validade\n";
	}
