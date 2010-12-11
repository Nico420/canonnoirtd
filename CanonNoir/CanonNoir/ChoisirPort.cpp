#include "ChoisirPort.h"
#include "Moteur.h"

ChoisirPort::ChoisirPort(){
	this->message = "";
	this->moteur = NULL;
	for(int i=0;i<4;i++){
		this->portsLibres[i] = 1;
	}
}

ChoisirPort::ChoisirPort(std::string mess,Moteur* mot){
	this->message = mess;
	this->moteur = mot;
	for(int i=0;i<4;i++){
		this->portsLibres[i] = 1;
	}
}

void ChoisirPort::execute(){
	int joueurCourant = this->moteur->getJoueurCourant();
	int nbJoueurs = this->moteur->getNbJoueurs();
	std::string mes = "Joueur " + joueurCourant;
	if(joueurCourant<nbJoueurs-1 || (nbJoueurs==2 && joueurCourant==1)){
		mes +=  ", choisir un port.";
		this->setMessage(mes);
		int x = this->moteur->getClick().first;
		int y = this->moteur->getClick().second;
		if(x==1 && y==1) this->setPortsLibres(1);
		if(x==11 && y==1) this->setPortsLibres(2);
		if(x==1 && y==8) this->setPortsLibres(3);
		if(x==11 && y==8) this->setPortsLibres(4);
	}
	else{
		mes +=  ", lancer les dés pour déterminer l'ordre des joueurs.";
		this->setMessage(mes);
		this->moteur->setEtat(Moteur::SETORDREJOUEURS);
	}
	this->moteur->setJoueurCourant((joueurCourant+1)%nbJoueurs);
}