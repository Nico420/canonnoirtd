#include "ChoisirPort.h"
#include "Moteur.h"
#include <sstream>

ChoisirPort::ChoisirPort(){
	this->message = "";
	this->moteur = NULL;
	this->portsLibres = new int[4];
	for(int i=0;i<4;i++){
		this->portsLibres[i] = 1;
	}
	this->compteur = 0;
	this->port1 = 0;
	this->port2 = 0;
	this->etatsuivant = 0;
}

ChoisirPort::ChoisirPort(Moteur* mot){
	this->message = "";
	this->moteur = mot;
	this->portsLibres = new int[4];
	for(int i=0;i<4;i++){
		this->portsLibres[i] = 1;
	}
	this->compteur = 0;
	this->port1 = 0;
	this->port2 = 0;
	this->etatsuivant = Moteur::CHOISIRPORT;
}

ChoisirPort::~ChoisirPort(){
	delete[] this->portsLibres;
}

bool ChoisirPort::estLibre(int i) const{
	return this->portsLibres[i-1] == 1;
}

void ChoisirPort::execute(){
	int joueurCourant = this->moteur->getJoueurCourant();
	int nbJoueurs = this->moteur->getNbJoueurs();
	ostringstream mes;
	std::string mes2;
	int nbport = 0;
	int x = this->moteur->getClick().first;
	int y = this->moteur->getClick().second;
	if(x==1 && y==1) nbport = 1;
	else if(x==11 && y==1) nbport = 2;
	else if(x==1 && y==8) nbport = 3;
	else if(x==11 && y==8) nbport = 4;
	if(nbport!=0 && this->estLibre(nbport)){
		this->compteur++;
		if(nbJoueurs==joueurCourant) this->moteur->setJoueurCourant(1);
		else this->moteur->setJoueurCourant(joueurCourant+1);
		if(joueurCourant<nbJoueurs || (nbJoueurs==2 && this->compteur<4)){
			if(nbJoueurs>2){
				this->moteur->addJoueur(joueurCourant-1,joueurCourant,1,nbport);
			}
			else{
				if(this->compteur==1) this->port1 = nbport;
				if(this->compteur==2) this->port2 = nbport;
				else if(this->compteur==3) this->moteur->addJoueur(joueurCourant-1,joueurCourant,2,this->port1,nbport);
			}
			mes2 = ", choisir un port.";
			this->setPortsLibres(nbport);
		}
		else{
			if(nbJoueurs==2) this->moteur->addJoueur(joueurCourant-1,joueurCourant,2,this->port2,nbport);
			else this->moteur->addJoueur(joueurCourant-1,joueurCourant,1,nbport);
			mes2 = ", lancer les dés pour déterminer l'ordre des joueurs.";
			this->etatsuivant = Moteur::SETORDREJOUEURS;
		}
	}
	else mes2 = ", choisir un port.";
	mes << "Joueur " << this->moteur->getJoueurCourant() << mes2;
	this->setMessage(mes.str());
}

int* ChoisirPort::getCasesActives() const{
	int* res = new int[this->moteur->getPlateau().getLongueur()*this->moteur->getPlateau().getLargeur()];
	if(this->portsLibres[0]==1){
		res[0] = 1;
	}
	if(this->portsLibres[1]==1){
		res[10] = 1;
	}
	if(this->portsLibres[2]==1){
		res[77] = 1;
	}
	if(this->portsLibres[3]==1){
		res[87] = 1;
	}
	return res;
}