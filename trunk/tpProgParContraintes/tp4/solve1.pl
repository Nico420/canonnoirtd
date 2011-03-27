solve1(T) :-
	getData(_TailleEquipes,NbEquipes,_CapaBateaux,NbBateaux,NbConf),
	defineVars(T,NbEquipes,NbConf,NbBateaux),
	getVarList(T,L),
	labeling(L).
	
/* Tests
[eclipse 10]: solve1(T).

T = []([](1, 1, 1), [](1, 1, 1), [](1, 1, 1), [](1, 1, 1))
Yes (0.00s cpu, solution 1, maybe more) ? ;

T = []([](1, 1, 1), [](1, 1, 1), [](1, 1, 1), [](1, 1, 2))
Yes (0.00s cpu, solution 2, maybe more) ? ;

T = []([](1, 1, 1), [](1, 1, 1), [](1, 1, 1), [](1, 1, 3))
Yes (0.00s cpu, solution 3, maybe more) ?
*/