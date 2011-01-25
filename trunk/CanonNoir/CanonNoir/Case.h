/**
*\file  Case.h
*\brief Class corresponding to a square placed on the board game
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/

#ifndef CASE_H
#define CASE_H
#pragma once

/**
*\class Case
*\brief Class which represents a square placed on the board game
*/

class Case
{
	protected :
		int hauteur;
		bool estNavigable;

	public :
		/**
		*\fn Case()
		*\brief default constructor
		*/
		Case():hauteur(0),estNavigable(false){};
		/**
		*\fn Case(int haut,bool nav)
		*\brief constructor of a square
		*\param haut Altitude of the square
		*\param nav Boolean which is true of the square is a waterway
		*/
		Case(int haut,bool nav);
		/**
		*\fn ~Case()
		*\brief destructor of a square
		*/
		virtual ~Case(){};
		/**
		*\fn virtual bool getEstNavigable() const
		*\brief gets if the current square is a waterway
		*\return a boolean true if the current square is a waterway, else false
		*/
		virtual bool getEstNavigable() const;
		/**
		*\fn virtual void setEstNavigable(bool b)
		*\brief sets the current square as a waterway or not
		*\param b Boolean which is set at true of the square will be a waterway
		*/
		virtual void setEstNavigable(bool b);
		/**
		*\fn virtual void libereCase()
		*\brief free the current square (used when the boat leaves it)
		*/
		virtual void libereCase();
		/**
		*\fn int getHauteur() const
		*\brief gets the altitude of the current square
		*\return the altitude of the current square
		*/
		int getHauteur() const;
		/**
		*\fn virtual int getNbTresors() const
		*\brief gets the number of treasures placed on the current square
		*\return the number of treasures placed on the current square
		*/
		virtual int getNbTresors() const;
		/**
		*\fn virtual void enleveUnTresor()
		*\brief remove one treasure on the current square, if there is at least one treasure on
		*/
		virtual void enleveUnTresor();
		/**
		*\fn virtual bool estPort() const
		*\brief tests if the current square is a port
		*\return a boolean if the current square is a port, else false
		*/
		virtual bool estPort() const;
		/**
		*\fn virtual int getEtat() const
		*\brief gets the state of the current square (which means here what is the next state if a boat is on)
		*\return the number of the state corresponding
		*/
		virtual int getEtat() const;
};

inline bool Case::getEstNavigable() const {
	return this->estNavigable;
}

inline void Case::setEstNavigable(bool b){
	this->estNavigable=b;
}

inline int Case::getHauteur() const{
	return this->hauteur;
}

inline int Case::getNbTresors() const{
	return 0;
}

inline bool Case::estPort() const{
	return false;
}

#endif