/**
*\file  TirCanon.h
*\brief Class corresponding to the state of shooting a player with a cannon
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef TIRCANON_H
#define TIRCANON_H
#pragma once
#include <vector>
#include <list>
#include "Etat.h"

/**
*\class TirCanon
*\brief Class which is a state where the current player shoots a player thanks to a cannon
*/

class TirCanon : public Etat
{
	protected :
		std::string message;
		Moteur* moteur;

		int angle;
		int puissance;
		int bateauAttaquant;
		int bateauAttaque;
		bool tirReussi;
		std::pair<int,int> positionAttaquant;
		std::pair<int,int> positionAttaque;
		std::list<std::pair<double,double>> histogramme;
		std::vector<std::pair<double,double>> trajectoireTir;
		bool angleObtenu;
		bool puissanceObtenue;
		int etatsuivant;

		double f(int x,int x1,int x2,int y1,int y2) const;
		double g(int y,int x1,int x2,int y1,int y2) const;

	public :
		/**
		*\fn TirCanon()
		*\brief default constructor
		*/
		TirCanon() : angle(-1),puissance(-1),bateauAttaquant(0),bateauAttaque(0),tirReussi(false),
			positionAttaquant(std::make_pair(0,0)),positionAttaque(std::make_pair(0,0)),message(""),moteur(NULL),
			angleObtenu(false),puissanceObtenue(false),etatsuivant(0) {};
		/**
		*\fn TirCanon(Moteur* mot)
		*\brief constructor of the state where the current player can shoot another player
		*\param mot Pointer of the motor of the application
		*/
		TirCanon(Moteur* mot);
		/**
		*\fn virtual ~TirCanon()
		*\brief destructor of the cannon shooting state
		*/
		virtual ~TirCanon(){};
		/**
		*\fn virtual void execute()
		*\brief does the actions that must be done in the current state (here it has to be implemented in derived classes)
		*/
		virtual void execute();
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
		/**
		*\fn void setAngle(int ang)
		*\brief sets the angle ang in the current state
		*\param ang The angle that the current state must set
		*/
		void setAngle(int ang);
		/**
		*\fn void setPuissance(int puis)
		*\brief sets the power ang in the current state
		*\param puis The power that the current state must set
		*/
		void setPuissance(int puis);
		/**
		*\fn bool getTirReussi() const
		*\brief gets if the shoot that has just been done succeeded
		*\return a boolean true if the shoot succeeded, else false
		*/
		bool getTirReussi() const;
		/**
		*\fn void calculerRelief()
		*\brief computes the relief histogram that appears between two players that are involved in the current state
		*/
		void calculerRelief();
		/**
		*\fn void calculerTir()
		*\brief computes trajectory points coordinates that appears when a player attacks a boat (after selection of angle and power of shoot)
		*/
		void calculerTir();
		/**
		*\fn void effectuerChangements(int joueurAttaquant,int batAttaquant,int joueurAttaque,int batAttaque)
		*\brief makes the changes that are caused by the previous shoot (no change if the shoot failed) as transforming a caravel into a frigate,
		* remove a treasure from a frigate to give it to the player who has attacked and managed to touch the other boat
		*\param joueurAttaquant Number of the player who has attacked
		*\param batAttaquant Number of the player's boat who has attacked
		*\param joueurAttaque Number of the player who has been attacked
		*\param batAttaque Number of the player's boat who has been attacked
		*/
		void effectuerChangements(int joueurAttaquant,int batAttaquant,int joueurAttaque,int batAttaque);
		/**
		*\fn void setTirReussi()
		*\brief computes according to shoot trajectory if a shoot succeeded (after selection of angle and power of shoot)
		*/
		void setTirReussi();
}; 

inline void TirCanon::setMessage(std::string mes){
	this->message = mes;
}

inline std::string TirCanon::getMessage() const{
	return this->message;
}

inline void TirCanon::setAngle(int ang){
	this->angle = ang;
}

inline void TirCanon::setPuissance(int puis){
	this->puissance = puis;
}

inline bool TirCanon::getTirReussi() const{
	return this->tirReussi;
}

#endif