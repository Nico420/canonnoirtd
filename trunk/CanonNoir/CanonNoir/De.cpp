#include "De.h"

De::De(){
	numero = 5;
}

De::De(int nb){
	alea = nb;
}

/*De::~De(){
}*/

void De::lancerDe(){
	//Problème, on ne fait que des doubles
	srand((unsigned)time(0)*alea);
	numero = (rand()) % 6 + 1;
}