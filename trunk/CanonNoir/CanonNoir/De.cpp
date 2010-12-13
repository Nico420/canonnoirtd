#include "De.h"

De::De(){
	numero = 1;
}

De::De(int nb){
	numero = nb;
}

De::~De(){
}

void De::lancerDe(){
	srand((unsigned)time(0));
	numero = (rand()*numero) % 6 + 1;
}