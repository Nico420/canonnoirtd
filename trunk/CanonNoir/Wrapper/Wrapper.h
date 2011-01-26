// Wrapper.h

#include "../CanonNoir/Facade.h"
#pragma comment (lib,"../Debug/CanonNoir.lib")

using namespace System;

namespace Wrapper {

	public ref class WrapperFacade
	{
		private: 
			Facade* FacadeW;/*!< Facade between Motor and display*/
	public:
		
		/**
		*\fn WrapperFacade()
		*\brief default constructor
		*/
		WrapperFacade(){
			FacadeW=Facade_New();
		};

		/**
		*\fn WrapperFacade()
		*\brief delete method
		*/
		~WrapperFacade(){
			Facade_Delete(FacadeW);
		};

		/**
		*\fn setNbJoueurs(int a)
		*\brief This method is use to give the Facade the number of player for the current game
		*\param a The number of player for the current game
		*/
		System::Void setNbJoueurs(int a){
			FacadeW->Facade::setNbJoueurs(a);
		};

		/**
		*\fn getMessage()
		*\brief Thanks to this method, the Facade can send the motor's message to the display
		*\return A string that contains the current message from the motor.
		*/
		System::String^ getMessage(){
			//A conversion is needed in order to get a String^, that the displayer can use.
			return gcnew String(FacadeW->Facade::getMessage().c_str());
		};

		/**
		*\fn getCasesActives
		*\brief This method returns a pointer to the table that describe the map at a given time.
		*\return A pointeur to a table of integer.
		*/
		System::IntPtr^ getCasesActives(){
			return gcnew IntPtr(FacadeW->Facade::getCasesActives());
		};

		/**
		*\fn getBateaux()
		*\brief This method returns a pointer to the table that describe the game's boat at a given time.
		*\return A pointeur to a table of integer.
		*/
		System::IntPtr^ getBateaux(){
			return gcnew IntPtr(FacadeW->Facade::getBateaux());
		};

		/**
		*\fn getScores()
		*\brief This method returns a pointer to the table that contains the current score for each player of the game.
		*\return A pointeur to a table of integer.
		*/
		System::IntPtr^ getScores(){
			return gcnew IntPtr(FacadeW->Facade::getScores());
		};

		/**
		*\fn getTrajectoire()
		*\brief This method returns the description of the shoot way.
		*\return A pointeur to a table of integer.
		*/
		System::IntPtr^ getTrajectoire(){
			return gcnew IntPtr(FacadeW->Facade::getTrajectoire());
		};

		/**
		*\fn getHisto()
		*\brief This method returns the description of the relief between two boats.
		*\return A pointeur to a table of integer.
		*/
		System::IntPtr^ getHisto(){
			return gcnew IntPtr(FacadeW->Facade::getHistogramme());
		};

		/**
		*\fn activerDes()
		*\brief Ask the facade if the dices need to be enabled or not.
		*\return true if the dice have to be enabled, else false
		*/
		bool activerDes(){
			return FacadeW->activerDes();
		};

		/**
		*\fn affichePorts()
		*\brief Ask the facade if the ports need to be display or not.
		*\return True if ports need to be display, else false.
		*/
		bool affichePorts(){
			return FacadeW->affichePortsLibres();
		}

		/**
		*\fn afficheCanon()
		*\brief Ask the facade if the Shoot windows needs to be enabled or not.
		*\return true if display is needed, else false
		*/
		bool afficheCanon(){
			return FacadeW->afficherCanon();
		};
		
		/**
		*\fn activerCases()
		*\brief This method asks the Facade if we display the boxes
		*\return true if the boxes can be displayed, else false.
		*/
		bool activerCases(){
			return FacadeW->activerCases();
		};
		
		/**
		*\fn getNbJoueurs
		*\brief Thanks to this method we can know the number of player for the current game.
		*\return the number of player
		*/
		int getNbJoueurs(){
			return FacadeW->getNbJoueurs();
		};
		
		/**
		*\fn afficheBateaux()
		*\brief Asks if we need to display the boats.
		*\return True if the boats can be displayed, else false
		*/
		bool afficheBateaux(){return FacadeW->afficheBateaux();};
		
		/**
		*\fn afficheScores()
		*\brief Asks if we need to display the scores.
		*\return True
		*/
		bool afficheScores(){return true;};
		
		/**
		*\fn setPuissance(int puissance)
		*\brief Set the value of the shoot's power in the Facade.
		*\param puissance The shoot's power.
		*/
		void setPuissance(int puissance){FacadeW->setPuissance(puissance);};
		
		/**
		*\fn setAngle(int angle)
		*\brief Set the value of the shoot's angle in the Facade.
		*\param angle The shoot's angle, in degree
		*/
		void setAngle(int angle){FacadeW->setAngle(angle);};

		/**
		*\fn setClick(int x,int y)
		*\brief This method call the setClick from Facade.
		*\param x the x's position of Click
		*\param y the y's position of Click
		*/
		void setClick(int x,int y){
			FacadeW->setClick(x,y);
		}
		
		/**
		*\fn lancerDes()
		*\brief We use this this method to ask the Facade a dices' roll.
		*/
		void lancerDes(){
			FacadeW->lancerDes();
		};

		/**
		*\fn getDes1()
		*\brief Return the value of the first dice
		*\return the value of the dice 1
		*/
		int getDes1(){
			return FacadeW->getDes1();
		};

		/**
		*\fn getDes2()
		*\brief Return the value of the second dice.
		*\return the value of the dice 2
		*/
		int getDes2(){
			return FacadeW->getDes2();
		};
	protected:
		!WrapperFacade(){
			Facade_Delete(FacadeW);
		};
	};
}
