%{ 
open Printf
(*type terminaux = Ident of string | Lettre | Chiffre | Beg | Pt_virg | End | Virg | Int | Bool | Op_fleche | Op_plus | Op_inf | And | Parg | Pard | EOF*)
(*type nonterminaux = bloc | sdecl | Sinst | Decl | Type | Inst | Expr | SuiteIdent*)
%}
%type <Arbre.prog> main

%type <string> Ident 
%type <int> Int 
%token Chiffre Beg Pt_virg End Virg
%token Int Bool Op_fleche Op_plus
%token Op_inf And Parg Pard
%token EOF

%left Op_plus Op_inf And
%right
%start bloc

%type <unit> bloc
%%
bloc :
	Beg sdecl Pt_virg Sinst End {Noeud($2,$4)}
;
sdecl : 
	Decl {[$1]}
	| Decl Virg sdecl {$1::$3}
;
Sinst : 
	Inst {[$1]}
	| Inst Pt_virg Sinst {$1::$3}
;
Decl : 
	Type Ident {($1,$2)}
;
Type : 
	Int {SInt}
	| Bool {SBool}
;
Inst : 
	bloc {Newbloc($1)}
	| Ident Op_fleche Expr {Affect($1,$3)}
;
Expr : 
	Expr Op_plus Expr {Plus($1,$3)}
	| Expr Op_inf Expr {Inf($1,$3)}
	| Expr And Expr {And($1,$3)}
	| Parg Expr Pard {$2}
	| Ident {Feuille $1}
;
	
