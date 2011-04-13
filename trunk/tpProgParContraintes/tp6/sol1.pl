%TP6

:- lib(ic).
:- lib(branch_and_bound).
:- lib(ic_global).

getData(Poids,NbPersonnes,NbPlaces) :-
	NbPersonnes = 10,
	NbPlaces = 16,
	Poids = [](24,39,85,60,165,6,32,123,7,14).
	
defineVars(Places,NbPlaces,NbPersonnes):-
	dim(Places,[NbPersonnes]),
	Borne #= NbPlaces/2,
	( for(I,1,NbPersonnes),param(Places,Borne)
		do
			Places[I] #:: -Borne..Borne,
			Places[I] #\= 0
	).

getVarList(Places,NbPersonnes,L) :-
	( for(Ind,1,NbPersonnes),fromto([],In,Out,L),param(Places)
		do
			Var #= Places[Ind],
			append([Var],In,Out)
	).

balancoireEquilibree(Poids,NbPersonnes,Places) :-
	( for(J,1,NbPersonnes),fromto(0,In,Out,SommeMoments),param(Places,Poids)
		do
			Distance #= Places[J],
			Poids1 #= Poids[J],
			Out #= In + Distance * Poids1
	),
	SommeMoments #= 0.

pasMemesPlaces(Places) :-
	ic:alldifferent(Places).
	
cinqChaqueCote(Places,NbPersonnes) :-
	NbPersGauche #= NbPersonnes/2,
	( for(K,1,NbPersonnes),fromto(0,In,Out,NbPersonnesAGauche),param(Places)
		do
			Var #= Places[K],
			(Var #< 0) => (Out #= In + 1),
			(Var #> 0) => (Out #= In)
	),
	NbPersGauche #= NbPersonnesAGauche.

parentsEncadrentEnfants(Places) :-
	PlaceMere #= Places[4],
	PlacePere #= Places[8],
	((PlaceMere #= ic:max(Places)) and (PlacePere #= ic:min(Places)))
	or
	((PlacePere #= ic:max(Places)) and (PlaceMere #= ic:min(Places))).
	/*
	(maxlist(Places,PlaceMere) and minlist(Places,PlacePere))
	or
	(maxlist(Places,PlacePere) and minlist(Places,PlaceMere)).
*/

danEtMaxDevantParents(Places) :-
	PlaceDan #= Places[6],
	PlaceMax #= Places[9],
	PlaceMere #= Places[4],
	PlacePere #= Places[8],
	(((PlaceMere #<0) and (PlaceDan #<0)) and ((PlaceMere #= PlaceDan - 1) and (PlacePere #= PlaceMax + 1)))
	or
	(((PlaceMere #<0) and (PlaceMax #<0)) and ((PlaceMere #= PlaceMax - 1) and (PlacePere #= PlaceDan + 1)))
	or
	(((PlacePere #<0) and (PlaceDan #<0)) and ((PlacePere #= PlaceDan - 1) and (PlaceMere #= PlaceMax + 1)))
	or
	(((PlacePere #<0) and (PlaceMax #<0)) and ((PlacePere #= PlaceMax - 1) and (PlaceMere #= PlaceDan + 1))).

solve(Places) :-
	getData(Poids,NbPers,NbPlac),
	defineVars(Places,NbPlac,NbPers),
	pasMemesPlaces(Places),
	balancoireEquilibree(Poids,NbPers,Places),
	cinqChaqueCote(Places,NbPers),
	parentsEncadrentEnfants(Places),
	danEtMaxDevantParents(Places),
	getVarList(Places,NbPers,L),
	labeling(L).

/* Tests
[eclipse 29]: solve(P).

P = [](-6, -5, -4, -8, 2, 5, 3, 6, -7, 1)
Yes (0.13s cpu, solution 1, maybe more) ? ;

P = [](-6, -5, -1, 8, 5, 7, 3, -8, -7, 1)
Yes (0.15s cpu, solution 2, maybe more) ? ;

P = [](-6, -5, 1, -8, -2, 6, 5, 7, -7, 4)
Yes (0.02s cpu, solution 3, maybe more) ? 
*/
