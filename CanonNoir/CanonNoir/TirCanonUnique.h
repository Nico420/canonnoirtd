#ifndef TIRCANONUNIQUE_H
#define TIRCANONUNIQUE_H
#pragma once

#include "TirCanon.h"

class TirCanonUnique : public TirCanon
{
	private :
		bool cibleChoisie;
	public :
		TirCanonUnique() : TirCanon(),cibleChoisie(false){};
		TirCanonUnique(Moteur* mot) : TirCanon(mot),cibleChoisie(false){};
		void setCible(int num);
		virtual void execute();
		virtual int getEtat() const;
};

inline int TirCanonUnique::getEtat() const{
	return this->etatsuivant;
}

#endif