#pragma once

#include "Case.h"
#include "Etat.h"

using namespace std;
class Plateau
{
	public :
		Case tab_case[11][8];
		static const int longueur=11;
		static const int largeur=8;
		
	public :
		Plateau();
		inline virtual int getLargeur(){return this->largeur;}
		inline virtual int getLongueur(){return this->longueur;}
		Case getCase(int x, int y){return tab_case[x][y];}
		void libereCase(int x,int y);
		class Etat getEtat(int x,int y);
		bool estNavigable(int x,int y);

}; 

