// joueur.cpp

#include "joueur.h"



Joueur::Joueur(Partie * p) {
  maPartie = p;
}



void Joueur::jouer(){
	cout << "Joueur::jouer(): debut:" << endl;
	Case * c = choisirUneCase();
	effectuerCoupSurCase(c);
	cout << "Joueur::jouer(): fin." << endl;
}


void Joueur::afficher() {

  cout << " ma Partie = ";
  if (maPartie) cout << maPartie << endl;
  else cout << " null..." << endl;
}

