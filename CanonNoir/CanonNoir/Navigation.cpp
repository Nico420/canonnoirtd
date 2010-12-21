#include "Navigation.h"
#include "Moteur.h"

using namespace std;

void Navigation::execute(){
}

void Navigation::deplacer(int x, int y){
	if(this->moteur->getCasesDeplacementBateau().count(make_pair(x,y))>0){
		int numBat = 1;
		if(this->moteur->getNbJoueurs()==2) int numBat = this->moteur->getCasesDeplacementBateau()[make_pair(x,y)];
		Bateau& bat = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(numBat);
		this->moteur->getPlateau().libereCase(bat.getPosition().first,bat.getPosition().second);
		bat.deplacer(x,y);
		this->moteur->getPlateau().occupeCase(x,y);
		std::string mes = "Joueur ";
		mes += this->moteur->getJoueurCourant();
		if(this->moteur->getPlateau().getEtat(x,y)==Moteur::TIRCANONUNIQUE){
			mes += ", choisissez le bateau que vous voulez attaquer.";
			this->setMessage(mes);
			this->casesBateauxCibles.clear();
			//reste à proposer les bateaux à attaquer
		}
		else if(this->moteur->getPlateau().getEtat(x,y)==Moteur::TIRCANONDUEL){

		}
		else if(this->moteur->getPlateau().getEtat(x,y)==Moteur::LANCERDESDEPLACEMENT){

		}
		else if(this->moteur->getPlateau().getEtat(x,y)==Moteur::PARTIEGAGNEE){

		}
	}
}