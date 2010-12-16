#include "TirCanonDuel.h"
#include "Moteur.h"

TirCanonDuel::TirCanonDuel(){
	this->TirCanon::TirCanon();
	this->premierTir = true;
}

TirCanonDuel::TirCanonDuel(Moteur* mot){
	this->TirCanon::TirCanon(mot);
	this->premierTir = true;
}

void TirCanonDuel::echangeDuel(){
	this->message = "";
	this->angle = -1;
	this->bateauAttaquant = this->bateauAttaque;
	this->bateauAttaque = this->moteur->getJoueurCourant();
	std::pair<int,int> temp = this->positionAttaquant;
	this->positionAttaquant = this->positionAttaque;
	this->positionAttaque = temp;
	this->premierTir = false;
	this->puissance = -1;
	this->tirReussi = false;
}

void TirCanonDuel::execute(){

}