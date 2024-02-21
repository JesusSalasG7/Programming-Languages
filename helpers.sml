(* 
    Programming Languages
    Assignment 01

    Helpers functions to be used in the interpreter.
*)

(* helper functions for comparing real numbers since rounding means
   we should never compare for equality *)
val epsilon = 0.00001

fun real_close (r1, r2) = (Real.abs (r1 - r2)) < epsilon

(* notice curried *)
fun real_close_point (x1, y1) (x2, y2) = 
    real_close (x1, x2) andalso real_close (y1, y2)

(* helper function to return the Line or VerticalLine containing 
   points (x1, y1) and (x2, y2). Actually used only when intersecting 
   line segments, but might be generally useful *)
fun two_points_to_line (x1, y1, x2, y2) = 
    if real_close (x1, x2)
    then VerticalLine x1
    else
	    let 
            val m = (y2 - y1) / (x2 - x1)
            val b = y1 - m * x1
	    in
    	    Line(m, b)
	    end

(* helper function for interpreter: return value that is the intersection
   of the arguments: 25 cases because there are 5 kinds of values, but
   many cases can be combined, especially because intersection is commutative.
   Do *not* call this function with non-values (e.g., shifts or lets)
 *)
fun intersect (v1, v2) =
    case (v1, v2) of
        (NoPoints, _) => NoPoints (* 5 cases *)
        | (_, NoPoints) => NoPoints (* 4 additional cases *)
        | (Point p1, Point p2) =>
            if real_close_point p1 p2
			then v1
			else NoPoints
        | (Point (x, y), Line (m, b)) =>
            if real_close(y, m * x + b)
			then v1
			else NoPoints
        | (Point (x1, _), VerticalLine x2) =>
            if real_close (x1, x2)
			then v1
			else NoPoints
        | (Point _, LineSegment seg) => intersect (v2, v1)
        | (Line _, Point _) => intersect (v2, v1)
        | (Line (m1, b1), Line (m2, b2)) =>
            if real_close(m1, m2) 
	        then 
                (if real_close (b1, b2)
	            then v1 (* same line *)
	            else NoPoints) (* parallel lines do not intersect *)
	        else 
	            let (* one-point intersection *)
		            val x = (b2 - b1) / (m1 - m2)
		            val y = m1 * x + b1
	            in
		            Point (x,y)
	            end
        | (Line (m1, b1), VerticalLine x2) => Point(x2, m1 * x2 + b1)
        | (Line _, LineSegment _) => intersect(v2, v1)
        | (VerticalLine _, Point _) => intersect(v2, v1)
        | (VerticalLine _, Line _)  => intersect(v2, v1)
        | (VerticalLine x1, VerticalLine x2) => if real_close (x1, x2)
	                                            then v1 (* same line *)
	                                            else NoPoints (* parallel *)
        | (VerticalLine _, LineSegment seg) => intersect (v2, v1)
        | (LineSegment seg, _) =>
	        (* the hard case, actually 4 cases because v2 could be a point,
	           line, vertical line, or line segment *)
	        (* First compute the intersection of (1) the line containing the segment 
               and (2) v2. Then use that result to compute what we need. *)
	        (case intersect (two_points_to_line seg, v2) of
	            NoPoints => NoPoints 
	            | Point(x0, y0) => (* see if the point is within the segment bounds *)
	            (* assumes v1 was properly preprocessed *)
                    let 
                        fun inbetween (v, end1, end2) =
                            (end1 - epsilon <= v andalso v <= end2 + epsilon)
                            orelse (end2 - epsilon <= v andalso v <= end1 + epsilon)
                        val (x1, y1, x2, y2) = seg
                    in
                        if inbetween (x0, x1, x2) andalso inbetween (y0, y1, y2)
                        then Point(x0, y0)
                        else NoPoints
                    end
	            | Line _ => v1 (* so segment seg is on line v2 *)
	            | VerticalLine _ => v1 (* so segment seg is on vertical-line v2 *)
	            | LineSegment seg2 => 
	                (* the hard case in the hard case: seg and seg2 are on the same
                       line (or vertical line), but they could be (1) disjoint or 
                       (2) overlapping or (3) one inside the other or (4) just touching.
	                   And we treat vertical segments differently, so there are 4*2 cases.
	                *)
	                let
		                val (x1start, y1start, x1end, y1end) = seg
		                val (x2start, y2start, x2end, y2end) = seg2
	                in
		                if real_close(x1start,x1end)
		                then (* the segments are on a vertical line *)
		                (* let segment a start at or below start of segment b *)
		                    let 
                                val ((a_x_start, a_y_start, a_x_end, a_y_end),
                                     (b_x_start, b_y_start, b_x_end, b_y_end)) =
                                        if y1start < y2start
                                        then (seg, seg2)
                                        else (seg2, seg)
		                    in
			                    if real_close(a_y_end, b_y_start)
			                    then Point (a_x_end, a_y_end) (* just touching *)
			                    else if a_y_end < b_y_start
			                    then NoPoints (* disjoint *)
			                    else if a_y_end > b_y_end
			                    then LineSegment(b_x_start, b_y_start, b_x_end, b_y_end) (* b inside a *)
			                    else LineSegment(b_x_start, b_y_start, a_x_end, a_y_end) (* overlapping *)
		                    end
		                else (* the segments are on a (non-vertical) line *)
		                    (* let segment a start at or to the left of start of segment b *)
		                    let 
			                    val ((a_x_start, a_y_start, a_x_end, a_y_end),
			                         (b_x_start, b_y_start, b_x_end, b_y_end)) =
                                        if x1start < x2start
                                        then (seg, seg2)
							            else (seg2, seg)
		                    in
			                    if real_close(a_x_end, b_x_start)
			                    then Point (a_x_end, a_y_end) (* just touching *)
			                    else if a_x_end < b_x_start
			                    then NoPoints (* disjoint *)
			                    else if a_x_end > b_x_end
			                    then LineSegment(b_x_start, b_y_start, b_x_end, b_y_end) (* b inside a *)
			                    else LineSegment(b_x_start, b_y_start, a_x_end, a_y_end) (* overlapping *)
		                    end	
	                end						
	  | _ => raise Impossible "bad result from intersecting with a line")
      | _ => raise Impossible "bad call to intersect: only for shape values"

fun equal_expr (e1, e2) =
    case (e1, e2) of
        (NoPoints, NoPoints) => true
        | (Point(a, b), Point(c, d)) => real_close (a, c) andalso real_close (b, d)
        | (Line(a, b), Line(c, d)) => real_close (a, c) andalso real_close (b, d)
        | (VerticalLine a, VerticalLine b) => real_close (a, b)
        | (LineSegment(a, b, c, d), LineSegment(e, f, g, h)) => real_close (a, e) andalso real_close (b, f) andalso real_close (c, g) andalso real_close (d, h)
        | (Intersect (e3, e4), Intersect (e5, e6)) => equal_expr (e3, e5) andalso equal_expr (e4, e6)
        | (Let(s1, e3, e4), Let(s2, e5, e6)) => s1 = s2 andalso equal_expr (e3, e5) andalso equal_expr (e4, e6)
        | (Var s1, Var s2) => s1 = s2
        | (Shift(x1, y1, e3), Shift(x2, y2, e4)) => real_close (x1, x2) andalso real_close (y1, y2) andalso equal_expr (e3, e4)
        | (_, _) => false