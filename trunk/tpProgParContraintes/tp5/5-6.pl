pose_contraintes2(Fabriquer,NbTechniciensTotal,Profit) :-
	getData(NbTech,NbSor,Tech,Quan,Bene),
	defineVars(Fabriquer,NbSor),
	nbOuvriersNecessaires(Fabriquer,Tech,NbSor,NbTechniciensTotal),
	NbTechniciensTotal #=< NbTech,
	getVarList(Fabriquer,NbSor,L),
	profitTotal(Fabriquer,Bene,Quan,NbSor,Profit),
	Profit #>=1000,
	labeling(L).

/* Tests
[eclipse 74]: minimize(pose_contraintes2(F,N,P),N).
Found a solution with cost 10
Found a solution with cost 9
Found a solution with cost 8
Found a solution with cost 7
Found no solution with cost -1.0Inf .. 6

F = [](1, 0, 1, 0, 0, 0, 0, 0, 0)
N = 7
P = 1040
Yes (0.00s cpu)
*/
