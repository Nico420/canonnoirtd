#include "TirCanonDuel.h"
#include "Moteur.h"
#include <iostream>
#include <sstream>

using namespace std;

void TirCanonDuel::echangeDuel(){
	this->message = "";
	this->angle = -1;
	int tem = this->bateauAttaquant;
	this->bateauAttaquant = this->bateauAttaque;
	this->bateauAttaque = tem;
	tem = joueurAttaquant;
	joueurAttaquant = joueurAttaque;
	joueurAttaque = tem;
	std::pair<int,int> temp = this->positionAttaquant;
	this->positionAttaquant = this->positionAttaque;
	this->positionAttaque = temp;
	this->premierTir = false;
	this->puissance = -1;
	this->tirReussi = false;
}

void TirCanonDuel::execute(){
	cout<<"Début du execute de TirCanonDuel"<<endl;
	ostringstream mes;
	mes << "Joueur ";
	if(!this->angleObtenu){
		//We get the player's number who will be attacked
		if(this->premierTir){
			for(int i=1;i<=moteur->getNbJoueurs();i++){
				if(moteur->getJoueur(i).getBateau(1)->getNumPort()==this->bateauAttaque){
					this->joueurAttaque = moteur->getJoueur(i).getBateau(1)->getNumPort();
				}
				if(moteur->getNbJoueurs()==2){
					if(moteur->getJoueur(i).getBateau(2)->getNumPort()==this->bateauAttaque){
						this->joueurAttaque = moteur->getJoueur(i).getBateau(2)->getNumPort();
					}
				}
			}
		}
		//We get the player's number who will attack
		this->joueurAttaquant = this->moteur->getJoueurCourant();
		this->angle = this->moteur->getAngle();
		this->angleObtenu = true;
		mes << this->moteur->getJoueurCourant();
		mes << ", sélectionnez la puissance de votre tir.";
	}
	else if(!this->puissanceObtenue){
		this->premierTir = false;
		this->puissance = this->moteur->getPuissance();
		this->puissanceObtenue = true;
		this->calculerRelief();
		moteur->setHistogramme(this->histogramme);
		this->calculerTir();
		moteur->setTrajectoireTir(this->trajectoireTir);
		//If the shoot succeeded
		if(this->tirReussi){
			this->effectuerChangements(joueurAttaquant,bateauAttaquant,joueurAttaque,bateauAttaque);
			this->moteur->passerAuJoueurSuivant();
			mes << this->moteur->getJoueurCourant();
			mes << ", lancez les dés pour jouer.";
			this->etatsuivant = Moteur::LANCERDESDEPLACEMENT;
		}
		//If the shoot failed and it was the first shoot
		else if(this->premierTir){
			this->echangeDuel();
			mes << this->joueurAttaquant;
			mes << ", sélectionnez l'angle de votre tir.";
		}
		//If the shoot failed and it was the second shoot
		else{
			this->moteur->passerAuJoueurSuivant();
			mes << this->moteur->getJoueurCourant();
			mes << ", lancez les dés pour jouer.";
			this->etatsuivant = Moteur::LANCERDESDEPLACEMENT;
		}
		cout<<"Histogramme :"<<endl;
		for(list<pair<double,double>>::iterator it=histogramme.begin();it!=histogramme.end();it++){
			cout<<it->first<<" "<<it->second<<endl;
		}
	}
	this->setMessage(mes.str());
}