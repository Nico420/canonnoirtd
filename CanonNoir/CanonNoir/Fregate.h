#ifndef FREGATE_H
#define FREGATE_H
#pragma once

/**
*\file  Fregate.h
*\brief Class corresponding to frigates of the application
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/

#include "Bateau.h"

/**
*\class Fregate
*\brief Class which is one of the game's boats, frigates
*/

class Fregate : public Bateau
{
	public :
		/**
		*\fn Fregate()
		*\brief default constructor
		*/
		Fregate() : Bateau(){};
		/**
		*\fn Fregate(bool tres, int posx, int posy, int posPortx, int posPorty)
		*\brief constructor of frigates
		*\param tres Boolean which says if the boat owns a treasure
		*\param posx Abscissa of boat's current position
		*\param posy Ordinate of boat's current position
		*\param posPortx Abscissa of boat's port
		*\param posPorty Ordinate of boat's port
		*/
		Fregate(bool tres, int posx, int posy, int posPortx, int posPorty) : 
			Bateau(1,tres,posx,posy,posPortx,posPorty){};
		/**
		*\fn Fregate(const Bateau* bat)
		*\brief constructor of frigates from another boat
		*\param bat A boat that is wanted to copy to the current frigate
		*/
		Fregate(const Bateau* bat);
		/**
		*\fn virtual ~Fregate()
		*\brief destructor of frigates
		*/
		virtual ~Fregate();
		/**
		*\fn virtual int getType() const
		*\brief get the current boat's type
		*\return the number representing the current boat's type
		*/
		virtual int getType() const;
};

#endif