#include <iostream>
using namespace std;

struct noh{
	string dadoNome;
	string dadoPremio;
	char dadoTipo;
	int dadoTempo;
	
	noh* proximoValor;
	
	};

class filaPremio{
	private:
		noh* fimFilaPremio;
		noh* inicioFilaPremio;
	
	public:
		filaPremio();
		~filaPremio();
		void enfileiraPremio(string valorInseridoPremio);
		string desenfileiraPremio();
		bool vazioPremio();
		void imprimePremio();
		void imprimeInicioPremio();
		
		
	};

	filaPremio::filaPremio(){
		fimFilaPremio = NULL;
		inicioFilaPremio= NULL;
		}
		
	filaPremio::~filaPremio(){
		{
		noh* temp2;
		while(inicioFilaPremio!= NULL){
			temp2 = inicioFilaPremio;
			inicioFilaPremio= inicioFilaPremio->proximoValor;
			delete temp2;
			}
		
	}	
		
		}
	
	void filaPremio::enfileiraPremio(string valorInseridoPremio){
				noh* novoNoh = new noh;
				novoNoh->dadoPremio = valorInseridoPremio;
				novoNoh->proximoValor = NULL;
				
				if(! vazioPremio()){ // nao ha nenhum valor na fila
					fimFilaPremio -> proximoValor = novoNoh;
				}else if(vazioPremio()){
					inicioFilaPremio = novoNoh;
					}	
					fimFilaPremio = novoNoh;
		}		
	
	string filaPremio::desenfileiraPremio(){
		if(vazioPremio()){
			cout << "Erro: fila vazia!" << endl;
			return 0;
			}else{
				noh* aux = inicioFilaPremio;
				string dadoRemovido = inicioFilaPremio -> dadoPremio;
				inicioFilaPremio= inicioFilaPremio -> proximoValor;
				
				if (inicioFilaPremio == NULL) {
					fimFilaPremio = NULL;
					}
				
				delete aux;
				return dadoRemovido;
				
				}
		}
	
	bool filaPremio::vazioPremio(){
		return (inicioFilaPremio == NULL);
		}
	
	void filaPremio::imprimePremio(){
		noh* temporario = inicioFilaPremio;
		cout << endl << "Fila: " << endl;
		while(temporario != NULL){
			cout << temporario-> dadoPremio << " ";
			temporario = temporario -> proximoValor;
			
			}
		cout << endl;
		}
		
	void filaPremio::imprimeInicioPremio(){
		   if (!vazioPremio()) {
				cout << "Premio: " << inicioFilaPremio->dadoPremio << endl;
			} else {
				cout << "Erro: fila vazia!" << endl;
				}
		}	
	
	
class filaTipo{
	private:
		noh* fimFilaTipo;
		noh* inicioFilaTipo;
	
	public:
		filaTipo();
		~filaTipo();
		void enfileiraTipo(char valorInseridoTipo);
		int desenfileiraTipo();
		bool vazioTipo();
		void imprimeTipo();
		void imprimeInicioTipo();
		
		
	};

	filaTipo::filaTipo(){
		fimFilaTipo = NULL;
		inicioFilaTipo= NULL;
		}
		
	filaTipo::~filaTipo(){
		{
		noh* temp2;
		while(inicioFilaTipo!= NULL){
			temp2 = inicioFilaTipo;
			inicioFilaTipo= inicioFilaTipo->proximoValor;
			delete temp2;
			}
		
	}	
		
		}
	
	void filaTipo::enfileiraTipo(char valorInseridoTipo){
				noh* novoNoh = new noh;
				novoNoh->dadoTipo = valorInseridoTipo;
				novoNoh->proximoValor = NULL;
				
				if(! vazioTipo()){ // nao ha nenhum valor na fila
					fimFilaTipo -> proximoValor = novoNoh;
				}else if(vazioTipo()){
					inicioFilaTipo = novoNoh;
					}	
					fimFilaTipo = novoNoh;
		}		
	
	int filaTipo::desenfileiraTipo(){
		if(vazioTipo()){
			cout << "Erro: fila vazia!" << endl;
			return 0;
			}else{
				noh* aux = inicioFilaTipo;
				char dadoRemovido = inicioFilaTipo -> dadoTipo;
				inicioFilaTipo= inicioFilaTipo -> proximoValor;
				
				if (inicioFilaTipo == NULL) {
					fimFilaTipo = NULL;
					}
				
				delete aux;
				return dadoRemovido;
				
				}
		}
	
	bool filaTipo::vazioTipo(){
		return (inicioFilaTipo == NULL);
		}
	
	void filaTipo::imprimeTipo(){
		noh* temporario = inicioFilaTipo;
		cout << endl << "Fila: " << endl;
		while(temporario != NULL){
			cout << temporario-> dadoTipo << " ";
			temporario = temporario -> proximoValor;
			
			}
		cout << endl;
		}
		
	void filaTipo::imprimeInicioTipo(){
		   if (!vazioTipo()) {
				cout << "Tipo: " << inicioFilaTipo->dadoTipo << endl;
			} else {
				cout << "Erro: fila vazia!" << endl;
				}
		}
		
	
	
class filaTempo{
	private:
		noh* fimFilaTempo;
		noh* inicioFilaTempo;
	
	public:
		filaTempo();
		~filaTempo();
		void enfileiraTempo(int valorInseridoTempo);
		int desenfileiraTempo();
		bool vazioTempo();
		void imprimeTempo();
		void imprimeInicioTempo();
		
		
	};

	filaTempo::filaTempo(){
		fimFilaTempo = NULL;
		inicioFilaTempo= NULL;
		}
		
	filaTempo::~filaTempo(){
		{
		noh* temp2;
		while(inicioFilaTempo!= NULL){
			temp2 = inicioFilaTempo;
			inicioFilaTempo= inicioFilaTempo->proximoValor;
			delete temp2;
			}
		
	}	
		
		}
	
	void filaTempo::enfileiraTempo(int valorInseridoTempo){
				noh* novoNoh = new noh;
				novoNoh->dadoTempo = valorInseridoTempo;
				novoNoh->proximoValor = NULL;
				
				if(! vazioTempo()){ // nao ha nenhum valor na fila
					fimFilaTempo -> proximoValor = novoNoh;
				}else if(vazioTempo()){
					inicioFilaTempo = novoNoh;
					}	
					fimFilaTempo = novoNoh;
		}		
	
	int filaTempo::desenfileiraTempo(){
		if(vazioTempo()){
			cout << "Erro: fila vazia!" << endl;
			return 0;
			}else{
				noh* aux = inicioFilaTempo;
				int dadoRemovido = inicioFilaTempo -> dadoTempo;
				inicioFilaTempo= inicioFilaTempo -> proximoValor;
				
				if (inicioFilaTempo == NULL) {
					fimFilaTempo = NULL;
					}
				
				delete aux;
				return dadoRemovido;
				
				}
		}
	
	bool filaTempo::vazioTempo(){
		return (inicioFilaTempo == NULL);
		}
	
	void filaTempo::imprimeTempo(){
		noh* temporario = inicioFilaTempo;
		cout << endl << "Fila: " << endl;
		while(temporario != NULL){
			cout << temporario-> dadoTempo << " ";
			temporario = temporario -> proximoValor;
			
			}
		cout << endl;
		}
		
	void filaTempo::imprimeInicioTempo(){
		   if (!vazioTempo()) {
				cout << "Tempo: " << inicioFilaTempo->dadoTempo << endl;
			} else {
				cout << "Erro: fila vazia!" << endl;
				}
		}

class filaNome{
	private:
		noh* fimFilaNome;
		noh* inicioFilaNome;
	
	public:
		filaNome();
		~filaNome();
		void enfileiraNome(string valorInseridoNome);
		string desenfileiraNome();
		bool vazioNome();
		void imprimeNome();
		void imprimeInicioNome();
		
		
	};

	filaNome::filaNome(){
		fimFilaNome = NULL;
		inicioFilaNome= NULL;
		}
		
	filaNome::~filaNome(){
		{
		noh* temp2;
		while(inicioFilaNome!= NULL){
			temp2 = inicioFilaNome;
			inicioFilaNome= inicioFilaNome->proximoValor;
			delete temp2;
			}
		
	}	
		
		}
	
	void filaNome::enfileiraNome(string valorInseridoNome){
				noh* novoNoh = new noh;
				novoNoh->dadoNome = valorInseridoNome;
				novoNoh->proximoValor = NULL;
				
				if(! vazioNome()){ // nao ha nenhum valor na fila
					fimFilaNome -> proximoValor = novoNoh;
				}else if(vazioNome()){
					inicioFilaNome = novoNoh;
					}	
					fimFilaNome = novoNoh;
		}		
	
	string filaNome::desenfileiraNome(){
		if(vazioNome()){
			cout << "Erro: fila vazia!" << endl;
			return 0;
			}else{
				noh* aux = inicioFilaNome;
				string dadoRemovido = inicioFilaNome -> dadoNome;
				inicioFilaNome= inicioFilaNome -> proximoValor;
				
				if (inicioFilaNome == NULL) {
					fimFilaNome = NULL;
					}
				
				delete aux;
				return dadoRemovido;
				
				}
		}
	
	bool filaNome::vazioNome(){
		return (inicioFilaNome == NULL);
		}
	
	void filaNome::imprimeNome(){
		noh* temporario = inicioFilaNome;
		cout << endl << "Fila: " << endl;
		while(temporario != NULL){
			cout << temporario-> dadoNome << " ";
			temporario = temporario -> proximoValor;
			
			}
		cout << endl;
		}
		
	void filaNome::imprimeInicioNome(){
		   if (!vazioNome()) {
				cout << "Nome: " << inicioFilaNome->dadoNome << endl;
			} else {
				cout << "Erro: fila vazia!" << endl;
				}
		}	
	
int main () {
	filaNome fN;
	filaPremio fP;
	filaTipo f;
	filaTempo fT;
	
	cout << " e) Enfileirar \n d) Desenfileirar \n i) EspiarTopo \n f) Finalizar Programa " << endl;
	char resposta; 
	cin >> resposta;
	
	while(resposta!='f'){
		if(resposta=='e'){ //enfileirar
			string n;
			string p;
			char t;
			int periodo;
			
			
			cin >> n;
			cin >> p;
			cin >>t;
			cin >>periodo;
			
			fN.enfileiraNome(n);
			fP.enfileiraPremio(p);
			f.enfileiraTipo(t);
			fT.enfileiraTempo(periodo);
			
			}else if(resposta== 'd'){ // desenfileirar
				cout << "Nome: "<< fN.desenfileiraNome() << " Premio " << fP.desenfileiraPremio() << " Tipo: " << f.desenfileiraTipo() << " tempo: " << fT.desenfileiraTempo() << endl;
				
				}else if(resposta == 'i'){ // esppiar inicio da fila
					 fN.imprimeInicioNome();
					 fP.imprimeInicioPremio();
					 f.imprimeInicioTipo();
					 fT.imprimeInicioTempo();
					}
		cin >> resposta;
		}
		cout << "Fila resultante: " << endl;
		
	while(! fN.vazioNome() and ! fP.vazioPremio()and ! f.vazioTipo() and ! fT.vazioTempo()){
		cout << "Nome: "<<fN.desenfileiraNome() << " ";
		cout << "Premio: "<<fP.desenfileiraPremio() << " ";
		cout << "Tipo: "<< f.desenfileiraTipo() << " ";
		cout << "tempo: " << fT.desenfileiraTempo() << endl;
		
		}
	
	return 0;
	}

