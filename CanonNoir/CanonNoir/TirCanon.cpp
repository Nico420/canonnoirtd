#include "TirCanon.h"

TirCanon::TirCanon(){
	this->angle = -1;
	this->puissance = -1;
	this->joueurAttaquant = 0;
	joueurAttaque = -1;
	tirReussi = false;
	this->positionAttaquant = std::make_pair(0,0);
	this->positionAttaque = std::make_pair(0,0);
	this->message = "";
	this->moteur = NULL;
}

TirCanon::TirCanon(std::string mess,Moteur* mot){
	this->angle = -1;
	this->puissance = -1;
	this->joueurAttaquant = 0;
	joueurAttaque = -1;
	tirReussi = false;
	this->positionAttaquant = std::make_pair(0,0);
	this->positionAttaque = std::make_pair(0,0);
	this->message = mess;
	this->moteur = mot;
}