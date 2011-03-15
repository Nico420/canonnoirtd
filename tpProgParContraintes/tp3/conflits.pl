conflits(Taches) :- dim(Taches,[Dim]),
			(for(Indice,1,Dim),param(Taches,Dim)
			do
				Elem is Taches[Indice],
				I2 is Indice+1,
				/*Il faut assurer que les indices soient differents, sinon on va se retrouver a comparer deux fois la meme taches*/
				(for(I,I2,Dim),param(Taches,Elem)
				do		
					Elem2 is Taches[I],
					machinesDifferentes(Elem,Elem2)
				)
			).

machinesDifferentes(tache(_,_,M1,_),tache(_,_,M2,_)):- \=(M1,M2),!.
machinesDifferentes(tache(Duree,_,M,Debut),tache(Duree2,_,M,Debut2)) :- ((Debut #>= Debut2+Duree2) or (Debut+Duree #=< Debut2)).


solve2(Taches,Fin) :-	taches(Taches),
						domaines(Taches,Fin),
						precedences(Taches),
						conflits(Taches),
						getVarList(Taches,Fin,Liste),
						labeling(Liste),
						affiche(Taches).
/*
[eclipse 10]: solve2(Taches,Fin).
tache(3, [], m1, 0)
tache(8, [], m1, 29)
tache(8, [4, 5], m1, 9)
tache(6, [], m2, 0)
tache(3, [1], m2, 6)
tache(4, [1, 7], m1, 25)
tache(8, [3, 5], m1, 17)
tache(6, [4], m2, 12)
tache(6, [6, 7], m2, 31)
tache(6, [9, 12], m2, 37)
tache(3, [1], m2, 9)
tache(6, [7, 8], m2, 25)

Taches = [](tache(3, [], m1, 0), tache(8, [], m1, 29), tache(8, [4, 5], m1, 9), tache(6, [], m2, 0), tache(3, [1], m2, 6), tache(4, [1, 7], m1, 25), tache(8, [3, 5], m1, 17), tache(6, [4], m2, 12), tache(6, [6, 7], m2, 31), tache(6, [9, 12], m2, 37), tache(3, [1], m2, 9), tache(6, [7, 8], m2, 25))
Fin = 43
Yes (0.01s cpu, solution 1, maybe more) ? ;
tache(3, [], m1, 1)
tache(8, [], m1, 29)
tache(8, [4, 5], m1, 9)
tache(6, [], m2, 0)
tache(3, [1], m2, 6)
tache(4, [1, 7], m1, 25)
tache(8, [3, 5], m1, 17)
tache(6, [4], m2, 12)
tache(6, [6, 7], m2, 31)
tache(6, [9, 12], m2, 37)
tache(3, [1], m2, 9)
tache(6, [7, 8], m2, 25)

Taches = [](tache(3, [], m1, 1), tache(8, [], m1, 29), tache(8, [4, 5], m1, 9), tache(6, [], m2, 0), tache(3, [1], m2, 6), tache(4, [1, 7], m1, 25), tache(8, [3, 5], m1, 17), tache(6, [4], m2, 12), tache(6, [6, 7], m2, 31), tache(6, [9, 12], m2, 37), tache(3, [1], m2, 9), tache(6, [7, 8], m2, 25))
Fin = 43
Yes (0.01s cpu, solution 2, maybe more) ? ;
tache(3, [], m1, 2)
tache(8, [], m1, 29)
tache(8, [4, 5], m1, 9)
tache(6, [], m2, 0)
tache(3, [1], m2, 6)
tache(4, [1, 7], m1, 25)
tache(8, [3, 5], m1, 17)
tache(6, [4], m2, 12)
tache(6, [6, 7], m2, 31)
tache(6, [9, 12], m2, 37)
tache(3, [1], m2, 9)
tache(6, [7, 8], m2, 25)

Taches = [](tache(3, [], m1, 2), tache(8, [], m1, 29), tache(8, [4, 5], m1, 9), tache(6, [], m2, 0), tache(3, [1], m2, 6), tache(4, [1, 7], m1, 25), tache(8, [3, 5], m1, 17), tache(6, [4], m2, 12), tache(6, [6, 7], m2, 31), tache(6, [9, 12], m2, 37), tache(3, [1], m2, 9), tache(6, [7, 8], m2, 25))
Fin = 43
Yes (0.01s cpu, solution 3, maybe more) ?
*/

/*
[eclipse 11]: solve2(Taches,42).

No (0.00s cpu)
*/
