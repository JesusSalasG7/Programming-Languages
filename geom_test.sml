(* 
    Programming Languages
    Assignment 01

    Some simple test cases that cover all of the expressions.

    You are welcome to add more test cases.
*)

(* Will not compile until you implement preprocess and eval_prog *)

use "geom_lang.sml";
use "helpers.sml";
use "geom.sml";

(* 1- Preprocess tests *)

(* 1.1 Preprocess LineSegment to Point *)
let
	val current = preprocess_prog (LineSegment(3.2, 4.1, 3.2, 4.1))
	val expected = Point(3.2, 4.1)
in
    if equal_expr (current, expected)
	then (print "preprocess converted a LineSegment to a Point successfully\n")
	else (print "preprocess failed converting a LineSegment to a Point\n")
end;

(* 1.1 Preprocess LineSegment to flipped LineSegment *)
let 
	val current = preprocess_prog (LineSegment(3.2, 4.1, ~3.2, ~4.1))
	val expected = LineSegment(~3.2, ~4.1, 3.2, 4.1)
in
    if equal_expr (current, expected)
	then (print "preprocess flipped an improper LineSegment successfully\n")
	else (print "preprocess failed flipping an improper LineSegment\n")
end;

(* 2 Eval tests *)

(* 2.1 Eval NoPoints test *)
let 
	val current = eval_prog (preprocess_prog NoPoints, [])
in
    case current of
        NoPoints => (print "eval_prog with NoPoints and empty environment worked\n")
        | _ => (print "eval_prog with NoPoints and empty environment returned an unexpected expression\n")
end;

(* 2.2 Eval Point test *)
let 
	val current = eval_prog (preprocess_prog (Point(4.0, 4.0)), [])
	val expected = Point(4.0, 4.0) 
in
    if equal_expr (current, expected)
	then (print "eval_prog with Point and empty environment worked\n")
	else (print "eval_prog with Point and empty environment failed\n")
end;

(* 2.3 Eval Line test *)
let 
	val current = eval_prog (preprocess_prog (Line(5.0, 2.0)), [])
	val expected = Line(5.0, 2.0) 
in
    if equal_expr (current, expected)
	then (print "eval_prog with Line and empty environment worked\n")
	else (print "eval_prog with Line and empty environment failed\n")
end;

(* 2.4 Eval VerticalLine test *)
let 
	val current = eval_prog (preprocess_prog (VerticalLine 4.0), [])
	val expected = (VerticalLine 4.0)
in
    if equal_expr (current, expected)
	then (print "eval_prog with VerticalLine and empty environment worked\n")
	else (print "eval_prog with VerticalLine and empty environment failed\n")
end;

(* 2.5 Eval LineSegment test *)
let
    val current = eval_prog (preprocess_prog (LineSegment(3.2, 4.1, ~3.2, ~4.1)), [])
	val expected = LineSegment(~3.2, ~4.1, 3.2, 4.1)
in
    if equal_expr (current, expected)
    then (print "eval_prog with LineSegment and empty environment worked\n")
    else (print "eval_prog with LineSegment and empty environment failed\n")
end;

(* 2.6 Eval Intersect tests *)

(* 2.5.1 Eval Intersect NoPoints with NoPoints test *)
let
    val current = eval_prog (preprocess_prog (Intersect(NoPoints, NoPoints)), [])
in
    case current of
        NoPoints => (print "eval_prog with Intersect and empty environment worked\n")
        | _ => (print "eval_prog with Intersect and empty environment returned an unexpected expression\n")
end;

(* 2.5.2 Eval Intersect LineSegment with VerticalLine test *)
let
    val current = eval_prog (preprocess_prog (Intersect(LineSegment(1.0, 3.0, 5.0, 3.0), VerticalLine 3.0)), [])
    val expected = Point(3.0, 3.0)
in
    if equal_expr (current, expected)
    then (print "eval_prog with Intersect LineSegment and VerticalLine, and empty environment worked\n")
	else (print "eval_prog with Intersect LineSegment and VerticalLine, and empty environment failed\n")
end;

(* You are welcome to add more Intersect tests *)

(* 2.6 Eval Var test *)
let
    val current = eval_prog (preprocess_prog (Var "p"), [("p", Point(2.5, 3.2))])
    val expected = Point(2.5, 3.2)
in
    if equal_expr (current, expected)
	then (print "eval_prog with Var and 'p' in environment worked\n")
	else (print "eval_prog with Var and 'p' in environment failed\n")
end;

(* 2.7 Eval Let test *)
let
    val program = Let("vl", VerticalLine 3.0, Intersect(LineSegment(1.0, 3.0, 5.0, 3.0), Var "vl"))
    val current = (eval_prog (preprocess_prog program, []))
    val expected = Point(3.0, 3.0)
in
    if equal_expr (current, expected)
    then (print "eval_prog with Let and empty environment worked\n")
	else (print "eval_prog with Let and empty environment failed\n")
end;

(* 2.8 Eval Shift tests *)

(* 2.8.1 Eval Shift Point test *)
let 
	val current = (eval_prog (preprocess_prog (Shift(3.0, 4.0, Point(4.0, 4.0))), []))
	val expected = Point(7.0, 8.0) 
in
    if equal_expr (current, expected)
	then (print "eval_prog with Shift Point and empty environment worked\n")
	else (print "eval_prog with Shift Point and empty environment failed\n")
end;

(* 2.8.2 Eval Shift Var *)
let 
	val current = (eval_prog (Shift(3.0, 4.0, Var "p"), [("p", Point(4.0, 4.0))]))
	val expected = Point(7.0, 8.0) 
in
	if equal_expr (current, expected)
	then (print "eval_prog with Shift Var and 'p' in environment worked\n")
	else (print "eval_prog with Shift Var and 'p' in environment failed\n")
end;


(* 2.8.3 Eval Shift Var with Variable Shadowing *)
let 
	val current = (eval_prog (Shift(3.0, 4.0, Var "p"), [("p", Point(4.0, 4.0)), ("p", Point(1.0, 1.0))]))
	val expected = Point(7.0,8.0) 
in
	if equal_expr (current, expected)
	then (print "eval_prog with Shift Var and shadowed 'p' in environment worked\n")
	else (print "eval_prog with Shift Var and shadowed 'p' in environment failed\n")
end;
