#include "LancerDesDeplacement.h"
#include "Moteur.h"

LancerDesDeplacement::LancerDesDeplacement(){
	this->LancerDes::LancerDes();
}

LancerDesDeplacement::LancerDesDeplacement(Moteur* mot){
	this->LancerDes::LancerDes(mot);
}

void LancerDesDeplacement::execute(){
	this->moteur->getDes().first.lancerDe();
	this->moteur->getDes().second.lancerDe();
	int de1 = this->moteur->getDes().first.getNum();
	int de2 = this->moteur->getDes().second.getNum();
	int totalDes = de1 + de2;
}

void LancerDesDeplacement::calculCasesDeplacement(int scoreDe){
	for(int i=0;i<this->moteur->getPlateau().getLongueur();i++){

	}
}