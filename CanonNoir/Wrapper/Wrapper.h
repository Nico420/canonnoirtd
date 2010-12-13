// Wrapper.h

#pragma once
#include "../CanonNoir/AttenteNbJoueurs.h";
using namespace System;

namespace Wrapper {

	public ref class WrapperFacade
	{
		private: 
			Facade* FacadeW;
	public:
		WrapperFacade(){
			FacadeW=AttenteNbJoueurs_New();
		};

		~WrapperNbjoueurs(){
			AttenteNbJoueurs_Delete(FacadeW)
		};

		System::Void setNbJoueur(int a){
			FacadeW->setNbJoueur(a);
		};
	protected:
		!WrapperNbjoueurs(){
			Facade_Delete(FacadeW);
		};
	};
}
