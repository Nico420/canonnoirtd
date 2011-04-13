solve2(Places) :-
	getData(Poids,NbPers,NbPlac),
	defineVars(Places,NbPlac,NbPers),
	elimineSymetrie(Places), %Gain de temps monstrueux
	pasMemesPlaces(Places),
	cinqChaqueCote(Places,NbPers),
	balancoireEquilibree(Poids,NbPers,Places),
	parentsEncadrentEnfants(Places),
	danEtMaxDevantParents(Places),
	getVarList(Places,NbPers,L),
	labeling(L).
	
/* Tests
[eclipse 31]: solve2(P).

P = [](-6, -5, -4, -8, 2, 5, 3, 6, -7, 1)
Yes (0.02s cpu, solution 1, maybe more) ? ;

P = [](-6, -5, 1, -8, -2, 6, 5, 7, -7, 4)
Yes (0.04s cpu, solution 2, maybe more) ? ;

P = [](-6, -5, 3, -8, -3, -7, 4, 7, 6, 5)
Yes (0.01s cpu, solution 3, maybe more) ? 
*/
