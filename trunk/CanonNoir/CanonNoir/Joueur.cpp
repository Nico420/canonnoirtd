#include "Joueur.h"
#include "Caravelle.h"
#include "Fregate.h"
#include "Radeau.h"
#include <typeinfo>
#include <iostream>

Joueur::Joueur(){
	this->num = 0;
	this->bateaux[0] = NULL;
	this->bateaux[1] = NULL;
}

Joueur::Joueur(int num,int nbBat,int nbPort1,int nbPort2){
	this->num = num;
	this->score[nbPort1] = 0;
	int x1 = (nbPort1==1 || nbPort1==3)? 1 : 11;
	int y1 = (nbPort1==1 || nbPort1==2)? 1 : 8;
	this->bateaux[0] = new Caravelle(false,x1,y1,x1,y1);
	if(nbBat==2){
		this->score[nbPort2] = 0;
		int x2 = (nbPort2==1 || nbPort2==3)? 1 : 11;
		int y2 = (nbPort2==1 || nbPort2==2)? 1 : 8;
		this->bateaux[1] = new Caravelle(false,x2,y2,x2,y2);
	}
}

Joueur::~Joueur(){
}

void Joueur::setScore(int x,int y){
	int i = (this->bateaux[0]->getPosition().first==x && this->bateaux[0]->getPosition().second==y)? 0 : 1;
	if(this->bateaux[i]->aTresorABord()) this->score[this->bateaux[i]->getNumPort()]++;
	std::cout<<"Map size :"<<score.size()<<std::endl;
	this->bateaux[i]->enleveTresor();
}

void Joueur::degraderBateau(int x,int y){
	std::cout<<"dégrader"<<std::endl;
	int i = (this->bateaux[0]->getPosition().first==x && this->bateaux[0]->getPosition().second==y)? 0 : 1;
	if(typeid(this->bateaux[i])==typeid(Caravelle*)){
		delete this->bateaux[i];
		Fregate* freg = new Fregate(this->bateaux[i]);
		this->bateaux[i] = freg;
	}
	else if(typeid(this->bateaux[i])==typeid(Fregate*)){
		delete this->bateaux[i];
		Radeau* rad = new Radeau(this->bateaux[i]);
		this->bateaux[i] = rad;
	}
}

int Joueur::getScore(int x,int y) const{
	int numPort = 0;
	if(x==1 && y==1) numPort = 1;
	if(x==11 && y==1) numPort = 2;
	if(x==1 && y==8) numPort = 3;
	if(x==11 && y==8) numPort = 4;
	return this->score.find(numPort)->second;
}

int Joueur::getScore(int nbPort) const{
	if(this->score.count(nbPort)>0){
		return this->score.find(nbPort)->second;
	}
	else{
		return -1;
	}
}

void Joueur::rentreAuPort(int x,int y){
	int i = (this->bateaux[0]->getPosition().first==x && this->bateaux[0]->getPosition().second==y)? 0 : 1;
	Bateau* bat = this->bateaux[i];
	this->bateaux[i] = new Caravelle(this->bateaux[i]);
	delete bat;
}