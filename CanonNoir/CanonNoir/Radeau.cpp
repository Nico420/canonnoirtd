#include "Radeau.h"

Radeau::Radeau(const Bateau& bat){
	this->nbDes = 1;
	this->tresorABord = false;
	this->position = std::make_pair(bat.getPosition().first,bat.getPosition().second);
	this->positionPort = std::make_pair(bat.getPositionPort().first,bat.getPosition().second);
}

Radeau::~Radeau(){
}