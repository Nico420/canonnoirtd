/**
*\file  ChoisirPort.h
*\brief Class corresponding to the state of choosing each port of each player at the beginning of the game
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef CHOISIRPORT_H
#define CHOISIRPORT_H

#pragma once
#include "Etat.h"

/**
*\class ChoisirPort
*\brief Class which is a state where each player chooses its port
*/

class ChoisirPort : public Etat
{
	private :
		int* portsLibres;
		int compteur;
		int port1;
		int port2;
		int etatsuivant;

	protected :
		std::string message;
		Moteur* moteur;

	public :
		/**
		*\fn ChoisirPort()
		*\brief default constructor
		*/
		ChoisirPort();
		/**
		*\fn ChoisirPort(Moteur* mot)
		*\brief constructor of the state where each player chooses its port
		*\param mot Pointer of the motor of the application
		*/
		ChoisirPort(Moteur* mot);
		/**
		*\fn ~ChoisirPort()
		*\brief destructor of the state where each player chooses its port
		*/
		~ChoisirPort();
		/**
		*\fn void execute()
		*\brief does the actions that must be done in the current state
		*/
		void execute();
		/**
		*\fn void setPortsLibres(int i)
		*\brief sets the port i with the current player
		*\param i Indice of the chosen port
		*/
		void setPortsLibres(int i);
		/**
		*\fn bool estLibre(int i) const
		*\brief tests if the port i has already been chosen
		*\param i Indice of the tested port
		*/
		bool estLibre(int i) const;
		/**
		*\fn string getMessage() const
		*\brief gets the message of the current state
		*\return the message of the current state
		*/
		std::string getMessage() const;
		/**
		*\fn void setMessage(std::string mes)
		*\brief sets the message mes in the current state
		*\param mes The message that the current state must set
		*/
		inline void setMessage(std::string mes){this->message = mes;};
		/**
		*\fn std::vector<int> getCasesActives() const
		*\brief gets all the ports that are still free
		*\return all the ports that are still free
		*/
		std::vector<int> getCasesActives() const;
		/**
		*\fn int getEtat() const
		*\brief gets the indice of the next state that the motor has to be fixed at
		*\return the indice of the next state that the motor has to be fixed at
		*/
		int getEtat() const;

};

inline void ChoisirPort::setPortsLibres(int i){
	this->portsLibres[i-1] = 0;
}

inline std::string ChoisirPort::getMessage() const{
	return this->message;
}

inline int ChoisirPort::getEtat() const{
	return this->etatsuivant;
}

#endif