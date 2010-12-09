#include "Plateau.h"

Plateau::Plateau(){
	for(int i=0;i<11;i++){
		for(int j=0;j<8;j++){
			this->tab_case[i][j] = Case();
		}
	}
}

void Plateau::libereCase(int x,int y){
	tab_case[x][y].libereCase();
}

int Plateau::getEtat(int x, int y) const{
	return tab_case[x][y].getEtat();
}

bool Plateau::estNavigable(int x, int y) const{
	return tab_case[x][y].getEstNavigable();
}


Case Plateau::getCase(int x, int y) const{
	return tab_case[x][y];
}