// Wrapper.h

#pragma once
#include "../CanonNoir/AttenteNbJoueurs.h";
using namespace System;

namespace Wrapper {

	public ref class WrapperNbJoueurs
	{
		private: 
			AttenteNbJoueur* nbJoueurW;
	public:
		WrapperNbjoueurs(){nbJoueurW=AttenteNbJoueurs_New();
		~WrapperNbjoueurs(){AttenteNbJoueurs_Delete(nbJoueurW)};
	protected:
		!WrapperNbjoueurs(){AttenteNbJoueurs_Delete(nbJoueurW)};
	};
}
