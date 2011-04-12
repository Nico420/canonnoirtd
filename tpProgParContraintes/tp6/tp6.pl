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

% Impose que la mere soit a gauche sur la balancoire
elimineSymetrie(Places) :-
	Places[4] #< 0.

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

% Version 1 de search :

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
% Ici, il semble que most_constrained soit plus adapte que occurrence, vu la vitesse de reponse (2.13s au lieu de 2.50s)

% Version 2 de search :

/* Ici on vise a essayer de mettre les places les plus au centre en premier,
parce que c'est dans ce cas que l'on minimise le mieux le moment total. */
quick_sort([],[]).
quick_sort([H|T],Sorted):-
	pivoting(H,T,L1,L2),quick_sort(L1,Sorted1),quick_sort(L2,Sorted2),
	append(Sorted1,[H|Sorted2],Sorted).
   
pivoting(_H,[],[],[]).
pivoting(H,[X|T],[X|L],G):-abs(X)=<abs(H),pivoting(H,T,L,G),!.
pivoting(H,[X|T],L,[X|G]):-abs(X)>abs(H),pivoting(H,T,L,G),!.

/* Tests
[eclipse 50]: quick_sort([1,2,3,4,-1,-2,-3,-4],L).

L = [-1, 1, -2, 2, -3, 3, -4, 4]
Yes (0.00s cpu)
*/

choice(X) :-
	get_domain_as_list(X,L),
	quick_sort(L,L2),
	member(X,L2).

solve5(Places) :-
	getData(Poids,NbPers,NbPlac),
	defineVars(Places,NbPlac,NbPers),
	elimineSymetrie(Places),
	pasMemesPlaces(Places),
	cinqChaqueCote(Places,NbPers),
	balancoireEquilibree2(Poids,NbPers,Places,SNormeMom),
	parentsEncadrentEnfants(Places),
	danEtMaxDevantParents(Places),
	getVarList(Places,NbPers,L),
	minimize(search(L,0,input_order,choice,complete,[]),SNormeMom).
	
/* Tests
[eclipse 32]: solve5(P).
Found a solution with cost 1216
Found a solution with cost 956
Found a solution with cost 947
Found a solution with cost 917
Found a solution with cost 852
Found a solution with cost 802
Found no solution with cost -1.0Inf .. 801

P = [](-3, 1, -2, -6, -1, 4, 3, 5, -5, 2)
Yes (1.80s cpu)
*/

% Version 3 de search :

solve6(Places) :-
	getData(Poids,NbPers,NbPlac),
	defineVars(Places,NbPlac,NbPers),
	elimineSymetrie(Places),
	pasMemesPlaces(Places),
	cinqChaqueCote(Places,NbPers),
	balancoireEquilibree2(Poids,NbPers,Places,SNormeMom),
	parentsEncadrentEnfants(Places),
	danEtMaxDevantParents(Places),
	getVarList(Places,NbPers,L),
	minimize(search(L,0,occurrence,choice,complete,[]),SNormeMom).

/* Tests
[eclipse 52]: solve6(P).
Found a solution with cost 933
Found a solution with cost 898
Found a solution with cost 872
Found a solution with cost 852
Found a solution with cost 848
Found a solution with cost 834
Found a solution with cost 802
Found no solution with cost -1.0Inf .. 801

P = [](-3, 1, -2, -6, -1, 4, 3, 5, -5, 2)
Yes (2.98s cpu)
*/

% Le resultat n'est pas satisfaisant ici

% Version 4 :

solve7(Places) :-
	getData(Poids,NbPers,NbPlac),
	defineVars(Places,NbPlac,NbPers),
	elimineSymetrie(Places),
	pasMemesPlaces(Places),
	cinqChaqueCote(Places,NbPers),
	balancoireEquilibree2(Poids,NbPers,Places,SNormeMom),
	parentsEncadrentEnfants(Places),
	danEtMaxDevantParents(Places),
	getVarList2(Places,NbPers,L),
	minimize(search(L,0,input_order,indomain_split,complete,[]),SNormeMom).

