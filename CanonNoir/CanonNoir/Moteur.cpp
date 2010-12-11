#include "Moteur.h"
#include "AttenteNbJoueurs.h"
#include "ChoisirPort.h"
#include "SetOrdreJoueurs.h"
#include "LancerDesDeplacement.h"
#include "Navigation.h"
#include "TirCanonDuel.h"
#include "TirCanonUnique.h"
#include "PartieGagnee.h"

Moteur::Moteur(){
	this->nbJoueurs = 0;
	this->joueurCourant = 1;
	this->click = std::make_pair(0,0);
	this->des.first = De::De();
	this->des.second = De::De();
	this->plateau = Plateau::Plateau();
	this->etat= new AttenteNbJoueurs();
}

Moteur::~Moteur(){
	delete this->etat;
}

void Moteur::setNbJoueurs(int nb){
	this->nbJoueurs = nb;
	this->setEtat(CHOISIRPORT);
	this->execute();
}

void Moteur::setClick(int x,int y){
	this->click.first = x;
	this->click.second = y;
	this->execute();
}

void Moteur::setEtat(int e){
	delete this->etat;
	switch(e) {
		case ATTENTENBJOUEURS:
			this->etat = new AttenteNbJoueurs();
			break;
		case CHOISIRPORT:
			this->etat = new ChoisirPort();
			break; 
		case SETORDREJOUEURS: 
			this->etat = new SetOrdreJoueurs();
			break;
		case LANCERDESDEPLACEMENT:
			this->etat = new LancerDesDeplacement();
			break;
		case NAVIGATION:
			this->etat = new Navigation();
			break;
		case TIRCANONDUEL:
			this->etat = new TirCanonDuel();
			break;
		case TIRCANONUNIQUE:
			this->etat = new TirCanonUnique();
			break;
		case PARTIEGAGNEE:
			this->etat = new PartieGagnee();
			break;
	}
}

void Moteur::execute(){
	this->etat->execute();
}