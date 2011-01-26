/**
*\file  PartieGagnee.h
*\brief Class corresponding to the state where a player has won, the game is over
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef PARTIEGAGNEE_H
#define PARTIEGAGNEE_H
#pragma once
#include "Etat.h"

/**
*\class PartieGagnee
*\brief Class which is a state where a player has managed to bring three treasures to one of its own ports
*/

class PartieGagnee : public Etat
{
	private :
		int gagnant;

	protected :
		std::string message;
		Moteur* moteur;

	public :
		/**
		*\fn PartieGagnee()
		*\brief default constructor
		*/
		PartieGagnee() : message(""),moteur(NULL){};
		/**
		*\fn PartieGagnee(Moteur* mot)
		*\brief constructor of the state where a player has won
		*\param mot Pointer of the motor of the application
		*/
		PartieGagnee(Moteur* mot) : message(""),moteur(mot){};
		/**
		*\fn virtual void execute()
		*\brief does the actions that must be done in the current state
		*/
		virtual void execute();
		/**
		*\fn void setMessage(std::string mes)
		*\brief sets the message mes in the current state
		*\param mes The message that the current state must set
		*/
		void setMessage(std::string mes);
		/**
		*\fn std::string getMessage() const
		*\brief gets the message of the current state
		*\return the message of the current state
		*/
		std::string getMessage() const;

}; 

#endif