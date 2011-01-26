/**
*\file  Etat.h
*\brief Class corresponding to an abstract state taken by the motor
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef ETAT_H
#define ETAT_H

#pragma once

#include <string>
#include <vector>

/**
*\class Etat
*\brief Class which is an abstract state taken by the motor (all the states derive from it)
*/

class Moteur;

class Etat
{
	public :
		/**
		*\fn virtual void execute() = 0
		*\brief does the actions that must be done in the current state, has to be implemented in all states
		*/
		virtual void execute() = 0;
		/**
		*\fn virtual void setMessage(std::string mes)
		*\brief sets the message mes in the current state
		*\param mes The message that the current state must set
		*/
		virtual void setMessage(std::string mes);
		/**
		*\fn virtual int* getPortsLibres() const
		*\brief gets the ports that are free
		*\return a pointer of all the ports that are free
		*/
		virtual int* getPortsLibres() const;
		/**
		*\fn virtual std::string getMessage() const
		*\brief gets the message of the current state
		*\return the message of the current state
		*/
		virtual std::string getMessage() const;
		/**
		*\fn virtual int getEtat() const
		*\brief gets the indice of the next state that the motor has to be fixed at
		*\return the indice of the next state that the motor has to be fixed at
		*/
		virtual int getEtat() const;
		/**
		*\fn virtual std::vector<int> getCasesActives() const
		*\brief gets all the indices of the squares that must be activated
		*\return all the indices of the squares that must be activated
		*/
		virtual std::vector<int> getCasesActives() const;
		/**
		*\fn virtual bool getActiveDe2() const
		*\brief gets if the second dice has to be shown
		*\return boolean true if the second dice has to be shown, else false
		*/
		virtual bool getActiveDe2() const;
};

#endif