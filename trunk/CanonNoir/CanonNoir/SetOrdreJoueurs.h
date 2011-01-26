/**
*\file  SetOrdreJoueurs.h
*\brief Class corresponding to the state where the order of players is set (throwing dices)
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef SETORDREJOUEURS_H
#define SETORDREJOUEURS_H
#pragma once

#include "LancerDes.h"
#include "Moteur.h"
#include <map>

/**
*\class SetOrdreJoueurs
*\brief Class which is a state where the order of players is set (throwing dices)
*/

class SetOrdreJoueurs : public LancerDes
{
	private :
		std::map<int,int> scoreDesJoueurs;
		int etatsuivant;

	public :
	/**
		*\fn SetOrdreJoueurs()
		*\brief default constructor
		*/
		SetOrdreJoueurs() : LancerDes(NULL),etatsuivant(0){};
		/**
		*\fn SetOrdreJoueurs(Moteur* mot)
		*\brief constructor of the state where the order of players is set (throwing dices)
		*\param mot Pointer of the motor of the application
		*/
		SetOrdreJoueurs(Moteur* mot) : LancerDes(mot),etatsuivant(Moteur::SETORDREJOUEURS){};
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

inline int SetOrdreJoueurs::getEtat() const{
	return this->etatsuivant;
}

#endif