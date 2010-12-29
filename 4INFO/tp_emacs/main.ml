exception BadExpr

let rec eval = function
  | Node ((Int i), _) -> i
  | Node ((Op op), [l; r]) ->
      let fonction_operateur =
	(match op with
	   | Add -> ( + )
	   | Mul -> ( * ))
      in fonction_operateur (eval l) (eval r)
  | _ -> raise BadExpr
