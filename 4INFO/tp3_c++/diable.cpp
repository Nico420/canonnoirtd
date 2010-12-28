// diable.cpp

#include "diable.h"
#include "partie.h"

Diable::Diable(Partie * p) : Joueur(p) {
}


void Diable::afficher() {
  Joueur::afficher();
}

void Diable::effectuerCoupSurCase(Case * c) {
  maPartie->monDamier->mesCases[c->getX()][c->getY()]->setBouchee(true);
}


