/**
*\file  Facade.h
*\brief Class corresponding to the window dressing of the application
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#define WANTDLLEXP

#ifdef WANTDLLEXP		//exportation dll 
		#define DLL  __declspec( dllexport ) 
		#define EXTERNC extern "C"
#else
		#define DLL		//standard
		#define EXTERNC 
		
#endif

#ifndef FACADE_H
#define FACADE_H

#pragma once
#include <vector>
#include <typeinfo>
#include "Moteur.h"

/**
*\class Facade
*\brief Class which is the window dressing of the game (the only class which contains methods called by the wrapper)
*/

class DLL Facade
{
	private :
		Moteur* motor;

		bool affichePlateau;
		bool afficheCanon;
		int* scoresBateaux;
		int nbBateaux;
		bool afficheAttenteNbJoueurs;
		bool afficheJeuNormal;
		bool affichePorts;
		bool afficheSco;
		bool afficheBat;
		bool activeDe1;
		bool activeDe2;
		bool activeCases;
		bool activeLancerDes;
		int de1;
		int de2;
		int* casesActives;
		int* infosBateaux;
		int* histogramme;
		int* trajectoireTir;

	public :
		std::string message;
		/**
		*\fn Facade()
		*\brief default constructor of the window dressing
		*/
		Facade();
		/**
		*\fn ~Facade()
		*\brief destructor of the window dressing
		*/
		~Facade();
		/**
		*\fn bool activerDes()
		*\brief gets if throwing dices button has to be activated
		*\return boolean true if throwing dices button has to be enabled, else false
		*/
		bool activerDes(){return this->activeLancerDes;};
		/**
		*\fn int* getCasesActives() const
		*\brief gets all squares that must be activated on displaying
		*\return a pointer on a list which stores all squares at each index, and 0 or 1 a value to know if it is activated
		*/
		int* getCasesActives() const{return this->casesActives;};
		/**
		*\fn bool activerCases() const
		*\brief gets if board game squares must be activated, waiting a click of the current player
		*\return boolean true if the display must call and read getCasesActives(), else false
		*/
		bool activerCases() const{return this->activeCases;};
		/**
		*\fn std::string getMessage() const
		*\brief gets the message that must be displayed (useful for the users of the game)
		*\return a message which says what the current player has to do at the moment
		*/
		std::string getMessage() const{return this->message;};
		/**
		*\fn bool afficherCanon() const
		*\brief gets if the cannon shoot window has to be displayed
		*\return boolean true if the cannon shoot window has to be displayed, else false
		*/
		bool afficherCanon() const{return this->afficheCanon;};
		/**
		*\fn int getNbJoueurs() const
		*\brief gets players number of the game (initialized after the state AttenteNbJoueurs)
		*\return number of players for the game
		*/
		int getNbJoueurs() const{return this->motor->nbJoueurs;};
		/**
		*\fn int* getScores() const
		*\brief gets all players' scores
		*\return a pointer on all the scores (each boat of each player actually)
		*/
		int* getScores() const{return this->scoresBateaux;};
		/**
		*\fn bool afficheBateaux() const
		*\brief gets if the boats on the board game have to be displayed
		*\return boolean true if the boats on the board game have to be displayed, else false
		*/
		bool afficheBateaux() const{return afficheBat;};
		/**
		*\fn bool afficheScores() const
		*\brief gets if the scores have to be displayed
		*\return boolean true if the scores have to be displayed, else false
		*/
		bool afficheScores() const{ return afficheSco;};
		/**
		*\fn bool affichePortsLibres() const
		*\brief gets if the free ports have to be displayed (useful during ChoisirPort state)
		*\return boolean true if the free ports have to be displayed, else false
		*/
		bool affichePortsLibres() const{return affichePorts;};
		/**
		*\fn void setAngle(int angle)
		*\brief sets the angle chosen by the current player during one of the TirCanon states
		*\param angle Value of the chosen angle for the shoot
		*/
		void setAngle(int angle);
		/**
		*\fn void setPuissance(int puissance)
		*\brief sets the power chosen by the current player during one of the TirCanon states
		*\param puissance Value of the chosen power for the shoot
		*/
		void setPuissance(int puissance);
		/**
		*\fn void setNbJoueurs(int nb)
		*\brief sets the players number chosen by users during AttenteNbJoueurs state
		*\param nb Players number for the game which will start soon (after the initializations)
		*/
		void setNbJoueurs(int nb);
		/**
		*\fn void setClick(int x,int y)
		*\brief sets a click done by a user on the board game
		*\param x Abscissa of clicked square's coordinates wanted to be stored
		*\param y Ordinate of clicked square's coordinates wanted to be stored
		*/
		void setClick(int x,int y);
		/**
		*\fn void lancerDes()
		*\brief throws dices to move some boat, called from the wrapper
		*/
		void lancerDes();
		/**
		*\fn int getDes1() const
		*\brief gets number of the first dice that has to be displayed
		*\return number of the first dice that is displayed after dices throwing
		*/
		int getDes1() const{return de1;};
		/**
		*\fn int getDes2() const
		*\brief gets number of the second dice that has to be displayed
		*\return number of the second dice that is displayed after dices throwing
		*/
		int getDes2() const{return de2;};
		/**
		*\fn int getTailleTabTrajectoire() const
		*\brief gets the length of trajectory table in the window dressing
		*\return length of trajectory table in the window dressing
		*/
		int getTailleTabTrajectoire() const {return motor->NBPOINTS*2;};
		/**
		*\fn int* getBateaux() const
		*\brief gets all useful informations about boats of the game (position, type, port,has a treasure)
		*\return a pointer on all informations about boats of the game
		*/
		int* getBateaux() const{return this->infosBateaux;};
		/**
		*\fn void miseAJourCasesActives(std::vector<int> caseActives)
		*\brief updates activated squares stored in the window dressing
		*\param caseActives Informations about activated squares that have to be copied and updated in the window dressing
		*/
		void miseAJourCasesActives(std::vector<int> caseActives);
		/**
		*\fn void miseAJourInfosPorts(std::vector<int> infos)
		*\brief updates all informations about boats and ports in the game (position, treasure, type)
		*\param infos Informations about boats and ports that have to be copied and updated in the window dressing
		*/
		void miseAJourInfosPorts(std::vector<int> infos);
		/**
		*\fn void miseAJourScores(std::vector<int> scores)
		*\brief updates all scores of each boat of each player
		*\param infos Informations about boats and ports that have to be copied and updated in the window dressing
		*/
		void miseAJourScores(std::vector<int> scores);
		/**
		*\fn void miseAJourHistogramme()
		*\brief updates the histogram of the relief stored in the window dressing
		*/
		void miseAJourHistogramme();
		/**
		*\fn void miseAJourTrajectoire()
		*\brief updates the trajectory of a shoot stored in the window dressing
		*/
		void miseAJourTrajectoire();
		/**
		*\fn int* getTrajectoire() const
		*\brief gets some coordinates of a shot trajectory (computed by the motor)
		*\return a pointer on all coordinates of a shot trajectory
		*/
		int* getTrajectoire() const{return this->trajectoireTir;};
		/**
		*\fn int* getHistogramme()
		*\brief gets all histogram informations necessary to display it (computed by the motor)
		*\return a pointer on all histogram informations in order to display it
		*/
		int* getHistogramme(){this->miseAJourHistogramme();return this->histogramme;};
};

EXTERNC DLL Facade* Facade_New();
EXTERNC DLL void Facade_Delete(Facade* f);
#endif