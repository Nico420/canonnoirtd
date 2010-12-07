#include "AttenteNbJoueurs.h"

AttenteNbJoueurs::AttenteNbJoueurs(){
	this->Etat::Etat();
}

AttenteNbJoueurs::AttenteNbJoueurs(std::string mess,Moteur* mot){
	this->Etat::Etat(mess,mot);
}

void AttenteNbJoueurs::execute(){
	this->setMessage("Choisir le nombre de joueurs.");
}