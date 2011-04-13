balancoireEquilibree2(Poids,NbPersonnes,Places,SNormeMoments) :-
	( for(J,1,NbPersonnes),fromto(0,In,Out,SommeMoments),fromto(0,In2,Out2,SNormeMoments),param(Places,Poids)
		do
			Distance #= Places[J],
			Poids1 #= Poids[J],
			Out #= In + Distance * Poids1,
			(Places[J] #> 0) => (Out2 #= In2 + Distance * Poids1),
			(Places[J] #=< 0) => (Out2 #= In2)
	),
	SommeMoments #= 0.

solve3(Places) :-
	getData(Poids,NbPers,NbPlac),
	defineVars(Places,NbPlac,NbPers),
	elimineSymetrie(Places), %Gain de temps monstrueux
	pasMemesPlaces(Places),
	cinqChaqueCote(Places,NbPers),
	balancoireEquilibree2(Poids,NbPers,Places,SNormeMom),
	parentsEncadrentEnfants(Places),
	danEtMaxDevantParents(Places),
	getVarList(Places,NbPers,L),
	minimize(labeling(L),SNormeMom).
	
/* Tests
[eclipse 25]: solve3(P).
Found a solution with cost 874
Found a solution with cost 872
Found a solution with cost 802
Found no solution with cost -1.0Inf .. 801

P = [](-3, 1, -2, -6, -1, 4, 3, 5, -5, 2)
Yes (1.66s cpu)
*/
