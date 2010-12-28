// damier.cpp

#include "damier.h"



Damier::Damier(int t) {
  taille = t;
  int i, j;
  for (i=0; i<taille; i++) {
    for (j=0; j<taille; j++) {
      mesCases[i][j] = new Case(i, j, this);
    }
  }
}



void Damier::afficher() {
  
  int i, j;
  cout << "   ";
  for (i=1; i<=taille; i++) cout << " " << i << " ";
  cout << endl;
  for (i=0; i<taille; i++) {
    cout << " " << (i+1) << " ";
    for (j=0; j<taille; j++) {
      mesCases[i][j]->afficher();
    }
    cout << " " << (i+1) << " ";
    cout << endl;
  }
  cout << "   ";
  for (i=1; i<=taille; i++) cout << " " << i << " ";
  cout << endl;
  
}
