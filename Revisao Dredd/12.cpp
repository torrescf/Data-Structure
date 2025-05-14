#include <iostream>
#include <cmath>
using namespace std;

struct Retangulos{
	
	float base;
	float altura;
	float perimetroR;
	float areaR;
	};	

struct Piramides{
	
	float lado1;
	float lado2;
	float lado3;
	float perimetroP;
	float areaP;
	};

struct Circulos{
	
	float raio;
	float perimetroC;
	float areaC;
	};



int main () {
	int numC=0;
	int numP=0;
	int numR=0;
	Circulos *dadosC= new Circulos[numC];
	Piramides *dadosP= new Piramides[numP];
	Retangulos *dadosR= new Retangulos[numR];
	
	string nomeFigura;
	int contadorFiguras=0;
	
	while(contadorFiguras<5){
		cin >> nomeFigura;
		
		if(nomeFigura == "C"){
			int novoNumC=numC+1;
			Circulos *AuxC = new Circulos[novoNumC];
			
			for(int i=0; i<numC ; i++){
				AuxC[i]= dadosC[i];
				}
				
				delete [] dadosC;
				dadosC = AuxC;
				numC= novoNumC;
				
				cin >> dadosC[numC-1].raio;
				dadosC[numC-1].perimetroC= 2*M_PI*dadosC[numC-1].raio;
				dadosC[numC-1].areaC= M_PI*pow(dadosC[numC-1].raio,2);
					
			}else if(nomeFigura == "P"){
				int novoNumP=numP+1;
				Piramides *AuxP = new Piramides[novoNumP];
				
				for(int i=0; i<numP ; i++){
					AuxP[i]= dadosP[i];
					}
					
					delete [] dadosP;
					dadosP = AuxP;
					numP= novoNumP;
					
					cin >> dadosP[numP-1].lado1;
					cin >> dadosP[numP-1].lado2;
					cin >> dadosP[numP-1].lado3;
					
					float somatoriaLados = dadosP[numP - 1].lado1 + dadosP[numP - 1].lado2 + dadosP[numP - 1].lado3;
					dadosP[numP - 1].perimetroP = somatoriaLados;
					
					float p = somatoriaLados/2;
					float heron = p * (p - dadosP[numP - 1].lado1) * (p - dadosP[numP - 1].lado2) * (p - dadosP[numP - 1].lado3);
					dadosP[numP - 1].areaP = sqrt(heron);
				
				
		}else if(nomeFigura == "R"){
			int novoNumR=numR+1;
			Retangulos *AuxR = new Retangulos[novoNumR];
			
			for(int i=0; i<numR ; i++){
				AuxR[i]= dadosR[i];
				}
					
				delete[] dadosR;
				dadosR = AuxR;
				numR= novoNumR;
					
				cin >> dadosR[numR-1].base;
				cin >> dadosR[numR-1].altura;
				dadosR[numR-1].perimetroR= (2*(dadosR[numR-1].base))+(2*(dadosR[numR-1].altura));
				dadosR[numR-1].areaR = (dadosR[numR-1].base)*(dadosR[numR-1].altura);
		}
		contadorFiguras++;
		
		
	}
	if(numC>0){
	for(int i=0; i<numC ; i++){
		cout << "Circulo ";
		cout << dadosC[i].perimetroC << " " << dadosC[i].areaC << endl;
		}
	}
	
	if(numP>0){
	for(int i=0; i<numP ; i++){
		cout << "Triangulo ";
		cout << dadosP[i].perimetroP << " " << dadosP[i].areaP << endl;
		}	
	}
	
	if(numR>0){
	for(int i=0; i<numR ; i++){
		cout << "Retangulo ";
		cout << dadosR[i].perimetroR << " " << dadosR[i].areaR << endl;
		}
	}
	
	delete[] dadosC;
    //delete[] dadosP;
    delete[] dadosR;
	
	return 0;
	}
