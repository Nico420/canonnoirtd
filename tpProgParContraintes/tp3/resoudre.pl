resoudre(R) :- rue(R),getVarList(R,L),labeling_symbolic(L),ecrit_maisons(R).

/* Test
[eclipse 3]: resoudre(R).
m(anglais, rouge, cafe, bmw, chien, 1)
m(espagnol, verte, the, toyota, serpents, 2)
m(ukrainien, blanche, lait, ford, renard, 3)
m(norvegien, jaune, jusdOrange, honda, cheval, 4)
m(japonais, bleue, eau, datsun, zebre, 5)

R = [m(anglais, rouge, cafe, bmw, chien, 1), m(espagnol, verte, the, toyota, serpents, 2), m(ukrainien, blanche, lait, ford, renard, 3), m(norvegien, jaune, jusdOrange, honda, cheval, 4), m(japonais, bleue, eau, datsun, zebre, 5)]
Yes (0.10s cpu, solution 1, maybe more) ? ;
m(anglais, rouge, cafe, bmw, chien, 1)
m(espagnol, verte, the, toyota, serpents, 2)
m(ukrainien, blanche, lait, ford, renard, 3)
m(norvegien, jaune, jusdOrange, honda, zebre, 4)
m(japonais, bleue, eau, datsun, cheval, 5)

R = [m(anglais, rouge, cafe, bmw, chien, 1), m(espagnol, verte, the, toyota, serpents, 2), m(ukrainien, blanche, lait, ford, renard, 3), m(norvegien, jaune, jusdOrange, honda, zebre, 4), m(japonais, bleue, eau, datsun, cheval, 5)]
Yes (0.10s cpu, solution 2, maybe more) ? ;
m(anglais, rouge, cafe, bmw, chien, 1)
m(espagnol, verte, the, toyota, serpents, 2)
m(ukrainien, blanche, lait, ford, renard, 3)
m(norvegien, jaune, jusdOrange, datsun, cheval, 4)
m(japonais, bleue, eau, honda, zebre, 5)

R = [m(anglais, rouge, cafe, bmw, chien, 1), m(espagnol, verte, the, toyota, serpents, 2), m(ukrainien, blanche, lait, ford, renard, 3), m(norvegien, jaune, jusdOrange, datsun, cheval, 4), m(japonais, bleue, eau, honda, zebre, 5)]
Yes (0.10s cpu, solution 3, maybe more) ? ;
m(anglais, rouge, cafe, bmw, chien, 1)
m(espagnol, verte, the, toyota, serpents, 2)
m(ukrainien, blanche, lait, ford, renard, 3)
m(norvegien, jaune, jusdOrange, datsun, zebre, 4)
m(japonais, bleue, eau, honda, cheval, 5)

R = [m(anglais, rouge, cafe, bmw, chien, 1), m(espagnol, verte, the, toyota, serpents, 2), m(ukrainien, blanche, lait, ford, renard, 3), m(norvegien, jaune, jusdOrange, datsun, zebre, 4), m(japonais, bleue, eau, honda, cheval, 5)]
*/
