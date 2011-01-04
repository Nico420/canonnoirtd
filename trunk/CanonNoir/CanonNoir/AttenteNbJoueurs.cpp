#include "AttenteNbJoueurs.h"

AttenteNbJoueurs::~AttenteNbJoueurs(){
}

void AttenteNbJoueurs::setMessage(std::string mes){
	this->message=mes;
}

void AttenteNbJoueurs::execute(){
	this->setMessage("Choisir le nombre de joueurs.");
}