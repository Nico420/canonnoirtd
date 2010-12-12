#include "AttenteNbJoueurs.h"

AttenteNbJoueurs::~AttenteNbJoueurs(){
}

void AttenteNbJoueurs::execute(){
	this->setMessage("Choisir le nombre de joueurs.");
}

/*EXTERNC DLL AttenteNbJoueurs* AttenteNbJoueurs_New(){
	;
}*/

EXTERNC DLL void setNbJoueur(int a){
	;
}