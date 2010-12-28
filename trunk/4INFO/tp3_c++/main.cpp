// main.cpp

#include <iostream>
#include "partie.h"

using namespace std;

void main () {
  cout << "Jeu de l'Ange et du Diable." << endl << endl;
  char r;
  int t;
  Partie * p = NULL;

  do {
    cout << "quitter             (q)" << endl;
    cout << "faire une partie    (f)" << endl;
    cin >> r;
    if (r=='f') {
      cout << "\tTaille du damier ? " << endl;
      cin >> t;
      p = new Partie(t);
      p->initialiser();
      cout << "Voici la partie: " << endl;
      p->afficher();
      cout << "Voici l'ange: " << endl;
      p->monAnge->afficher();
      cout << "Voici le diable: " << endl;
      p->monDiable->afficher();
      cout << "Voici faire: " << endl;
      cout << p->faire() << endl;
    }
  } while (r!='q');
 

  cout << "Au revoir." << endl;

  
}
