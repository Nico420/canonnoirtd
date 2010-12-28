// angeAleatoire.h

#ifndef ANGE_ALEATOIRE_H
#define ANGE_ALEATOIRE_H

#include "ange.h"
#include "alea.h"

class Partie;

class AngeAleatoire : public Ange { 
public:
  AngeAleatoire(Partie *, int);
  Case * choisirUneCase();
};

#endif
