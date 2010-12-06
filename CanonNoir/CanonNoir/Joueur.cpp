#include "Joueur.h"
#include "Caravelle.h"

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