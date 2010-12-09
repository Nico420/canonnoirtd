#include "ChoisirPort.h"
#include "Moteur.h"

void ChoisirPort::execute(){
	int joueurCourant = this->moteur->getJoueurCourant();
	int nbJoueurs = this->moteur->getNbJoueurs();
	std::string mes = "Joueur " + joueurCourant;
	if(joueurCourant<nbJoueurs-1 || (nbJoueurs==2 && joueurCourant==1)){
		mes +=  ", choisir un port.";
		this->setMessage(mes);
	}
	else{
		mes +=  ", lancer les dés pour déterminer l'ordre des joueurs.";
		this->setMessage(mes);
		this->moteur->setEtat(Moteur::SETORDREJOUEURS);
	}
	this->moteur->setJoueurCourant((joueurCourant+1)%nbJoueurs);
}