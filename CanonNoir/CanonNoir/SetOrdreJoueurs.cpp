#include "SetOrdreJoueurs.h"
#include "Moteur.h"
#include <vector>
#include <sstream>

void SetOrdreJoueurs::execute(){
	// On insère le joueur dans le bon ordre selon son score aux dés
	int joueurCourant = this->moteur->getJoueurCourant();
	/*this->moteur->getDes().first.lancerDe();
	this->moteur->getDes().second.lancerDe();*/
	int totalDes =2; //this->moteur->getDes().first.getNum() + this->moteur->getDes().second.getNum();
	this->scoreDesJoueurs[joueurCourant] = totalDes;
	if(joueurCourant==1){
		this->moteur->getOrdreJoueurs().push_back(1);
	}
	else{
		std::vector<int>::iterator it;
		bool inserted = false;
		for(it=this->moteur->getOrdreJoueurs().begin();it < this->moteur->getOrdreJoueurs().end();it++){
			if(this->scoreDesJoueurs[*it]>totalDes){
				this->moteur->getOrdreJoueurs().insert(it,joueurCourant);
				inserted = true;
			}
		}
		if(!inserted) this->moteur->getOrdreJoueurs().push_back(joueurCourant);
	}
	ostringstream mes;
	mes << "Joueur ";
	if(joueurCourant<this->moteur->getNbJoueurs()){
		this->moteur->setJoueurCourant(joueurCourant+1);
		mes << this->moteur->getJoueurCourant();
		mes << ", lancez les \ndés pour déterminer l'ordre des joueurs.";
		this->setMessage(mes.str());
	}
	else{
		this->moteur->setJoueurCourant(this->moteur->getOrdreJoueurs().at(0));
		mes << this->moteur->getJoueurCourant();
		mes << ", lancez les \ndés pour jouer.";
		this->setMessage(mes.str());
		this->etatsuivant = Moteur::LANCERDESDEPLACEMENT;
	}
}