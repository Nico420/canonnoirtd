getVarList(T,L):-
	dim(T,[NbEquipes,NbConf]),
	( for(Indice1,1,NbConf),fromto([],In,Out,L),param(T,NbEquipes)
	do
		( for(Indice2,1,NbEquipes),fromto([],In2,Out2,L2),param(T,Indice1)
		do
			Var is T[Indice2,Indice1],
			append(In2,[Var],Out2)
		),
		append(In,L2,Out)
	).
	
/* Tests
[eclipse 9]:  getData(TailleEq,NbEq,CapaBat,NbBat,NbConf),defineVars(T,NbEq,NbConf,NbBat),getVarList(T,L).

TailleEq = [](5, 5, 2, 1)
NbEq = 4
CapaBat = [](7, 6, 5)
NbBat = 3
NbConf = 3
T = []([](_484{1 .. 3}, _553{1 .. 3}, _622{1 .. 3}), [](_693{1 .. 3}, _762{1 .. 3}, _831{1 .. 3}), [](_902{1 .. 3}, _971{1 .. 3}, _1040{1 .. 3}), [](_1111{1 .. 3}, _1180{1 .. 3}, _1249{1 .. 3}))
L = [_484{1 .. 3}, _693{1 .. 3}, _902{1 .. 3}, _1111{1 .. 3}, _553{1 .. 3}, _762{1 .. 3}, _971{1 .. 3}, _1180{1 .. 3}, _622{1 .. 3}, _831{1 .. 3}, _1040{1 .. 3}, _1249{1 .. 3}]
Yes (0.00s cpu)
*/