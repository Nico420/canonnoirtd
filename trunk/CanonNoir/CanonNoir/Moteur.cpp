#include "Moteur.h"

Moteur::Moteur(){
	this->nbJoueurs = 0;
	this->joueurCourant = -1;
	this->des[0] = De::De();
	this->des[1] = De::De();
	this->plateau = Plateau::Plateau();
	for(int i=0;i<6;i++){
		this->etats[i] = new Etat();
	}
}

Moteur::~Moteur(){
}

void Moteur::setNbJoueurs(int nb){

}