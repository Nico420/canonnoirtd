/**
*\file  AttenteNbJoueurs.h
*\brief Class corresponding to the state of waiting the number of players at the beginning of the game
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef ATTENTENBJOUEURS_H
#define ATTENTENBJOUEURS_H
#pragma once

#include <iostream>

#include "Etat.h"
#include "Facade.h"

/**
*\namespace std
* Namespace gathering the entire STL library
*/

using namespace std;

/**
*\class AttenteNbJoueurs
*\brief Class which is a state which waits the number of players
*/

class AttenteNbJoueurs : public Etat
{
	protected :
		std::string message;
		Moteur* moteur;

	public :
		/**
		*\fn AttenteNbJoueurs()
		*\brief default constructor
		*/
		AttenteNbJoueurs() : message(""),moteur(NULL){};
		/**
		*\fn AttenteNbJoueurs(Moteur* mot)
		*\brief constructor of the state which waits the number of players
		*\param mot Pointer of the motor of the application
		*/
		AttenteNbJoueurs(Moteur* mot) : message(""),moteur(mot){};
		/**
		*\fn ~AttenteNbJoueurs()
		*\brief destructor of the state which waits the number of players
		*/
		~AttenteNbJoueurs();
		/**
		*\fn string getMessage() const
		*\brief gets the message of the current state
		*\return the message of the current state
		*/
		string getMessage() const;
		/**
		*\fn void execute()
		*\brief does the actions that must be done in the current state
		*/
		void execute();
		/**
		*\fn void setMessage(std::string mes)
		*\brief sets the message mes in the current state
		*\param mes The message that the current state must set
		*/
		void setMessage(std::string mes);

}; 

inline string AttenteNbJoueurs::getMessage() const{
	return this->message;
}

#endif