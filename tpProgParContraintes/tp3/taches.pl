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