#include "LancerDes.h"

LancerDes::LancerDes(){
	this->Etat::Etat();
}

LancerDes::LancerDes(std::string mess,Moteur* mot){
	this->Etat::Etat(mess,mot);
}

LancerDes::execute(){

}