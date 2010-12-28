#include "Carte.h"

#include <iostream>
#include <cstdlib>


Carte::Carte(Couleur coul, Valeur haut, char prop)
{
	_couleur = coul;
	_valeur = haut;
	_proprietaire = prop;
	if(prop == 'N'){
		if(first_card_N != NULL){
			_carte_prec = first_card_N;
		}
		else{
			_carte_prec = NULL;
			last_card_N = this;
		}
		first_card_N = this;
	}
	else{
		if(first_card_S != NULL){
			_carte_prec = first_card_S;
		}
		else{
			_carte_prec = NULL;
			last_card_S = this;
		}
		Carte::first_card_S = this;
	}
}

Carte::~Carte(void)
{
}

void Carte::afficherN(){
	Carte* carte=first_card_N;
	while(carte!=NULL){
		std::cout << carte->_valeur + " " + carte->_couleur << std::endl;
		carte=carte->_carte_prec;
	}
}

void Carte::afficherS(){
	Carte* carte=first_card_S;
	while(carte!=NULL){
		std::cout << carte->_valeur + " " + carte->_couleur << std::endl;
		carte=carte->_carte_prec;
	}
}

void Carte::afficher(){
		std::cout << _valeur + " " + _couleur << std::endl;
}

Carte* Carte::suc(){
	return _carte_prec;
}

Carte* Carte::getNTete(){
	return first_card_N;
}

Carte* Carte::getSTete(){
	return first_card_S;
}

bool Carte::egale(Carte* carte){
	return this->_valeur==carte->_valeur;
}

void Carte::changerProp(){
	if(this->_proprietaire=='N'){
		_proprietaire = 'S';
		first_card_N = this->_carte_prec;
		last_card_S->_carte_prec = this;
		last_card_S = this;
	}
	else{
		_proprietaire = 'N';
		first_card_S = this->_carte_prec;
		last_card_N->_carte_prec = this;
		last_card_N = this;
	}
}

bool Carte::supAbs(Carte* carte){
	return this->_valeur > carte->_valeur;
}

void Carte::passerDerriere(){
	if(this->_proprietaire=='N'){
		first_card_N = this->_carte_prec;
		last_card_N->_carte_prec = this;
		last_card_N = this;
	}
	else{
		first_card_S = this->_carte_prec;
		last_card_S->_carte_prec = this;
		last_card_S = this;
	}
}
