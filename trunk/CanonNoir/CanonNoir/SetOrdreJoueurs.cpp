#include "SetOrdreJoueurs.h"
#include "Moteur.h"
#include <vector>
#include <sstream>

void SetOrdreJoueurs::execute(){
	// On ins�re le joueur dans le bon ordre selon son score aux d�s
	int joueurCourant = this->moteur->getJoueurCourant();
	this->moteur->lancerDes();
	int totalDes = this->moteur->getDe1()+ this->moteur->getDe2();
	ostringstream mes;

	this->scoreDesJoueurs[joueurCourant] = totalDes;
	
	//Pour le premier joueur qui lance les d�s.
	if(joueurCourant==1){
		//On met le premier joueur en premier
		this->moteur->getOrdreJoueurs().push_back(1);
	}
	else{
		std::vector<int>::iterator it;
		bool inserted = false;
		for(it=this->moteur->getOrdreJoueurs().begin();it < this->moteur->getOrdreJoueurs().end();++it){
			if(this->scoreDesJoueurs[*it]>totalDes){
				this->moteur->getOrdreJoueurs().insert(it,joueurCourant);
				inserted = true;
			}
		}

		if(!inserted) this->moteur->getOrdreJoueurs().push_back(joueurCourant);
	}
	
	mes << "Joueur ";
	if(joueurCourant<this->moteur->getNbJoueurs()){
		this->moteur->setJoueurCourant(joueurCourant+1);
		mes << this->moteur->getJoueurCourant();
		mes << ", lancez les \nd�s pour d�terminer l'ordre des joueurs.";
		this->setMessage(mes.str());
	}
	else{
		this->moteur->setJoueurCourant(this->moteur->getOrdreJoueurs().at(0));
		mes << this->moteur->getJoueurCourant();
		mes << ", lancez les \nd�s pour jouer.";
		this->setMessage(mes.str());
		this->etatsuivant = Moteur::LANCERDESDEPLACEMENT;
	}
}