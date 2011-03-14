affiche(Taches) :-	dim(Taches,[Dim]),
			(for(Indice,1,Dim),param(Taches)
						do
							Elem is Taches[Indice],							
							writeln(Elem)
					).


/*
[eclipse 4]: taches(T),affiche(T).
tache(3, [], m1, _235)
tache(8, [], m1, _242)
tache(8, [4, 5], m1, _249)
tache(6, [], m2, _260)
tache(3, [1], m2, _267)
tache(4, [1, 7], m1, _276)
tache(8, [3, 5], m1, _287)
tache(6, [4], m2, _298)
tache(6, [6, 7], m2, _307)
tache(6, [9, 12], m2, _318)
tache(3, [1], m2, _329)
tache(6, [7, 8], m2, _338)

T = [tache(3, [], m1, _235), tache(8, [], m1, _242), tache(8, [4, 5], m1, _249), tache(6, [], m2, _260), tache(3, [1], m2, _267), tache(4, [1, 7], m1, _276), tache(8, [3, 5], m1, _287), tache(6, [4], m2, _298), tache(6, [6, 7], m2, _307), tache(6, [9, 12], m2, _318), tache(3, [1], m2, _329), tache(6, [7, 8], m2, _338)]
Yes (0.00s cpu)

*/	