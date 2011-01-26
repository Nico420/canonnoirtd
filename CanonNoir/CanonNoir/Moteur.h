/**
*\file  Moteur.h
*\brief Class corresponding to the motor of the application
*\author Nicolas DESFEUX
*\author Aurélien TEXIER
*\version 1.0
*/
#ifndef MOTEUR_H
#define MOTEUR_H
#pragma once

#include <vector>
#include <list>
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
public : 
	static const int NBPOINTS = 100;
	private :
		vector<int> ordreJoueurs;
		int joueurCourant;
		pair<int,int> click;
		map<pair<int,int>,int> casesDeplacementBateau;
		int numEtatCourant;
		int angle;
		int puissance;
		vector<double> histogramme;
		vector<double> trajectoireTir;
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
		*\param x Abscissa of the square's coordinates clicked wanted to be stored
		*\param y Ordinate of the square's coordinates clicked wanted to be stored
		*/
		void setClick(int x,int y);
		/**
		*\fn int getJoueurCourant() const
		*\brief get the current player number
		*\return The current player number
		*/
		int getJoueurCourant() const;
		/**
		*\fn vector<int> getPosBateaux()
		*\brief gets all necessary informations about boats (position,type,port), needed to display
		*\return all useful informations about boats
		*/
		vector<int> getPosBateaux();
		/**
		*\fn vector<int>& getOrdreJoueurs()
		*\brief gets a range of indices which lists players'order
		*\return a list of players'order
		*/
		vector<int>& getOrdreJoueurs();
		/**
		*\fn void setJoueurCourant(int jc)
		*\brief sets the current player at jc
		*\param jc Index of the player that will be the future current player
		*/
		void setJoueurCourant(int jc);
		/**
		*\fn void lancerDes()
		*\brief throws the dices randomly
		*/
		void lancerDes();
		/**
		*\fn void passerAuJoueurSuivant()
		*\brief sets the current player at the next player in the order established
		*/
		void passerAuJoueurSuivant();
		/**
		*\fn Etat* getEtat() const
		*\brief gets the current state of the motor
		*\return a pointer on the current state of the motor
		*/
		Etat* getEtat() const;
		/**
		*\fn int getAngle() const
		*\brief gets the angle stored in the motor
		*\return the angle stored in the motor
		*/
		int getAngle() const;
		/**
		*\fn int getPuissance() const
		*\brief gets the power stored in the motor
		*\return the power stored in the motor
		*/
		int getPuissance() const;
		/**
		*\fn void setAngle(int ang)
		*\brief sets the angle stored in the motor at the value ang
		*\param ang The angle value that the motor will store
		*/
		void setAngle(int ang);
		/**
		*\fn void setPuissance(int puis)
		*\brief sets the power stored in the motor at the value puis
		*\param puis The power value that the motor will store
		*/
		void setPuissance(int puis);
		/**
		*\fn int getDe1() const
		*\brief gets the number stored by the first dice
		*\return the number stored by the first dice
		*/
		int getDe1() const;
		/**
		*\fn int getDe2() const
		*\brief gets the number stored by the second dice
		*\return the number stored by the second dice
		*/
		int getDe2() const;
		/**
		*\fn vector<int> getScores()
		*\brief gets all the scores of each boat
		*\return a list of the scores of each boat
		*/
		vector<int> getScores();
		/**
		*\fn Joueur& getJoueur(int nb)
		*\brief gets the player which number is nb
		*\param nb Index of the player wanted to be get
		*\return a reference of the player with index nb
		*/
		Joueur& getJoueur(int nb);
		/**
		*\fn Plateau& getPlateau()
		*\brief gets the board game
		*\return a reference of the board game
		*/
		Plateau& getPlateau();
		/**
		*\fn map<pair<int,int>,int>& getCasesDeplacementBateau()
		*\brief gets possible chosen squares, with for each of them the boat that can reach them
		*\return a reference of a map with possible squares coordinates in key, and the corresponding boat in value
		*/
		map<pair<int,int>,int>& getCasesDeplacementBateau();
		/**
		*\fn vector<double> getHistogramme() const
		*\brief gets the histogram of the relief to display when a player is about to shoot (relief between current player and attacked player)
		*\return a list of number describing all the histogram (width and heigth)
		*/
		vector<double> getHistogramme() const;
		/**
		*\fn void setHistogramme(list<pair<double,double>>& hist)
		*\brief sets the histogram of the relief at the values of hist
		*\param hist List of pairs of widths and heights describing the histogram
		*/
		void setHistogramme(list<pair<double,double>>& hist);
		/**
		*\fn vector<double> getTrajectoireTir() const
		*\brief gets the trajectory of the shoot to display when a player has just shot
		*\return a list of number describing the trajectory (abscissa and ordinate)
		*/
		vector<double> getTrajectoireTir() const;
		/**
		*\fn void setTrajectoireTir(vector<pair<double,double>>& traj)
		*\brief sets the trajectory of the shoot at the values of traj
		*\param traj List of pairs of abscissas and ordinates describing the trajectory of the shoot
		*/
		void setTrajectoireTir(vector<pair<double,double>>& traj);
		/**
		*\fn void addJoueur(int ind,int num,int nbBat,int nbPort1,int nbPort2=0)
		*\brief adds a player, it happens during initialization, during choosing ports
		*\param ind Index of the player in the motor
		*\param num Number of the player in the motor
		*\param nbBat Number of boats owned by the future added player
		*\param nbPort1 Number of the first port chosen by the future added player
		*\param nbPort2 Number of the second port chosen by the future added player, 0 if it's not specified, by default
		*/
		void addJoueur(int ind,int num,int nbBat,int nbPort1,int nbPort2=0);
		/**
		*\fn Bateau* getBateau(int joueur,int numPort)
		*\brief gets the boat owned by the player with number joueur, and this boat has to have the port numPort
		*\param joueur Index of a player in the motor
		*\param numPort Number of a port in the motor
		*\return a pointer on the boat corresponding to the specifications (joueur joueur and port numPort)
		*/
		Bateau* getBateau(int joueur,int numPort);
		/**
		*\enum Etats
		* All the states which can be instanciated are enumerated here
		*/
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

inline int Moteur::getPuissance() const{
	return puissance;
}

inline vector<double> Moteur::getHistogramme() const{
	return this->histogramme;
}

inline vector<double> Moteur::getTrajectoireTir() const{
	return this->trajectoireTir;
}

#endif