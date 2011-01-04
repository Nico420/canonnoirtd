#include "CasePort.h"
#include "Moteur.h"

bool CasePort::getEstNavigable() const{
	return this->estNavigable; //Test si une case port est navigable.
			//Vérifier si un bateau peut aller sur un port qui n'a pas sa couleur.
}

int CasePort::getEtat() const{
	return Moteur::LANCERDESDEPLACEMENT;
}