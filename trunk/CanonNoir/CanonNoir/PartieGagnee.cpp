#include "PartieGagnee.h"
#include "Moteur.h"
#include <sstream>

void PartieGagnee::execute(){
	ostringstream mes;
	mes << "Félicitation ! Joueur ";
	mes << moteur->getJoueurCourant();
	mes << ", vous avez gagné la partie !";
	this->setMessage(mes.str());
}