#include "Plateau.h"
#include "CasePort.h"
#include "CaseNormale.h"
#include "CaseTresor.h"
#include "CaseCanon.h"

Plateau::Plateau(){
	//Cases Port
	tab_case[0][0] = CasePort(); tab_case[10][0] = CasePort(); tab_case[0][7] = CasePort();
	tab_case[10][7] = CasePort();
	//Cases Trésor
	tab_case[4][2] = CaseTresor(4); tab_case[4][5] = CaseTresor(3); tab_case[6][3] = CaseTresor(3);
	tab_case[6][6] = CaseTresor(4);
	//Cases Canon
	tab_case[7][1] = CaseCanon(); tab_case[4][1] = CaseCanon(); tab_case[4][9] = CaseCanon();
	tab_case[3][6] = CaseCanon();
	//Cases au bord
	for(int i1=1;i1<10;i1++) tab_case[i1][0] = CaseNormale(0,false,true);
	for(int i2=1;i2<7;i2++) tab_case[0][i2] = CaseNormale(0,false,true);
	for(int i3=1;i3<10;i3++) tab_case[i3][7] = CaseNormale(0,false,true);
	for(int i4=1;i4<7;i4++) tab_case[7][i4] = CaseNormale(0,false,true);
	//Cases iles
	tab_case[2][2] = CaseNormale(6,false,false); tab_case[3][2] = CaseNormale(8,false,false);
	tab_case[2][3] = CaseNormale(9,false,false); tab_case[3][3] = CaseNormale(4,false,false);
	tab_case[2][4] = CaseNormale(10,false,false); tab_case[3][4] = CaseNormale(5,false,false);
	tab_case[2][5] = CaseNormale(3,false,false); tab_case[3][5] = CaseNormale(2,false,false);
	tab_case[7][2] = CaseNormale(2,false,false); tab_case[8][2] = CaseNormale(3,false,false);
	tab_case[7][3] = CaseNormale(5,false,false); tab_case[8][3] = CaseNormale(7,false,false);
	tab_case[7][4] = CaseNormale(6,false,false); tab_case[8][4] = CaseNormale(10,false,false);
	tab_case[7][5] = CaseNormale(4,false,false); tab_case[8][5] = CaseNormale(3,false,false);
	//Autres cases normales
	for(int i5=1;i5<7;i5++) if(i5!=4) tab_case[1][i5] = CaseNormale(0,true,false);
	tab_case[2][1] = CaseNormale(0,true,false); tab_case[2][6] = CaseNormale(0,true,false);
	tab_case[3][1] = CaseNormale(0,true,false);
	for(int i6=1;i6<7;i6++) if(i6!=2 && i6!=5) tab_case[4][i6] = CaseNormale(0,true,false);
	for(int i7=1;i7<7;i7++) tab_case[5][i7] = CaseNormale(0,true,false);
	for(int i8=1;i8<7;i8++) if(i8!=3 && i8!=6) tab_case[6][i8] = CaseNormale(0,true,false);
	tab_case[7][6] = CaseNormale(0,true,false);
	tab_case[8][1] = CaseNormale(0,true,false); tab_case[8][6] = CaseNormale(0,true,false);
	for(int i9=1;i9<7;i9++) if(i9!=4) tab_case[9][i9] = CaseNormale(0,true,false);
	/*
	for(int i=0;i<11;i++){
		for(int j=0;j<8;j++){
			this->tab_case[i][j] = Case();
		}
	}*/
}

void Plateau::libereCase(int x,int y){
	tab_case[x-1][y-1].libereCase();
}

void Plateau::occupeCase(int x,int y){
	tab_case[x-1][y-1].setEstNavigable(false);
}

void Plateau::enleveUnTresor(int x,int y){
	this->tab_case[x-1][y-1].enleveUnTresor();
}

int Plateau::getEtat(int x, int y) const{
	return tab_case[x-1][y-1].getEtat();
}

bool Plateau::estNavigable(int x, int y) const{
	return tab_case[x-1][y-1].getEstNavigable();
}

bool Plateau::estPort(int x,int y) const{
	return tab_case[x-1][y-1].estPort();
}

Case& Plateau::getCase(int x, int y){
	return tab_case[x-1][y-1];
}

int Plateau::getNbTresors(int x,int y) const{
	return this->tab_case[x-1][y-1].getNbTresors();
}