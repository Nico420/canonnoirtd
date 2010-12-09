#include "Facade.h"

Facade::Facade(){

}

Facade::~Facade(){
}

void Facade::setNbJoueurs(int nb){
	this->motor->setNbJoueurs(nb);
}

void Facade::setClick(int x,int y){
	//if(x==1 && y==1) this->motor->etat->setPortsLibres(1);
}