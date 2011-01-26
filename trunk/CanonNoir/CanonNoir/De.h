/**
*\file  De.h
*\brief Class corresponding to each dice of the application
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef DE_H
#define DE_H
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
*\class De
*\brief Class which represents a dice in the game
*/

class De
{
	private :
		int alea;

	public :
		/**
		*\fn De()
		*\brief default constructor
		*/
		De();
		/**
		*\fn De(int nb)
		*\brief constructor of a dice
		*\param nb Number that the dice will take
		*/
		De(int nb);
		int numero;
		/*~De();*/
		/**
		*\fn void lancerDe()
		*\brief throws the current dice randomly
		*/
		void lancerDe();
		/**
		*\fn int getNum() const
		*\brief gets the number that the dice has taken
		*\return the number that the dice has taken
		*/
		int getNum() const;

}; 

inline int De::getNum() const{
	return numero;
}

#endif