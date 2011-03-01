
%%%%%%%%%%%%%%%%%%%%%%%%%
% Paramètres d'exécution
%

:- set( clauselength, 100 ).      % on borne la taille des clauses
:- set( minacc, 0.99 ).          % [0-1] on autorise x% de bruit au maximum
:- set( noise, 1).               % nb max d'e- pouvant etre couverts par une hypothese
%:- set( minposfrac, 0.03 ).      % pourcentage min de couverture de E+
:- set( minpos, 2 ).              % nb e+ minimal pour une hypothese
:- set( minscore, 0.1 ).          % score minimal pour une hypothese
:- set( verbose, 0 ).             % pas de blabla, on travaille
:- set( i, 3 ).                   % longueur max de connexion avec les var de tete
:- set( depth, 30 ).              % profondeur de preuve (pour couverture)
:- set( newvars, 20).             % nombre max var introduite
:- set( nodes, 100000 ).           % nb maximum de clauses construites dans la recherche
:- set( check_useless, true).     % pour avoir des var qui servent a qq chose ds bot
:- set( record, true ).           % on garde une trace...
:- set( recordfile, 'test_modif_v2'). % ...dans ce fichier
:- set( evalfn, coverage ).       %  fonction d'evaluation de la qualite des clauses
:- set( lazy_on_contradiction, true).
:- set( search, bf ).      % shorter first: bf, best first: heuristic




%%%%%%%%%%%%%%%%%%%%%%%%% Definition du langage d'hypothese Lh
% Modes
%       modeh are mode declarations for head literals
%       modeb are mode declarations for body literals
%       + represents input arguments
%       - represents output arguments
%       + or - are followed by type of each argument
%       in this example, the type "int" is a built-in unary predicate

%:- modeh(1,carre(+jeu)).
%:- modeh(1,paire(+jeu)).
%:- modeh(1,double_paire(+jeu)).
%:- modeh(1,brelan(+jeu)).
:- modeh(1,suite(+jeu)).
%:- modeh(1,couleur(+jeu)).
%:- modeh(1,full(+jeu)).
%:- modeh(1,quinte_flush(+jeu)).
%:- modeh(1,quinte_royale(+jeu)).

:- modeb(1,cartes(+jeu,set(-c,-c,-c,-c,-c))).
:- modeb(1,meme_hauteur(+c,+c)).
:- modeb(1,meme_couleur(+c,+c)).
:- modeb(1,a_suivre(+c,+c)).


%:- determination(carre/1,cartes/2).
%:- determination(carre/1,meme_hauteur/2).

%:- determination(paire/1,cartes/2).
%:- determination(paire/1,meme_hauteur/2).

%:- determination(double_paire/1,cartes/2).
%:- determination(double_paire/1,meme_hauteur/2).

:- determination(suite/1,cartes/2).
:- determination(suite/1,a_suivre/2).

%:- determination(couleur/1,cartes/2).
%:- determination(couleur/1,meme_couleur/2).

%:- determination(full/1,cartes/2).
%:- determination(full/1,meme_hauteur/2).

%:- determination(quinte_flush/1,cartes/2).
%:- determination(quinte_flush/1,meme_couleur/2).
%:- determination(quinte_flush/1,a_suivre/2).

%:- determination(quinte_royale/1,cartes/2).
%:- determination(quinte_royale/1,meme_couleur/2).
%:- determination(quinte_royale/1,a_suivre/2).

%:- determination(brelan/1,cartes/2).
%:- determination(brelan/1,meme_hauteur/2).




meme_hauteur(C1,C2) :- 		valeur(C1,A),valeur(C2,A),\=(C1,C2).
meme_couleur(C1,C2) :- 		couleur(C1,A),couleur(C2,A),\=(C1,C2).
a_suivre(C1,C2) :- 		valeur(C1,sept),valeur(C2,huit),\=(C1,C2).
a_suivre(C1,C2) :- 		valeur(C1,huit),valeur(C2,neuf),\=(C1,C2).
a_suivre(C1,C2) :- 		valeur(C1,neuf),valeur(C2,dix),\=(C1,C2).
a_suivre(C1,C2) :- 		valeur(C1,dix),valeur(C2,valet),\=(C1,C2).
a_suivre(C1,C2) :- 		valeur(C1,valet),valeur(C2,dame),\=(C1,C2).
a_suivre(C1,C2) :- 		valeur(C1,dame),valeur(C2,roi),\=(C1,C2).
a_suivre(C1,C2) :- 		valeur(C1,roi),valeur(C2,as),\=(C1,C2).

cartes(Jeu,set(A,B,C,D,E)) :- 	a_carte(Jeu,A),
				a_carte(Jeu,B),\=(A,B),
				a_carte(Jeu,C),\=(A,C),\=(B,C),
				a_carte(Jeu,D),\=(A,D),\=(B,D),\=(C,D),
				a_carte(Jeu,E),\=(A,E),\=(B,E),\=(C,E),\=(D,E).

