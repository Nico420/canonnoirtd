#include "Navigation.h"
#include "Moteur.h"

void Navigation::execute(){
}

void Navigation::deplacer(int x, int y){
	if(this->moteur->getNbJoueurs()==2){
		// traitement spécial
	}
	else{
		this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(0).deplacer(x,y);
	}
}