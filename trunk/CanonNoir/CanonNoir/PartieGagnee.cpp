#include "PartieGagnee.h"
#include "Moteur.h"
#include <sstream>

void PartieGagnee::execute(){
	ostringstream mes;
	mes << "F�licitation ! Joueur ";
	mes << moteur->getJoueurCourant();
	mes << ", vous avez gagn� la partie !";
	this->setMessage(mes.str());
}