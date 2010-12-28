// angeAleatoire.cpp

#include "angeAleatoire.h"
#include "partie.h"



AngeAleatoire::AngeAleatoire(Partie * pa, int pui) : 
Ange(pa, pui) 
{
}

Case * AngeAleatoire::choisirUneCase() {
	int x = 0;
	int y = 0;
	int t = maPartie->monDamier->taille;
	int i, j, n, r;
	Case * c;
	// le programme choisit un coup
	n = 0; // on compte le nombre de coups possibles.
	for (i=0; i<t; i++) {
		for (j=0; j<t; j++) {
			c = maPartie->monDamier->mesCases[i][j];
			if ((c->distance(maCase)<=puissance) && !(c->estBouchee()) && (!c->estAnge()))
				n++;
		}
	}
	r = Alea::engendrer(n);
	n = 0; // on selectionne un coup aleatoire dans les coups possibles.
	for (i=0; i<t; i++) {
		for (j=0; j<t; j++) {
			c = maPartie->monDamier->mesCases[i][j];
			if ((c->distance(maCase)<=puissance) && !(c->estBouchee()) && (!c->estAnge()))
				if (++n == r) {
					x = c->getX() + 1;
					y = c->getY() + 1;
				}
			}
	}
	return c;
}



