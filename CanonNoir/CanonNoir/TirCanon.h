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

		double f(int x,int x1,int x2,int y1,int y2) const;
		double g(int y,int x1,int x2,int y1,int y2) const;

	public :
		TirCanon();
		TirCanon(Moteur* mot);
		virtual ~TirCanon(){};
		virtual void execute();
		void setAngle(int ang);
		void setPuissance(int puis);
		void setCible(int num);
		void faireTir();
		bool getTirReussi();
		void effectuerChangements();
		void calculerRelief();
		bool tirFini();
		std::vector<std::pair<int,int>> calculerTir();
}; 

inline void TirCanon::setAngle(int ang){
	this->angle = ang;
}

inline void TirCanon::setPuissance(int puis){
	this->puissance = puis;
}
#endif