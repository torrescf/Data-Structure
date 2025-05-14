#include <iostream>
using namespace std;

struct noh{
	string dado;
	noh* proximo;
	};

class filaPrioritario{
	private:
		noh* inicioPrioritario; //primeiro valor inserido
		noh* fimPrioritario; // ultimo valor inserido
	
	public:
		filaPrioritario();
		~filaPrioritario();
		void enfileiraPrioritario(string nomeInseridoPrioritario);
		string desenfileiraPrioritario();
		bool filaVaziaPrioritario();
		
	};

	filaPrioritario::filaPrioritario(){
		inicioPrioritario = NULL;
		fimPrioritario = NULL;
		}
	
	filaPrioritario::~filaPrioritario(){
		
		while(! filaVaziaPrioritario()){
			noh* temp= inicioPrioritario;
			inicioPrioritario= inicioPrioritario-> proximo;
			delete temp;
			
			}
			cout << endl << "Fila Desennfileirada com sucesso!" << endl;
		}
	
	
	void filaPrioritario::enfileiraPrioritario(string nomeInseridoPrioritario){
		noh* novoNoh= new noh;
		novoNoh->dado= nomeInseridoPrioritario;
		novoNoh-> proximo= NULL;
		
		if(filaVaziaPrioritario()){
			inicioPrioritario = novoNoh;
			}else{
				fimPrioritario-> proximo= novoNoh;
				}
				fimPrioritario = novoNoh;
		}
	
	
	string filaPrioritario::desenfileiraPrioritario(){
		if(filaVaziaPrioritario()){
			cout << "ERRO, fila vazia!" << endl;
			return 0;
			}else{
				noh* aux = inicioPrioritario;
				string dadoRemovido= aux-> dado;
				inicioPrioritario= inicioPrioritario-> proximo;
				delete aux;
				return dadoRemovido;
				
				}
		}
	
	bool filaPrioritario::filaVaziaPrioritario(){
		return (inicioPrioritario == NULL);
		}





class filaNormal{
	private:
		noh* inicioNormal; //primeiro valor inserido
		noh* fimNormal; // ultimo valor inserido
	
	public:
		filaNormal();
		~filaNormal();
		void enfileiraNormal(string nomeInseridoNormal);
		string desenfileiraNormal();
		bool filaVaziaNormal();
		
	};

	filaNormal::filaNormal(){
		inicioNormal = NULL;
		fimNormal = NULL;
		}
	
	filaNormal::~filaNormal(){
		
		while(! filaVaziaNormal()){
			noh* temp= inicioNormal;
			inicioNormal= inicioNormal-> proximo;
			delete temp;
			
			}
			cout << endl << "Fila Desennfileirada com sucesso!" << endl;
		}
	
	
	void filaNormal::enfileiraNormal(string nomeInseridoNormal){
		noh* novoNoh= new noh;
		novoNoh->dado= nomeInseridoNormal;
		novoNoh-> proximo= NULL;
		
		if(filaVaziaNormal()){
			inicioNormal = novoNoh;
			}else{
				fimNormal-> proximo= novoNoh;
				}
				fimNormal = novoNoh;
		}
	
	
	string filaNormal::desenfileiraNormal(){
		if(filaVaziaNormal()){
			cout << "ERRO, fila vazia!" << endl;
			return 0;
			}else{
				noh* aux = inicioNormal;
				string dadoRemovido= aux-> dado;
				inicioNormal= inicioNormal-> proximo;
				delete aux;
				return dadoRemovido;
				
				}
		}
	
	bool filaNormal::filaVaziaNormal(){
		return (inicioNormal == NULL);
		}

int main () {
	filaNormal fN;
	filaPrioritario fP;
	
	string resposta;
	int contadorClientes=0;
	string fim = "nao";
	while (fim != "sim"){
	do{
		cout << "Atendimento: ";
		cin >> resposta;
		string nome;
		if(resposta == "prioridade"){
			cout << "nome: ";
			cin >> nome;
			fP.enfileiraPrioritario(nome);
			contadorClientes++;
			}else if(resposta == "normal"){
				cout << "nome: ";
				cin >> nome;
				fN.enfileiraNormal(nome);
				contadorClientes++;
				
				}else if (resposta != "normal" and resposta != "prioridade" and resposta != "atender"){
					cout << "Tipo de atendimento invalido " << endl;
					}
		
		}while(resposta != "atender");
		
		cout << "\nQuantas pessoas deseja atender: ";
		int num;
		cin >> num;
		if(num <= contadorClientes){
			if(fN.filaVaziaNormal() and fP.filaVaziaPrioritario()){
				cout << " AGUARDE " << endl;
			}else{
			int contadorAtendimentos = num;
			while(contadorAtendimentos != 0){
				if(! fP.filaVaziaPrioritario()){
					cout << endl << fP.desenfileiraPrioritario() << endl;
					contadorClientes--;
					contadorAtendimentos--;
					}
				if(! fN.filaVaziaNormal() and fP.filaVaziaPrioritario()){
					cout << endl << fN.desenfileiraNormal() << endl;
					contadorClientes--;
					contadorAtendimentos--;
					}
				
				}
			}
			}else{
				cout << "Numero de clientes menor que o desejado" << endl;
				}
				cout << "Deseja continuar? (sim ou nao)"<< endl;
				cin >> fim; 	
	}
	
	return 0;
	}

