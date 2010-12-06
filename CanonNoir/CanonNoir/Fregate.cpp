#include "Fregate.h"
#include "Radeau.h"

Fregate::Fregate(bool tres, int posx, int posy, int posPortx, int posPorty){
	this->Bateau::Bateau(1,tres,posx,posy,posPortx,posPorty);
}

Bateau* Fregate::degraderBateau(){
	return dynamic_cast<Radeau*>(this);
}