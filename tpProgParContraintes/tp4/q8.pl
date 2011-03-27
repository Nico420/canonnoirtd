getData2(TailleEquipes,NbEquipes,CapaBateaux,NbBateaux,NbConf):-
	TailleEquipes = [](7,6,5,5,5,4,4,4,4,4,4,4,4,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2),
	NbEquipes = 29,
	CapaBateaux = [](10,10,9,8,8,8,8,8,8,7,6,4,4),
	NbBateaux = 13,
	NbConf = 7.

solve5(T):-
	getData2(TailleEq,NbEq,CapaBat,NbBat,NbConf),
	defineVars(T,NbEq,NbConf,NbBat),
	pasMemeBateaux(T,NbEq,NbConf),
	pasMemePartenaires(T,NbEq,NbConf),
	capaBateaux(T,TailleEq,NbEq,CapaBat,NbBat,NbConf),
	getVarList(T,L),
	labeling(L).
	
/* Tests
[eclipse 14]: solve5(T).

T = []([](1, 2, 3, 4, 5, 6, 7), [](2, 1, 4, 3, 6, 5, 8), [](3, 4, 1, 2, 7, 8, 5), [](4, 3, 1, 5, 2, 7, 6), [](5, 6, 2, 1, 3, 4, 9), [](2, 3, 5, 1, 4, 9, 10), [](3, 1, 2, 6, 4, 10, 11), [](6, 5, 7, 2, 1, 3, 4), [](6, 7, 5, 8, 2, 1, 3), [](7, 5, 6, 8, 3, 2, 1), [](7, 8, 9, 6, 1, 11, 2), [](8, 7, 6, 9, 10, 12, 2), [](8, 9, 7, 10, 11, 1, 12), [](1, 4, 8, 3, 9, 7, 10), [](4, 2, 8, 10, 7, 3, 9), [](5, 8, 3, 11, 6, 9, 1), [](9, 6, 4, 5, 8, 11, 13), [](9, 8, 10, 12, 13, 2, 11), [](9, 10, 8, 11, 12, 13, 2), [](9, 11, 12, 13, 1, 10, 3), [](10, 9, 11, 7, 12, 3, 13), [](10, 11, 9, 12, 8, 1, 4), [](10, 12, 13, 11, 9, 2, 3), [](11, 9, 10, 13, 8, 4, 5), [](11, 10, 12, 9, 13, 5, 1), [](11, 12, 9, 7, 10, 13, 8), [](12, 10, 13, 7, 11, 9, 4), [](12, 13, 11, 9, 8, 2, 6), [](13, 11, 10, 7, 9, 8, 1))
Yes (55.23s cpu, solution 1, maybe more) ?
*/
	
% Amelioration du labeling pour gagner du temps
	
getLast([A],A,[]).
getLast([A|R],B,[A|L]):- getLast(R,B,L).

debutfin([A|R],A,L,B) :- getLast(R,B,L).
debutfin([A,B,C],A,[A,C,B],C).

melangListe([],[]).
melangListe([A,B,C],[A,C,B]):-!.
melangListe(L,[A,B|L2]) :- debutfin(L,A,L1,B),melangListe(L1,L2).
	
getVarList2(T,L):-
	dim(T,[NbEquipes,NbConf]),
	( for(Indice1,1,NbConf),fromto([],In,Out,L),param(T,NbEquipes)
	do
		( for(Indice2,1,NbEquipes),fromto([],In2,Out2,L2),param(T,Indice1)
		do
			Var is T[Indice2,Indice1],
			append(In2,[Var],Out2)
		),
		melangListe(L2,L3),
		append(In,L3,Out)
	).

solve6(T):-
	getData2(TailleEq,NbEq,CapaBat,NbBat,NbConf),
	defineVars(T,NbEq,NbConf,NbBat),
	pasMemeBateaux(T,NbEq,NbConf),
	pasMemePartenaires(T,NbEq,NbConf),
	capaBateaux(T,TailleEq,NbEq,CapaBat,NbBat,NbConf),
	getVarList2(T,L),
	labeling(L).
	
/* Tests
[eclipse 15]: solve6(T).

T = []([](1, 2, 3, 4, 5, 6, 7), [](2, 1, 4, 3, 6, 5, 8), [](3, 4, 1, 2, 8, 7, 9), [](4, 3, 5, 1, 2, 9, 10), [](5, 6, 2, 7, 1, 3, 4), [](6, 5, 7, 2, 1, 4, 3), [](6, 7, 8, 5, 2, 1, 11), [](7, 5, 6, 8, 9, 1, 2), [](8, 9, 7, 10, 4, 11, 5), [](8, 10, 9, 6, 11, 3, 2), [](9, 8, 12, 13, 7, 2, 6), [](10, 9, 8, 11, 13, 12, 1), [](12, 13, 11, 9, 10, 8, 1), [](11, 10, 13, 3, 8, 9, 4), [](11, 12, 10, 7, 3, 13, 9), [](13, 11, 10, 9, 6, 1, 5), [](13, 8, 11, 12, 4, 10, 3), [](10, 11, 9, 8, 12, 2, 3), [](9, 11, 6, 12, 10, 5, 13), [](9, 7, 10, 11, 12, 8, 2), [](7, 8, 9, 10, 3, 4, 1), [](7, 6, 5, 9, 11, 2, 8), [](5, 7, 1, 8, 3, 10, 13), [](4, 1, 6, 5, 3, 2, 12), [](3, 2, 4, 1, 7, 11, 12), [](3, 1, 2, 6, 9, 10, 11), [](2, 4, 3, 1, 9, 8, 6), [](2, 3, 1, 6, 7, 4, 5), [](1, 3, 2, 5, 4, 7, 6))
Yes (6.98s cpu, solution 1, maybe more) ? ;

T = []([](1, 2, 3, 4, 5, 6, 7), [](2, 1, 4, 3, 6, 5, 8), [](3, 4, 1, 2, 8, 7, 9), [](4, 3, 5, 1, 2, 9, 10), [](5, 6, 2, 7, 1, 3, 4), [](6, 5, 7, 2, 1, 4, 11), [](6, 7, 8, 5, 2, 1, 3), [](7, 5, 6, 8, 9, 1, 2), [](8, 9, 7, 10, 4, 11, 5), [](8, 10, 9, 6, 11, 3, 2), [](9, 8, 12, 13, 7, 2, 6), [](10, 9, 8, 11, 13, 12, 1), [](12, 13, 11, 9, 10, 8, 1), [](11, 10, 13, 3, 8, 9, 4), [](11, 12, 10, 7, 3, 13, 9), [](13, 11, 10, 9, 6, 1, 5), [](13, 8, 11, 12, 4, 10, 3), [](10, 11, 9, 8, 12, 2, 3), [](9, 11, 6, 12, 10, 5, 13), [](9, 7, 10, 11, 12, 8, 2), [](7, 8, 9, 10, 3, 4, 1), [](7, 6, 5, 9, 11, 2, 8), [](5, 7, 1, 8, 3, 10, 13), [](4, 1, 6, 5, 3, 2, 12), [](3, 2, 4, 1, 7, 11, 12), [](3, 1, 2, 6, 9, 10, 11), [](2, 4, 3, 1, 9, 8, 6), [](2, 3, 1, 6, 7, 4, 5), [](1, 3, 2, 5, 4, 7, 6))
Yes (7.31s cpu, solution 2, maybe more) ?
*/