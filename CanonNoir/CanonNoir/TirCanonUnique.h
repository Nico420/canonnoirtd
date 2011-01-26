/**
*\file  TirCanonUnique.h
*\brief Class corresponding to the state of shooting a player with a cannon when a player is on a cannon square
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef TIRCANONUNIQUE_H
#define TIRCANONUNIQUE_H
#pragma once

#include "TirCanon.h"

/**
*\class TirCanonUnique
*\brief Class which is a state where the current player shoots a player thanks to a cannon the current player has arrived on a cannon square
*/

class TirCanonUnique : public TirCanon
{
	private :
		bool cibleChoisie;
	public :
		/**
		*\fn TirCanonUnique()
		*\brief default constructor
		*/
		TirCanonUnique() : TirCanon(),cibleChoisie(false){};
		/**
		*\fn TirCanonUnique(Moteur* mot)
		*\brief constructor of the state where the current player can shoot another player (on board game side, face to face)
		*\param mot Pointer of the motor of the application
		*/
		TirCanonUnique(Moteur* mot) : TirCanon(mot),cibleChoisie(false){};
		/**
		*\fn void setCible(int num)
		*\brief sets the target of the future current player shoot
		*\param num Number of the boat which will be targeted at the future shoot
		*/
		void setCible(int num);
		/**
		*\fn virtual void execute()
		*\brief does the actions that must be done in the current state
		*/
		virtual void execute();
		/**
		*\fn virtual int getEtat() const
		*\brief gets the indice of the next state that the motor has to be fixed at
		*\return the indice of the next state that the motor has to be fixed at
		*/
		virtual int getEtat() const;
};

inline int TirCanonUnique::getEtat() const{
	return this->etatsuivant;
}

#endif