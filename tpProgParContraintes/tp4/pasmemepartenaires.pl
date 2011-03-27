pasMemePartenaires(T,NbEquipes,NbConf):-
	dim(T,[NbEquipes,NbConf]),
	( for(Equipe1,1,NbEquipes),param(T,NbConf,NbEquipes)
	do
		Indice is Equipe1+1,
		( for(Equipe2,Indice,NbEquipes), param(T,Equipe1,NbConf)
		do
						
			( for(Conf,1,NbConf),param(T,Equipe1,Equipe2),fromto(0,In,Out,Tot)
			do
				Bateau1 is T[Equipe1,Conf],
				Bateau2 is T[Equipe2,Conf],
				#=(Bateau1,Bateau2,Ans),
				Out #= In + Ans
			),
			Tot #=< 1
		)
	).
	
solve3(T) :-
	getData(_TailleEquipes,NbEquipes,_CapaBateaux,NbBateaux,NbConf),
	defineVars(T,NbEquipes,NbConf,NbBateaux),
	pasMemeBateaux(T,NbEquipes,NbConf),
	pasMemePartenaires(T,NbEquipes,NbConf),
	getVarList(T,L),
	labeling(L).
	
/* Tests
[eclipse 12]: solve3(T).

T = []([](1, 2, 3), [](1, 3, 2), [](2, 1, 3), [](2, 3, 1))
Yes (0.00s cpu, solution 1, maybe more) ? ;

T = []([](1, 2, 3), [](1, 3, 2), [](2, 3, 1), [](2, 1, 3))
Yes (0.00s cpu, solution 2, maybe more) ? ;

T = []([](1, 3, 2), [](1, 2, 3), [](2, 1, 3), [](2, 3, 1))
Yes (0.00s cpu, solution 3, maybe more) ?
*/