/**
*\file  CaseCanon.h
*\brief Class corresponding to a cannon square placed on the board game
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef CASECANON_H
#define CASECANON_H

#pragma once
#include "Case.h"

/**
*\class CaseCanon
*\brief Class which represents a cannon square placed on the board game
*/

class CaseCanon : public Case
{
	public :
	/**
		*\fn CaseCanon()
		*\brief default constructor
		*/
		CaseCanon() : Case(0,true){};
		/**
		*\fn int getEtat() const
		*\brief gets the state of the current square (which means here what is the next state if a boat is on)
		*\return the number of the state corresponding
		*/
		int getEtat() const;
};

#endif