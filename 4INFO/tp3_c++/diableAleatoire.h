// diableAleatoire.h


#ifndef DIABLE_ALEATOIRE_H
#define DIABLE_ALEATOIRE_H

#include "alea.h"
#include "diable.h"

class Partie;



class DiableAleatoire : public Diable { 
public:
  DiableAleatoire(Partie *);
  Case * choisirUneCase();
};

#endif
