// Wrapper.h

#include "../CanonNoir/Facade.h"
#pragma comment (lib,"../Debug/CanonNoir.lib")

using namespace System;

namespace Wrapper {

	public ref class WrapperFacade
	{
		private: 
			Facade* FacadeW;
	public:
		WrapperFacade(){
			FacadeW=Facade_New();
		};

		~WrapperFacade(){
			Facade_Delete(FacadeW);
		};

		System::Void setNbJoueurs(int a){
			FacadeW->Facade::setNbJoueurs(a);
			FacadeW->message="test";
		};

		System::String^ getMessage(){
			//A conversion is needed in order to get a String^, that the displayer can use.
			return gcnew String(FacadeW->Facade::getMessage().c_str());
		};

		/*System::Void setAngle(int a){
			FacadeW->setAngle(a);
		};

		bool activerDes(){
			return FacadeW->activerDes();
		};
		bool activerCases(){
			return FacadeW->activerCases();
		};
		bool activerPorts(){
			return FacadeW->activerPorts();
		};
		bool afficheCurseurAngle(){
			return FacadeW->afficheCurseurAngle();
		};
		bool afficheCurseurPuissance(){
			return FacadeW->afficheCurseurPuissance();
		};
		std::vector<std::pair<int,int>> getRelief();
		bool afficheGagnant(){
			return FacadeW->afficheGagnant();
		};
		bool activerBateaux(){
			return FacadeW->activerBateaux();
		};
		bool afficheTir(){
			return FacadeW->afficheTir();
		};
		void init();
		int getNbJoueurs(){
			return FacadeW->getNbJoueurs();
		};
		bool getAttenteNbJoueurs(){
			return FacadeW->getAttenteNbJoueurs();
		};
		int* getScores();
		*/
		/*int getNbDes(){
			FacadeW->;
		}*/
		/*
		int* getPortsLibres();
		bool afficheBateaux();
		bool afficheRelief();
		bool afficheScores();
		bool affichePortsLibres();
		void setPuissance(int puissance);
		void setCible(int nb);
		void setDeplacement(int x, int y);
		void setClick(int x,int y);
		*/
		void lancerDes(){
			FacadeW->lancerDes();
		};
		int getDes1(){
			return FacadeW->getDes1();
		};
		int getDes2(){
			return FacadeW->getDes2();
		};

	protected:
		!WrapperFacade(){
			Facade_Delete(FacadeW);
		};
	};
}
