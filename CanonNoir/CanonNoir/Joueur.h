#ifndef JOUEUR_H
#define JOUEUR_H
#pragma once
#include "Bateau.h"
#include <map>

class Joueur
{
	private :
		std::map<int,int> score;
		int num;
		Bateau* bateaux [2];
		
	public :
		Joueur();
		Joueur(int num,int nbBat,int nbPort1,int nbPort2);
		~Joueur();
		void degraderBateau(int x,int y);
		int getScore(int x,int y) const;
		int getScore(int nbPort) const;
		void setScore(int x,int y);
		int getNum() const;
		Bateau* getBateau(int nb);
		void rentreAuPort(int x,int y);
};

inline int Joueur::getNum() const{
	return num;
}

inline Bateau* Joueur::getBateau(int nb){
	return this->bateaux[nb-1];
}

#endif