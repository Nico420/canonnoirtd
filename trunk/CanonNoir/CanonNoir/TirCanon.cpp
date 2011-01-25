#include "TirCanon.h"
#include "Moteur.h"
#include <iostream>

using namespace std;

TirCanon::TirCanon(Moteur* mot){
	this->moteur = mot;
	this->angle = -1;
	this->puissance = -1;
	this->bateauAttaquant = this->moteur->getJoueurCourant();
	this->bateauAttaque = 0;
	this->tirReussi = false;
	this->positionAttaquant = make_pair(0,0);
	this->positionAttaque = make_pair(0,0);
	this->message = "";
	this->angleObtenu = false;
	this->puissanceObtenue = false;
	this->etatsuivant = 0;
}

void TirCanon::execute(){
}

void TirCanon::calculerRelief(){
	list<pair<double,double>> intersections;
	list<pair<double,double>>::iterator it,end;
	double h,l,xa,ya,xb,yb;
	int x,y,i,j;
	int inc_x,inc_y;
	int x1 = this->positionAttaquant.first;
	int x2 = this->positionAttaque.first;
	int y1 = this->positionAttaquant.second;
	int y2 = this->positionAttaque.second;
	cout<<"x1 ="<<x1<<endl;
	cout<<"x2 ="<<x2<<endl;
	cout<<"y1 ="<<y1<<endl;
	cout<<"y2 ="<<y2<<endl;
	if(x1<x2){
		inc_x = 1;
		x = x1;
	}
	else{
		inc_x = -1;
		x = x1-1;
	}
	if(y1<y2){
		inc_y = 1;
		y = y1;
	}
	else{
		inc_y = -1;
		y = y1-1;
	}
	cout<<"x ="<<x<<endl;
	cout<<"x2 ="<<x2<<endl;
	cout<<"y ="<<y<<endl;
	cout<<"y2 ="<<y2<<endl;
	// x >=0 ??
	while((x*inc_x<x2*inc_x) && (y*inc_y<=y2*inc_y) && (x>0) && (y>0)){
		if(f(x,x1,x2,y1,y2)==(double)y){
			intersections.push_back(pair<double,double>(x,y));
			x += inc_x;
			y += inc_y;
		}
		else if(f(x,x1,x2,y1,y2)*inc_y < y*inc_y){
			intersections.push_back(pair<double,double>(x,f(x,x1,x2,y1,y2)));
			x += inc_x;
		}
		else{
			intersections.push_back(pair<double,double>(g(y,x1,x2,y1,y2),y));
			y += inc_y;
		}
	}
	cout<<"Taille intersections :"<<intersections.size()<<endl;
	if(intersections.size() >= 1){
		xb = x1;
		yb = y1;
		cout<<"Avant push back"<<endl;
		intersections.push_back(make_pair(x2,y2));
		cout<<"Apres push back"<<endl;
		it = intersections.begin();
		int nb = intersections.size();
		end = intersections.end();
		cout<<"boucle for calcul relief "<<nb<<endl;
		for(it ; it!=end; ++it){
			xa = xb;
			ya = yb;
			cout<<"Debut boucle for calcul relief "<<nb<<endl;
			xb = it->first;
			yb = it->second;
			cout<<"Debut boucle for calcul relief "<<nb<<endl;
			i = min(xa,xb) +1;
			j = min(ya,yb) +1;
			cout<<"Milieu boucle for calcul relief "<<i<<" "<<j<<endl;
			h = this->moteur->getPlateau().getHauteur(i,j);
			l = sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
			cout<<"Milieu boucle for calcul relief "<<nb<<endl;
			this->histogramme.push_back(make_pair(l,h));
			cout<<"Fin boucle for calcul relief "<<nb<<endl;
		}
	}
	cout<<"Fin calcul relief"<<endl;
}

void TirCanon::calculerTir(){
	int pi=3.1415;
	double angle_rad = 2*pi*angle/360;
	double vx = puissance * cos((double)angle);
	double vz = puissance * sin((double)angle);
	vector<pair<double,double>> res;
	cout<<"Trajectoire :"<<endl;
	//On stock en i z et en i+1 x
	for(int i=0;i<moteur->NBPOINTS;i=i+2){
		double y = -0.5*9.81*i*i/(puissance*puissance*cos((double) angle)*cos((double) angle))+i*tan((double) angle);
		res.at(i) = make_pair(i,y);
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
	moteur->setTrajectoireTir(res);
}

void TirCanon::effectuerChangements(int joueurAttaquant,int batAttaquant,int joueurAttaque,int batAttaque){
	if(moteur->getBateau(joueurAttaque,batAttaque)->aTresorABord()){
		moteur->getBateau(joueurAttaque,batAttaque)->enleveTresor();
		moteur->getBateau(joueurAttaquant,batAttaquant)->donneTresor();
	}
	int x = moteur->getBateau(joueurAttaque,batAttaque)->getPosition().first;
	int y = moteur->getBateau(joueurAttaque,batAttaque)->getPosition().second;
	moteur->getJoueur(joueurAttaque).degraderBateau(x,y);
}

double TirCanon::f(int x,int x1,int x2,int y1,int y2) const{
	return (double)((y2-y1)*x+(x2*y1-x1*y2))/(double)(x2-x1);
}

double TirCanon::g(int y,int x1,int x2,int y1,int y2) const{
	return (double)((x2-x1)*y+(x2*y1-x1*y2))/(double)(y2-y1);
}