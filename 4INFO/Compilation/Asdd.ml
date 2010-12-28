open Lex;;
open List;;
type ul=unite_lexicale;;

type vn=
  Expr
| SuiteExpr
| Termb
| SuiteTermb
| Facteurb
| Relation
| Op;;

type vt=
  Vt_ou
| Vt_et
| Vt_parg
| Vt_pard
| Vt_si
| Vt_alors
| Vt_sinon
| Vt_fsi
| Vt_ident of string
| Vt_eg
| Vt_neg
| Vt_inf
| Vt_sup
| Vt_supeg
| Vt_infeg
| Vt_eof;;

type v = VN of vn | VT of vt ;;

type arbre_concret = Feuille of vt
	| Noeud of (vn*arbre_concret list);;



let derivation (vn,ul) = match (vn,ul) with
	  (Expr,_) -> [VN(Termb);VN(SuiteExpr)]
	| (SuiteExpr,U_ou) -> [VT(Vt_ou);VN(Termb);VN(SuiteExpr)]
	| (SuiteExpr,_) -> []
	| (Termb,_) -> [VN(Facteurb);VN(SuiteTermb)]
	| (SuiteTermb,U_et) -> [VT(Vt_et);VN(Facteurb);VN(SuiteTermb)]
	| (SuiteTermb,_) -> []
	| (Facteurb,U_paro) -> [VT(Vt_parg);VN(Expr);VT(Vt_pard)]
	| (Facteurb,U_si) -> [VT(Vt_si);VN(Expr);VT(Vt_alors);VN(Expr);VT(Vt_sinon);VN(Expr);VT(Vt_fsi)]
	| (Facteurb,_) -> [VN(Relation)]
	| (Relation,_) -> [VT(Vt_ident"");VN(Op);VT(Vt_ident"" )]
	| (Op,U_eg) -> [VT(Vt_eg)]
	| (Op,U_neg) -> [VT(Vt_neg)]
	| (Op,U_inf) -> [VT(Vt_inf)]
	| (Op,U_sup) -> [VT(Vt_sup)]
	| (Op,U_supeg) -> [VT(Vt_supeg)]
	| (Op,_) -> [VT(Vt_infeg)];; (*Correspond a infeg, mais comme ils sont tous passe avant *)

let ul_vers_vt ul = match ul with
		  U_ident(_) -> Vt_ident ""
		| U_paro -> Vt_parg
 		| U_parf -> Vt_pard
		| U_sup -> Vt_sup
		| U_inf -> Vt_inf
		| U_eg -> Vt_eg
		| U_neg -> Vt_neg
		| U_supeg -> Vt_supeg
		| U_infeg -> Vt_infeg
		| U_et -> Vt_et
		| U_ou -> Vt_ou
		| U_si -> Vt_si
		| U_alors -> Vt_alors
		| U_sinon -> Vt_sinon
		| U_fsi -> Vt_fsi
		| _ -> Vt_eof;;




exception Etat_incorrect of string;;

let rec analyse_caractere (v,ul) = match (v,ul) with
  | (VT(Vt_et),(U_et)::reste)-> (Feuille Vt_et,reste)
  | (VT(Vt_et),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_ou),(U_ou)::reste)-> (Feuille Vt_ou,reste)
  | (VT(Vt_ou),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_parg),(U_paro)::reste)-> (Feuille Vt_parg,reste)
  | (VT(Vt_parg),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_pard),(U_parf)::reste)-> (Feuille Vt_pard,reste)
  | (VT(Vt_pard),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_si),(U_si)::reste)-> (Feuille Vt_si,reste)
  | (VT(Vt_si),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_sinon),(U_sinon)::reste)-> (Feuille Vt_sinon,reste)
  | (VT(Vt_sinon),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_alors),(U_alors)::reste)-> (Feuille Vt_alors,reste)
  | (VT(Vt_alors),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_fsi),(U_fsi)::reste)-> (Feuille Vt_fsi,reste)
  | (VT(Vt_fsi),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_ident ""),(U_ident(id1))::reste) -> (Feuille (Vt_ident id1),reste)
  | (VT(Vt_ident ""),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_eg),(U_eg)::reste)-> (Feuille Vt_eg,reste)
  | (VT(Vt_eg),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_neg),(U_neg)::reste)-> (Feuille Vt_neg,reste)
  | (VT(Vt_neg),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_sup),(U_sup)::reste)-> (Feuille Vt_sup,reste)
  | (VT(Vt_sup),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_inf),(U_inf)::reste)-> (Feuille Vt_inf,reste)
  | (VT(Vt_inf),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_infeg),(U_infeg)::reste)-> (Feuille Vt_infeg,reste)
  | (VT(Vt_infeg),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VT(Vt_supeg),(U_supeg)::reste)-> (Feuille Vt_supeg,reste)
  | (VT(Vt_supeg),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (VN(tn),a::reste)-> let (acl,ullist)= analyse_mot (derivation(tn,a),a::reste) in (Noeud(tn,acl),ullist)
  | (VN(tn),_)-> raise(Etat_incorrect("Mauvais ul"))
  | (_,_)-> raise(Etat_incorrect("Mauvais ul"))

and

analyse_mot (vl,ull) = match (vl,ull) with
  |([],ull)-> ([],ull)
  |([a],ull)-> let (al,l)=analyse_caractere (a,ull) in ([al],l)
  |(a::reste,ull) -> 
let (ac,ullist2)=analyse_caractere(a,ull) in
let (acl,ullist)=analyse_mot (reste,ullist2) in 
  (ac::acl,ullist);;

let vlist = [VN Expr];;
let ullist= [U_ident("t");U_sup;U_ident("y");U_et;U_paro;U_ident("x");U_eg;U_ident("y");U_parf;U_eof];;

let arbre = analyse_mot(vlist,ullist);;


let vlist2 = [VN Expr];;
let ullist2= [U_ident("t");U_ident("y");U_et;U_paro;U_ident("x");U_eg;U_ident("y");U_parf;U_eof];;

let arbre2 = analyse_mot(vlist2,ullist2);;
(* Les tests fonctionnent *)

(*
Seance 3 - Construction de l'arbre syntaxique abstrait
*)

type operator =
   Op_eg
  | Op_neg
  | Op_sup
  | Op_supeg
  | Op_inf
  | Op_infeg;;

type arbre_abstrait =
   Expr_ou of arbre_abstrait * arbre_abstrait
  | Expr_et of arbre_abstrait * arbre_abstrait
  | Expr_si of arbre_abstrait * arbre_abstrait* arbre_abstrait
  | Relations of string * operator * string;;


let rec convert ab = match ab with
          Noeud(Expr,[a;Noeud(SuiteExpr, [])]) -> convert a
	| Noeud(Expr,[terme1; Noeud(SuiteExpr, [(Feuille Vt_ou); terme2; suite])]) -> Expr_ou((convert terme1), (convert(Noeud(Expr,[terme2;suite]))))
	| Noeud(Termb,[fact; Noeud(SuiteTermb,[])]) -> convert fact
	| Noeud(Termb,[fact1; Noeud(SuiteTermb,[(Feuille Vt_et); fact2; suite])]) -> Expr_et((convert fact1), (convert(Noeud(Termb,[fact2;suite]))))
	| Noeud(Facteurb,[a]) -> convert a
	| Noeud(Facteurb,[(Feuille Vt_parg); expr;(Feuille Vt_pard)]) -> convert expr
	| Noeud(Facteurb,[(Feuille Vt_si); expr1; (Feuille Vt_alors); expr2; (Feuille Vt_sinon); expr3;(Feuille Vt_fsi)]) ->
	    Expr_si((convert expr1),(convert expr2),(convert expr3))
	| Noeud(Relation,(Feuille (Vt_ident id1))::Noeud(operator,(Feuille oper)::[])::(Feuille (Vt_ident id2))::[]) -> Relations(id1, (match oper with
		 		      Vt_inf -> Op_inf
				    | Vt_infeg -> Op_infeg
				    | Vt_sup -> Op_sup
				    | Vt_supeg -> Op_supeg
				    | Vt_eg -> Op_eg
				    | Vt_neg -> Op_neg)
			      , id2);;


ul_vers_vt (U_ident("test"));;
VT(Vt_ident "test");;
let ([a],b) = arbre;;
convert a;;

let vlist3 = [VN Expr];;
let ullist3= [U_ident("a");U_infeg;U_ident("b");U_ou;U_paro;U_ident("x");U_supeg;U_ident("b");U_ou;U_ident("x");U_inf;U_ident("a");U_parf;U_eof];;

let arbre3 = analyse_mot(vlist3,ullist3);;

let ([arb],reste) = arbre3;;
convert arb;;
