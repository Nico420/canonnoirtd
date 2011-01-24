#ifndef TIRCANON_H
#define TIRCANON_H
#pragma once
#include <vector>
#include <list>
#include "Etat.h"

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
		std::list<std::pair<double,double>> trajectoireTir;
		bool angleObtenu;
		bool puissanceObtenue;
		int etatsuivant;

		double f(int x,int x1,int x2,int y1,int y2) const;
		double g(int y,int x1,int x2,int y1,int y2) const;

	public :
		TirCanon() : angle(-1),puissance(-1),bateauAttaquant(0),bateauAttaque(0),tirReussi(false),
			positionAttaquant(std::make_pair(0,0)),positionAttaque(std::make_pair(0,0)),message(""),moteur(NULL),
			angleObtenu(false),puissanceObtenue(false),etatsuivant(0) {};
		TirCanon(Moteur* mot);
		virtual ~TirCanon(){};
		virtual void execute();
		void setMessage(std::string mes);
		std::string getMessage() const;
		void setAngle(int ang);
		void setPuissance(int puis);
		void setCible(int num);
		bool getTirReussi() const;
		void effectuerChangements();
		void calculerRelief();
		std::vector<std::pair<int,int>> calculerTir();
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