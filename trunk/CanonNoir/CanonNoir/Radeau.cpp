#include "Radeau.h"

Radeau::Radeau(){
	this->Bateau::Bateau();
}

Radeau::Radeau(int posx, int posy, int posPortx, int posPorty){
	this->Bateau::Bateau(1,false,posx,posy,posPortx,posPorty);
}

Radeau::Radeau(const Bateau& bat){
	this->nbDes = 1;
	this->tresorABord = false;
	this->position = std::make_pair(bat.getPosition().first,bat.getPosition().second);
	this->positionPort = std::make_pair(bat.getPositionPort().first,bat.getPosition().second);
}

Radeau::~Radeau(){
}