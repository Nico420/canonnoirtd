/**
*\file  LancerDes.h
*\brief Class corresponding to the state of throwing the dices
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef LANCERDES_H
#define LANCERDES_H
#pragma once

#include "Etat.h"

/**
*\class LancerDes
*\brief Class which is a state where the dices have been thrown, including to move the boats, and to set players' playing order
*/

class LancerDes : public Etat
{
	protected :
		std::string message;
		Moteur* moteur;

	public :
		/**
		*\fn LancerDes()
		*\brief default constructor
		*/
		LancerDes() : message(""),moteur(NULL){};
		/**
		*\fn LancerDes(Moteur* mot)
		*\brief constructor of the state where the dices have been thrown
		*\param mot Pointer of the motor of the application
		*/
		LancerDes(Moteur* mot) : message(""),moteur(mot){};
		/**
		*\fn virtual void execute()=0
		*\brief does the actions that must be done in the current state, must be implemented in derived classes
		*/
		virtual void execute()=0;
		/**
		*\fn virtual int* getCasesDeplacement() const
		*\brief gets the indices of squares that has to be proposed for boat's moves
		*\return a pointer on all indices of squares that has to be proposed for boat's moves
		*/
		virtual int* getCasesDeplacement() const;
		/**
		*\fn virtual int getNbCasesDeplacement() const
		*\brief gets the number of squares that has to be proposed for boat's moves
		*\return a number of squares that has to be proposed for boat's moves
		*/
		virtual int getNbCasesDeplacement() const;
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

inline void LancerDes::setMessage(std::string mes){
	this->message = mes;
}

inline std::string LancerDes::getMessage() const{
	return this->message;
}

#endif