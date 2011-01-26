/**
*\file  Caravelle.h
*\brief Class corresponding to caravels of the application
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef CARAVELLE_H
#define CARAVELLE_H
#pragma once

#include "Bateau.h"

/**
*\class Caravelle
*\brief Class which is one of the game's boats, caravels
*/

class Caravelle : public Bateau
{
	public :
		/**
		*\fn Caravelle()
		*\brief default constructor
		*/
		Caravelle() : Bateau(){};
		/**
		*\fn Caravelle(bool tres, int posx, int posy, int posPortx, int posPorty)
		*\brief constructor of caravels
		*\param tres Boolean which says if the boat owns a treasure
		*\param posx Abscissa of boat's current position
		*\param posy Ordinate of boat's current position
		*\param posPortx Abscissa of boat's port
		*\param posPorty Ordinate of boat's port
		*/
		Caravelle(bool tres, int posx, int posy, int posPortx, int posPorty) : 
			Bateau(2,tres,posx,posy,posPortx,posPorty){};
		/**
		*\fn Caravelle(const Bateau* bat)
		*\brief constructor of caravels from another boat
		*\param bat A boat that is wanted to copy to the current caravel
		*/
		Caravelle(const Bateau* bat);
		/**
		*\fn virtual ~Caravelle()
		*\brief destructor of caravels
		*/
		virtual ~Caravelle();
		/**
		*\fn virtual int getType() const
		*\brief get the current boat's type
		*\return the number representing the current boat's type
		*/
		virtual int getType() const;
};

#endif