#ifndef RADEAU_H
#define RADEAU_H

#pragma once

/**
*\file  Radeau.h
*\brief Class corresponding to rafts of the application
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/

#include "Bateau.h"

/**
*\class Radeau
*\brief Class which is one of the game's boats, rafts
*/

class Radeau : public Bateau
{
	public :
		/**
		*\fn Radeau()
		*\brief default constructor
		*/
		Radeau() : Bateau(){};
		/**
		*\fn Radeau(int posx, int posy, int posPortx, int posPorty)
		*\brief constructor of rafts
		*\param posx Abscissa of boat's current position
		*\param posy Ordinate of boat's current position
		*\param posPortx Abscissa of boat's port
		*\param posPorty Ordinate of boat's port
		*/
		Radeau(int posx, int posy, int posPortx, int posPorty) : 
			Bateau(1,false,posx,posy,posPortx,posPorty){};
		/**
		*\fn Radeau(const Bateau* bat)
		*\brief constructor of rafts from another boat
		*\param bat A boat that is wanted to copy to the current raft
		*/
		Radeau(const Bateau* bat);
		/**
		*\fn virtual ~Radeau()
		*\brief destructor of rafts
		*/
		virtual ~Radeau();
		/**
		*\fn virtual bool donneTresor()
		*\brief Redefinition to never give a treasure to a raft
		*\return boolean false
		*/
		virtual bool donneTresor();
		/**
		*\fn virtual int getType() const
		*\brief get the current boat's type
		*\return the number representing the current boat's type
		*/
		virtual int getType() const;
};

inline bool Radeau::donneTresor(){
	return false;
}

#endif