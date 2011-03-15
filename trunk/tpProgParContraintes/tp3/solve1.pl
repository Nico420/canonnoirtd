solve1(Taches,Fin) :-	taches(Taches),
						domaines(Taches,Fin),
						getVarList(Taches,Fin,Liste),
						labeling(Liste),
						affiche(Taches).
/*
[eclipse 4]: solve1(Taches,Fin).
lists.eco  loaded in 0.00 seconds
tache(3, [], m1, 0)
tache(8, [], m1, 0)
tache(8, [4, 5], m1, 0)
tache(6, [], m2, 0)
tache(3, [1], m2, 0)
tache(4, [1, 7], m1, 0)
tache(8, [3, 5], m1, 0)
tache(6, [4], m2, 0)
tache(6, [6, 7], m2, 0)
tache(6, [9, 12], m2, 0)
tache(3, [1], m2, 0)
tache(6, [7, 8], m2, 0)

Taches = [](tache(3, [], m1, 0), tache(8, [], m1, 0), tache(8, [4, 5], m1, 0), tache(6, [], m2, 0), tache(3, [1], m2, 0), tache(4, [1, 7], m1, 0), tache(8, [3, 5], m1, 0), tache(6, [4], m2, 0), tache(6, [6, 7], m2, 0), tache(6, [9, 12], m2, 0), tache(3, [1], m2, 0), tache(6, [7, 8], m2, 0))
Fin = 8
Yes (0.00s cpu, solution 1, maybe more) ? ;
tache(3, [], m1, 1)
tache(8, [], m1, 0)
tache(8, [4, 5], m1, 0)
tache(6, [], m2, 0)
tache(3, [1], m2, 0)
tache(4, [1, 7], m1, 0)
tache(8, [3, 5], m1, 0)
tache(6, [4], m2, 0)
tache(6, [6, 7], m2, 0)
tache(6, [9, 12], m2, 0)
tache(3, [1], m2, 0)
tache(6, [7, 8], m2, 0)

Taches = [](tache(3, [], m1, 1), tache(8, [], m1, 0), tache(8, [4, 5], m1, 0), tache(6, [], m2, 0), tache(3, [1], m2, 0), tache(4, [1, 7], m1, 0), tache(8, [3, 5], m1, 0), tache(6, [4], m2, 0), tache(6, [6, 7], m2, 0), tache(6, [9, 12], m2, 0), tache(3, [1], m2, 0), tache(6, [7, 8], m2, 0))
Fin = 8
Yes (0.01s cpu, solution 2, maybe more) ? ;
tache(3, [], m1, 2)
tache(8, [], m1, 0)
tache(8, [4, 5], m1, 0)
tache(6, [], m2, 0)
tache(3, [1], m2, 0)
tache(4, [1, 7], m1, 0)
tache(8, [3, 5], m1, 0)
tache(6, [4], m2, 0)
tache(6, [6, 7], m2, 0)
tache(6, [9, 12], m2, 0)
tache(3, [1], m2, 0)
tache(6, [7, 8], m2, 0)

Taches = [](tache(3, [], m1, 2), tache(8, [], m1, 0), tache(8, [4, 5], m1, 0), tache(6, [], m2, 0), tache(3, [1], m2, 0), tache(4, [1, 7], m1, 0), tache(8, [3, 5], m1, 0), tache(6, [4], m2, 0), tache(6, [6, 7], m2, 0), tache(6, [9, 12], m2, 0), tache(3, [1], m2, 0), tache(6, [7, 8], m2, 0))
Fin = 8
Yes (0.01s cpu, solution 3, maybe more) ?
*/