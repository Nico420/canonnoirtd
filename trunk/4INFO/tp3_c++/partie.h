// partie.h

#ifndef PARTIE_H
#define PARTIE_H

#include "damier.h"
#include "joueur.h"
#include "case.h"
#include "diable.h"
#include "ange.h"

#include "angeHumain.h"
#include "angeAleatoire.h"
#include "diableHumain.h"
#include "diableAleatoire.h"

#include <iostream>

using namespace std;

class Ange;
class Diable;
class Damier;
class Joueur;

class Partie { 
public:
	Ange * monAnge;
    Diable * monDiable;
    Damier * monDamier;
    Joueur * trait;
    bool gagnee;

    Partie(int);
    Partie(int, char, char);
    bool faire();
    void initialiser();
    void afficher();
    Joueur * autreJoueur();
};

#endif
