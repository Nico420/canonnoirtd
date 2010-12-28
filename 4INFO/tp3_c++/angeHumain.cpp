// angeHumain.cpp

#include "angeHumain.h"
#include "partie.h"


AngeHumain::AngeHumain(Partie * pa, int pui) : 
Ange(pa, pui) {
}

void AngeHumain::afficherPrompt() {
  cout << "Ange > ";
}



Case * AngeHumain::choisirUneCase() {
  int x, y;
	bool ok;
	Case * c;
	// l’utilisateur choisit un coup
	do {
		// l’utilisateur tape un coup
		cout << "Ange > x ? ";
		cin >> x;
		cout << "Ange > y ? ";
		cin >> y;
		// le programme verifie le coup
		if ((x>0)&&(y>0)&&
		(x<=maPartie->monDamier->taille)&&
		(y<=maPartie->monDamier->taille)) {
			ok = true;
			c = maPartie->monDamier->mesCases[x-1][y-1];
			if (c->estBouchee()) {
				cout << "Erreur: case bouchee." << endl; ok = false;
			}
			if (c->estAnge()) {
				cout << "Erreur: case occupee par l'ange." << endl; ok = false;
			}
			// la case est-elle inaccessible a l’ange ?
			if (c->distance(maCase) > puissance) {
				cout << "Erreur: case inaccessible." << endl; ok = false;
			}
		}
		else ok = false;
	} while (!ok);
	return c;

}
