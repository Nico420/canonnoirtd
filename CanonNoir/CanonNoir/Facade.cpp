#include "Facade.h"

Facade::Facade(){
	this->motor = new Moteur();
	int dim = this->motor->getPlateau().getLongueur()*this->motor->getPlateau().getLargeur();
	this->casesActivesX = new int[dim];
	this->casesActivesY = new int[dim];
	for(int i=0;i<dim;i++){
		this->casesActivesX[i] = 0;
		this->casesActivesY[i] = 0;
	}
	this->affichePlateau = true;
	this->afficheCanon = false;
	this->afficheAttenteNbJoueurs = true;
	this->afficheJeuNormal = false;
	this->message = this->motor->getEtat()->getMessage();
	this->activeDe1 = false;
	this->activeDe2 = false;
	this->activeCases = false;
	this->activeLancerDes = false;
}

Facade::~Facade(){
	delete this->motor;
}

void Facade::setNbJoueurs(int nb){
	this->motor->setNbJoueurs(nb);
	this->message = this->motor->getEtat()->getMessage();
	this->afficheAttenteNbJoueurs = false;
	this->afficheJeuNormal = true;
	this->activeDe1 = true;
	this->activeDe2 = true;
	this->activeLancerDes = true;
}

void Facade::setClick(int x,int y){
	this->motor->setClick(x,y);
	if(this->motor->getEtat()->getPortsLibres() != NULL){
		if(this->motor->getEtat()->getPortsLibres()[0]==1){
			this->casesActivesX[0] = 1;
			this->casesActivesY[0] = 1;
		}
		if(this->motor->getEtat()->getPortsLibres()[1]==1){
			this->casesActivesX[10] = 1;
			this->casesActivesY[0] = 1;
		}
		if(this->motor->getEtat()->getPortsLibres()[2]==1){
			this->casesActivesX[0] = 1;
			this->casesActivesY[7] = 1;
		}
		if(this->motor->getEtat()->getPortsLibres()[3]==1){
			this->casesActivesX[10] = 1;
			this->casesActivesY[7] = 1;
		}
	}
	this->activeCases = true;
}