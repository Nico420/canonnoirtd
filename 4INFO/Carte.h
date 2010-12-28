#pragma once
#ifndef CARTE_H
#define CARTE_H

enum Couleur { PIQUE, TREFLE, COEUR, CARREAU };
enum Valeur { AS, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI };


class Carte
{
	Couleur _couleur;
	Valeur _valeur;
	char _proprietaire;
	Carte* _carte_prec;
	static Carte* first_card_N;
	static Carte* first_card_S;
	static Carte* last_card_N;
	static Carte* last_card_S;

public:
	Carte(Couleur coul, Valeur haut, char prop);
	~Carte(void);
	static void afficherN();
	static void afficherS();
	void afficher();
	Carte* suc();
	static Carte* getNTete();
	static Carte* getSTete();
	bool egale(Carte* carte);
	void changerProp();
	bool supAbs(Carte* carte);
	void passerDerriere();
};


#endif
