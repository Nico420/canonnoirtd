/**
*\file  TirCanonDuel.h
*\brief Class corresponding to the state of shooting a player with a cannon when the two boats involved are on the board game side, face to face
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef TIRCANONDUEL_H
#define TIRCANONDUEL_H
#pragma once
#include "TirCanon.h"

/**
*\class TirCanonDuel
*\brief Class which is a state where the current player shoots a player thanks to a cannon when the two
* boats involved are on the board game side, face to face
*/

class TirCanonDuel : public TirCanon
{
	private :
		bool premierTir;
		int joueurAttaquant;
		int joueurAttaque;
	public :
		/**
		*\fn TirCanonDuel()
		*\brief default constructor
		*/
		TirCanonDuel() : TirCanon(),premierTir(true),joueurAttaquant(0){};
		/**
		*\fn TirCanonDuel(Moteur* mot)
		*\brief constructor of the state where the current player can shoot another player (on board game side, face to face)
		*\param mot Pointer of the motor of the application
		*/
		TirCanonDuel(Moteur* mot) : TirCanon(mot),premierTir(true),joueurAttaquant(0){};
		/**
		*\fn virtual void execute()
		*\brief does the actions that must be done in the current state
		*/
		virtual void execute();
		/**
		*\fn void echangeDuel()
		*\brief does the exchanges of player who attacks and player who is attacked (in case the player who has attacked failed its shoot)
		*/
		void echangeDuel();
		/**
		*\fn virtual int getEtat() const
		*\brief gets the indice of the next state that the motor has to be fixed at
		*\return the indice of the next state that the motor has to be fixed at
		*/
		virtual int getEtat() const;
};

inline int TirCanonDuel::getEtat() const{
	return this->etatsuivant;
}

#endif