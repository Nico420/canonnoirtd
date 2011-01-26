#include "stdafx.h"
#include "assert.h"
#include "Facade.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestProjectCanonNoir
{
	[TestClass]
	public ref class Test_unitaire_1
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Obtient ou définit le contexte de test qui fournit
		///des informations sur la série de tests active ainsi que ses fonctionnalités.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//Vous pouvez utiliser les attributs supplémentaires suivants lorsque vous écrivez vos tests :
		//
		//Utilisez ClassInitialize pour exécuter du code avant d'exécuter le premier test de la classe
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Utilisez ClassCleanup pour exécuter du code une fois que tous les tests d'une classe ont été exécutés
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Utilisez TestInitialize pour exécuter du code avant d'exécuter chaque test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Utilisez TestCleanup pour exécuter du code après que chaque test a été exécuté
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void TestMethod1()
		{
			//Scénario de tests unitaires
			Facade f = new Facade();
			assert(!f->afficheScores());
			f->setNbJoueurs(3);
			assert(f->activerCases());
			assert(f->getNbJoueurs()==3);
			f->setClick(1,1);
			f->setClick(1,8);
			assert(f->activerCases());
			f->setClick(11,1);
			assert(!f->activerCases());
			assert(f->activerDes());
			f->lancerDes();
			assert(f->activerCases());
			assert(!f->activerDes());
			assert(f->afficheScores());
			assert(true);
			//
			// TODO: ajoutez ici la logique du test
			//
		};
	};
}
