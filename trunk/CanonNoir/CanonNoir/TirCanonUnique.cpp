#include "TirCanonUnique.h"
#include "Moteur.h"
#include <sstream>
#include <iostream>

using namespace std;

void TirCanonUnique::execute(){
	ostringstream mes;
	mes << "Joueur ";
	if(!this->cibleChoisie){
		//Récupération de la position du bateau attaquant
		cout<<"Récupération de la position du bateau attaquant"<<endl;
		int x = moteur->getJoueur(moteur->getJoueurCourant()).getBateau(1)->getPosition().first;
		int y = moteur->getJoueur(moteur->getJoueurCourant()).getBateau(1)->getPosition().second;
		if(moteur->getPlateau().getEtat(x,y)==Moteur::TIRCANONUNIQUE){
			this->positionAttaquant = make_pair(x,y);
		}
		else{
			this->positionAttaquant = moteur->getJoueur(moteur->getJoueurCourant()).getBateau(2)->getPosition();
		}
		//Récupération du numéro du bateau choisie comme cible
		this->positionAttaque = this->moteur->getClick();
		for(int i=1;i<=moteur->getNbJoueurs();i++){
			if(moteur->getJoueur(i).getBateau(1)->getPosition()==this->positionAttaque){
				this->bateauAttaque = moteur->getJoueur(i).getBateau(1)->getNumPort();
			}
			if(moteur->getNbJoueurs()==2){
				if(moteur->getJoueur(i).getBateau(2)->getPosition()==this->positionAttaque){
					this->bateauAttaque = moteur->getJoueur(i).getBateau(2)->getNumPort();
				}
			}
		}
		mes << this->moteur->getJoueurCourant();
		mes << ", sélectionnez l'angle de votre tir.";
	}
	else if(!this->angleObtenu){
		this->angle = this->moteur->getAngle();
		this->angleObtenu = true;
		mes << this->moteur->getJoueurCourant();
		mes << ", sélectionnez la puissance de votre tir.";
	}
	else if(!this->puissanceObtenue){
		this->puissance = this->moteur->getPuissance();
		this->puissanceObtenue = true;
		this->calculerRelief();
		this->calculerTir();
		this->moteur->passerAuJoueurSuivant();
		mes << this->moteur->getJoueurCourant();
		mes << ", lancez les dés pour jouer.";
		cout<<"Histogramme :"<<endl;
		for(list<pair<double,double>>::iterator it=histogramme.begin();it!=histogramme.end();it++){
			cout<<it->first<<" "<<it->second<<endl;
		}
	}
	this->setMessage(mes.str());
}