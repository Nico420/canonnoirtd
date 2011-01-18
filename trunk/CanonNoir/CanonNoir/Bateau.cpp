#include "Bateau.h"
#include "Caravelle.h"

Bateau::Bateau(){
	this->nbDes = 2;
	this->tresorABord = false;
	this->position = std::make_pair(0,0);
	this->positionPort = std::make_pair(0,0);
}

Bateau::Bateau(int nbDes, bool tres, int posx, int posy, int posPortx, int posPorty){
	this->nbDes = nbDes;
	tresorABord = tres;
	position = std::make_pair(posx,posy);
	positionPort = std::make_pair(posPortx,posPorty);
}

Bateau::~Bateau(){
}

void Bateau::deplacer(int x, int y){
	position.first = x;
	position.second = y;
}