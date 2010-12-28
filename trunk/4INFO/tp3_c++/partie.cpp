// partie.cpp

#include "partie.h"

Partie::Partie(int t, char a, char d) {
  monDamier = new Damier(t);
  gagnee = false;
  
  if (a=='h') monAnge = new AngeHumain(this, 1);
  if (a=='a') monAnge = new AngeAleatoire(this, 1);   
  Case * c = monDamier->mesCases[monDamier->taille/2][monDamier->taille/2];
  c->setAnge(monAnge);
  monAnge->setCase(c);
  if (d=='h') monDiable = new DiableHumain(this);
  if (d=='a') monDiable = new DiableAleatoire(this);

  trait = monAnge;
}

Partie::Partie(int t) {
  monDamier = new Damier(t);
  gagnee = false;
}


bool Partie::faire() {
  cout << "Debut de la partie." << endl;
  monDamier->afficher();
  do {
    trait->jouer();
    monDamier->afficher();
    gagnee = monAnge->jeSuisBloque() || monAnge->jeSuisLibre();
    trait = autreJoueur();
  } while (!gagnee);
  cout << "Fin de la partie." << endl;
  return (monAnge->jeSuisBloque());
}

Joueur * Partie::autreJoueur() {
  if (trait == monAnge) return monDiable;
  else return monAnge;
}

void Partie::initialiser() {
  cout << "\tAnge Humain ou Aleatoire ? (h/a)" << endl;
  char r;
  cin >> r;
  if (r=='h') monAnge = new AngeHumain(this, 1);
  if (r=='a') monAnge = new AngeAleatoire(this, 1);   
  Case * c = monDamier->mesCases[monDamier->taille/2][monDamier->taille/2];
  c->setAnge(monAnge);
  monAnge->setCase(c);
  cout << "\tDiable Humain ou Aleatoire ? (h/a)" << endl;
  cin >> r;
  if (r=='h') monDiable = new DiableHumain(this);
  if (r=='a') monDiable = new DiableAleatoire(this);
  trait = monAnge;
}

void Partie::afficher() {
    cout << " mon Ange = ";
    if (monAnge) cout << monAnge << endl;
    else cout << " null..." << endl;

    cout << " mon Diable = ";
    if (monDiable) cout << monDiable << endl;
    else cout << " null..." << endl;

    cout << " mon Damier = ";
    if (monDamier) cout << monDamier << endl;
    else cout << " null..." << endl;

    cout << " trait = ";
    if (trait==monAnge)   cout << " >a< " << endl;
    if (trait==monDiable) cout << "  @  " << endl;
    if (trait==NULL) cout << " null " << endl;

    cout << " gagnee = ";
    if (gagnee)   cout << "true " << endl;
    else cout << "false " << endl;
}

