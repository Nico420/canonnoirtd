#include "Case.h"

Case::Case(int haut,bool nav){
	this->hauteur = haut;
	this->estNavigable = nav;
}
void Case::libereCase(){
	this->estNavigable=true;
	this->hauteur=0;

}

int Case::getEtat() const{
	return 0;
}