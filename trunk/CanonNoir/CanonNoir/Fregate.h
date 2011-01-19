#ifndef FREGATE_H
#define FREGATE_H
#pragma once
#include "Bateau.h"

class Fregate : public Bateau
{
	public :
		Fregate() : Bateau(){};
		Fregate(bool tres, int posx, int posy, int posPortx, int posPorty) : 
			Bateau(1,tres,posx,posy,posPortx,posPorty){};
		Fregate(const Bateau* bat);
		virtual ~Fregate();
		virtual int getType() const;
};

#endif