#include "ChoisirPort.h"
#include "Moteur.h"

ChoisirPort::ChoisirPort(){
	this->message = "";
	this->moteur = NULL;
	this->portsLibres = new int[4];
	for(int i=0;i<4;i++){
		this->portsLibres[i] = 1;
	}
	this->compteur = 0;
}

ChoisirPort::ChoisirPort(Moteur* mot){
	this->message = "";
	this->moteur = mot;
	for(int i=0;i<4;i++){
		this->portsLibres[i] = 1;
	}
	this->compteur = 0;
}

ChoisirPort::~ChoisirPort(){
}

bool ChoisirPort::estLibre(int i) const{
	return this->portsLibres[i-1] == 1;
}

void ChoisirPort::execute(){
	int joueurCourant = this->moteur->getJoueurCourant();
	int nbJoueurs = this->moteur->getNbJoueurs();
	std::string mes = "Joueur " + joueurCourant;
	int nbport = 0;
	int x = this->moteur->getClick().first;
	int y = this->moteur->getClick().second;
	if(x==1 && y==1) nbport = 1;
	else if(x==11 && y==1) nbport = 2;
	else if(x==1 && y==8) nbport = 3;
	else if(x==11 && y==8) nbport = 4;
	if(nbport!=0 && this->estLibre(nbport)){
		this->compteur++;
		this->moteur->setJoueurCourant((joueurCourant+1)%(nbJoueurs+1));
		if(joueurCourant<nbJoueurs || (nbJoueurs==2 && this->compteur<4)){
			if(nbJoueurs>2){
				this->moteur->addJoueur(joueurCourant-1,joueurCourant,1,nbport);
			}
			else{

			}
			mes +=  ", choisir un port.";
			this->setMessage(mes);
			this->setPortsLibres(nbport);
		}
		else{
			mes +=  ", lancer les dés pour déterminer l'ordre des joueurs.";
			this->setMessage(mes);
			this->moteur->setEtat(Moteur::SETORDREJOUEURS);
		}
	}
}