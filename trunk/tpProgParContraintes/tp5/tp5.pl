%TP5

:- lib(ic).
:- lib(branch_and_bound).

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
	
nbOuvriersNecessaires(Fabriquer,Techniciens,NbSortes,NbOuvriersTotal) :-
	( for(J,1,NbSortes),fromto(0,In,Out,NbOuvriersTotal),param(Fabriquer,Techniciens)
		do
			Var is Fabriquer[J],
			NbTech is Techniciens[J],
			Out #= In + NbTech * Var
	).
	
vectBeneficeTotal(Fabriquer,Benefice,Quantite,NbSortes,VectBenefTotal) :-
	( for(K,1,NbSortes),fromto([],In,Out,VectBenefTotal),param(Fabriquer,Benefice,Quantite)
		do
			Var is Fabriquer[K],
			Benef is Benefice[K],
			Quan is Quantite[K],
			Elem #= Var * Benef * Quan,
			append(In,[Elem],Out)
	).
	
profitTotal(Fabriquer,Benefice,Quantite,NbSortes,ProfitTotal) :-
	vectBeneficeTotal(Fabriquer,Benefice,Quantite,NbSortes,VectBenefTotal),
	ProfitTotal #= sum(VectBenefTotal).
	
pose_contraintes(Fabriquer,NbTechniciensTotal,Profit) :-
	getData(NbTech,NbSor,Tech,Quan,Bene),
	defineVars(Fabriquer,NbSor),
	nbOuvriersNecessaires(Fabriquer,Tech,NbSor,NbTechniciensTotal),
	NbTechniciensTotal #=< NbTech,
	getVarList(Fabriquer,NbSor,L),
	profitTotal(Fabriquer,Bene,Quan,NbSor,Profit),
	labeling(L).

test(X,Y,Z,W) :-
	[X,Y,Z,W] #:: [0..10],
	X #= Z+Y+2*W,
	X#\= Z+Y+W.
	
/* Question 5.4
Il faut toujours faire un labeling dans le but,
car il faut que les variables aient ete instanciees.

[eclipse 53]: minimize(test(X,Y,Z,W),X).
bb_min: search did not instantiate cost variable
Aborting execution ...
Abort

Avec le labeling sur [X,Y,Z,W], cela fonctionne, Prolog trouve les reponses

[eclipse 57]: test(X,Y,Z,W),labeling([X,Y,Z,W]).

X = 2
Y = 0
Z = 0
W = 1
Yes (0.00s cpu, solution 1, maybe more) ? ;

X = 3
Y = 0
Z = 1
W = 1
Yes (0.00s cpu, solution 2, maybe more) ? ;
*/

/* Test

[eclipse 71]: P2#=P*(-1), minimize(pose_contraintes(F,N,P),P2).
Found a solution with cost 0
Found a solution with cost -495
Found a solution with cost -795
Found a solution with cost -1195
Found a solution with cost -1495
Found a solution with cost -1535
Found a solution with cost -1835
Found a solution with cost -1955
Found a solution with cost -1970
Found a solution with cost -2010
Found a solution with cost -2015
Found a solution with cost -2315
Found a solution with cost -2490
Found a solution with cost -2665
Found no solution with cost -1.0Inf .. -2666

P2 = -2665
P = 2665
F = [](0, 1, 1, 0, 0, 1, 1, 0, 1)
N = 22
Yes (0.00s cpu)
*/

% Question 5.6

pose_contraintes2(Fabriquer,NbTechniciensTotal,Profit) :-
	getData(NbTech,NbSor,Tech,Quan,Bene),
	defineVars(Fabriquer,NbSor),
	nbOuvriersNecessaires(Fabriquer,Tech,NbSor,NbTechniciensTotal),
	NbTechniciensTotal #=< NbTech,
	getVarList(Fabriquer,NbSor,L),
	profitTotal(Fabriquer,Bene,Quan,NbSor,Profit),
	Profit #>=1000,
	labeling(L).

/* Tests
[eclipse 74]: minimize(pose_contraintes2(F,N,P),N).
Found a solution with cost 10
Found a solution with cost 9
Found a solution with cost 8
Found a solution with cost 7
Found no solution with cost -1.0Inf .. 6

F = [](1, 0, 1, 0, 0, 0, 0, 0, 0)
N = 7
P = 1040
Yes (0.00s cpu)
*/

