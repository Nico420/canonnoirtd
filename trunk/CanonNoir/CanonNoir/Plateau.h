#ifndef PLATEAU_H
#define PLATEAU_H

#pragma once

/**
*\file  Plateau.h
*\brief Class corresponding to the game board
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/

#include "Case.h"
#include <vector>

/**
*\class Plateau
*\brief Class which represents the game board
*/

class Plateau
{
	private :
		static const int longueur = 11;
		static const int largeur = 8;
		Case* tab_case [longueur][largeur];
		
	public :
		/**
		*\fn Plateau()
		*\brief default constructor
		*/
		Plateau();
		/**
		*\fn ~Plateau()
		*\brief destructor of the game board
		*/
		~Plateau();
		/**
		*\fn int getLargeur() const
		*\brief get the width of the board game (in squares)
		*\return number of squares on the width
		*/
		int getLargeur() const;
		/**
		*\fn int getLongueur() const
		*\brief get the length of the board game (in squares)
		*\return number of squares on the length
		*/
		int getLongueur() const;
		/**
		*\fn Case* getCase(int x, int y)
		*\brief get the square at the position (x,y) (beginnig at 1)
		*\param x Abscissa of the position of the square wanted
		*\param y Ordinate of the position of the square wanted
		*\return a pointer of the case wanted
		*/
		Case* getCase(int x, int y);
		/**
		*\fn void libereCase(int x,int y)
		*\brief free the square at position (x,y) (used when the boat leaves it)
		*\param x Abscissa of the position of the square freed
		*\param y Ordinate of the position of the square freed
		*/
		void libereCase(int x,int y);
		/**
		*\fn void occupeCase(int x,int y)
		*\brief put taken the square at position (x,y) (used when the boat arrives on it)
		*\param x Abscissa of the position of the square taken
		*\param y Ordinate of the position of the square taken
		*/
		void occupeCase(int x,int y);
		/**
		*\fn void enleveUnTresor(int x,int y)
		*\brief remove one treasure on the square at position (x,y), if there is at least one treasure on
		*\param x Abscissa of the position of the square wanted
		*\param y Ordinate of the position of the square wanted
		*/
		void enleveUnTresor(int x,int y);
		/**
		*\fn bool estPort(int x,int y) const
		*\brief tests if the square at position (x,y) is a port
		*\param x Abscissa of the position of the square tested
		*\param y Ordinate of the position of the square tested
		*\return a boolean if the square is a port, else false
		*/
		bool estPort(int x,int y) const;
		/**
		*\fn int getEtat(int x,int y) const
		*\brief get the state returned by the square at position (x,y)
		*\param x Abscissa of the position of the square wanted
		*\param y Ordinate of the position of the square wanted
		*\return the number of the state returned by the square at (x,y)
		*/
		int getEtat(int x,int y) const;
		/**
		*\fn bool estNavigable(int x,int y) const
		*\brief tests if the square at position (x,y) is a waterway
		*\param x Abscissa of the position of the square tested
		*\param y Ordinate of the position of the square tested
		*\return a boolean if the square is a waterway, else false
		*/
		bool estNavigable(int x,int y) const;
		/**
		*\fn int getNbTresors(int x,int y) const
		*\brief gets the number of treasures placed on the square at position (x,y)
		*\param x Abscissa of the position of the square tested
		*\param y Ordinate of the position of the square tested
		*\return the number of treasures placed on the square at (x,y)
		*/
		int getNbTresors(int x,int y) const;
		/**
		*\fn int getHauteur(int x,int y) const
		*\brief gets the altitude of the square at position (x,y)
		*\param x Abscissa of the position of the square wanted
		*\param y Ordinate of the position of the square wanted
		*\return the altitude of the square at (x,y)
		*/
		int getHauteur(int x,int y) const;
}; 

inline int Plateau::getLargeur() const{
	return this->largeur;
}

inline int Plateau::getLongueur() const{
	return this->longueur;
}

#endif