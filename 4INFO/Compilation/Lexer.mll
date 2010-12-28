{ 
open Parser
open Printf
type terminaux = Ident of string | Lettre | Chiffre | Beg | Pt_virg | End | Virg | Int | Bool | Op_fleche | Op_plus | Op_inf | And | Parg | Pard | EOF
}

rule get_token = parse
 	  "begin" 	{Beg}
	| ';' 		{Pt_virg} 
	| "end" 	{End} 
	| ',' 		{Virg} 
	| "int" 	{Int} 
	| "bool" 	{Bool} 
	| "<-" 		{Op_fleche} 
	| '+' 		{Op_plus} 
	| '<' 		{Op_inf} 
	| "and" 	{And} 
	| '(' 		{Parg} 
	| ')' 		{Pard}
	| '.' '\t' '\n' {get_token lexbuf}
	| ((['a'-'z'] | ['A'-'Z'])(['a'-'z'] | ['A'-'Z'] | ['0'-'9'])+) {Ident(Lexing.lexeme lexbuf)}
	(*| ['0'-'9'] 	{Chiffre}*)
	| eof		{EOF}
	| _		{get_token lexbuf}


