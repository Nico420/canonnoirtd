#include "Caravelle.h"
#include "Fregate.h"

Caravelle::Caravelle(bool tres, int posx, int posy, int posPortx, int posPorty){
	this->Bateau::Bateau(2,tres,posx,posy,posPortx,posPorty);
}

Caravelle::Caravelle(const Bateau* bat){
	this->nbDes = 2;
	this->tresorABord = bat->aTresorABord();
	this->position = std::make_pair(bat->getPosition().first,bat->getPosition().second);
	this->positionPort = std::make_pair(bat->getPositionPort().first,bat->getPosition().second);
}