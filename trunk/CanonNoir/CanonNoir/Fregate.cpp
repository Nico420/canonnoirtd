#include "Fregate.h"

Fregate::Fregate(){
	this->Bateau::Bateau();
}

Fregate::Fregate(bool tres, int posx, int posy, int posPortx, int posPorty){
	this->Bateau::Bateau(1,tres,posx,posy,posPortx,posPorty);
}

Fregate::Fregate(const Bateau& bat){
	this->nbDes = 1;
	this->tresorABord = bat.aTresorABord();
	this->position = std::make_pair(bat.getPosition().first,bat.getPosition().second);
	this->positionPort = std::make_pair(bat.getPositionPort().first,bat.getPosition().second);
}