#include <iostream>

using namespace std;

struct usuario{
	char id;
	string nomeAcao;
	int tempoExec;
	int tempoConsumido;
	};


class noh{
	friend class listaDE;
	
	private:
		noh* proximo;
		noh* anterior;
		usuario informacoes;
	
	public:
		noh(usuario d);
};


noh::noh(usuario d){
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
		
		void insereListaVazia(usuario dados);
		void insereInicioLista(usuario dados);
		void insereFimLista(usuario dados);
		void inserePosicaoDesejadaLista(usuario dados, int posicaoInsercao);
		
		void removeInicioLista();
		void removeFimLista();
		void removePosicaoDesejadaLista(int posicaoRemocao);
		
		void imprime();
		void imprimeReverso();
		void procuraAcao(string nomeDesejado);
		void removeIdDesejado(int idDesejado);
		void removeNomeDesejado(string nomeDesejado);
		void removerMaiorTE();
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

void listaDE::insereListaVazia(usuario dados){
	noh* novo = new noh(dados);
	primeiro=novo;
	ultimo=novo;
	tamanhoLista++;
	cout << "\n acao inserido em uma lista vazia\n";
	
}
void listaDE::insereInicioLista(usuario dados){
	if(listaVazia()){
		insereListaVazia(dados);
		}else{
			noh* novo = new noh(dados);
			
			novo -> proximo = primeiro;
			primeiro -> anterior = novo;
			primeiro = novo;
			
			tamanhoLista++;
			cout << "\nAcao inserido no inicio da lista\n";
			}
}
void listaDE::insereFimLista(usuario dados){
	if(listaVazia()){
		insereListaVazia(dados);
		}else{
			noh* novo = new noh(dados);
			
			novo -> anterior = ultimo;
			ultimo -> proximo = novo;
			ultimo = novo;
			
			tamanhoLista++;
			cout << "\nAcao inserido no fim da lista\n";
			}
}
void listaDE::inserePosicaoDesejadaLista(usuario dados, int posicaoInsercao){
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
							novo -> anterior=aux;
							aux -> proximo->anterior=novo;
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
			cout <<" Removido da lista no inicio\n";
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
				cout <<" Removido da lista no fim\n";
				delete aux;
				tamanhoLista--;
				}
	
}

void listaDE::removePosicaoDesejadaLista(int posicaoRemocao){
	if(listaVazia()){
		cout << "Erro: remocao em lista vazia\n";
		}else{
			noh* aux = primeiro;
			
			for(int i=0 ; i<posicaoRemocao ; i++){
				aux = aux->proximo;
				}

			if (aux->anterior != nullptr) {
				aux->anterior->proximo = aux->proximo;
				} else { // Se o nó é o primeiro
					primeiro = aux->proximo;
					}

			if (aux->proximo != nullptr) {
				aux->proximo->anterior = aux->anterior;
				} else { // Se o nó é o último
					ultimo = aux->anterior;
					}

			cout << endl << "[ "<<  aux->informacoes.id << "/" << aux->informacoes.nomeAcao << "/" << aux->informacoes.tempoExec << "/" << aux->informacoes.tempoConsumido << "]" << endl;
			delete aux;
			tamanhoLista--;
			}
}

void listaDE::removeNomeDesejado(string nomeDesejado){
	noh* aux= primeiro;
	int posAux=0;
	
	while((aux!=nullptr) and (aux->informacoes.nomeAcao != nomeDesejado)){
		aux= aux -> proximo;
		posAux++;
		}
	if(aux==nullptr){
		cout << "\nErro: nome nao encontrada na lista\n";
		}else{
			removePosicaoDesejadaLista(posAux);
			}
	}

void listaDE::removeIdDesejado(int idDesejado){
	cout << tamanhoLista << endl;
	noh* aux= primeiro;
	int posAux=0;
	
	while((aux!=nullptr) and (aux->informacoes.id != idDesejado)){
		aux= aux -> proximo;
		posAux++;
		}
	if(aux==nullptr){
		cout << "\nErro: nome nao encontrada na lista\n";
		}else{
			removePosicaoDesejadaLista(posAux);
			cout << tamanhoLista << endl;
			}
	
	}

void listaDE::removerMaiorTE(){
	

	int maiorTE=0;
	noh* aux = primeiro;

	for(int i=0; i<tamanhoLista ; i++){
		if(aux->informacoes.tempoExec > maiorTE){
			maiorTE = aux->informacoes.tempoExec;
			}

		}
	
	int posAux=0;
	aux=primeiro;
	while(aux->informacoes.tempoExec != maiorTE){
		aux= aux->proximo;
		posAux++;
	}

	removePosicaoDesejadaLista(posAux);

}	

void listaDE::imprime(){
	noh* temp = primeiro;
	while(temp != nullptr){
		cout << "[ " << temp->informacoes.id << "/" << temp->informacoes.nomeAcao << "/" << temp->informacoes.tempoExec << "/" << temp->informacoes.tempoConsumido <<" ]";
		cout << endl;
		temp = temp -> proximo;
		}
}

void listaDE::imprimeReverso(){
	noh* temp = ultimo;
	while(temp != nullptr){
		cout << "[ " << temp->informacoes.id << "/" << temp->informacoes.nomeAcao << "/" << temp->informacoes.tempoExec << "/" << temp->informacoes.tempoConsumido <<" ]";
		cout << endl;
		temp = temp -> anterior;
		}
	}

void listaDE::procuraAcao(string nomeDesejado){
	noh* aux= primeiro;
	int posAux=0;
	
	while((aux!=nullptr) and (aux->informacoes.nomeAcao != nomeDesejado)){
		aux= aux -> proximo;
		posAux++;
		}
	if(aux==nullptr){
		cout << "\nErro: nome nao encontrada na lista\n";
		}else{
			cout << "\nNome encontrada na posicao " << posAux << " da lista\n";
			cout << "[ " << aux->informacoes.id << "/" << aux->informacoes.nomeAcao << "/" << aux->informacoes.tempoExec << "/" << aux->informacoes.tempoConsumido <<" ]";
			}
}
	

void menu();

int main (){
	listaDE l1;
	usuario info;
	
	int tamanho=0;
	
	char resposta;
	
	do{
		menu();
		cin >> resposta;
		
		switch(resposta){
			case 'i':{ // inserirInicio
				cout << "\nIdentificacao: ";
				cin >> info.id;
				cout << "Nome da acao: ";
				cin >> info.nomeAcao;
				cout << "Tempo de execucao: ";
				cin >> info.tempoExec;
				cout << "Tempo consumido: ";
				cin >> info.tempoConsumido;
				
				l1.insereInicioLista(info);
				tamanho++;
				
				break;
				}
			case 'h':{ // inserirFim
				cout << "\nIdentificacao: ";
				cin >> info.id;
				cout << "Nome da acao: ";
				cin >> info.nomeAcao;
				cout << "Tempo de execucao: ";
				cin >> info.tempoExec;
				cout << "Tempo consumido: ";
				cin >> info.tempoConsumido;
				
				l1.insereFimLista(info);
				tamanho++;
				
				break;
				}
			case 'm':{ // inserirPosicaoDesejada
				int posicaoDesejada;
				cout << "\nPosicao: ";
				cin >> posicaoDesejada;
				
				if(posicaoDesejada<=0 or posicaoDesejada>tamanho+1){
					cout << "\nErro: posicao fora do intervalo de validade\n";
					}else{
						cout << "\nIdentificacao: ";
						cin >> info.id;
						cout << "Nome da acao: ";
						cin >> info.nomeAcao;
						cout << "Tempo de execucao: ";
						cin >> info.tempoExec;
						cout << "Tempo consumido: ";
						cin >> info.tempoConsumido;
						
						l1.inserePosicaoDesejadaLista(info, posicaoDesejada);
						tamanho++;
						}
				
				break;
				}
			case 'r':{ // RemoverInicio
				if(tamanho==0){
					cout << "\nErro: remocao em lista vazia\n";
					}else{
						l1.removeInicioLista();
						tamanho--;
						}
				
				break;
				}
			case 'a':{ // removerFim
				if(tamanho==0){
					cout << "\nErro: remocao em lista vazia\n";
					}else{
						l1.removeFimLista();
						tamanho--;
						}
				
				break;
				}
			case '?':{ // removerPosicaoDesejada
				if(tamanho==0){
					cout << "\nErro: remocao em lista vazia\n";
					}else{
						int posicaoDesejada;
						cout << "\nPosicao: ";
						cin >> posicaoDesejada;
						
						l1.removePosicaoDesejadaLista(posicaoDesejada);
						tamanho--;
						}
				break;
				}
			case 'x':{ // remover um nome especifico
				if(tamanho==0){
					cout << "\nErro: remocao em lista vazia\n";
					//cout << " Remoção em lista vazia!" << endl;
					}else{
						cout << "Nome da acao: ";
						cin >> info.nomeAcao;
						l1.removeNomeDesejado(info.nomeAcao);
						tamanho--;
						}
				break;
				}
			case 'w':{ // remover por um id
				if(tamanho==0){
					cout << "\nErro: remocao em lista vazia\n";
					//cout << " Remoção em lista vazia!" << endl;
					}else{
						cout << "Id: ";
						cin >> info.id;
						
						l1.removeIdDesejado(info.id);
						tamanho--;
						}
				break;
				}
			case 't':{
				if(tamanho==0){
					cout << "\nErro: remocao em lista vazia\n";
				}else{
					l1.removerMaiorTE();
					tamanho--;
				}
				break;
			}
			case 's':{ // Procurar pelo nome
				cout << "Nome da acao: ";
				cin >> info.nomeAcao;
				
				l1.procuraAcao(info.nomeAcao);
				
				break;
				}
			case 'p':{ //Imprimri lista
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
			case 'f':{ // FIM
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
		
		}while(resposta !='f');
		
	return 0;
	}


void menu(){
	cout << "\n					<Lista Dupla Encadeada>\n";
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "i)Inserir no inicio\n";
	cout << "h)Inserir no fim\n";
	cout << "m)Inserir em uma posicao desejada\n";
	cout << endl;
	cout << "r)Remover no inicio\n";
	cout << "a)Remover no fim\n";
	cout << "?)Remover em uma posicao desejada\n";
	cout << "x)Remover um nome especifico\n";
	cout << "w)Remover um id especifico\n";
	cout << "t)Remover acao com maior tempo de execucao\n";
	cout << endl;
	cout << "s)Procurar por acao pelo nome\n";
	cout << "p)Imprimir a lista\n";
	cout << "f)Fim\n";
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Resposta: ";
	}

