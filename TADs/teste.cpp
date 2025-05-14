#include <iostream>
using namespace std;

class livro {
private:
    string nome;
    string autor;
    string genero;

public:
    livro();
    void cadastrar(string n, string a, string g);
    void mostrar();
    string retornarNome() { return nome; }
};

livro::livro() {
    nome = "disponivel";
    autor = "-";
    genero = "-";
}

void livro::cadastrar(string n, string a, string g) {
    nome = n;
    autor = a;
    genero = g;
}

void livro::mostrar() {
    cout << "-------------------\n";
    cout << "Nome: " << nome << endl;
    cout << "Autor: " << autor << endl;
    cout << "Gênero: " << genero << endl;
    cout << "-------------------\n";
}

class biblioteca {
private:
    livro *exemplar;
    int capacidade;
    int tamanho;

public:
    biblioteca(int c);
    ~biblioteca();
    bool registrar(string n, string a, string g);
    bool consultar(string n);
};

biblioteca::biblioteca(int c) {
    exemplar = new livro[c];
    capacidade = c;
    tamanho = 0;
}

biblioteca::~biblioteca() {
    delete[] exemplar;
}

bool biblioteca::registrar(string n, string a, string g) {
    if (tamanho < capacidade) {
        exemplar[tamanho].cadastrar(n, a, g);
        tamanho++;
        return true;
    }
    return false;
}

bool biblioteca::consultar(string n) {
    int indice = 0;
    while ((indice < tamanho) && (n != exemplar[indice].retornarNome())) {
        indice++;
    }
    if (indice < tamanho) {
        return exemplar[indice].mostrar();
        
    }
    return false;
}

void menu() {
    cout << "1 - Registrar" << endl
         << "2 - Consultar" << endl
         << "0 - Sair" << endl;
}

int main() {
    int totalLivro, opcao;
    string nome, autor, genero;

    cout << "Digite a capacidade da biblioteca: ";
    cin >> totalLivro;
    biblioteca acervo(totalLivro);

    do {
        menu();
        cin >> opcao;

        if (opcao == 1) {
            cout << "Digite o nome do livro: ";
            cin >> nome; // Lê apenas a primeira palavra
            cout << "Digite o autor do livro: ";
            cin >> autor; // Lê apenas a primeira palavra
            cout << "Digite o gênero do livro: ";
            cin >> genero; // Lê apenas a primeira palavra

            if (!acervo.registrar(nome, autor, genero)) {
                cout << "Biblioteca cheia!" << endl;
            }

        } else if (opcao == 2) {
            cout << "Digite o nome do livro a consultar: ";
            cin >> nome; // Lê apenas a primeira palavra

            if (!acervo.consultar(nome)) {
                cout << "Não encontrado!" << endl;
            }

        } else if (opcao != 0) {
            cout << "Opção inválida!" << endl;
        }

    } while (opcao != 0);
    
    return 0;
}
