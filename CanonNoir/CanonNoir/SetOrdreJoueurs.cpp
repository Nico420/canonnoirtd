#include "SetOrdreJoueurs.h"
#include "Moteur.h"
#include <vector>
#include <sstream>

void SetOrdreJoueurs::execute(){
	// On insère le joueur dans le bon ordre selon son score aux dés
	int joueurCourant = this->moteur->getJoueurCourant();
	this->moteur->lancerDes();
	int totalDes = this->moteur->getDe1()+ this->moteur->getDe2();
	ostringstream mes;
	this->scoreDesJoueurs[joueurCourant] = totalDes;

	std::vector<int>::iterator it;
	bool inserted = false;
	for(it=this->moteur->getOrdreJoueurs().begin();!inserted && it < this->moteur->getOrdreJoueurs().end();it++){
		if(this->scoreDesJoueurs[*it]<totalDes){
			inserted = true;
		}
	}
	if(inserted) this->moteur->getOrdreJoueurs().insert(it-1,joueurCourant);
	else this->moteur->getOrdreJoueurs().push_back(joueurCourant);
	
	mes << "Joueur ";
	if(joueurCourant<this->moteur->getNbJoueurs()){
		this->moteur->setJoueurCourant(joueurCourant+1);
		mes << this->moteur->getJoueurCourant();
		mes << ", lancez les \ndés pour déterminer l'ordre des joueurs.";
		this->setMessage(mes.str());
	}
	else{
		this->moteur->setJoueurCourant(this->moteur->getOrdreJoueurs().at(0));
		mes << this->moteur->getJoueurCourant();
		mes << ", lancez les \ndés pour jouer.";
		this->setMessage(mes.str());
		this->etatsuivant = Moteur::LANCERDESDEPLACEMENT;
	}
}