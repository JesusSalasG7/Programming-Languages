(* 
    Programming Languages
    Assignment 01

    Authors: 
    Rosmar Ramos 
    Juan Hernández
    Jesús Salas
*)

fun preprocess_prog e =
    case e of
        LineSegment(a, b, c, d) =>
            if equal_expr(Point(a, b), Point(c, d))
            then Point(a, d)
            else if a > c
            then LineSegment(c, d, a, b)
            else if real_close(a, c) andalso b > d
            then LineSegment(c, d, a, b)
            else LineSegment(a, b, c, d)
        | Intersect(e1, e2) => 
            Intersect(preprocess_prog e1, preprocess_prog e2)
        | Let(s, e1, e2) => 
            Let(s, preprocess_prog e1, preprocess_prog e2)
        | Shift(a, b, e1) => 
            Shift(a, b, preprocess_prog e1)
        | _ => e

(* interpreter for our language: 
   * takes a geometry expression and returns a geometry value
   * for simplicity we have the top-level function take an environment,
     (which should be [] for the whole program
   * we assume the expression e has already been "preprocessed" as described
     in the assignment: 
         * line segments are not actually points (endpoints not real close)
         * lines segment have left (or, if vertical, bottom) coordinate first
*)
fun eval_prog (e, env) =
    case e of
        NoPoints => e
	    | Point(_, _)  => e 
        | Line(_, _) => e
        | VerticalLine _ => e
        | LineSegment(_, _, _, _) => e
        | Intersect(e1, e2) => intersect( eval_prog(e1, env), eval_prog(e2, env))
        | Let(s, e1, e2) => eval_prog(e2, (s, eval_prog (e1, env))::env)
        | Var s => 
            let 
            fun search env1 =
                case env1 of
                    [] => raise BadProgram("var not found: " ^ s)
                    | (x, y)::env1' =>
                        if s = x 
                        then y
                        else search(env1')
            in
                search env
            end
        | Shift (dx, dy, e1) =>    
            case eval_prog(e1, env) of
                NoPoints => NoPoints
                | Point(x, y) => Point(x + dx, y + dy)
                | Line(m, b)  => Line(m, b + dy - m*dx)
                | VerticalLine x => VerticalLine (x + dx)
                | LineSegment (x1, y1, x2, y2) => 
                    LineSegment(x1 + dx, y1 + dy, x2 + dx, y2 + dy)
                | _ => 
                    raise  Impossible "bad call to Shift a non-value"