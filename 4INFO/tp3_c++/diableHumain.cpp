// diableHumain.cpp

#include "diableHumain.h"
#include "partie.h"



DiableHumain::DiableHumain(Partie * p) : 
Diable(p)
{}

void DiableHumain::afficherPrompt() {
  cout << "Diable > ";
}

Case * DiableHumain::choisirUneCase() {
	int x, y;
	bool ok;
	Case * c;
	// l’utilisateur choisit un coup
	do {
	// l’utilisateur tape un coup
		cout << "Diable > x ? ";
		cin >> x;
		cout << "Diable > y ? ";
		cin >> y;
		// le programme verifie le coup
		if ((x>0) && (y>0)&&
			(x<=maPartie->monDamier->taille)&&
			(y<=maPartie->monDamier->taille)) {
			ok = true;
			c = maPartie->monDamier->mesCases[x-1][y-1];
			if (c->estBouchee() ){
				cout << "Erreur: case bouchee." << endl; ok = false;
			}
			if (c->estAnge()) {
				cout << "Erreur: case occupee par l'ange." << endl; ok = false;
			}
			// aucune case n’est inaccessible au diable.
		}
		else ok = false;
	} while (!ok);
	return c;

}


