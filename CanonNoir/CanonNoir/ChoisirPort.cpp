#include "ChoisirPort.h"

ChoisirPort::ChoisirPort(){
	this->Etat::Etat();
}

ChoisirPort::ChoisirPort(std::string mess,Moteur* mot){
	this->Etat::Etat(mess,mot);
}

void ChoisirPort::execute(){
	int joueurCourant = this->moteur->getJoueurCourant();
	int nbJoueurs = this->moteur->getNbJoueurs();
	std::string mes = "Joueur " + joueurCourant;
	if(joueurCourant<nbJoueurs-1 || (nbJoueurs==2 && joueurCourant==1)){
		mes +=  ", choisir un port.";
		this->setMessage(mes);
	}
	else{
		mes +=  ", lancer les d�s pour d�terminer l'ordre des joueurs.";
		this->setMessage(mes);
	}
	this->moteur->setJoueurCourant((joueurCourant+1)%nbJoueurs);
}