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

int Bateau::getNumPort() const{
	int x = this->getPositionPort().first;
	int y = this->getPositionPort().second;
	int numPort;
	if(x==1 && y==1) numPort = 1;
	else if(x==11 && y==1) numPort = 2;
	else if(x==1 && y==8) numPort = 3;
	else if(x==11 && y==8) numPort = 4;
	return numPort;
}