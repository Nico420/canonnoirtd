defineVars(T,NbEquipes,NbConf,NbBateaux):-
	dim(T,[NbEquipes,NbConf]),
	( for(Ind1,1,NbEquipes),param(T,NbBateaux,NbConf)
	do
		( for(Ind2,1,NbConf),param(T,Ind1,NbBateaux)
		do
			T[Ind1,Ind2] #:: 1..NbBateaux
		)
	).
	
/* Tests
[eclipse 8]: getData(TailleEq,NbEq,CapaBat,NbBat,NbConf),defineVars(T,NbEq,NbConf,NbBat).

TailleEq = [](5, 5, 2, 1)
NbEq = 4
CapaBat = [](7, 6, 5)
NbBat = 3
NbConf = 3
T = []([](_419{1 .. 3}, _488{1 .. 3}, _557{1 .. 3}), [](_628{1 .. 3}, _697{1 .. 3}, _766{1 .. 3}), [](_837{1 .. 3}, _906{1 .. 3}, _975{1 .. 3}), [](_1046{1 .. 3}, _1115{1 .. 3}, _1184{1 .. 3}))
Yes (0.00s cpu)
*/