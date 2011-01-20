#ifndef MOTEUR_H
#define MOTEUR_H
#pragma once

/**
*\file  Moteur.h
*\brief Class corresponding to the motor of the application
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/

#include <vector>
#include "Joueur.h"
#include "Plateau.h"
#include "Etat.h"
#include "De.h"

/**
*\namespace std
* Namespace gathering the entire STL library
*/

using namespace std;

/**
*\class Moteur
*\brief Class which is the game's motor
*/

class Moteur
{
	private :
		vector<int> ordreJoueurs;
		int joueurCourant;
		pair<int,int> click;
		map<pair<int,int>,int> casesDeplacementBateau;
		int numEtatCourant;
		int angle;
		int puissance;
		vector<Joueur> joueurs;
		Plateau plateau;
		Etat* etat;
		pair<De,De> des;

	public :
		int nbJoueurs;
		/**
		*\fn Moteur()
		*\brief default constructor
		*/
		Moteur();

		/**
		*\fn ~Moteur()
		*\brief destructor
		*/
		~Moteur();

		/**
		*\fn void setNbJoueurs(int nb)
		*\brief set motor at the players number wanted
		*\param nb Players number that will be stocked
		*/
		void setNbJoueurs(int nb);

		/**
		*\fn void setEtat(int e)
		*\brief set motor at the state wanted
		*\param e Number which represents a state
		*/
		void setEtat(int e);

		/**
		*\fn void deplacerBateau(Bateau& b,int destx,int desty)
		*\brief move the boat b at the square at coordinates (destx,desty)
		*\param b Boat that will be moved
		*\param destx Abscissa of boat b's next position
		*\param desty Ordinate of boat b's next position
		*/
		void deplacerBateau(Bateau& b,int destx,int desty);

		/**
		*\fn void execute()
		*\brief execute motor's current state
		*/
		void execute();

		/**
		*\fn int getNbJoueurs() const
		*\brief get players number
		*\return players number
		*/
		int getNbJoueurs() const;

		/**
		*\fn pair<int,int> getClick() const
		*\brief get the square where the current player clicked
		*\return A pair of square clicked coordinates
		*/
		pair<int,int> getClick() const;

		/**
		*\fn void setClick(int x,int y)
		*\brief stock the square's coordinates where the current player clicked
		*\param x Abscissa of the square's coordinates clicked wanted to be stocked
		*\param y Ordinate of the square's coordinates clicked wanted to be stocked
		*/
		void setClick(int x,int y);

		/**
		*\fn int getJoueurCourant() const
		*\brief get the current player number
		*\return The current player number
		*/
		int getJoueurCourant() const;


		int* getPosBateaux();
		vector<int>& getOrdreJoueurs();
		void setJoueurCourant(int jc);
		void lancerDes();
		void passerAuJoueurSuivant();
		Etat* getEtat() const;
		int getAngle() const;
		int getPuissance() const;
		void setAngle(int ang);
		void setPuissance(int puis);
		int getDe1() const;
		int getDe2() const;
		Joueur& getJoueur(int nb);
		Plateau& getPlateau();
		map<pair<int,int>,int>& getCasesDeplacementBateau();
		void addJoueur(int ind,int num,int nbBat,int nbPort1,int nbPort2=0);
		enum Etats { ATTENTENBJOUEURS=1,CHOISIRPORT=2,SETORDREJOUEURS=3,LANCERDESDEPLACEMENT=4,NAVIGATION=5,
			TIRCANONDUEL=6,TIRCANONUNIQUE=7,PARTIEGAGNEE=8 };
};

inline int Moteur::getNbJoueurs() const{
	return nbJoueurs;
}

inline pair<int,int> Moteur::getClick() const{
	return this->click;
}

inline int Moteur::getJoueurCourant() const{
	return joueurCourant;
}

inline vector<int>& Moteur::getOrdreJoueurs(){
	return this->ordreJoueurs;
}

inline void Moteur::setJoueurCourant(int jc){
	this->joueurCourant = jc;
}

inline Etat* Moteur::getEtat() const{
	return this->etat;
}

/*inline pair<De&,De&> Moteur::getDes() const{
	return make_pair(des.first,des.second);
}*/

inline int Moteur::getDe1() const{
	return this->des.first.getNum();
}
inline int Moteur::getDe2() const{
	return this->des.second.getNum();
}

inline Plateau& Moteur::getPlateau(){
	return this->plateau;
}

inline Joueur& Moteur::getJoueur(int nb){
	return this->joueurs.at(nb-1);
}

inline map<pair<int,int>,int>& Moteur::getCasesDeplacementBateau(){
	return this->casesDeplacementBateau;
}

inline int Moteur::getAngle() const{
	return angle;
}
inline void Moteur::setAngle(int ang){
	angle = ang;
}

#endif