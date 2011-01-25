#include "CasePort.h"
#include "Moteur.h"

int CasePort::getEtat() const{
	return Moteur::LANCERDESDEPLACEMENT;
}