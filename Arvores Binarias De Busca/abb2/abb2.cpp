#include <iostream>
#include <fstream>

using namespace std;

struct aluno{
    int matricula;
    string nome;

};

class noh{
    friend class ABB;
    private:
        noh* direita;
        noh* esquerda;
        aluno informacoes;

    public:
        noh(aluno info);
};

noh::noh(aluno info){ // construtor do noh
    direita = nullptr;
    esquerda = nullptr;
    informacoes = info;

}

class ABB{
    private:
        noh* raiz; //primeiro elemento de uma arvore binaria

    public:
        ABB();
        ~ABB();
        bool arvoreVazia();
        noh* retornaRaiz();

        void insere(aluno info, char& direcao);
        void busca(aluno& info, string& local);

        void procuraRemove(noh*& atual, noh*& pai, bool& direcao, aluno& info);
        void remove(aluno info);

};

ABB::ABB(){ // construtor da arvore binaria de busca
    raiz = nullptr;

}

ABB::~ABB(){}

bool ABB::arvoreVazia(){ //  se a raiz for nula a arvore esta vazia
    return raiz==nullptr;

}

noh* ABB::retornaRaiz(){
    return raiz;

}

void ABB::insere(aluno info, char& direcao){
    noh* novo = new noh(info);

    if(arvoreVazia()){ // insere elemento novo na raiz da arvore
        raiz = novo;
        direcao = 'r';
    }else{ //  insere elemento novo em uma folha
        noh* aux = raiz;
        bool inserido=false;

        while(aux != nullptr and inserido != true){
            if(novo->informacoes.matricula < aux->informacoes.matricula){ // vai para a esquerda da arvore
                if(aux->esquerda == nullptr  and aux->direita == nullptr){ // aux eh uma folha da arvore
                    aux = novo;
                    inserido = true;
                    direcao= 'e';
                    cout << "Elemento inserido na esquerda" << endl<< endl;
                }else{ // aux ainda nao eh uma folha da arvore
                    aux = aux->esquerda;
                }
            }else{ // vai para a direita da arvore
                if(aux->direita == nullptr and aux->esquerda == nullptr){
                    aux = novo;
                    inserido = true;
                    direcao= 'd';
                    cout << "Elemento inserido na direita" << endl<< endl;
                }else{
                    aux = aux->direita;
                }
            }
        }

    }

}
void ABB::busca(aluno& info, string& local){
    noh* aux = raiz;

   	if(arvoreVazia()){
		cout << "\nErro: procurando em uma arvore binaria vazia\n";
		}else{

					while((aux != nullptr) (aux->informacoes.matricula != info.matricula)){
						if(info.matricula < aux->informacoes.matricula){ // aux vai para a esquerda do noh
							aux = aux->esquerda;
							}else if(info.matricula > aux->informacoes.matricula){ // aux vai para a direita do noh
								aux = aux->direita;
								}else { // encontrado
                                    cout << "\nEncontrado\n";
                                }
						}
        }

    if(aux == nullptr){ // matricula nao consta na arvore binaria
        local = "n";
        return;
    }else{
    if(aux == raiz){ // raiz
        local = "r";
    }else if((aux-> esquerda == nullptr) and (aux->direita == nullptr)){ // intermediario com 1 filho
        local = "i1";

    }else if((aux-> esquerda == nullptr) and (aux->direita != nullptr)){ // intermediario com 1 filho
        local = "i1";

    }else if((aux->esquerda != nullptr) and (aux->direita == nullptr)){ // intermediario com 1 filho
        local = "i1";

    }else { // intermediario com 2 filhos
        local = "i2";
    }
    }

}

void ABB::procuraRemove(noh*& a, noh*& p, bool& d, aluno& i){
    if(arvoreVazia()){
        cout << "\nErro: busca em arvore vazia\n";
    }

    noh* aux = raiz;
    bool encontrado = false;

    while((aux!= nullptr) and (encontrado != true)){
        if(i.matricula == aux->informacoes.matricula){ // matricula encontrada
            encontrado = true;
            a = raiz;
        }else if(i.matricula < aux->informacoes.matricula){ // esta para a esquerda do noh aux
            p = aux;
            aux = aux->esquerda;
            d = 'e';
        }else { // esta para a direita do noh aux
            p = aux;
            aux = aux->direita;
            d = 'd';
        }
    }

    if(aux == nullptr){
        i.nome = "?";
        cout << "Elemento [" << i.matricula << ", " << i.nome << "]" << " nao encontrado na arvore\n";
        return;
    }

}

void ABB::remove(aluno info){
    noh* atual;
    noh* pai;
    bool direcao;

    procuraRemove(atual, pai, direcao, info);
    cout << "\nAtual: " << atual->informacoes.matricula << atual->informacoes.nome <<endl;
    cout << "Pai: " << pai->informacoes.matricula << pai->informacoes.nome << endl;
    cout << "Direcao: " << direcao << endl;

}

    


void  menu();

void mensagemErro();

void  carregaDados (ABB& arvore, aluno& dados);

int main (){

    ABB arvore;
    aluno dados;

    carregaDados(arvore, dados);

    int resposta=0;

    do{
        menu();
        cin >> resposta;
        switch(resposta){
            case 1:{ //adicionar dado
                cout << "Matricula: ";
                cin >> dados.matricula;

                cout << "Nome: ";
                cin.ignore();
                getline(cin ,dados.nome);

                char localInserido='?';
                arvore.insere(dados, localInserido); // inserir os dados do usuario na ABB
                
                if(localInserido=='d'){
                    cout << "Elemento [" << dados.matricula << ", " << dados.nome << " ] inserido a direita\n";

                }else if (localInserido=='e'){
                    cout << "Elemento [" << dados.matricula << ", " << dados.nome << " ] inserido a esquerda\n";

                }else{
                    cout << "Elemento [" << dados.matricula << ", " << dados.nome << " ] inserido na raiz\n";

                }
                break;
            }
            case 2:{ // remover dado
                cout << "Matricula a ser removida: ";
                cin >> dados.matricula;
                arvore.remove(dados);

                break;
            }
            case 3:{// buscar 
                cout << "\nMatricula: ";
                cin >> dados.matricula;

                string localBusca;
                arvore.busca(dados, localBusca);
                if(localBusca == "r") {
                    cout << "Elemento [" << dados.matricula << ", " << dados.nome << "]" << " encontrado na raiz\n";
                }else if(localBusca == "i1") {
                    cout << "Elemento [" << dados.matricula << ", " << dados.nome << "]" << " encontrado em um noh intermediario com 1 filho\n";
                }else if(localBusca == "i2") {
                    cout << "Elemento [" << dados.matricula << ", " << dados.nome << "]" << " encontrado em um noh intermediario com 2 filhos\n";
                }else if(localBusca =="f") {
                    cout << "Elemento [" << dados.matricula << ", " << dados.nome << "]" << " encontrado em uma folha\n";
                }else {
                    dados.nome = "?";
                    cout << "Elemento [" << dados.matricula << ", " << dados.nome << "]" << " nao encontrado na arvore\n";
                }
                
                break;
            }
            case 4:{ // fim
                cout << "\nPROGRAMA ENCERRADO\n";
                break;
            }
            default:{
                mensagemErro();
                break;
            }
        }
    }while(resposta!= 4);

    return 0;
}


void  menu(){
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    
	cout << "                                                                                       |\n|";
	cout << " 1) Adicionar Dado                                                                    |\n|";
	cout << " 2) Remover Dado                                                                      |\n|";
	cout << " 3) Procurar um certo Dado                                                            |\n|";
	cout << " 4) Encerrar o Programa                                                               |\n";
	cout << "                                                                                       |\n";
	
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	
	cout << "-> Resposta (1 ate 4): ";

}

void mensagemErro(){
    cout << "\nErro: resposta fora do intervalo de validade, retornando ao comeco do codigo\n";

}

void carregaDados(ABB& a, aluno& d){
    ifstream entrada("dados.csv");
    

    while (entrada){
        entrada >> d.matricula;
        entrada.ignore(2, ',');
        getline (entrada, d.nome, ';');

        cout << d.matricula << ", "<< d.nome << endl;
        char local='n';
        a.insere(d, local);

    }
}