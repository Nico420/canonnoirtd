#include "De.h"

De::De(){
	numero = 5;
}

De::De(int nb){
	numero = nb;
}

/*De::~De(){
}*/

void De::lancerDe(){
	//Problème, on ne fait que des doubles
	srand((unsigned)time(0));
	numero = (rand()*numero) % 6 + 1;
}