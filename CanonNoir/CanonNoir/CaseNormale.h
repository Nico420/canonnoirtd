/**
*\file  CaseNormale.h
*\brief Class corresponding to a regular square placed on the board game
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef CASENORMALE_H
#define CASENORMALE_H

#pragma once
#include "Case.h"

/**
*\class CaseNormale
*\brief Class which represents a regular square placed on the board game
*/

class CaseNormale : public Case
{
	private :
		bool auBord;
	public :
		/**
		*\fn CaseNormale()
		*\brief default constructor
		*/
		CaseNormale() : Case(){};
		/**
		*\fn CaseNormale(int haut,bool nav,bool aubord)
		*\brief constructor of a regular square
		*\param haut Altitude of the square
		*\param nav Boolean which is true of the square is a waterway
		*\param aubord Boolean which is true of the square is on a side
		*/
		CaseNormale(int haut,bool nav,bool aubord) : Case(haut,nav),auBord(aubord){};
		/**
		*\fn bool estAuBord() const
		*\brief gets if the current regular square is on a side
		*\return a boolean true if the current square is on a side, else false
		*/
		bool estAuBord() const;
		/**
		*\fn bool getEstNavigable() const
		*\brief gets if the current regular square is a waterway
		*\return a boolean true if the current square is a waterway, else false
		*/
		bool getEstNavigable() const;
		/**
		*\fn int getEtat() const
		*\brief gets the state of the current regular square (which means here what is the next state if a boat is on)
		*\return the number of the state corresponding
		*/
		int getEtat() const;

};

inline bool CaseNormale::estAuBord() const{
	return auBord;
}

#endif