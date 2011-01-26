#include "Navigation.h"
#include "Moteur.h"
#include <sstream>
#include <iostream>


using namespace std;

void Navigation::execute(){
	cout << "Etat Navigation";
	this->deplacer(this->moteur->getClick().first,this->moteur->getClick().second);
}

void Navigation::deplacer(int x, int y){
	cout << "Etat Navigation";
	ostringstream mes;
	if(this->moteur->getCasesDeplacementBateau().count(make_pair(x,y))>0){
		int numBat = 1;
		if(this->moteur->getNbJoueurs()==2) numBat = this->moteur->getCasesDeplacementBateau()[make_pair(x,y)];
		Bateau* bat = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(numBat);
		this->moteur->getPlateau().libereCase(bat->getPosition().first,bat->getPosition().second);
		cout << "Deplacement du bateau"<<endl;
		bat->deplacer(x,y);
		this->moteur->getPlateau().occupeCase(x,y);
		
		mes << "Joueur ";
		mes << this->moteur->getJoueurCourant();
		if(this->moteur->getPlateau().getEtat(x,y)==Moteur::TIRCANONUNIQUE){
			mes << ", choisissez le bateau que vous voulez attaquer.";
			this->casesBateauxCibles.clear();
			this->setCasesBateauxCibles();
			this->etatsuivant = Moteur::TIRCANONUNIQUE;
		}
		else if(this->moteur->getPlateau().getEtat(x,y)==Moteur::TIRCANONDUEL){
			std::pair<int,int> caseOpposee = this->getCaseFaceOppose(x,y);
			if(!this->moteur->getPlateau().estNavigable(caseOpposee.first,caseOpposee.second)){
				mes << ", choisissez votre angle de tir.";
				this->etatsuivant = Moteur::TIRCANONDUEL;
			}
			else{
				this->moteur->passerAuJoueurSuivant();
				mes.str("");
				mes << "Joueur " << this->moteur->getJoueurCourant();
				mes << ", lancez les dés pour jouer.";
				this->etatsuivant = Moteur::LANCERDESDEPLACEMENT;
			}
		}
		else if(this->moteur->getPlateau().getEtat(x,y)==Moteur::LANCERDESDEPLACEMENT){
			bool partieFinie = false;
			if(!bat->aTresorABord() && this->moteur->getPlateau().getNbTresors(x,y)>0){
				if(bat->donneTresor()) this->moteur->getPlateau().enleveUnTresor(x,y);
			}
			else if(bat->getPositionPort().first==x && bat->getPositionPort().second==y){
				//traitement bateau rentre au port
				this->moteur->getJoueur(this->moteur->getJoueurCourant()).setScore(x,y);
				if(this->moteur->getJoueur(this->moteur->getJoueurCourant()).getScore(x,y)==3){
					partieFinie = true;
					mes << ", vous avez gagné ! Félicitations !";
					this->etatsuivant = Moteur::PARTIEGAGNEE;
				}
				this->moteur->getJoueur(this->moteur->getJoueurCourant()).rentreAuPort(x,y);
			}
			if(!partieFinie){
				this->moteur->passerAuJoueurSuivant();
				mes.str("");
				mes << "Joueur " << this->moteur->getJoueurCourant();
				mes << ", lancez les dés pour jouer.";
				this->etatsuivant = Moteur::LANCERDESDEPLACEMENT;
			}
		}
		this->setMessage(mes.str());
	}else{
		this->etatsuivant = Moteur::NAVIGATION;
		mes << "Attention, vous n'avez pas choisi de une case valide !\n";
		mes << "Joueur ";
		mes << this->moteur->getJoueurCourant();
		mes << ", choisissez la case où vous souhaitez vous déplacer.";
		this->setMessage(mes.str());
	}
}

void Navigation::setCasesBateauxCibles(){
	int nbJoueurs = this->moteur->getNbJoueurs();
	int joueurCourant = this->moteur->getJoueurCourant();
	if(nbJoueurs==2){
		int autreJoueur = (joueurCourant==1)? 2 : 1;
		this->casesBateauxCibles.insert(this->moteur->getJoueur(autreJoueur).getBateau(1)->getPosition());
		this->casesBateauxCibles.insert(this->moteur->getJoueur(autreJoueur).getBateau(2)->getPosition());
	}
	else{
		for(int i=1;i<=nbJoueurs;i++){
			if(joueurCourant!=i)
				this->casesBateauxCibles.insert(this->moteur->getJoueur(i).getBateau(1)->getPosition());
		}
	}
}

std::vector<int> Navigation::getCasesActives() const{
	int nbCases = this->moteur->getPlateau().getLongueur() * this->moteur->getPlateau().getLargeur();
	std::vector<int> res(nbCases,0);
	for(int i=0;i<nbCases;i++){
		bool boo = false;
		std::set<std::pair<int,int>>::iterator it;
		for(it=this->casesBateauxCibles.begin();it!=this->casesBateauxCibles.end();it++){
			int x = (*it).first-1;
			int y = ((*it).second-1)*this->moteur->getPlateau().getLongueur();
			if((x+y)==i) res.at(i) = 1;
		}
	}
	return res;
}

std::pair<int,int> Navigation::getCaseFaceOppose(int x,int y) const{
	int longueur = this->moteur->getPlateau().getLongueur();
	int largeur = this->moteur->getPlateau().getLargeur();
	if(x==1) return std::make_pair(longueur,y);
	if(x==longueur) return std::make_pair(1,y);
	if(y==1) return std::make_pair(x,largeur);
	if(y==largeur) return std::make_pair(x,1);
	return std::make_pair(0,0);
}