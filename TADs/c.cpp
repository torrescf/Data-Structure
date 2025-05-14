#include <iostream>
using namespace std;
//questao 7 - TADs

class Documento{
	friend class Biblioteca;
	
	private: 
		string nomeMusica;
		string nomeCompositor;
		string estilo;
		string tipoDocumento;
		
	
	public:
		Documento();
		void CadastrarDocumento(string nM,string nC, string e, string tD); // preencher os dados
		void imprimirDocumento();
		void alterarDados();
		
	
	};

class Biblioteca{
	
	
	};

int main () {
	
	
	
	return 0;
	}
