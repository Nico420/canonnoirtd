// joueur.h



#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
using namespace std;

class Partie;
class Case;

class Joueur { 
protected :
	Partie * maPartie;
public:
    Joueur(Partie *);
    void jouer();
    void afficher();
	virtual Case* choisirUneCase()=0;
	virtual void effectuerCoupSurCase(Case * c)=0;

};

#endif
