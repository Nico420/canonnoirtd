(*#use "parser.ml";;*)
open Lexer;;

(* si le fichier "test" contient un code à analyser *)
(*main get_token (Lexing.from_channel (open_in "test"));;*)

(* pour de tous petits tests *)
let lex_vers_string lexeme = match lexeme with
	  Lettre 	-> "lettre"
	| Chiffre 	-> "chiffre"
	| Beg 		-> "begin"
	| Pt_virg 	-> ";"
	| End 		-> "end"
	| Virg 		-> ","
	| Int 		-> "int"
	| Bool 		-> "bool"
	| Op_fleche 	-> "<-"
	| Op_plus 	-> "+"
	| Op_inf 	-> "<"
	| And 		-> "and"
	| Parg 		-> "("
	| Pard		-> ")"
	| Ident s 	-> s
	| EOF		-> "FIN";;


let lex = Lexing.from_string "begin int a14B ; aC <- ba + CA end";;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;(*  *)
Printf.printf "%s\n" (lex_vers_string (get_token lex));;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;
Printf.printf "%s\n" (lex_vers_string (get_token lex));;



(* La suite est utile pour tester l'analyseur lexical tout seul. *)
(* Il faut juste déclarer le type token. Normalement il est déclaré au début du *)
(* fichier parser.ml et provient des %token qui se trouvent dans l'en-tête de *)
(* parser.mly. *)
(*let lexbuf = Lexing.from_channel (open_in "test");;*)
(* ou *)
(* let lexbuf = Lexing.from_string "begin int a ; a <- b + c end";; *)

(*get_token lexbuf;; (* donne la prochaine unité lexicale *)*)
