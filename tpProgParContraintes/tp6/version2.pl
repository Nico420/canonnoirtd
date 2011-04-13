quick_sort([],[]).
quick_sort([H|T],Sorted):-
	pivoting(H,T,L1,L2),quick_sort(L1,Sorted1),quick_sort(L2,Sorted2),
	append(Sorted1,[H|Sorted2],Sorted).
   
pivoting(_H,[],[],[]).
pivoting(H,[X|T],[X|L],G):-abs(X)=<abs(H),pivoting(H,T,L,G),!.
pivoting(H,[X|T],L,[X|G]):-abs(X)>abs(H),pivoting(H,T,L,G),!.

/* Tests
[eclipse 50]: quick_sort([1,2,3,4,-1,-2,-3,-4],L).

L = [-1, 1, -2, 2, -3, 3, -4, 4]
Yes (0.00s cpu)
*/

choice(X) :-
	get_domain_as_list(X,L),
	quick_sort(L,L2),
	member(X,L2).

solve5(Places) :-
	getData(Poids,NbPers,NbPlac),
	defineVars(Places,NbPlac,NbPers),
	elimineSymetrie(Places),
	pasMemesPlaces(Places),
	cinqChaqueCote(Places,NbPers),
	balancoireEquilibree2(Poids,NbPers,Places,SNormeMom),
	parentsEncadrentEnfants(Places),
	danEtMaxDevantParents(Places),
	getVarList(Places,NbPers,L),
	minimize(search(L,0,input_order,choice,complete,[]),SNormeMom).
	
/* Tests
[eclipse 32]: solve5(P).
Found a solution with cost 1216
Found a solution with cost 956
Found a solution with cost 947
Found a solution with cost 917
Found a solution with cost 852
Found a solution with cost 802
Found no solution with cost -1.0Inf .. 801

P = [](-3, 1, -2, -6, -1, 4, 3, 5, -5, 2)
Yes (1.80s cpu)
*/
