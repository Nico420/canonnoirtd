/**
*\file  Joueur.h
*\brief Class corresponding to each player of the application
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef JOUEUR_H
#define JOUEUR_H
#pragma once

#include "Bateau.h"
#include <map>

/**
*\class Joueur
*\brief Class which represents each player
*/

class Joueur
{
	private :
		std::map<int,int> score;
		int num;
		Bateau* bateaux [2];
		
	public :
		/**
		*\fn Joueur()
		*\brief default constructor
		*/
		Joueur();
		/**
		*\fn Joueur(int num,int nbBat,int nbPort1,int nbPort2)
		*\brief constructor of a player
		*\param num Number of the player (from 1 to 4)
		*\param nbBat Number of boats controled by the current player
		*\param nbPort1 Number of the first port chosen by the current player
		*\param nbPort2 Number of the second port chosen by the current player (if there is 2 players, 0 else by default)
		*/
		Joueur(int num,int nbBat,int nbPort1,int nbPort2);
		/**
		*\fn ~Joueur()
		*\brief destructor of the player
		*/
		~Joueur();
		/**
		*\fn void degraderBateau(int x,int y)
		*\brief degrade the player's boat at the position (x,y). It means a caravel becomes a frigate, a frigate becomes a raft, else it happens nothing
		*\param x Abscissa of the position of the boat to degrade
		*\param y Ordinate of the position of the boat to degrade
		*/
		void degraderBateau(int x,int y);
		/**
		*\fn int getScore(int x,int y) const
		*\brief get the score of the port at position (x,y), owned by the current player
		*\param x Abscissa of the position of the port
		*\param y Ordinate of the position of the port
		*\return number of treasures got by the player at this port
		*/
		int getScore(int x,int y) const;
		/**
		*\fn int getScore(int nbPort) const
		*\brief get the score of the port with the number nbPort, owned by the current player
		*\param nbPort Number of the port
		*\return number of treasures got by the player at this port
		*/
		int getScore(int nbPort) const;
		/**
		*\fn void setScore(int x,int y)
		*\brief set the score at the port at position (x,y), and remove the treasure on the boat if it's on that port
		*\param x Abscissa of the position of the port
		*\param y Ordinate of the position of the port
		*/
		void setScore(int x,int y);
		/**
		*\fn int getNum() const
		*\brief get the number of the current player
		*\return number of the current player
		*/
		int getNum() const;
		/**
		*\fn Bateau* getBateau(int nb)
		*\brief get the pointer of boat with the number nb (1 or 2 according to the number of players)
		*\param nb Number of the boat wanted
		*\return the boat 1 or 2 owned by the current player
		*/
		Bateau* getBateau(int nb);
		/**
		*\fn void rentreAuPort(int x,int y)
		*\brief transform the boat on the port in caravel
		*\param x Abscissa of the position of the port
		*\param y Ordinate of the position of the port
		*/
		void rentreAuPort(int x,int y);
};

inline int Joueur::getNum() const{
	return num;
}

inline Bateau* Joueur::getBateau(int nb){
	return this->bateaux[nb-1];
}

#endif