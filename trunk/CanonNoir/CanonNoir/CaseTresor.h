/**
*\file  CaseTresor.h
*\brief Class corresponding to a treasure square placed on the board game
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/

#ifndef CASETRESOR_H
#define CASETRESOR_H

#pragma once
#include "Case.h"

/**
*\class CaseTresor
*\brief Class which represents a treasure square placed on the board game
*/

class CaseTresor : public Case
{
	private :
		int nbTresors;

	public :
		/**
		*\fn CaseTresor()
		*\brief default constructor
		*/
		CaseTresor() : Case(){};
		/**
		*\fn CaseTresor(int nbtres)
		*\brief constructor of a treasure square
		*\param nbtres number of treasures placed on the square at the beginning of the game
		*/
		CaseTresor(int nbtres) : Case(0,true),nbTresors(nbtres){};
		/**
		*\fn int getNbTresors() const
		*\brief gets the number of treasures placed on the current treasure square
		*\return the number of treasures placed on the current treasure square
		*/
		int getNbTresors() const;
		/**
		*\fn void enleveUnTresor()
		*\brief remove one treasure on the current treasure square, if there is at least one treasure on
		*/
		void enleveUnTresor();
		/**
		*\fn int getEtat() const
		*\brief gets the state of the current treasure square (which means here what is the next state if a boat is on)
		*\return the number of the state corresponding
		*/
		int getEtat() const;
}; 

inline int CaseTresor::getNbTresors() const{
	return this->nbTresors;
}
inline void CaseTresor::enleveUnTresor(){
	this->nbTresors--;
}

#endif