// damier.h

#ifndef DAMIER_H
#define DAMIER_H

#include <iostream>
#include "case.h"

using namespace std;

#define TAILLEMAX 101

class Case;

class Damier { 
	
public:
	Case * mesCases[TAILLEMAX][TAILLEMAX];
	int taille;
	Damier(int);
	void afficher();
};


#endif
