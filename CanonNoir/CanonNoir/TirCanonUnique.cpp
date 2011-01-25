#include "TirCanonUnique.h"
#include "Moteur.h"
#include <sstream>
#include <iostream>

using namespace std;

void TirCanonUnique::execute(){
	this->tirReussi=true;
	cout<<"Début du execute de TirCanonUnique"<<endl;
	cout<<"Booléen cibleChoisie : "<<cibleChoisie<<endl;
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
		cout<<"Récupération de la position du bateau choisi comme cible"<<endl;
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
		this->cibleChoisie = true;
		cout<< "calculrelief" <<endl;
		this->calculerRelief();
		moteur->setHistogramme(this->histogramme);
		cout<< "fin histo"<<endl;
		cout<<"fin traitement choix cible"<<endl;
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
		int joueurAttaque=0;
		for(int i=1;i<=moteur->getNbJoueurs();i++){
				if(moteur->getJoueur(i).getBateau(1)->getNumPort()==this->bateauAttaque){
					joueurAttaque = moteur->getJoueur(i).getBateau(1)->getNumPort();
				}
				if(moteur->getNbJoueurs()==2){
					if(moteur->getJoueur(i).getBateau(2)->getNumPort()==this->bateauAttaque){
						joueurAttaque = moteur->getJoueur(i).getBateau(2)->getNumPort();
					}
				}
		}

		this->puissance = this->moteur->getPuissance();
		this->puissanceObtenue = true;
		cout<< "entre les deux" <<endl;
		//
		cout<< "calcultir" <<endl;
		//this->calculerTir();
		cout<< "set Trajectoire tir unique" <<endl;
		//moteur->setTrajectoireTir(this->trajectoireTir);
		if(this->tirReussi){
			this->effectuerChangements(this->moteur->getJoueurCourant(),bateauAttaquant,joueurAttaque,bateauAttaque);
		}
		this->moteur->passerAuJoueurSuivant();
		mes << this->moteur->getJoueurCourant();
		mes << ", lancez les dés pour jouer.";
		cout<<"Histogramme :"<<endl;
		for(list<pair<double,double>>::iterator it=histogramme.begin();it!=histogramme.end();it++){
			cout<<it->first<<" "<<it->second<<endl;
		}
		this->etatsuivant = Moteur::LANCERDESDEPLACEMENT;
	}
	this->setMessage(mes.str());
}