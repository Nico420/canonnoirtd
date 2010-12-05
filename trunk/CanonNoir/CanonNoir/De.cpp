#include "De.h"

De::De(int nb){
	numero = nb;
}

De::~De(){
}

void De::lancerDe(){
	srand((unsigned)time(0));
	numero = rand() % 6 + 1;
}