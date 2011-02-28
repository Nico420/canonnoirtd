:-lib(ic).
:-lib(ic_symbolic).

taches(Taches) :- 	Taches = 	[tache(3,[],m1,_),
								tache(8,[],m1,_),
								tache(8,[4,5],m1,_),
								tache(6,[],m2,_),
								tache(3,[1],m2,_),
								tache(4,[1,7],m1,_),
								tache(8,[3,5],m1,_),
								tache(6,[4],m2,_),
								tache(6,[6,7],m2,_),
								tache(6,[9,12],m2,_),
								tache(3,[1],m2,_),
								tache(6,[7,8],m2,_)].
					
affiche(Taches) :-	(foreach(Elem,Taches)
						do
							writeln(Elem)
					).
						
domaines(Taches,Fin) :-	(foreach(Elem,Taches),param(Fin)
						do
							Elem = tache(Duree,_Nom,_Machine,Debut),
							FinTache #= Debut + Duree,
							FinTache #=< Fin,
							Debut #:: 0..Fin
						).
						
getVarList([],_Fin,[]).
getVarList([tache(_Duree,_Nom,_Machine,Debut)|Rest],Fin,[Debut | List]) :- getVarList(Rest,Fin,List).

labelingDebut(Liste) :-	(foreach(Elem,Liste)
							do
								indomain(Elem)
						).

solve(Taches,Fin) :-	taches(Taches),
						domaines(Taches,Fin),
						/*precedences(Taches),*/
						getVarList(Taches,Fin,Liste),
						labelingDebut(Liste),
						affiche(Taches).

precedences(Taches) :-	(foreach(Elem,Taches),param(Taches)
							do
								Elem = tache(_D,Noms,_M,Debut),
								(foreach(I,Noms),param(Debut,Taches)
									do		
										tache(Duree2,_N,_M,Debut2) is Taches[I],
										Debut #= Debut2+Duree2
								)
						).

