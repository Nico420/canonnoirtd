/**
*\file  LancerDesDeplacement.h
*\brief Class corresponding to the state of throwing the dices when game is begun
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef LANCERDESDEPLACEMENT_H
#define LANCERDESDEPLACEMENT_H
#pragma once

#include "LancerDes.h"
#include "Moteur.h"
#include <set>

/**
*\class LancerDesDeplacement
*\brief Class which is a state where the dices have been thrown when game is begun (so when all initializations are over)
*/

class LancerDesDeplacement : public LancerDes
{
	private :
		std::set<std::pair<int,int>> casesDeplacement;
		int etatsuivant;
		bool activeDe2;
	public :
		/**
		*\fn LancerDesDeplacement()
		*\brief default constructor
		*/
		LancerDesDeplacement() : LancerDes(NULL),etatsuivant(0){};
		/**
		*\fn LancerDesDeplacement(Moteur* mot)
		*\brief constructor of the state where the dices have been thrown to move a boat
		*\param mot Pointer of the motor of the application
		*/
		LancerDesDeplacement(Moteur* mot) : LancerDes(mot),etatsuivant(Moteur::NAVIGATION){};
		/**
		*\fn virtual void execute()
		*\brief does the actions that must be done in the current state
		*/
		virtual void execute();
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
		*\fn bool getActiveDe2() const
		*\brief gets if the second dice has to be shown
		*\return boolean true if the second dice has to be shown, else false
		*/
		bool getActiveDe2() const;
		/**
		*\fn void calculCasesDeplacement(int de1,int de2)
		*\brief computes all possible destination squares according to the rules of the game
		*\param de1 Number that the first dice has
		*\param de2 Number that the second dice has
		*/
		void calculCasesDeplacement(int de1,int de2);
		/**
		*\fn bool isValid(int x,int y) const
		*\brief tests if the square at position (x,y) exists, and if it is a waterway
		*\param x Abscissa of the tested square
		*\param y Ordinate of the tested square
		*\return boolean true if the square tested is valid, else false
		*/
		bool isValid(int x,int y) const;
		/**
		*\fn bool isCheminValid(const std::pair<int,int>& caseDepart,int x,int y) const
		*\brief tests if the way from caseDepart to square at position (x,y) is possible
		*\param caseDepart The start square
		*\param x Abscissa of the destination square
		*\param y Ordinate of the destination square
		*\return boolean true if the way tested is valid, else false
		*/
		bool isCheminValid(const std::pair<int,int>& caseDepart,int x,int y) const;
		/**
		*\fn void calculCasesDeplacement(int de1,int de2)
		*\brief computes all possible destination squares according to another way to play, with the right to turn during the move (not used here)
		*\param de1 Number that the first dice has
		*\param de2 Number that the second dice has
		*/
		void calculCasesDeplacement2(int de1,int de2);
		/**
		*\fn std::set<std::pair<int,int>> calculCasesDeplacementRec(const std::pair<int,int>& caseDepart,const std::set<std::pair<int,int>>& casesChemin)
		*\brief computes all possible squares for the move according to another way to play, recursive function used for calculCasesDeplacement2 function
		*\param caseDepart The start square
		*\param casesChemin all squares on which algorithm has to compute the possible ways
		*\return all new possible squares after computing
		*/
		std::set<std::pair<int,int>> calculCasesDeplacementRec(const std::pair<int,int>& caseDepart,const std::set<std::pair<int,int>>& casesChemin);
		/**
		*\fn static double distCases(const std::pair<int,int>& case1,const std::pair<int,int>& case2)
		*\brief computes the distance between two squares
		*\param case1 The first square
		*\param case2 The second square
		*\return the distance between case1 and case2
		*/
		static double distCases(const std::pair<int,int>& case1,const std::pair<int,int>& case2);
		/**
		*\fn std::set<std::pair<int,int>> casesAutour(const std::pair<int,int>& case1,int nb) const
		*\brief computes all squares around case1 square, with exactly nb steps
		*\param case1 The base square
		*\param nb The number of steps around case1
		*\return all squares around case1 square with exactly nb steps
		*/
		std::set<std::pair<int,int>> casesAutour(const std::pair<int,int>& case1,int nb) const;
		/**
		*\fn std::set<std::pair<int,int>> casesAutour(const std::pair<int,int>& case1) const
		*\brief computes all squares around case1 square, with exactly one step
		*\param case1 The base square
		*\return all squares around case1 square with exactly one step
		*/
		std::set<std::pair<int,int>> casesAutour(const std::pair<int,int>& case1) const;
		/**
		*\fn void setCasesDeplacementBateau(std::set<std::pair<int,int>>& cases,int value)
		*\brief sets all possible squares for the current move in the motor (std::map structure)
		*\param cases All possible squares for the current move
		*\param value Number of the boat of current player, useful if there are two players (to know which square corresponds to which boat)
		*/
		void setCasesDeplacementBateau(std::set<std::pair<int,int>>& cases,int value);
};

inline bool LancerDesDeplacement::getActiveDe2() const{
	return this->activeDe2;
}

#endif