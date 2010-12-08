#pragma once

#ifndef CASE_H
#define CASE_H

#include "Etat.h"

class Case
{
	protected :
		int hauteur;
		bool estNavigable;

	public :

		Case():hauteur(0),estNavigable(false){};
		virtual inline bool getEstNavigable() const {return estNavigable;};
		virtual inline void setEstNavigable(bool b){estNavigable=b;};
		virtual void libereCase();
		inline int getHauteur(){return this->hauteur;};
		class Etat& getEtat();
};
#endif