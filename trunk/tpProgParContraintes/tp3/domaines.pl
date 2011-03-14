domaines(Taches,Fin) :-	dim(Taches,[Dim]),
			(for(Indice,1,Dim),param(Taches,Fin)
						do
							tache(Duree,_Nom,_Machine,Debut) is Taches[Indice],
							Debut + Duree #=< Fin,
							Debut #>= 0
						).

/*
[eclipse 5]: taches(T),domaines(T,10).

T = [tache(3, [], m1, _421{0 .. 7}), tache(8, [], m1, _644{0 .. 2}), tache(8, [4, 5], m1, _867{0 .. 2}), tache(6, [], m2, _1090{0 .. 4}), tache(3, [1], m2, _1313{0 .. 7}), tache(4, [1, 7], m1, _1536{0 .. 6}), tache(8, [3, 5], m1, _1759{0 .. 2}), tache(6, [4], m2, _1982{0 .. 4}), tache(6, [6, 7], m2, _2205{0 .. 4}), tache(6, [9, 12], m2, _2428{0 .. 4}), tache(3, [1], m2, _2651{0 .. 7}), tache(6, [7, 8], m2, _2874{0 .. 4})]

There are 12 delayed goals. Do you want to see them? (y\n) 
Yes (0.00s cpu)
*/