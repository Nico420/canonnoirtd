:-lib(ic).
:-lib(ic_symbolic).

taches(Taches) :- 	Taches = 	[](tache(3,[],m1,_),
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
					tache(6,[7,8],m2,_)).

/*Test

[eclipse 3]: taches(T).

T = [tache(3, [], m1, _169), tache(8, [], m1, _176), tache(8, [4, 5], m1, _183), tache(6, [], m2, _194), tache(3, [1], m2, _201), tache(4, [1, 7], m1, _210), tache(8, [3, 5], m1, _221), tache(6, [4], m2, _232), tache(6, [6, 7], m2, _241), tache(6, [9, 12], m2, _252), tache(3, [1], m2, _263), tache(6, [7, 8], m2, _272)]
Yes (0.00s cpu)

*/
					
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


solve(Taches,Fin) :-				taches(Taches),
						domaines(Taches,Fin),
						precedences(Taches),
						getVarList(Taches,Fin,Liste),
						labeling(Liste),
						affiche(Taches).

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

/*
[eclipse 44]: taches(T), solve(T, Fin).
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
conflits(Taches) :- dim(Taches,[Dim]),
			(for(Indice,1,Dim),param(Taches,Dim)
			do
				Elem is Taches[Indice],
				I2 is Indice+1, /*Il faut assurer que les indices soient différents, sinon on va se retrouver à comparer deux fois la meme tâches*/
				(for(I,I2,Dim),param(Taches,Elem)
				do		
					Elem2 is Taches[I],
					test(Elem,Elem2)
				)
			).

test(tache(_,_,M1,_),tache(_,_,M2,_)):- \=(M1,M2),!.
test(tache(Duree,_,M,Debut),tache(Duree2,_,M,Debut2)) :- ((Debut #>= Debut2+Duree2) or (Debut+Duree #=< Debut2)).


solve2(Taches,Fin) :-				taches(Taches),
						domaines(Taches,Fin),
						precedences(Taches),
						conflits(Taches),
						getVarList(Taches,Fin,Liste),
						labeling(Liste),
						affiche(Taches).
/*
[eclipse 78]: taches(T), solve2(T, Fin).
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

T = [](tache(3, [], m1, 0), tache(8, [], m1, 29), tache(8, [4, 5], m1, 9), tache(6, [], m2, 0), tache(3, [1], m2, 6), tache(4, [1, 7], m1, 25), tache(8, [3, 5], m1, 17), tache(6, [4], m2, 12), tache(6, [6, 7], m2, 31), tache(6, [9, 12], m2, 37), tache(3, [1], m2, 9), tache(6, [7, 8], m2, 25))
Fin = 43
Yes (0.00s cpu, solution 1, maybe more) ? 
*/


/*Question 3.8

Oui, la solution est la meilleure !
Prolog résoud les contraintes en incrémentant le début des tâches, jusqu'à obtenir le respect des contraintes.

*/
