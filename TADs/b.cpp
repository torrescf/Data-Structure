#include <iostream>
using namespace std;

class VectorX{
	private: //declarar as variaveis
		int tamanho;
		int* vetorD;
	
	
	public: // declarar as funcoes para preencher as variaveis
		void inicializar(int tam); 
		void finalizar(); // desalocar a memoria que era do vetor(finalizar o programa)
		void preencher(); // preencher o vetor
		void imprimir(); // imprimir os valores do vetor
		int acessarPosicao(int posicao);
		int alterarDados(int posicao, int novoValor);
	};

	//implementar as funcoes do public para poder ser chamada na main
	void VectorX::inicializar(int tam){ //falar oq a funcao inicializar vai fazer quando for chamada na main
		tamanho= tam;
		vetorD = new int[tam];
		}
	
	void VectorX::finalizar(){ //desalocar a memoria do vetor 
		delete[] vetorD;
		tamanho=0;
		}
	
	void VectorX::preencher(){ // preencher o vetor  quando for chamad
		for(int  i=0; i<tamanho; i++){
			cin >> vetorD[i];
			}
		
		}
	
	void VectorX::imprimir(){
		for(int i=0; i<tamanho; i++){
			cout << vetorD[i] << " ";
			}
		}
	
	int VectorX::acessarPosicao(int posicao){
		if((posicao>=0) and (posicao<tamanho)){ //acessar apenas os dados validos do vetor
			return vetorD[posicao];
			}else{
				return -1;
				}
		
		}
		
	int VectorX::alterarDados(int posicao, int novoValor){
		if((posicao>=0) and (posicao<tamanho)){
			vetorD[posicao]=novoValor;
			return 1;
			
			}else{
				return -1;
				}
		
		}
	
	
int main () {
	//vectorX -- fazer um vetor que consiga ter o controle do seu proprio tamanho por meio de classes(orientacao de objetos)
	VectorX v1;
	int tV;
	cout <<"Insira o tamanho do vetor desejado: " << endl;
	cin >> tV; 
	v1.inicializar(tV);
	cout << "Insira os valores do vetor de tamanho " << tV << ": " << endl;
	v1.preencher();
	v1.imprimir();
	cout <<endl << "--------------------------------------" << endl; 
	cout << "-Deseja: " << endl << "1)Acessar uma posicao do vetor" << endl << "2)Acessar alterar uma posicao do vetor"<< endl;
	cout << "--------------------------------------" << endl;
	int resposta;
	cin >> resposta;
	if(resposta==1){
		cout << endl  << "Insira a posicao que deseja acessar do vetor: ";
		int posicaoDesejada;
		cin >> posicaoDesejada;
		posicaoDesejada-=1; // facilicar o entendimento ao usuario
		v1.acessarPosicao(posicaoDesejada);
		if(v1.acessarPosicao(posicaoDesejada)!=-1){
			cout << v1.acessarPosicao(posicaoDesejada);
			}else{
				cout << "Posicao Invalida" << endl;
				}
		}else if(resposta==2){
			cout << endl << "Insira a posicao que deseja alterar: ";
			int posicaoDesejada;
			cin >> posicaoDesejada;
			posicaoDesejada-=1;
			
			cout << endl << "Insira o novo valor: ";
			int novoValor;
			cin >> novoValor;
			
			v1.alterarDados(posicaoDesejada,novoValor);
			if(v1.acessarPosicao(posicaoDesejada)!=-1){
				cout << "Vetor alterado com sucesso" << endl << "Novo vetor: " << endl;
				v1.imprimir();
				}else{
					cout << "Posicao Invalida!" << endl;
					}
			}
	
	
	
	
	
	
	
	v1.finalizar();
	cout << endl << "Vetor desalocado com sucesso" << endl;
	//funcoes principais: Inicializar e Finalizar(todo codigo precisa)
	//funcoes secundarias: Preencher e Imprimir(varia de codigo para codigo)
	//classe friend tera acesso a tudo que esta na private de sua amiga
	
	
	return 0;
	}
