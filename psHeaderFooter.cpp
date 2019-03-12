#include <iostream>
#include <vector>
#include<map>
#include<sstream>

#include "parse_tree.h"
using namespace std;

void printHeader(){
	cout <<		"globaldict /_x 300 put" << endl;
	cout <<		"globaldict /_y 300 put" << endl;
	cout <<		"globaldict /_angle 0 put" << endl;
	cout <<		"globaldict /_pi 3.1415923 put" << endl;
	cout <<		"globaldict /_is_pen_on true put" << endl;
	cout <<		"\n";
	cout <<		"/turtle_left{" << endl;
	cout <<		"1 dict begin" << endl;
	cout <<		"	/angle exch def" << endl;
	cout <<		"	globaldict /_angle _angle angle add put" << endl;
	cout <<		"0" << endl;
	cout <<		"end" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
	cout <<		"/turtle_right{" << endl;
	cout <<		"1 dict begin" << endl;
	cout <<		"	/angle exch def" << endl;
	cout <<		"	globaldict /_angle _angle angle sub put" << endl;
	cout <<		"0" << endl;
	cout <<		"end" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";					
	cout <<		"/turtle_forward {" << endl;
	cout <<		"1 dict begin" << endl;
	cout <<		"	/len exch def" << endl;
	cout <<		"	%/_x _angle _pi mul 180 div cos len mul _x add def" << endl;
	cout <<		"	%/_y _angle _pi mul 180 div sin len mul _y add def" << endl;
	cout <<		"	_x _y moveto" << endl;
	cout <<		"	globaldict /_x _angle cos len mul _x add put" << endl;
	cout <<		"	globaldict /_y _angle sin len mul _y add put" << endl;
	cout <<		"	_is_pen_on {_x _y lineto stroke} {_x _y moveto}  ifelse" << endl;
	cout <<		"0" << endl;
	cout <<		"end" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
	cout <<		"/turn_pen_on {" << endl;
	cout <<		"	globaldict /_is_pen_on true put" << endl;
	cout <<		"0" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
	cout <<		"/turn_pen_off {" << endl;
	cout <<		"	globaldict /_is_pen_on false put" << endl;
	cout <<		"0" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
	cout <<		"/turtle_move_to {" << endl;
	cout <<		"2 dict begin" << endl;
	cout <<		"	/new_y exch def" << endl;
	cout <<		"	/new_x exch def" << endl;
	cout <<		"	_x _y moveto" << endl;
	cout <<		"	globaldict /_x new_x put" << endl;
	cout <<		"	globaldict /_y new_y put" << endl;
	cout <<		"	_is_pen_on {_x _y lineto stroke} {_x _y moveto}  ifelse" << endl;
	cout <<		"0" << endl;
	cout <<		"end" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
	cout <<		"/set_pen_color {" << endl;
	cout <<		"3 dict begin" << endl;
	cout <<		"	/b exch def" << endl;
	cout <<		"	/g exch def" << endl;
	cout <<		"	/r exch def" << endl;
	cout <<		"	r g b setrgbcolor" << endl;
	cout <<		"0" << endl;
	cout <<		"end" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
	cout <<		"/set_pen_line_width {" << endl;
	cout <<		"1 dict begin" << endl;
	cout <<		"	/line_width exch def" << endl;
	cout <<		"	line_width setlinewidth" << endl;
	cout <<		"0" << endl;
	cout <<		"end" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
	cout <<		"/print_number{" << endl;
	cout <<		"2 dict begin" << endl;
	cout <<		"	/str_len exch def" << endl;
	cout <<		"	/number exch def" << endl;
	cout <<		"	number str_len string cvs print" << endl;
	cout <<		"0" << endl;
	cout <<		"end" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
	cout <<		"/print_bool{" << endl;
	cout <<		"1 dict begin" << endl;
	cout <<		"	/boolean exch def" << endl;
	cout <<		"	boolean { boolean 4 string cvs print } { boolean 5 string cvs print } ifelse" << endl;
	cout <<		"0" << endl;
	cout <<		"end" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
	cout <<		"/print_string{" << endl;
	cout <<		"1 dict begin" << endl;
	cout <<		"	/str exch def" << endl;
	cout <<		"	str print" << endl;
	cout <<		"0" << endl;
	cout <<		"end" << endl;
	cout <<		"} def" << endl;
	cout <<		"\n";
}
void printFooter(){
	cout << endl;
	cout << "main" <<endl;
	cout << endl;
	cout << "showpage" << endl;

}