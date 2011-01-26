/**
*\file  Navigation.h
*\brief Class corresponding to the state of choosing where the current player want to move
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef NAVIGATION_H
#define NAVIGATION_H
#pragma once

#include "Case.h"
#include "Etat.h"
#include <vector>
#include <set>

/**
*\class Navigation
*\brief Class which is a state where the current player chooses where its wants its boat goes
*/

class Navigation : public Etat
{
	private :
		std::set<std::pair<int,int>> casesBateauxCibles;
		int etatsuivant;
	protected :
		std::string message;
		Moteur* moteur;

	public :
		/**
		*\fn Navigation()
		*\brief default constructor
		*/
		Navigation() : message(""),moteur(NULL){};
		/**
		*\fn Navigation(Moteur* mot)
		*\brief constructor of the state where the current player chooses its move
		*\param mot Pointer of the motor of the application
		*/
		Navigation(Moteur* mot) : message(""),moteur(mot){};
		/**
		*\fn virtual void execute()
		*\brief does the actions that must be done in the current state
		*/
		virtual void execute();
		/**
		*\fn void deplacer(int x, int y)
		*\brief does the move, and the actions according to the destination square
		*\param x Abscissa of boat's future position
		*\param y Ordinate of boat's future position
		*/
		void deplacer(int x, int y);
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
		*\fn void setCasesBateauxCibles()
		*\brief finds all boats positions which may be shoot cannon targets
		*/
		void setCasesBateauxCibles();
		/**
		*\fn std::pair<int,int> getCaseFaceOppose(int x,int y) const
		*\brief finds the opposed square coordinates to the square placed at (x,y)
		*\param x Abscissa of the tested square
		*\param y Ordinate of the tested square
		*\return a pair of the opposed square indices
		*/
		std::pair<int,int> getCaseFaceOppose(int x,int y) const;
		/**
		*\fn void setMessage(std::string mes)
		*\brief sets the message mes in the current state
		*\param mes The message that the current state must set
		*/
		void setMessage(std::string mes);
		/**
		*\fn std::string getMessage() const
		*\brief gets the message of the current state
		*\return the message of the current state
		*/
		std::string getMessage() const;
}; 

inline int Navigation::getEtat() const{
	return etatsuivant;
}

inline void Navigation::setMessage(std::string mes){
	this->message = mes;
}

inline std::string Navigation::getMessage() const{
	return this->message;
}

#endif