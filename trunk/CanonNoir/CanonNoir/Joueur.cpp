#include "Joueur.h"
#include "Caravelle.h"
#include "Fregate.h"
#include "Radeau.h"
#include <typeinfo>

Joueur::Joueur(){
	this->num = 0;
	this->bateaux[0] = Caravelle();
	this->bateaux[1] = Caravelle();
}

Joueur::Joueur(int num,int nbBat,int nbPort1,int nbPort2){
	this->num = num;
	this->score[nbPort1] = 0;
	int x1 = (nbPort1==1 || nbPort1==3)? 1 : 11;
	int y1 = (nbPort1==1 || nbPort1==2)? 1 : 8;
	this->bateaux[0] = Caravelle(false,x1,y1,x1,y1);
	if(nbBat==2){
		this->score[nbPort2] = 0;
		int x2 = (nbPort2==1 || nbPort2==3)? 1 : 11;
		int y2 = (nbPort2==1 || nbPort2==2)? 1 : 8;
		this->bateaux[1] = Caravelle(false,x2,y2,x2,y2);
	}
}

Joueur::~Joueur(){
}

void Joueur::degraderBateau(int x,int y){
	int i = (this->bateaux[0].getPosition().first==x && this->bateaux[0].getPosition().second==y)? 0 : 1;
	if(typeid(this->bateaux[i])==typeid(Caravelle)){
		Fregate freg = Fregate(this->bateaux[i]);
		this->bateaux[i] = freg;
	}
	else if(typeid(this->bateaux[i])==typeid(Fregate*)){
		Radeau rad = Radeau(this->bateaux[i]);
		this->bateaux[i] = rad;
	}
}