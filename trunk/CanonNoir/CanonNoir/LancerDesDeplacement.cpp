#include "LancerDesDeplacement.h"
#include "Moteur.h"
#include <math.h>

LancerDesDeplacement::LancerDesDeplacement(){
	this->LancerDes::LancerDes();
}

LancerDesDeplacement::LancerDesDeplacement(Moteur* mot){
	this->LancerDes::LancerDes(mot);
}

void LancerDesDeplacement::execute(){
	this->moteur->getDes().first.lancerDe();
	this->moteur->getDes().second.lancerDe();
	int de1 = this->moteur->getDes().first.getNum();
	int de2 = this->moteur->getDes().second.getNum();
	this->calculCasesDeplacement(de1,de2);
}

void LancerDesDeplacement::calculCasesDeplacement(int de1,int de2){
	int totalDes = de1 + de2;
	int nbDes = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(1).getNbDes();
	std::pair<int,int> caseDepart = this->moteur->getJoueur(this->moteur->getJoueurCourant()).getBateau(1).getPosition();
	this->casesDeplacement.insert(caseDepart);
	int i = de1;
	while(i--!=0){
		this->casesDeplacement = calculCasesDeplacementRec(caseDepart,this->casesDeplacement);
	}
	if(nbDes==2){
		i = de2;
		while(i--!=0){
			this->casesDeplacement = calculCasesDeplacementRec(caseDepart,this->casesDeplacement);
		}
		i = totalDes;
		while(i--!=0){
			this->casesDeplacement = calculCasesDeplacementRec(caseDepart,this->casesDeplacement);
		}
	}
	if(this->moteur->getNbJoueurs()==2){
		while(de1!=0){
			this->casesDeplacement = calculCasesDeplacementRec(caseDepart,this->casesDeplacement);
		}
		if(nbDes==2){
			while(de2!=0){
				this->casesDeplacement = calculCasesDeplacementRec(caseDepart,this->casesDeplacement);
			}
			while(totalDes!=0){
				this->casesDeplacement = calculCasesDeplacementRec(caseDepart,this->casesDeplacement);
			}
		}
	}
}

std::set<std::pair<int,int>> LancerDesDeplacement::calculCasesDeplacementRec(std::pair<int,int> caseDepart,std::set<std::pair<int,int>> casesChemin){
	std::set<std::pair<int,int>> res;
	std::set<std::pair<int,int>>::iterator it;
	for(it=casesChemin.begin();it!=casesChemin.end();it++){
		//casesChemin.erase(it);
		double dist = distCases(caseDepart,*it);
		std::set<std::pair<int,int>> casesPotentielles = this->casesAutour(*it);
		std::set<std::pair<int,int>>::iterator it2;
		for(it2=casesPotentielles.begin();it2!=casesPotentielles.end();it2++){
			double dist2 = distCases(caseDepart,*it2);
			if(dist<=dist2) res.insert(*it2);
		}
	}
	return res;
}

double LancerDesDeplacement::distCases(const std::pair<int,int>& case1,const std::pair<int,int>& case2){
	return pow((double)(case1.first - case2.first),2) + pow((double)(case1.second - case2.second),2);
}

std::set<std::pair<int,int>> LancerDesDeplacement::casesAutour(const std::pair<int,int>& case1){
	std::set<std::pair<int,int>> res;
	int longueur = this->moteur->getPlateau().getLongueur();
	int largeur = this->moteur->getPlateau().getLargeur();
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			int x = case1.first+i;
			int y = case1.second+j;
			if((i!=0 || j!=0) && ((x)<=longueur) && ((y)<=largeur)){
				if(this->moteur->getPlateau().estNavigable(x,y)) res.insert(std::make_pair(x,y));
			}
		}
	}
	return res;
}