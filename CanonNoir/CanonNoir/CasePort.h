/**
*\file  CasePort.h
*\brief Class corresponding to a port square placed on the board game
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef CASEPORT_H
#define CASEPORT_H

#pragma once
#include "Case.h"

/**
*\class CasePort
*\brief Class which represents a port square placed on the board game
*/

class CasePort : public Case
{
	private :

	public :
		/**
		*\fn CasePort()
		*\brief default constructor
		*/
		CasePort() : Case(){};
		/**
		*\fn int getEtat() const
		*\brief gets the state of the current port square (which means here what is the next state if a boat is on)
		*\return the number of the state corresponding
		*/
		int getEtat() const;

};
/*
inline bool CasePort::estPort() const{
	return true;
}*/

#endif