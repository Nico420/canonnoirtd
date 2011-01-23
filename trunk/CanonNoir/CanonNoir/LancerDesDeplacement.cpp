#include "LancerDesDeplacement.h"
#include "Moteur.h"
#include <math.h>
#include <sstream>
#include <iostream>

void LancerDesDeplacement::execute(){
	std::cout<<"Etat lancerDesDeplacement"<<std::endl;
	this->moteur->lancerDes();
	std::cout<<"lancer de dés effectue"<<std::endl;
	int de1 = this->moteur->getDe1();
	int de2 = this->moteur->getDe2();
	ostringstream mes;
	mes << "Joueur ";
	mes << this->moteur->getJoueurCourant();
	mes << ", choisissez la case où vous souhaitez vous déplacer.";
	this->setMessage(mes.str());
	this->calculCasesDeplacement(de1,de2);
	if(this->casesDeplacement.size()==0){
		cout<<"Suivant !"<<endl;
		this->etatsuivant = Moteur::LANCERDESDEPLACEMENT;
		this->moteur->passerAuJoueurSuivant();
		mes.str("");
		mes << "Joueur ";
		mes << this->moteur->getJoueurCourant();
		mes << ", lancez les dés pour jouer.";
		this->setMessage(mes.str());
	}
}

void LancerDesDeplacement::calculCasesDeplacement(int de1,int de2){
	this->moteur->getCasesDeplacementBateau().clear();
	int totalDes = de1 + de2;
	int nbDes = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(1)->getNbDes();
	this->activeDe2 = (nbDes==2);
	std::pair<int,int> caseDepart = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(1)->getPosition();
	std::set<std::pair<int,int>> res;
	res = this->casesAutour(caseDepart,de1);
	this->casesDeplacement.insert(res.begin(),res.end());
	res.clear();
	if(nbDes==2){
		res = this->casesAutour(caseDepart,de2);
		this->casesDeplacement.insert(res.begin(),res.end());
		res.clear();
		res = this->casesAutour(caseDepart,totalDes);
		this->casesDeplacement.insert(res.begin(),res.end());
		res.clear();
	}
	this->setCasesDeplacementBateau(this->casesDeplacement,1);
	//Cas de 2 joueurs
	if(this->moteur->getNbJoueurs()==2){
		nbDes = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(2)->getNbDes();
		this->activeDe2 |= (nbDes==2);
		caseDepart = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(2)->getPosition();
		res = this->casesAutour(caseDepart,de1);
		this->setCasesDeplacementBateau(res,2);
		this->casesDeplacement.insert(res.begin(),res.end());
		res.clear();
		if(nbDes==2){
			res = this->casesAutour(caseDepart,de2);
			this->setCasesDeplacementBateau(res,2);
			this->casesDeplacement.insert(res.begin(),res.end());
			res.clear();
			res = this->casesAutour(caseDepart,totalDes);
			this->setCasesDeplacementBateau(res,2);
			this->casesDeplacement.insert(res.begin(),res.end());
			res.clear();
		}
	}
}

bool LancerDesDeplacement::isValid(int x,int y) const{
	//cout<<"debut isValide"<<endl;
	int longueur = this->moteur->getPlateau().getLongueur();
	int largeur = this->moteur->getPlateau().getLargeur();
	bool res = (x<=longueur) && (y<=largeur) && (x>0) && (y>0);
	//std::cout<<x<<" "<<y<<std::endl;
	if(res) res &= this->moteur->getPlateau().estNavigable(x,y);
	//cout<<"fin isValide"<<endl;
	return res;
	
}

bool LancerDesDeplacement::isCheminValid(const std::pair<int,int>& caseDepart,int x,int y) const{
	bool cheminOK = false;
	//cout<<"chemin Valide"<<endl;
	if(this->isValid(x,y)){
		cheminOK = true;
		if(x==caseDepart.first){
			int a = (y>caseDepart.second)? caseDepart.second : y;
			int stop = (y>caseDepart.second)? y : caseDepart.second;
			for(int i=a+1;i<stop;i++) if(!this->moteur->getPlateau().estNavigable(x,i)) cheminOK = false;
		}
		else if(y==caseDepart.second){
			int a = (x>caseDepart.first)? caseDepart.first : x;
			int stop = (x>caseDepart.first)? x : caseDepart.first;
			for(int i=a+1;i<stop;i++) if(!this->moteur->getPlateau().estNavigable(i,y)) cheminOK = false;
		}
		else if(x<caseDepart.first && y<caseDepart.second){
			while(x!=caseDepart.first) if(!this->moteur->getPlateau().estNavigable(x++,y++)) cheminOK = false;
		}
		else if(x<caseDepart.first && y>caseDepart.second){
			while(x!=caseDepart.first) if(!this->moteur->getPlateau().estNavigable(x++,y--)) cheminOK = false;
		}
		else if(x>caseDepart.first && y<caseDepart.second){
			while(x!=caseDepart.first) if(!this->moteur->getPlateau().estNavigable(x--,y++)) cheminOK = false;
		}
		else if(x>caseDepart.first && y>caseDepart.second){
			while(x!=caseDepart.first) if(!this->moteur->getPlateau().estNavigable(x--,y--)) cheminOK = false;
		}
	}
	//cout<<"chemin Valide - FIN"<<endl;
	return cheminOK;
}

void LancerDesDeplacement::calculCasesDeplacement2(int de1,int de2){
	this->moteur->getCasesDeplacementBateau().clear();
	int totalDes = de1 + de2;
	int nbDes = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(1)->getNbDes();
	this->activeDe2 = (nbDes==2);
	std::pair<int,int> caseDepart = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(1)->getPosition();
	std::set<std::pair<int,int>> res;
	res.insert(caseDepart);
	int i = de1;
	while(i--!=0){
		res = calculCasesDeplacementRec(caseDepart,res);
	}
	this->casesDeplacement.insert(res.begin(),res.end());
	res.clear();
	res.insert(caseDepart);
	if(nbDes==2){
		i = de2+1;
		while(i--!=0){
			res = calculCasesDeplacementRec(caseDepart,res);
		}
		this->casesDeplacement.insert(res.begin(),res.end());
		res.clear();
		res.insert(caseDepart);
		i = totalDes+1;
		while(i--!=0){
			res = calculCasesDeplacementRec(caseDepart,res);
		}
		this->casesDeplacement.insert(res.begin(),res.end());
		res.clear();
		res.insert(caseDepart);
	}
	this->setCasesDeplacementBateau(this->casesDeplacement,1);
	/*
	if(this->moteur->getNbJoueurs()==2){
		nbDes = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(2).getNbDes();
		this->activeDe2 |= (nbDes==2);
		caseDepart = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(2).getPosition();
		de1++;
		while(de1--!=0){
			res = calculCasesDeplacementRec(caseDepart,res);
		}
		this->setCasesDeplacementBateau(res,2);
		this->casesDeplacement.insert(res.begin(),res.end());
		res.clear();
		res.insert(caseDepart);
		if(nbDes==2){
			de2++;
			while(de2--!=0){
				res = calculCasesDeplacementRec(caseDepart,res);
			}
			this->setCasesDeplacementBateau(res,2);
			this->casesDeplacement.insert(res.begin(),res.end());
			res.clear();
			res.insert(caseDepart);
			totalDes++;
			while(totalDes--!=0){
				res = calculCasesDeplacementRec(caseDepart,res);
			}
			this->setCasesDeplacementBateau(res,2);
			this->casesDeplacement.insert(res.begin(),res.end());
			res.clear();
		}
	}
	*/
}

std::set<std::pair<int,int>> LancerDesDeplacement::calculCasesDeplacementRec(const std::pair<int,int>& caseDepart,const std::set<std::pair<int,int>>& casesChemin){
	std::set<std::pair<int,int>> res;
	std::set<std::pair<int,int>>::iterator it;
	for(it=casesChemin.begin();it!=casesChemin.end();it++){
		//casesChemin.erase(it);
		double dist = distCases(caseDepart,*it);
		std::set<std::pair<int,int>> casesPotentielles = this->casesAutour(*it);
		std::set<std::pair<int,int>>::iterator it2;
		for(it2=casesPotentielles.begin();it2!=casesPotentielles.end();it2++){
			double dist2 = distCases(caseDepart,*it2);
			if(dist<dist2){
				res.insert(*it2);
			}
		}
	}
	return res;
}

double LancerDesDeplacement::distCases(const std::pair<int,int>& case1,const std::pair<int,int>& case2){
	return pow((double)(case1.first - case2.first),2) + pow((double)(case1.second - case2.second),2);
}

std::set<std::pair<int,int>> LancerDesDeplacement::casesAutour(const std::pair<int,int>& case1,int nb) const{
	std::set<std::pair<int,int>> res;
	int longueur = this->moteur->getPlateau().getLongueur();
	int largeur = this->moteur->getPlateau().getLargeur();
	for(int i=(0-nb);i<nb+1;i+=nb){
		for(int j=(0-nb);j<nb+1;j+=nb){
			int x = case1.first+i;
			int y = case1.second+j;
			if((i!=0 || j!=0) && this->isCheminValid(case1,x,y)){
					res.insert(std::make_pair(x,y));
			}
		}
	}
	return res;
}

std::set<std::pair<int,int>> LancerDesDeplacement::casesAutour(const std::pair<int,int>& case1) const{
	return this->casesAutour(case1,1);
}

std::vector<int> LancerDesDeplacement::getCasesActives() const{
	int nbCases = this->moteur->getPlateau().getLongueur() * this->moteur->getPlateau().getLargeur();
	std::vector<int> res(nbCases);
	for(int i=0;i<nbCases;i++){
		std::set<std::pair<int,int>>::iterator it;
		bool found = false;
		for(it=this->casesDeplacement.begin();it!=this->casesDeplacement.end();it++){
			int x = (*it).first-1;
			int y = ((*it).second-1)*this->moteur->getPlateau().getLongueur();
			if((x+y)==i) found = true;
		}
		res.at(i) = (found)? 1 : 0;
	}
	return res;
}

int LancerDesDeplacement::getEtat() const{
	return Moteur::NAVIGATION;
}

void LancerDesDeplacement::setCasesDeplacementBateau(std::set<std::pair<int,int>>& cases,int value){
	std::set<std::pair<int,int>>::iterator it;
	for(it=cases.begin();it!=cases.end();it++){
		this->moteur->getCasesDeplacementBateau().insert(std::pair<std::pair<int,int>,int>(*it,value));
	}
}