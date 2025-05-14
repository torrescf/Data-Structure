#include <iostream>
using namespace std;

int main () {
	
	int tam;
	cin >> tam;
	
	int mapaNavio[tam][tam];
	
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam ; j++){
			cin >> mapaNavio[i][j];
			}
		}
	
	int mapaTiros[tam][tam];
	
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam ; j++){
			cin >> mapaTiros[i][j];
			}
		}
	int naviosAfundados=0;
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam ; j++){
			if(mapaNavio[i][j]==mapaTiros[i][j] and mapaNavio[i][j]!=0){
				naviosAfundados++;
				}
			}
		}	
	
	cout << naviosAfundados;
	
	return 0;
	}
