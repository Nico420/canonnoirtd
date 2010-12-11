#include "Facade.h"

Facade::Facade(){
	this->motor = new Moteur();
	this->portsLibres = new int[4];
	this->affichePlateau = true;
	this->afficheCanon = false;
	this->afficheAttenteNbJoueurs = true;
	this->afficheJeuNormal = false;
	this->message = this->motor->getEtat()->getMessage();
	this->activeDe1 = false;
	this->activeDe2 = false;
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
	this->portsLibres = this->motor->getEtat()->getPortsLibres();
}