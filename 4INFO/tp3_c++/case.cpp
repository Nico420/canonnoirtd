// case.cpp

#include "case.h"


Case::Case(int a, int b, Damier * d) {
  monDamier = d;
  x = a;
  y = b;
  monAnge = NULL;
  bouchee = false;
}


int Case::distance(Case * c) {
  int dx = 0;
  if (x>=c->x) dx = x - c->x;
  else dx = c->x - x;
  int dy = 0;
  if (y>=c->y) dy = y - c->y;
  else dy = c->y - y;
  if (dx>dy) return dx;
  else return dy;
}


void Case::afficher() {
  if (monAnge != NULL) cout << ">A<";
  else if (bouchee) cout <<  " @ ";
  else cout << " + ";
}
