solve1(Taches,Fin) :-	taches(Taches),
						domaines(Taches,Fin),
						getVarList(Taches,Fin,Liste),
						labeling(Liste),
						affiche(Taches).