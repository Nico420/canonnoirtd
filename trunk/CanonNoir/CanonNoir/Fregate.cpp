#include "Fregate.h"

Fregate::Fregate(const Bateau* bat){
	this->nbDes = 1;
	this->tresorABord = bat->aTresorABord();
	this->position = std::make_pair(bat->getPosition().first,bat->getPosition().second);
	this->positionPort = std::make_pair(bat->getPositionPort().first,bat->getPosition().second);
}

Fregate::~Fregate(){
}


int Fregate::getType() const{
	return 2;
}