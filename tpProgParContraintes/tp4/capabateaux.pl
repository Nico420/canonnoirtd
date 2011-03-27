capaBateaux(T,TailleEquipes,NbEquipes,CapaBateaux,NbBateaux,NbConf):-
	dim(T,[NbEquipes,NbConf]),
	( for(Bateau,1,NbBateaux), param(T,NbEquipes,NbConf,CapaBateaux,TailleEquipes)
	do
		( for(Conf,1,NbConf), param(T,NbEquipes,Bateau,CapaBateaux,TailleEquipes)
		do		
			( for(Equipe,1,NbEquipes),param(T,Bateau,Conf,TailleEquipes),fromto(0,In,Out,Total)
			do
				BateauI is T[Equipe,Conf],
				#=(Bateau,BateauI,Cond),
				Inc #= TailleEquipes[Equipe] * Cond,
				Out #= In + Inc
			),
			Capacite is CapaBateaux[Bateau],
			Total #=< Capacite
		)
	).
	
solve4(T) :-
	getData(TailleEquipes,NbEquipes,CapaBateaux,NbBateaux,NbConf),
	defineVars(T,NbEquipes,NbConf,NbBateaux),
	pasMemeBateaux(T,NbEquipes,NbConf),
	pasMemePartenaires(T,NbEquipes,NbConf),
	capaBateaux(T,TailleEquipes,NbEquipes,CapaBateaux,NbBateaux,NbConf),
	getVarList(T,L),
	labeling(L).
	
/* Tests
[eclipse 13]: solve4(T).

T = []([](1, 2, 3), [](2, 3, 1), [](3, 1, 2), [](3, 2, 1))
Yes (0.01s cpu, solution 1, maybe more) ? ;

T = []([](1, 3, 2), [](2, 1, 3), [](3, 2, 1), [](3, 1, 2))
Yes (0.01s cpu, solution 2, maybe more) ? ;

T = []([](1, 2, 3), [](3, 1, 2), [](2, 3, 1), [](1, 3, 2))
Yes (0.01s cpu, solution 3, maybe more) ?
*/