/**
*\file  Bateau.h
*\brief Class corresponding to each boat of the application
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef BATEAU_H
#define BATEAU_H
#pragma once

#include <utility>

/**
*\class Bateau
*\brief Class which is game's boat
*/

class Bateau
{
	protected :
		int nbDes;
		bool tresorABord;
		std::pair<int,int> position;
		std::pair<int,int> positionPort;

	public :
		/**
		*\fn Bateau()
		*\brief default constructor
		*/
		Bateau();
		/**
		*\fn Bateau(int nbDes, bool tres, int posx, int posy, int posPortx, int posPorty)
		*\brief constructor
		*\param nbDes Dices number that will be attached at the boat
		*\param tres Boolean which says if the boat owns a treasure
		*\param posx Abscissa of boat's current position
		*\param posy Ordinate of boat's current position
		*\param posPortx Abscissa of boat's port
		*\param posPorty Ordinate of boat's port
		*/
		Bateau(int nbDes, bool tres, int posx, int posy, int posPortx, int posPorty);
		/**
		*\fn ~Bateau()
		*\brief destructor
		*/
		virtual ~Bateau();
		/**
		*\fn void deplacer(int x, int y)
		*\brief move the current boat at the position with coordinates (x,y)
		*\param x Abscissa of boat's future position
		*\param y Ordinate of boat's future position
		*/
		void deplacer(int x, int y);
		/**
		*\fn virtual bool aTresorABord() const
		*\brief get if the current boat owns a treasure
		*\return boolean true if the current boat owns a treasure, false else
		*/
		virtual bool aTresorABord() const;
		/**
		*\fn virtual void enleveTresor()
		*\brief remove the treasure on the current boat
		*/
		virtual void enleveTresor();
		/**
		*\fn virtual bool donneTresor()
		*\brief give a treasure to the current boat
		*\return boolean true
		*/
		virtual bool donneTresor();
		/**
		*\fn virtual int getNbDes() const
		*\brief get dices number attributed to the current boat
		*\return the number of dices that the current boat owns to have
		*/
		virtual int getNbDes() const;
		/**
		*\fn virtual int getType() const
		*\brief get the current boat's type
		*\return the number representing the current boat's type
		*/
		virtual int getType() const;
		/**
		*\fn std::pair<int,int> getPosition() const
		*\brief get the current boat's position
		*\return a pair of coordinates representing the current boat's position
		*/
		std::pair<int,int> getPosition() const;
		/**
		*\fn std::pair<int,int> getPositionPort() const
		*\brief get the current boat's port position
		*\return a pair of coordinates representing the current boat's port position
		*/
		std::pair<int,int> getPositionPort() const;
		/**
		*\fn int getNumPort() const
		*\brief get the current boat's port number
		*\return a number representing the current boat's port number
		*/
		int getNumPort() const;
}; 

inline bool Bateau::aTresorABord() const{
	return tresorABord;
}

inline void Bateau::enleveTresor(){
	tresorABord = false;
}

inline bool Bateau::donneTresor(){
	tresorABord = true;
	return true;
}

inline int Bateau::getNbDes() const{
	return this->nbDes;
}

inline int Bateau::getType() const{
	return 0;
}

inline std::pair<int,int> Bateau::getPosition() const{
	return position;
}

inline std::pair<int,int> Bateau::getPositionPort() const{
	return positionPort;
}

#endif