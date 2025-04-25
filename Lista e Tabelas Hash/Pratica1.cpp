/*
Programa para gerenciar equipes de uma maratona de programação utilizando uma lista encadeada.
Cada equipe possui: Nome, Líder, Linguagem de Programação e Quantidade de Membros.

Comandos disponíveis:
i: Inserir uma nova equipe no início da lista.
h: Inserir uma nova equipe no fim da lista.
m: Inserir uma nova equipe em uma posição específica da lista.
r: Remover a equipe do início da lista.
a: Remover a equipe do fim da lista.
p: Imprimir todas as equipes cadastradas.
s: Buscar uma equipe pelo nome e retornar sua posição.
d: Imprimir as equipes em ordem reversa.
f: Finalizar o programa.

Formato de saída das equipes: (Nome, Líder, Linguagem, QtdMembros).
*/

#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

struct equipe {
    string nomeEquipe;
    string lider;
    string linguagem; 
    int qtdMembros;
};

class noh {
friend class lista;
private:
    equipe elenco;
    noh* proximo;
public:
    noh(equipe d);
};

noh::noh(equipe d) {
    elenco = d;
    proximo = NULL;
}

class lista {
private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
    void removeTodos();
    void imprimeReversoAux(noh* umNoh);
public:
    lista();
    lista(const lista& umaLista);
    ~lista();
    lista& operator=(const lista& umaLista);  
    inline void insere(equipe elenco);
    void insereNoFim(equipe elenco);
    void insereNoInicio(equipe elenco);
    void insereNaPosicao(int posicao, equipe elenco);
    int procura(string valor);
    void imprime();
    void imprimeReverso();
    inline bool vazia();
    void removeNoFim();
    void removeNoInicio();
};

lista::lista() {
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

lista::lista(const lista& umaLista) {
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
    noh* aux = umaLista.primeiro;
    
    while (aux != NULL) {
        insereNoFim(aux->elenco);
        aux = aux->proximo;  
    }
}

lista::~lista() {
    removeTodos();
}    

void lista::removeTodos() {
    while (!vazia()) {
        removeNoInicio();
    }
}

lista& lista::operator=(const lista& umaLista) {
    removeTodos();
    noh* aux = umaLista.primeiro;
    
    while (aux != NULL) {
        insereNoFim(aux->elenco);
        aux = aux->proximo;  
    }
    
    return *this; 
}

void lista::insereNoFim(equipe elenco) {
    noh* novo = new noh(elenco);
    if (vazia()) {
        primeiro = novo;
        ultimo = novo;
    } else {
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

void lista::insereNoInicio(equipe elenco) {
    noh* novo = new noh(elenco);
    if (vazia()) {
        primeiro = novo;
        ultimo = novo;
    } else {
        novo->proximo = primeiro;
        primeiro = novo;
    }
    tamanho++;
}

void lista::insereNaPosicao(int posicao, equipe elenco) {
    if (posicao < 0 || posicao > tamanho) {
        cout << "Posição Inexistente!" << endl;
        return;
    }
    
    if (posicao == 0) {
        insereNoInicio(elenco);
    } else if (posicao == tamanho) {
        insereNoFim(elenco);
    } else {
        noh* novo = new noh(elenco);
        noh* anterior = primeiro;
        
        for (int i = 0; i < posicao - 1; i++) {
            anterior = anterior->proximo;
        }
        
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
        tamanho++;
    }
}

int lista::procura(string valor) {
    if (vazia()) {
        throw runtime_error("Lista vazia!");
    }
    
    noh* atual = primeiro;
    int posicao = 0;
    while (atual != NULL) {
        if (atual->elenco.nomeEquipe == valor) {
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }
    throw runtime_error("Nao encontrado");
}

void lista::imprime() {
    if (vazia()) {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    noh* atual = primeiro;
    while (atual != NULL) {
        cout << "(" << atual->elenco.nomeEquipe << ", " 
             << atual->elenco.lider << ", " 
             << atual->elenco.linguagem << ", " 
             << atual->elenco.qtdMembros << ")" << endl;
        atual = atual->proximo;
    }
}

void lista::imprimeReverso() {
    if (vazia()) {
        cout << "Lista vazia!" << endl;
        return;
    }
    imprimeReversoAux(primeiro);
}

void lista::imprimeReversoAux(noh* umNoh) {
    if (umNoh != NULL) {
        imprimeReversoAux(umNoh->proximo);
        cout << "(" << umNoh->elenco.nomeEquipe << ", " 
             << umNoh->elenco.lider << ", " 
             << umNoh->elenco.linguagem << ", " 
             << umNoh->elenco.qtdMembros << ")" << endl;
    }
}

inline bool lista::vazia() {
    return (primeiro == NULL);
}

void lista::removeNoFim() {
    if (vazia()) {
        cout << "Remoção em lista vazia!" << endl;
        return;
    }
    
    if (primeiro == ultimo) {
        delete primeiro;
        primeiro = NULL;
        ultimo = NULL;
    } else {
        noh* anterior = primeiro;
        while (anterior->proximo != ultimo) {
            anterior = anterior->proximo;
        }
        
        delete ultimo;
        ultimo = anterior;
        ultimo->proximo = NULL;
    }
    tamanho--;
}

void lista::removeNoInicio() {
    if (vazia()) {
        cout << "Remoção em lista vazia!" << endl;
        return;
    }
    
    noh* aux = primeiro;
    primeiro = primeiro->proximo;
    delete aux;
    tamanho--;
    
    if (vazia()) {
        ultimo = NULL;
    }
}

int main() {
    lista minhaLista;
    equipe info;
    char comando;
    int posicao;
    string nomeEquipe;

    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir no início
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoInicio(info);
                    break;
                case 'h': // inserir no fim
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoFim(info);
                    break;             
                case 'm': // inserir na posição
                    cin >> posicao;
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNaPosicao(posicao, info);
                    break;             
                case 's': // buscar
                    cin >> nomeEquipe;
                    cout << minhaLista.procura(nomeEquipe) << endl;
                    break;                    
                case 'r': // remover do início
                    minhaLista.removeNoInicio();
                    break;
                case 'a': // remover do fim
                    minhaLista.removeNoFim();
                    break;                                   
                case 'p': // imprimir
                    minhaLista.imprime();
                    break;
                case 'd': // imprimir reverso (extra)
                    minhaLista.imprimeReverso();
                    break;
                case 'f': // finalizar
                    break;
                default:
                    cerr << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            if (string(e.what()) == "Lista vazia!") {
                cout << "Lista vazia!" << endl;
            } else if (string(e.what()) == "Nao encontrado") {
                cout << "Nao encontrado" << endl;
            } else {
                cout << e.what() << endl;
            }
        }
    } while (comando != 'f');
    
    return 0;
}