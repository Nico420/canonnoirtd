solve4(Places) :-
	getData(Poids,NbPers,NbPlac),
	defineVars(Places,NbPlac,NbPers),
	elimineSymetrie(Places),
	pasMemesPlaces(Places),
	cinqChaqueCote(Places,NbPers),
	balancoireEquilibree2(Poids,NbPers,Places,SNormeMom),
	parentsEncadrentEnfants(Places),
	danEtMaxDevantParents(Places),
	getVarList(Places,NbPers,L),
	minimize(search(L,0,occurrence,indomain_min,complete,[]),SNormeMom).
	
/* Tests
[eclipse 9]: solve4(P).
Found a solution with cost 953
Found a solution with cost 852
Found a solution with cost 834
Found a solution with cost 802
Found no solution with cost -1.0Inf .. 801

P = [](-3, 1, -2, -6, -1, 4, 3, 5, -5, 2)
Yes (2.50s cpu)
*/
