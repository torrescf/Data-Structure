#include <iostream>
#include <fstream>

using namespace std;

struct data{
    int num;
    string nome;

};

class noh{
    friend class ABB;
    private:
        noh* filhoDireita;
        noh* filhoEsquerda;
        data d;

    public:
        noh(data dados);
};

noh::noh(data dados){
    d = dados;
    filhoDireita = nullptr;
    filhoEsquerda = nullptr;

}

class ABB {
    private:
        noh* raiz;

    public:
        ABB();
        ~ABB();

        void insere(data info, string& lI);
        string busca(data infoBusca); // nome e num
        void remove(data infoRemocao);
        void removeBusca(data& infoBuscaRemove, noh*& pai, noh*& novoNoh);
        

        void imprimePreOrdem();
        void imprimeOrdem();
        void imprimePosOrdem();

        bool raizNula();
        noh* retornaRaiz();


};


ABB::ABB(){
    raiz= nullptr;

}

ABB::~ABB(){

}

bool ABB::raizNula(){
    return(raiz == nullptr);

}

noh* ABB::retornaRaiz(){
    return raiz;

}

void ABB::insere(data info, string& lI){
    noh* novo = new noh(info);
    bool elementoInserido = false;

    novo->filhoDireita = nullptr;
    novo->filhoEsquerda = nullptr;
    
    if(raizNula()){ // insere na raiz
        raiz = novo;
        lI= "raiz";

    }else{ // insere em uma folha ou noh com 1/2 filhos
        noh* aux= raiz;

        while((aux != nullptr) and (elementoInserido!=true)){
            if(novo->d.num > aux->d.num){ // vai para a direita
                if(aux->filhoDireita == nullptr){ // inserir
                    aux->filhoDireita  = novo;
                    elementoInserido = true;
                    lI="direita";

                    //cout << "Elemento [" << novo->d.num << ", " << novo->d.nome << " ] inserido a direita\n";
            }else{
                aux = aux->filhoDireita;
            }
                
            }else{ // vai para a esquerda
                if(aux->filhoEsquerda == nullptr){ // inserir
                    aux->filhoEsquerda = novo;
                    elementoInserido = true;
                    //cout << "Elemento [" << novo->d.num << ", " << novo->d.nome << " ] inserido a esquerda\n";
                    lI="esquerda";
                }else{
                aux = aux->filhoEsquerda;
                }
                
            }
        }
    }
}

string ABB::busca (data infoBusca){
    if(raizNula()){
        cout << "\nErro: nao ha numeros na arvore\n";
    }else{
        noh* novo = new noh(infoBusca);
        noh* aux= raiz;

        if(novo->d.num == raiz->d.num){
            return("raiz");
        }else{
            while(aux != nullptr and aux->d.num != novo->d.num){
                if(novo->d.num > aux->d.num){ // vai para a direita
                    if(novo->d.num == aux->d.num){
                        novo = aux;
                    }else{
                        aux = aux->filhoDireita;
                    }

                }else{
                    if(novo->d.num == aux->d.num){
                        novo = aux;
                    }else{
                        aux = aux->filhoEsquerda;
                    }
                }
            }
            if(aux == nullptr){
                return ("nao");
            }else if(aux->filhoEsquerda == nullptr and aux->filhoDireita == nullptr){
                return("folha");
            }else{
                return("intermediario");
            }
        }
    }
	return 0;
}

void ABB::removeBusca(data& infoBuscaRemove, noh*& pai, noh*& novoNoh){
    if(raizNula()){
        cout << "\nErro: nao ha numeros na arvore\n";
    }else{
        noh* novo = new noh(infoBuscaRemove);
        noh* aux= raiz;

        if(novo->d.num == raiz->d.num){ // raiz
            pai = nullptr;

        }else{
            while(aux != nullptr and aux->d.num != novo->d.num){
                if(novo->d.num > aux->d.num){ // vai para a direita
                    if(novo->d.num == aux->d.num){
                        novo = aux;
                        novoNoh= aux;
                    }else{
                        pai = aux;
                        aux = aux->filhoDireita;

                    }

                }else{
                    if(novo->d.num == aux->d.num){
                        novo = aux;
                    }else{
                        pai = aux;
                        aux = aux->filhoEsquerda;

                    }
                }
            }
        }
        infoBuscaRemove.num = aux->d.num;
        infoBuscaRemove.nome = aux->d.nome;
        //infoBuscaRemove = aux->d;
    }
}

void ABB::remove(data infoRemocao){
    noh* pai;
    noh* novo;
    removeBusca(infoRemocao, pai, novo);

    cout << infoRemocao.num << " " << infoRemocao.nome << endl;
    cout << pai->d.num << " " << pai->d.nome << endl;

    if(novo->filhoDireita == nullptr and novo->filhoEsquerda == nullptr){ // folha
        cout << "Folha" << endl;

    }else if(novo->filhoDireita != nullptr and novo->filhoEsquerda == nullptr){ // intermediario 1 filho
        cout << "Intermediario esquerda = null" << endl;
    }else if(novo->filhoDireita == nullptr and novo->filhoEsquerda != nullptr){ // intermediario 1 filho
        cout << "Intermediario direita = null" << endl;

    }else{ // intermediario 2 filhos
        cout << "Intermediario com 2 filhos/ raiz" << endl;
    }
}

void  menu();

void mensagemErro();

void carregaDados(ABB& a, data& d);

int main (){
	
	ABB arvore;
    data dados;

    carregaDados(arvore, dados);

    int resposta=0;

    do{
        menu();
        cin >> resposta;
        switch(resposta){
            case 1:{ //adicionar dado
                cout << "Numero: ";
                cin >> dados.num;
                cout << "Nome: ";
                cin.ignore();
                getline(cin ,dados.nome);
                string localInserido="null";
                arvore.insere(dados, localInserido);
                
                if(localInserido=="direita"){
                    cout << "Elemento [" << dados.num << ", " << dados.nome << " ] inserido a direita\n";
                }else if (localInserido=="esquerda"){
                    cout << "Elemento [" << dados.num << ", " << dados.nome << " ] inserido a esquerda\n";
                }else{
                    cout << "Elemento [" << dados.num << ", " << dados.nome << " ] inserido na raiz\n";
                }
                break;
            }
            case 2:{ // remover dado
                cout << "Numero a ser removido: ";
                cin >> dados.num;
                arvore.remove(dados);

                break;
            }
            case 3:{// buscar 
                cout << "\nNumero: ";
                cin >> dados.num;

                string localRemocao = arvore.busca(dados);
                if(localRemocao == "raiz"){
                    cout << "Elemento [" << dados.num << ", " << dados.nome << "]" << " encontrado na raiz\n";
                }else if(localRemocao == "intermediario"){
                    cout << "Elemento [" << dados.num << ", " << dados.nome << "]" << " encontrado em um noh intermediario\n";
                }else if(localRemocao =="folha"){
                    cout << "Elemento [" << dados.num << ", " << dados.nome << "]" << " encontrado em uma folha\n";
                }else {
                    cout << "Elemento [" << dados.num << ", " << dados.nome << "]" << " encontrado nao encontrado na arvore\n";
                }
                
                break;
            }
            case 4:{ // fim
                cout << "\nPrograma encerrado\n";
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

void carregaDados(ABB& a, data& d){
    ifstream entrada("dados.csv");
    string local="nulo";

    while (entrada){
        entrada >> d.num;
        getline (entrada, d.nome, ';');
        cout << d.num << d.nome << endl;
        a.insere(d, local);
    }
}