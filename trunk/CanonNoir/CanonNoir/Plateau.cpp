#include "Plateau.h"

Plateau::Plateau(int lo, int la){
			for(int i=0;i<11;i++){
				for(int i=0;i<11;i++){
				
				}
			}
		}

	void Plateau::libereCase(int x,int y){
		tab_case[x][y].libereCase();
	}

	Etat& Plateau::getEtat(int x, int y){
		return tab_case[x][y].getEtat();
	}

	bool Plateau::estNavigable(int x, int y){
		return tab_case[x][y].getEstNavigable();
	}

