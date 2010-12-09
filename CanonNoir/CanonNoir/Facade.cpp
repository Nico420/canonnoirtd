#include "Facade.h"

Facade::Facade(){

}

Facade::~Facade(){
}

void Facade::setNbJoueurs(int nb){
	this->motor->setNbJoueurs(nb);
}