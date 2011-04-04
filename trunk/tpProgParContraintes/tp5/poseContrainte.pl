pose_contraintes(Fabriquer,NbTechniciensTotal,Profit) :-
	getData(NbTech,NbSor,Tech,Quan,Bene),
	defineVars(Fabriquer,NbSor),
	nbOuvriersNecessaires(Fabriquer,Tech,NbSor,NbTechniciensTotal),
	NbTechniciensTotal #=< NbTech,
	getVarList(Fabriquer,NbSor,L),
	profitTotal(Fabriquer,Bene,Quan,NbSor,Profit),
	labeling(L).
