#include "SetOrdreJoueurs.h"
#include "Moteur.h"

SetOrdreJoueurs::SetOrdreJoueurs(){
	this->LancerDes::LancerDes();
}

SetOrdreJoueurs::SetOrdreJoueurs(std::string mess,Moteur* mot){
	this->LancerDes::LancerDes(mess,mot);
}

void SetOrdreJoueurs::execute(){
	this->moteur->getDes().first.lancerDe();
	this->moteur->getDes().second.lancerDe();
	std::string mes = "Joueur " + this->moteur->getJoueurCourant();
	mes += ", lancer les dés pour déterminer l'ordre des joueurs.";
	this->setMessage(mes);
}