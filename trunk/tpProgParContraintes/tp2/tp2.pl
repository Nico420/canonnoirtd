:-lib(ic).
:-lib(ic_symbolic).

% Question 2.1

:- local domain(pays(anglais,espagnol,ukrainien,norvegien,japonais)).
:- local domain(couleur(rouge,verte,blanche,jaune,bleue)).
:- local domain(boisson(cafe,the,lait,jusdOrange,eau)).
:- local domain(voiture(bmw,toyota,ford,honda,datsun)).
:- local domain(animal(chien,serpents,renard,cheval,zebre)).

domaines_maison(m(Pays,Couleur,Boisson,Voiture,Animal,Numero)) :- 
												Pays &:: pays,
												Couleur &:: couleur,
												Boisson &:: boisson,
												Voiture &:: voiture,
												Animal &:: animal,
												Numero #:: 1..5.
																	
rue(Rue) :- length(Rue,5),
			(foreach(Elem,Rue), for(I, 1, 5), fromto([],InP,OutP,FinP), fromto([],InC,OutC,FinC), fromto([],InB,OutB,FinB), fromto([],InV,OutV,FinV), fromto([],InA,OutA,FinA)
			do
				domaines_maison(Elem),
				Elem = m(P,C,B,V,A,I),
				OutP=[P|InP],
				OutC=[C|InC],
				OutB=[B|InB],
				OutV=[V|InV],
				OutA=[A|InA]
			),
			ic_symbolic:alldifferent(FinP),
			ic_symbolic:alldifferent(FinC),
			ic_symbolic:alldifferent(FinB),
			ic_symbolic:alldifferent(FinV),
			ic_symbolic:alldifferent(FinA).

/*Tests
[eclipse 42]: rue(R).

R = [m(_296{[anglais, espagnol, ukrainien, norvegien, japonais]}, _400{[rouge, verte, blanche, jaune, bleue]}, _504{[cafe, the, lait, jusdOrange, eau]}, _608{[bmw, toyota, ford, honda, datsun]}, _712{[chien, serpents, renard, cheval, zebre]}, 1), m(_894{[anglais, espagnol, ukrainien, norvegien, japonais]}, _998{[rouge, verte, blanche, jaune, bleue]}, _1102{[cafe, the, lait, jusdOrange, eau]}, _1206{[bmw, toyota, ford, honda, datsun]}, _1310{[chien, serpents, renard, cheval, zebre]}, 2), m(_1492{[anglais, espagnol, ukrainien, norvegien, japonais]}, _1596{[rouge, verte, blanche, jaune, bleue]}, _1700{[cafe, the, lait, jusdOrange, eau]}, _1804{[bmw, toyota, ford, honda, datsun]}, _1908{[chien, serpents, renard, cheval, zebre]}, 3), m(_2090{[anglais, espagnol, ukrainien, norvegien, japonais]}, _2194{[rouge, verte, blanche, jaune, bleue]}, _2298{[cafe, the, lait, jusdOrange, eau]}, _2402{[bmw, toyota, ford, honda, datsun]}, _2506{[chien, serpents, renard, cheval, zebre]}, 4), m(_2688{[anglais, espagnol, ukrainien, norvegien, japonais]}, _2792{[rouge, verte, blanche, jaune, bleue]}, _2896{[cafe, the, lait, jusdOrange, eau]}, _3000{[bmw, toyota, ford, honda, datsun]}, _3104{[chien, serpents, renard, cheval, zebre]}, 5)]

There are 30 delayed goals. Do you want to see them? (y/n) 
Yes (0.10s cpu)
*/	

ecrit_maisons(Rue) :- 	(foreach(Elem,Rue)
						do
							writeln(Elem)
						).
% Permet de tester l'affichage
% Ruetest = [m(anglais,rouge,cafe,bmw,chien,1),m(norvegien,bleue,lait,honda,zebre,2)]

/* Test
[eclipse 48]: Ruetest = [m(anglais,rouge,cafe,bmw,chien,1),m(norvegien,bleue,lait,honda,zebre,2)],ecrit_maisons(Ruetest).
m(anglais, rouge, cafe, bmw, chien, 1)
m(norvegien, bleue, lait, honda, zebre, 2)

Ruetest = [m(anglais, rouge, cafe, bmw, chien, 1), m(norvegien, bleue, lait, honda, zebre, 2)]
Yes (0.00s cpu)

*/

getVarList([],[]).
getVarList([m(P,C,B,V,A,_I)|Rest],[P,C,B,V,A | Liste]) :- getVarList(Rest,Liste).

labeling_symbolic(Liste) :- (foreach(Elem,Liste)
							do
								ic_symbolic:indomain(Elem)
							).

/* Test

rue(R),getVarList(R,L),labeling_symbolic(L).

R = [m(anglais, rouge, cafe, bmw, chien, 1), m(espagnol, verte, the, toyota, serpents, 2), m(ukrainien, blanche, lait, ford, renard, 3), m(norvegien, jaune, jusdOrange, honda, cheval, 4), m(japonais, bleue, eau, datsun, zebre, 5)]
L = [anglais, rouge, cafe, bmw, chien, espagnol, verte, the, toyota, serpents, ukrainien, blanche, lait, ford, renard, norvegien, jaune, jusdOrange, honda, ...]
Yes (0.00s cpu, solution 1, maybe more) ? ;

R = [m(anglais, rouge, cafe, bmw, chien, 1), m(espagnol, verte, the, toyota, serpents, 2), m(ukrainien, blanche, lait, ford, renard, 3), m(norvegien, jaune, jusdOrange, honda, zebre, 4), m(japonais, bleue, eau, datsun, cheval, 5)]
L = [anglais, rouge, cafe, bmw, chien, espagnol, verte, the, toyota, serpents, ukrainien, blanche, lait, ford, renard, norvegien, jaune, jusdOrange, honda, ...]
Yes (0.00s cpu, solution 2, maybe more) ? ;

R = [m(anglais, rouge, cafe, bmw, chien, 1), m(espagnol, verte, the, toyota, serpents, 2), m(ukrainien, blanche, lait, ford, renard, 3), m(norvegien, jaune, jusdOrange, datsun, cheval, 4), m(japonais, bleue, eau, honda, zebre, 5)]
L = [anglais, rouge, cafe, bmw, chien, espagnol, verte, the, toyota, serpents, ukrainien, blanche, lait, ford, renard, norvegien, jaune, jusdOrange, datsun, ...

*/

contraintes(R) :- 	(foreach(m(P,C,B,V,A,I),R)
						do
							(P &= anglais) #= (C &= rouge),
							(P &= espagnol) #= (A &= chien),
							(B &= cafe) #= (C &= verte),
							(P &= ukrainien) #= (B &= the),
							(A &= serpents) #= (V &= bmw),
							(C &= jaune) #= (V &= toyota),
							(B &= lait) #= (I #= 3),
							(P &= norvegien) #= (I #= 1),
							(B &= jusdOrange) #= (V &= honda),
							(P &= japonais) #= (V &= datsun)
					).
					
contraintes2(R) :-	(foreach(m(_P1,C1,_B1,_V1,_A1,I1),R),param(R)
						do
							(foreach(m(_P2,C2,_B2,_V2,_A2,I2),R),param(I1,C1)
								do
									(I1 #= I2-1) #= (C1 &= blanche),
									(C1 &= blanche) #= (C2 &= verte),
									(I1 #= I2-1) #= (C2 &= verte)
							)
					).
						
resoudre(R) :- rue(R),contraintes(R),getVarList(R,L),labeling_symbolic(L),ecrit_maisons(R).

resoudre2(R) :- rue(R),getVarList(R,L),contraintes2(R),labeling_symbolic(L),ecrit_maisons(R).


