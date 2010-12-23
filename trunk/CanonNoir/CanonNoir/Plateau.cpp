#include "Plateau.h"

Plateau::Plateau(){
	for(int i=0;i<11;i++){
		for(int j=0;j<8;j++){
			this->tab_case[i][j] = Case();
		}
	}
}

void Plateau::libereCase(int x,int y){
	tab_case[x-1][y-1].libereCase();
}

void Plateau::occupeCase(int x,int y){
	tab_case[x-1][y-1].setEstNavigable(false);
}

void Plateau::enleveUnTresor(int x,int y){
	this->tab_case[x-1][y-1].enleveUnTresor();
}

int Plateau::getEtat(int x, int y) const{
	return tab_case[x-1][y-1].getEtat();
}

bool Plateau::estNavigable(int x, int y) const{
	return tab_case[x-1][y-1].getEstNavigable();
}

bool Plateau::estPort(int x,int y) const{
	return tab_case[x-1][y-1].estPort();
}

Case& Plateau::getCase(int x, int y){
	return tab_case[x-1][y-1];
}

int Plateau::getNbTresors(int x,int y) const{
	return this->tab_case[x-1][y-1].getNbTresors();
}