#include <iostream>
using namespace std;

struct dados{
	
	int qntC;
	int qntH;
	
	};

int main () {
	
	dados* hidrocarbonetos = new dados[1];
	
	cin >> hidrocarbonetos[0].qntC;
	cin >> hidrocarbonetos[0].qntH;
	
	int mmC = 12*hidrocarbonetos[0].qntC;
	
	int calculo = mmC+hidrocarbonetos[0].qntH;
	
	cout << calculo;
	
	delete[] hidrocarbonetos;
	
	return 0;
	}
