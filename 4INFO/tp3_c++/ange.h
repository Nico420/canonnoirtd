// ange.h

#ifndef ANGE_H
#define ANGE_H

#include "joueur.h"

class Partie;

class Ange : public Joueur { 
	    
protected:
    int puissance;
	Case * maCase;
public:
	Ange(Partie *, int);
	void setCase(Case *c){maCase=c;}
    bool jeSuisBloque();
    bool jeSuisLibre();
    void afficher();
	void effectuerCoupSurCase(Case * c);
	bool caseInaccessible(Case * c);
};

#endif
