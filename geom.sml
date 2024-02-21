(* 
    Programming Languages
    Assignment 01

    Authors: Juan Hernández
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
        |(_) => e

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
    (* Replace the exception raise with your solution *)
    raise NoImplementedYet