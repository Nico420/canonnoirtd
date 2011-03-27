pasMemeBateaux(T,NbEquipes,NbConf):-
	dim(T,[NbEquipes,NbConf]),
	( for(Indice1,1,NbEquipes),param(T,NbConf)
	do
		( for(Indice2,1,NbConf), fromto([],In,Out,L), param(T,Indice1)
		do
			Bat is T[Indice1,Indice2],
			append(In,[Bat],Out)
		),
		alldifferent(L)
	).
	
solve2(T) :-
	getData(_TailleEquipes,NbEquipes,_CapaBateaux,NbBateaux,NbConf),
	defineVars(T,NbEquipes,NbConf,NbBateaux),
	pasMemeBateaux(T,NbEquipes,NbConf),
	getVarList(T,L),
	labeling(L).
	
/* Tests
[eclipse 11]: solve2(T).

T = []([](1, 2, 3), [](1, 2, 3), [](1, 2, 3), [](1, 2, 3))
Yes (0.00s cpu, solution 1, maybe more) ? ;

T = []([](1, 2, 3), [](1, 2, 3), [](1, 2, 3), [](1, 3, 2))
Yes (0.00s cpu, solution 2, maybe more) ? ;

T = []([](1, 2, 3), [](1, 2, 3), [](1, 3, 2), [](1, 2, 3))
Yes (0.00s cpu, solution 3, maybe more) ?
*/