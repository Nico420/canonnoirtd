#include "Plateau.h"

Plateau::Plateau(){
			for(int i=0;i<11;i++){
				for(int j=0;j<8;j++){
					tab_case[i][j]=Case();
				}
			}
		}

	void Plateau::libereCase(int x,int y){
		Case test = tab_case[x][y];
	}

	Etat Plateau::getEtat(int x, int y){
		return tab_case[x][y].Case::getEtat();
	}

	bool Plateau::estNavigable(int x, int y){
		return tab_case[x][y].getEstNavigable();
	}

