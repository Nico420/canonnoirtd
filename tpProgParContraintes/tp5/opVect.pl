nbOuvriersNecessaires(Fabriquer,Techniciens,NbSortes,NbOuvriersTotal) :-
	( for(J,1,NbSortes),fromto(0,In,Out,NbOuvriersTotal),param(Fabriquer,Techniciens)
		do
			Var is Fabriquer[J],
			NbTech is Techniciens[J],
			Out #= In + NbTech * Var
	).
	
vectBeneficeTotal(Fabriquer,Benefice,Quantite,NbSortes,VectBenefTotal) :-
	( for(K,1,NbSortes),fromto([],In,Out,VectBenefTotal),param(Fabriquer,Benefice,Quantite)
		do
			Var is Fabriquer[K],
			Benef is Benefice[K],
			Quan is Quantite[K],
			Elem #= Var * Benef * Quan,
			append(In,[Elem],Out)
	).
	
profitTotal(Fabriquer,Benefice,Quantite,NbSortes,ProfitTotal) :-
	vectBeneficeTotal(Fabriquer,Benefice,Quantite,NbSortes,VectBenefTotal),
	ProfitTotal #= sum(VectBenefTotal).
