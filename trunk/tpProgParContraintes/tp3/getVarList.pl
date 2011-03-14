getVarList(Taches,Fin,ListFin):- dim(Taches,[Dim]),
				(for(Indice,1,Dim),fromto([],In,Out,List),param(Taches)
				do
					Xi is Taches[Indice],
					Xi = tache(_,_,_,Debut),
					Out=[Debut|In]
				),
				ListFin=[Fin|List].
				

/*
[eclipse 6]: taches(T), getVarList(T, Fin, L).

T = [](tache(3, [], m1, _238), tache(8, [], m1, _243), tache(8, [4, 5], m1, _248), tache(6, [], m2, _257), tache(3, [1], m2, _262), tache(4, [1, 7], m1, _269), tache(8, [3, 5], m1, _278), tache(6, [4], m2, _287), tache(6, [6, 7], m2, _294), tache(6, [9, 12], m2, _303), tache(3, [1], m2, _312), tache(6, [7, 8], m2, _319))
Fin = Fin
L = [Fin, _319, _312, _303, _294, _287, _278, _269, _262, _257, _248, _243, _238]
Yes (0.00s cpu)


*/