#include "Radeau.h"

Radeau::Radeau(int posx, int posy, int posPortx, int posPorty){
	this->Bateau::Bateau(1,false,posx,posy,posPortx,posPorty);
}

Bateau* Radeau::degraderBateau(){
	return this;
}