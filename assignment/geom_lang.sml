(* 
    Programming Languages
    Assignment 01

    Definition of the geometric language.
*)

(* expressions in a little language for 2D geometry objects
   values: points, lines, vertical lines, line segments
   other expressions: intersection of two expressions, lets, variables, 
                      (shifts added by you)
*)
datatype geom_exp = 
        NoPoints
	    | Point of real * real (* represents point (x, y) *)
        | Line of real * real (* represents line (slope, intercept) *)
        | VerticalLine of real (* x value *)
        | LineSegment of real * real * real * real (* x1,y1 to x2,y2 *)
        | Intersect of geom_exp * geom_exp (* intersection expression *)
        | Let of string * geom_exp * geom_exp (* let s = e1 in e2 *)
        | Var of string
        | Shift of real * real * geom_exp

exception BadProgram of string
exception Impossible of string
exception NoImplementedYet