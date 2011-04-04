getData(NbTechniciens,NbSortes,Techniciens,Quantite,Benefice) :-
	NbTechniciens = 22,
	NbSortes = 9,
	Techniciens = [](5,7,2,6,9,3,7,5,3),
	Quantite = [](140,130,60,95,70,85,100,30,45),
	Benefice = [](4,5,8,5,6,4,7,10,11).
	
defineVars(Fabriquer,NbSortes):-
	dim(Fabriquer,[NbSortes]),
	( for(I,1,NbSortes),param(Fabriquer)
	do
		Fabriquer[I] #:: 0..1
	).

getVarList(Fabriquer,NbSortes,L) :-
	( for(Ind,1,NbSortes),fromto([],In,Out,L),param(Fabriquer)
		do
			Var #= Fabriquer[Ind],
			append(In,[Var],Out)
	).
