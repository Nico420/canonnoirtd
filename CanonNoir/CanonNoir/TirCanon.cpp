#include "TirCanon.h"
#include "Moteur.h"

TirCanon::TirCanon(){
	this->angle = -1;
	this->puissance = -1;
	this->bateauAttaquant = 0;
	this->bateauAttaque = 0;
	this->tirReussi = false;
	this->positionAttaquant = std::make_pair(0,0);
	this->positionAttaque = std::make_pair(0,0);
	this->message = "";
	this->moteur = NULL;
}

TirCanon::TirCanon(Moteur* mot){
	this->angle = -1;
	this->puissance = -1;
	this->bateauAttaquant = this->moteur->getJoueurCourant();
	this->bateauAttaque = 0;
	this->tirReussi = false;
	this->positionAttaquant = std::make_pair(0,0);
	this->positionAttaque = std::make_pair(0,0);
	this->message = "";
	this->moteur = mot;
}

void TirCanon::setCible(int num){
	this->bateauAttaque = num;
	//Fixer la position du bateau correspondante
}

void TirCanon::execute(){
}