#include <iostream>
using namespace std;
//representar um objeto da vida real na forma de dados para o computador

class dados{ // permite que apenas os que forem aceitos poderao acessar oq esta privado (diferente de uma struct, que tudo esta publico)
	friend void test(dados f); // indicar que a funcao test pode acessar todos os dados da classe 
	private: //serao colocados os atributos que normalmente pertenceriam a uma struct
	
	int n;
	char c;
	float f;
	string s;
	int *vet;
	
	public: // metodos/funcoes que serao usados para preencher os atributos privados
		bool inicializa();
		bool finaliza();
		float calcula(int x);
		void imprimir();
		
		
	};
	
	bool dados::inicializa(){ // "::" indica o escopo que esta sendo mirado
		n=0;
		c = 'a';
		f=0;
		s="aa";
		vet = new int[10];
		return true;
		}
	
	bool dados::finaliza(){
		delete[] vet;
		return true;
		}
	
	float dados::calcula(int x){
		return x*f;
		}	
	
	void dados::imprimir (){
		cout << n << " ";
		cout << c << " ";
		cout << f << " ";
		cout << s << endl;
		}
	
int main () {
	//existem 2 formas de implementar as funcoes da classe(dentro ou fora dela)
	
	
	
	return 0;
	}
