#include "Moteur.h"
#include "AttenteNbJoueurs.h"
#include "ChoisirPort.h"
#include "SetOrdreJoueurs.h"
#include "LancerDesDeplacement.h"
#include "Navigation.h"
#include "TirCanonDuel.h"
#include "TirCanonUnique.h"
#include "PartieGagnee.h"
#include "Bateau.h"
#include <sstream>

Moteur::Moteur(){
	this->nbJoueurs = 0;
	this->joueurCourant = 1;
	this->click = std::make_pair(0,0);
	this->numEtatCourant = ATTENTENBJOUEURS;
	this->des.first = De::De(1);
	this->des.second = De::De(2);
	//pour avoir des lancer de dés différents
	des.second.numero=1;
	cout<<"testMoteur"<<endl;
	this->plateau = Plateau::Plateau();
	cout<<"testMoteur"<<endl;
	this->etat= new AttenteNbJoueurs();
}

Moteur::~Moteur(){
	delete this->etat;
}

void Moteur::setNbJoueurs(int nb){
	this->nbJoueurs = nb;
	this->setEtat(CHOISIRPORT);
	this->execute();
}

void Moteur::setClick(int x,int y){
	this->click.first = x;
	this->click.second = y;
	this->execute();
}


void Moteur::setEtat(int e){
	if(e!=this->numEtatCourant){
		delete this->etat;
		this->numEtatCourant = e;
		switch(e) {
			case ATTENTENBJOUEURS:
				this->etat = new AttenteNbJoueurs(this);
				break;
			case CHOISIRPORT:
				this->etat = new ChoisirPort(this);
				break; 
			case SETORDREJOUEURS: 
				this->etat = new SetOrdreJoueurs(this);
				break;
			case LANCERDESDEPLACEMENT:
				this->etat = new LancerDesDeplacement(this);
				break;
			case NAVIGATION:
				this->etat = new Navigation(this);
				break;
			case TIRCANONDUEL:
				this->etat = new TirCanonDuel(this);
				break;
			case TIRCANONUNIQUE:
				this->etat = new TirCanonUnique(this);
				break;
			case PARTIEGAGNEE:
				this->etat = new PartieGagnee(this);
				break;
		}
	}
}

vector<int> Moteur::getPosBateaux(){
	
	joueurs.at(0);
	int taille = (this->nbJoueurs==3)? 15 : 20;
	vector<int> res(taille);
	int cpt = 0;
	for(int i=0;i<nbJoueurs;i++){
		res.at(cpt*5) = joueurs.at(i).getBateau(1)->getPosition().first;
		res.at(cpt*5+1) = joueurs.at(i).getBateau(1)->getPosition().second;
		res.at(cpt*5+2) = joueurs.at(i).getBateau(1)->aTresorABord();
		res.at(cpt*5+3) = joueurs.at(i).getBateau(1)->getType();
		res.at(cpt*5+4) = joueurs.at(i).getBateau(1)->getNumPort();
		if(nbJoueurs==2){
			cpt++;
			res.at(cpt*5) = joueurs.at(i).getBateau(2)->getPosition().first;
			res.at(cpt*5+1) = joueurs.at(i).getBateau(2)->getPosition().second;
			res.at(cpt*5+2) = joueurs.at(i).getBateau(2)->aTresorABord();
			res.at(cpt*5+3) = joueurs.at(i).getBateau(2)->getType();
			res.at(cpt*5+4) = joueurs.at(i).getBateau(2)->getNumPort();
		}
		cpt++;
	}
	//cout<<"fin getPosBateaux"<<endl;
	return res;
}

void Moteur::execute(){
	this->etat->execute();
}

void Moteur::addJoueur(int ind,int num,int nbBat,int nbPort1,int nbPort2){
	this->joueurs.push_back(Joueur::Joueur(num,nbBat,nbPort1,nbPort2));
}

void Moteur::lancerDes(){
	this->des.first.lancerDe();
	this->des.second.lancerDe();
}

void Moteur::passerAuJoueurSuivant(){
	int index;
	for(int i=0;i<this->nbJoueurs;i++){
		if(this->ordreJoueurs.at(i)==this->joueurCourant) index = i;
	}
	cout<<"Debut joueur suivant"<<endl;
	this->joueurCourant = this->ordreJoueurs.at((index+1)%this->nbJoueurs);
	cout<<this->joueurCourant<<endl;
	cout<<"Fin joueur suivant"<<endl;
}

vector<int> Moteur::getScores(){
	vector<int> res(4,-1);
	vector<Joueur>::iterator it;
	for(it = joueurs.begin();it!=joueurs.end();it++){
		int a = it->getBateau(1)->getNumPort();
		res.at(a-1) = it->getScore(a);
		if(this->nbJoueurs==2){
			int b = it->getBateau(2)->getNumPort();
			res.at(b-1) = it->getScore(b);
		}
	}
	return res;
}


void Moteur::setAngle(int ang){
	angle = ang;
	this->execute();
}

void Moteur::setPuissance(int puis){
	puissance = puis;
	this->execute();
}

void Moteur::setHistogramme(list<pair<double,double>>& hist){
	this->histogramme.clear();
	for(list<pair<double,double>>::iterator it=hist.begin();it!=hist.end();it++){
		cout<< "debut for set histogramme moteur" <<endl;
		this->histogramme.push_back(it->second);
		this->histogramme.push_back(it->first);
		cout<< "set histogramme moteur" <<endl;
	}
	cout<< "Fin histogramme moteur" <<endl;
}

void Moteur::setTrajectoireTir(vector<pair<double,double>>& traj){
	int cpt = 0;
	for(vector<pair<double,double>>::iterator it=traj.begin();it!=traj.end();it++){
		this->trajectoireTir.at(cpt++) = it->first;
		this->trajectoireTir.at(cpt++) = it->second;
	}
}

Bateau* Moteur::getBateau(int joueur,int numPort){
	if(this->getJoueur(joueur).getBateau(1)->getNumPort()==numPort){
		return this->getJoueur(joueur).getBateau(1);
	}
	else{
		return this->getJoueur(joueur).getBateau(2);
	}
}