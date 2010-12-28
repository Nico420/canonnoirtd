// diableHumain.h

#ifndef DIABLE_HUMAIN_H
#define DIABLE_HUMAIN_H

#include "diable.h"

class Partie;


class DiableHumain : public Diable{ 
public:
  DiableHumain(Partie *);
  void afficherPrompt();
  Case * choisirUneCase();
};

#endif

