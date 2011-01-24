#include "Facade.h"
#include "SetOrdreJoueurs.h"
#include <iostream>
#include <math.h>


#define NBPOINTS 100

Facade::Facade(){
	this->motor = new Moteur();
	int dim = this->motor->getPlateau().getLongueur()*this->motor->getPlateau().getLargeur();
	this->casesActives = new int[dim];
	for(int i=0;i<dim;i++){
		this->casesActives[i] = 0;
	}

	this->affichePlateau = true;
	this->afficheCanon = false;
	this->affichePorts = false;
	this->afficheBat = false;
	this->afficheSco = false;
	this->message = this->motor->getEtat()->getMessage();
	this->scoresBateaux = NULL;
	this->nbBateaux = 0;
	this->afficheAttenteNbJoueurs = true;
	this->afficheJeuNormal = false;
	this->activeDe1 = false;
	this->activeDe2 = false;
	this->activeCases = false;
	this->activeLancerDes = false;
	this->de1 = 1;
	this->de2 = 1;
	this->motor->execute();
}

Facade::~Facade(){
	delete this->motor;
	delete[] this->casesActives;
	delete[] this->scoresBateaux;
	delete[] this->infosBateaux;
}

void Facade::setNbJoueurs(int nb){
	this->motor->setNbJoueurs(nb);
	this->message = this->motor->getEtat()->getMessage();
	this->nbBateaux = (nb==3)? 3 : 4;
	this->scoresBateaux = new int[this->nbBateaux];
	for(int i=0;i<this->nbBateaux;i++) this->scoresBateaux[i] = -1;
	this->afficheAttenteNbJoueurs = false;
	this->afficheJeuNormal = true;
	this->activeDe1 = false;
	this->activeDe2 = false;
	this->activeLancerDes = false;
	this->affichePorts=true;
	this->miseAJourCasesActives(this->motor->getEtat()->getCasesActives());
	this->activeCases = true;
	this->infosBateaux = (this->motor->getNbJoueurs()==3)? new int[15] : new int[20];
}

void Facade::setClick(int x,int y){
	this->motor->setClick(x,y);
	this->message = this->motor->getEtat()->getMessage();
	if(this->motor->getEtat()->getEtat()!=Moteur::NAVIGATION && this->motor->getEtat()->getEtat()!=0)
		this->miseAJourCasesActives(this->motor->getEtat()->getCasesActives());
	if(this->motor->getEtat()->getEtat()==Moteur::CHOISIRPORT){
		this->activeCases = true;
	}
	else if(this->motor->getEtat()->getEtat()==Moteur::SETORDREJOUEURS){
		this->afficheSco = true;
		this->miseAJourInfosPorts(this->motor->getPosBateaux());
		this->miseAJourScores(this->motor->getScores());
		cout<<"Après maj scores"<<endl;
		/*cout<<"begin"<<endl;
		for(int i=0;i<15;i++){
			cout<<infosBateaux[i]<<endl;
		}*/
		this->motor->setEtat(Moteur::SETORDREJOUEURS);
		this->activeLancerDes = true;
		this->activeDe1 = true;
		this->activeDe2 = true;
		this->activeCases = false;
		this->affichePorts = false;
		this->afficheBat = true;	
	}
	else if(this->motor->getEtat()->getEtat()==Moteur::LANCERDESDEPLACEMENT){
		this->miseAJourInfosPorts(this->motor->getPosBateaux());
		cout<<"begin"<<endl;
		for(int i=0;i<20;i++){
			//cout<<infosBateaux[i]<<endl;
		}
		this->miseAJourScores(this->motor->getScores());
		cout<<"score :"<<endl;
		for(int i=0;i<4;i++) cout<<this->scoresBateaux[i]<<endl;
		this->motor->setEtat(Moteur::LANCERDESDEPLACEMENT);
		this->activeLancerDes = true;
		this->activeDe1 = true;
		this->activeDe2 = this->motor->getEtat()->getActiveDe2();
		this->activeCases = false;
		this->affichePorts = false;
		this->afficheBat = true;
	}
	else if(this->motor->getEtat()->getEtat()==Moteur::TIRCANONUNIQUE){
		this->miseAJourInfosPorts(this->motor->getPosBateaux());
		cout<<"Construction de l'état tircanonunique"<<endl;
		this->motor->setEtat(Moteur::TIRCANONUNIQUE);
		cout<<"Fin construction de l'état tircanonunique"<<endl;
		this->afficheCanon = true;
	}
}

void Facade::lancerDes(){
	this->motor->execute();
	cout<<"Fin du execute de lancerDes"<<endl;
	this->message = this->motor->getEtat()->getMessage();
	this->miseAJourInfosPorts(this->motor->getPosBateaux());
	this->de1 = this->motor->getDe1();
	this->de2 = this->motor->getDe2();
	if(this->motor->getEtat()->getEtat()==Moteur::LANCERDESDEPLACEMENT){
		for(int i=0;i<20;i++){
			cout<<this->infosBateaux[i]<<" ";
		}
		cout <<endl;
		this->motor->setEtat(Moteur::LANCERDESDEPLACEMENT);
		this->activeCases = false;
		this->activeLancerDes = true;
	}
	else if(this->motor->getEtat()->getEtat()==Moteur::NAVIGATION){
		cout<<"FACADE - avant miseajourCasesActives"<<endl;
		this->miseAJourCasesActives(this->motor->getEtat()->getCasesActives());
		cout<<"FACADE - avant miseajourCasesActives"<<endl;
		this->motor->setEtat(Moteur::NAVIGATION);
		this->activeCases = true;
		this->activeDe1 = true;
		this->activeDe2 = this->motor->getEtat()->getActiveDe2();
		bool a = this->casesDispo(this->getCasesActives());
		if(a){
			this->activeLancerDes = true;
		}else{
			this->activeLancerDes = false;
		}
	}
}

void Facade::setAngle(int angle){
	cout<<"Appel de setAngle dans Facade"<<endl;
	motor->setAngle(angle);
	this->message = this->motor->getEtat()->getMessage();
}

void Facade::setPuissance(int puissance){
	cout<<"Appel de setPuissance dans Facade"<<endl;
	motor->setPuissance(puissance);
	this->message = this->motor->getEtat()->getMessage();
}

bool Facade::casesDispo(int* t){
	for(int i=0;i<88;i++){
		if(t[i]==1) return false;
	}
	return true;
}

void Facade::miseAJourCasesActives(std::vector<int> caseActives){
	for(int i=0;i<this->motor->getPlateau().getLongueur()*this->motor->getPlateau().getLargeur();i++){
		this->casesActives[i] = caseActives.at(i);
	}
}

void Facade::miseAJourInfosPorts(std::vector<int> infos){
	for(int i=0;i<infos.size();i++){
		this->infosBateaux[i] = infos.at(i);
	}
}

void Facade::miseAJourScores(std::vector<int> scores){
	for(int i=0;i<scores.size();i++){
		this->scoresBateaux[i] = scores.at(i);
	}
}

int* Facade::getTrajectoire(int angle, int puissance){
	int pi=3.1415;
	double angle_rad = 2*pi*angle/360;
	double vx = puissance * cos((double)angle);
	double vz = puissance * sin((double)angle);
	int res[NBPOINTS];
	cout<<"test"<<endl;
	//On stock en i z et en i+1 x
	for(int i=0;i<NBPOINTS;i=i+2){
		res[i] = -0.5*9.81*i*i/(puissance*puissance*cos((double) angle)*cos((double) angle))+i*tan((double) angle);
		cout<<res[i]<<endl;
	}
	return res;
}

EXTERNC DLL Facade* Facade_New(){
	return new Facade();
}
EXTERNC DLL void Facade_Delete(Facade* f){
	delete f;
}