type typ = SInt | SBool;;


type expr = Feuille of string
	|Inf of expr * expr
   	|Plus of expr * expr
	|And of expr * expr;;

type prog = Noeud of ((typ*string) list * sinst list)

and

sinst =  NewBloc of prog
	     |Affect of (string * expr);;
