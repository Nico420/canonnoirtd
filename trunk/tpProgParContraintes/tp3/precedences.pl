precedences(Taches) :-	dim(Taches,[Dim]),
			(for(Indice,1,Dim),param(Taches)
			do
				Elem is Taches[Indice],
				Elem = tache(_D,Noms,_M,Debut),
				(foreach(I,Noms),param(Debut,Taches)
				do							
					tache(Duree2,_N,_M,Debut2) is Taches[I],
					Debut #>= Debut2+Duree2
				)
			).
			
solve(Taches,Fin) :-	taches(Taches),
						domaines(Taches,Fin),
						precedences(Taches),
						getVarList(Taches,Fin,Liste),
						labeling(Liste),
						affiche(Taches).

/*
[eclipse 44]: solve(T, Fin).
tache(3, [], m1, 0)
tache(8, [], m1, 0)
tache(8, [4, 5], m1, 6)
tache(6, [], m2, 0)
tache(3, [1], m2, 3)
tache(4, [1, 7], m1, 22)
tache(8, [3, 5], m1, 14)
tache(6, [4], m2, 6)
tache(6, [6, 7], m2, 26)
tache(6, [9, 12], m2, 32)
tache(3, [1], m2, 3)
tache(6, [7, 8], m2, 22)

T = [](tache(3, [], m1, 0), tache(8, [], m1, 0), tache(8, [4, 5], m1, 6), tache(6, [], m2, 0), tache(3, [1], m2, 3), tache(4, [1, 7], m1, 22), tache(8, [3, 5], m1, 14), tache(6, [4], m2, 6), tache(6, [6, 7], m2, 26), tache(6, [9, 12], m2, 32), tache(3, [1], m2, 3), tache(6, [7, 8], m2, 22))
Fin = 38

*/