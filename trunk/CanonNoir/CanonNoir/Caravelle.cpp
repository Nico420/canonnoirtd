#include "Caravelle.h"
#include "Fregate.h"

Caravelle::Caravelle(bool tres, int posx, int posy, int posPortx, int posPorty){
	this->Bateau::Bateau(2,tres,posx,posy,posPortx,posPorty);
}

Bateau* Caravelle::degraderBateau(){
	return dynamic_cast<Fregate*>(this);
}