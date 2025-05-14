#include <iostream>
#include <cmath>
using namespace std;

int main () {
	
	float lado1 = 3;
	float lado2 = 4;
	float lado3 = 5;
	
	float somatoriaLados = (lado1) + (lado2) + (lado3);
	float perimetroP= somatoriaLados;
	float p = somatoriaLados/2;
	float heron= p * (p -lado1) * (p - lado2) * (p - lado3);
	float areaP = sqrt(heron);
	
	cout << perimetroP << endl << areaP << endl;
	
	return 0;
	} 
