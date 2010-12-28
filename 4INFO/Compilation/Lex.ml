(*DESFEUX Nicolas
* PHILIPPE Renaud
Analyse lexicale et crible
*)

(* Définition des unités lexicales. *)
type unite_lexicale = 
  | U_ident of string (* Unité lexicale de l'identifiant *)
  | U_eg (* Unité lexicale du = *)
  | U_neg (* Unité lexicale du <> *) 
  | U_sup (* Unité lexicale du > *)
  | U_inf (* Unité lexicale du < *)
  | U_ou (* Unité lexicale du ou *)
  | U_et (* Unité lexicale du et *)
  | U_paro (* Unité lexicale de la parenthèse ouvrante *)
  | U_parf (* Unité lexicale de la parenthèse fermante *)
  | U_com (* Unité lexicale du commentaire *)
  | U_eof
  | U_si
  | U_fsi
  | U_sinon
  | U_alors
  | U_supeg
  | U_infeg;; (* Unité lexicale de la fin de fichier *)

(* Définition des états *)
type etat =
    Etat_dep
  | Etat_e
  | Etat_o
  | Etat_ident
  | Etat_finident
  | Etat_com
  | Etat_op
  | Etat_opfin
  | Etat_opdif
  | Etat_finetou
  | Etat_etou
  | Etat_debcom
  | Etat_com2
  | Etat_fincom
  | Etat_par
  | Etat_eof
  | Etat_s
  | Etat_finsi
  | Etat_si;;

(* Les états finaux sont choisi parmi les états que nous avons créé. *)
let mesEtatsFinaux=[Etat_finident;Etat_finetou;Etat_fincom;Etat_par;Etat_opfin;Etat_opdif;Etat_eof];;

type automate={ 
  etatc: etat; 
  transition: etat * char -> etat * bool; 
  etatfin: etat list; 
  etatinit:etat; 
}

(* Définition de l'exception lorsque qu'un caractère incorrecte est entré. *)
exception Caractere_incorrect of string * char;;


(* Définition des transitions pour l'automate. la fonction de transition rend un état, et un booléen. le booléen indique si l'on doit consommer ou non le caractère lu. *)
let transition (etat,caractere) = match (etat,caractere) with 
    (Etat_dep,'e') -> (Etat_e,true)
  | (Etat_dep,'o') -> (Etat_o,true)
  | (Etat_dep,'/') -> (Etat_debcom,true)
  | (Etat_dep,' ') -> (Etat_dep,false)
  | (Etat_dep,'s') -> (Etat_s,true)
  | (Etat_s,'i') -> (Etat_si,true)
  | (Etat_s,_) -> (Etat_ident,true)
  | (Etat_si,' ') -> (Etat_finsi,true)
  | (Etat_si,_) -> (Etat_ident,true);
  | (Etat_debcom,'*') -> (Etat_com,true)
  | (Etat_com,'*') -> (Etat_com2,true)
  | (Etat_com2,'/') -> (Etat_fincom,true)
  | (Etat_com2,_) | (Etat_com,_) -> (Etat_com,true)
  | (Etat_dep,'=')  | (Etat_dep,'>')  | (Etat_dep,'<')  -> (Etat_op,true)
  | (Etat_op,'>') -> (Etat_opdif,true)
  | (Etat_op,' ') -> (Etat_opfin,false)
  | (Etat_opdif,_)   | (Etat_op,_) -> (Etat_opfin,false)
  | (Etat_dep,'a'..'z') -> (Etat_ident,true)
  | (Etat_e,'t') | (Etat_o,'u') -> (Etat_etou,true)
  | (Etat_etou,' ')-> (Etat_finetou,false)
  | (Etat_etou,_)-> (Etat_ident,true)
  | (Etat_e,_) | (Etat_o,_) -> (Etat_ident,true)
  | (Etat_ident,'a'..'z') | (Etat_ident,'0'..'9') -> (Etat_ident,true)
  | (Etat_ident,_) -> (Etat_finident,false)
  | (Etat_dep,'(') | (Etat_dep,')') -> (Etat_par,true)
  | (Etat_par,_) -> (Etat_dep,false)
  | (Etat_dep,'\000') -> (Etat_eof,true)
  | (Etat_dep,'\n') -> (Etat_eof,true)
  | (Etat_dep,'0'..'9') -> raise(Caractere_incorrect ("Impossible de mettre un chiffre en debut de mot du langage : ",caractere)) (* On lève une exception si on voit un chiffre en début de lexeme (soit un nombre seul, soit au début d'un ident) *)
  | (_,a) -> raise(Caractere_incorrect ("Mauvais caractere en entree : ",a));; (* On lève une exception si on voit un caractère non autorisé ($,!,?,...), et dans tous les autres cas non reconnus par les transitions *)

(* Fonction de crible. permet de transformer les lexeme en leur unité lexicale correspondante *)
let crible lexeme = match lexeme with
	"=" -> U_eg
|	"<" -> U_inf
|	">" -> U_sup
|	"<>" -> U_neg
|       "<=" -> U_infeg
|       ">=" -> U_supeg
|       "si" -> U_si
|	"(" -> U_paro
|	")" -> U_parf
|	"ou" -> U_ou
|	"et" -> U_et
|   "\000" -> U_eof
|   "\n" -> U_eof
|	_-> if(
	          ((String.sub lexeme 0 2)="/*") 
	      & ((String.sub lexeme ((String.length lexeme) - 2) 2)="*/")
	      ) 
	       then U_com 
	       else U_ident lexeme;;


(* On teste la fonction de transition *)
transition(Etat_dep,'\000');;
transition(Etat_dep,'=');;
(* et la fonction de crible *)
crible("=");;


(* Fonction parcours_automate. Cette fonction lit un fichier en simulant l'automate. Elle doit rendre un couple (état * lexème) *)
let rec parcours_automate chan autom etatc chainec  = 
  let 
      charc = try(input_char chan) with End_of_file -> '\000'
  in
  let (e,b)=autom.transition(etatc,charc) in 
    if ((List.mem e mesEtatsFinaux) & (b=false)) then 
      begin 
	seek_in chan ((pos_in chan) -1) ;
	(e,chainec)
      end
 else
   if ((List.mem e mesEtatsFinaux) & (b=true)) then
    (e,(chainec^(String.make 1 (charc))))
   else
     if(b=true) then
       parcours_automate chan autom e (chainec^(String.make 1 (charc)))
     else
       parcours_automate chan autom e chainec
       ;;

(* Test de parcours automate. On part d'un fichier test. *)
let test = open_in "test";;
let automa = {etatc=Etat_dep; transition=transition; etatfin=mesEtatsFinaux; etatinit=Etat_dep};;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;
parcours_automate test automa Etat_dep "";;


(* Fonction get_token. Rend le coupl unité lexicale * lexeme lors du parcours de l'automate *)
let get_token automate channel =
  let (etat,lexeme)=parcours_automate channel automate Etat_dep "" in 
	(crible lexeme,lexeme);;

(* Test de get_token *)
let test = open_in "test";;
get_token automa test;;

(* Fonction scanner *)
let rec scanner automate test =
  let (u_l,lexeme)= (get_token automate test) in  
    match (u_l,lexeme) with 
      | (U_eof,_)-> [(U_eof,"")] (* on poursuit la récurrence jusque être dans un état de fin de fichier *)
      | (_,_) -> (u_l,lexeme)::(scanner automate test);; (* On concatène les couples créer par get_token, jusqu'au cas d'arrêt *)


(* Test *)
(*let test = open_in "test";;
let test1 = open_in "testop";;
let test2 = open_in "erreuridentchiffre";;
let test3 = open_in "erreurchiffre";;
let test4 = open_in "erreurcar$";;
let test5 = open_in "test2";;
let test6 = open_in "erreurcar";;


scanner automa test;;
scanner automa test1;;
scanner automa test2;;
scanner automa test3;;
scanner automa test4;;
scanner automa test5;;
scanner automa test6;;*)
(* Tout ces tests donnent des résultats cohérents *)
