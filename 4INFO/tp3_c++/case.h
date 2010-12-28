// case.h

#ifndef CASE_H
#define CASE_H

#include "damier.h"
#include "ange.h"

class Damier;
class Ange;

class Case { 
private :
    Damier * monDamier;
    bool bouchee;
    Ange * monAnge;
    int x;
    int y;
public:
    Case(int, int, Damier *);
	int getX(){return x;}
	int getY(){return y;}
	bool estBouchee(){return bouchee;}
	bool estAnge(){return monAnge!=NULL;}
	void setBouchee(bool b){bouchee=b;}
	void setAnge(Ange* ma){monAnge=ma;}
    int distance(Case *);
    void afficher();
};


#endif
