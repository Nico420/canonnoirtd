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
	while((x*inc_x<x2*inc_x) && (y*inc_y<=y2*inc_y)){
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
		intersections.push_back(make_pair(x2,y2));
		it = intersections.begin();
		end = intersections.end();
		for( ; it!=end; ++it){
			xa = xb;
			ya = yb;
			xb = it->first;
			yb = it->second;
			i = min(xa,xb) +1;
			j = min(ya,yb) +1;
			h = this->moteur->getPlateau().getHauteur(i,j);
			l = sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
			this->histogramme.push_back(make_pair(l,h));
		}
	}
}

vector<pair<int,int>> TirCanon::calculerTir(){
	vector<pair<int,int>> res;
	return res;
}

double TirCanon::f(int x,int x1,int x2,int y1,int y2) const{
	return (double)((y2-y1)*x+(x2*y1-x1*y2))/(double)(x2-x1);
}

double TirCanon::g(int y,int x1,int x2,int y1,int y2) const{
	return (double)((x2-x1)*y+(x2*y1-x1*y2))/(double)(y2-y1);
}