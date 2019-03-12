# The *Turtle* Programming Language Compiler
**Turtle graphics**[1] are frequently used for drawing **logos** and **recursive fractals** in vector format. A useful existing language for such a task is the **PostScript** scripting language[2]. However, the PostScript language is implemented as a **stack machine** and is **not very intuitive** to use. This repository holds a **compiler** built as part of a student project for a more **high-level C like programming language** called *Turtle*. It compiles the high-level code into the lower-level PostScript language.The lexical analysis is done using the open source tool **Flex**[3]. The parser for the syntactic analys is implemented in the open source tool **Bison**[4] that works well together with Flex. **Semantic analysis** and **code generation** are done with a tree data structure implemented in the **C++**.

## Language Description
As already stated, the "Turtle" language is **domain specific**, focused on turtle graphics. To this end, the programming language implements the basic parameters and functions that define the turtle, such as **turtle position**, **turtle direction (angle)**, **state of the pen** (on or off), **pen color**, **pen line width** and **turtle forward** (a function that tells the turtle to move forward x steps drawing a line along the path if the pen is turned on). In order to be able to draw various shapes, the language implements **control flow** (branches and loops), **functions** and **procedures**, as well as **recursion**. Recursion is needed to draw recursive fractals, which is one of the more interesting applications of turtle graphics.

## Language Syntax
The **C-like syntax** has only four data types: `integer (int)`, `decimal (real)`, `boolean (bool)` and `string (str)`. Another difference is the way variables and functions are declared. **Declarations** use the following **syntax**: `identifier : type = initialization_statement`. **Variable names** are the same as in C, except that **identifiers** cannot start with an underscore ("_"), since this symbol is used for **system variables** (turtle x and y position coordinates, turtle angle etc.). If a function **does not return a value**, the type specification is **omitted** (instead of marking it as void). If a function **returns a value**, the return value is stated after the compound statement block using the keyword **returns**. Examples of source code written in the *Turtle* language are given in the sections below.

Some additional functions were **manually implemented** in PostScript and their names are **reserved** (their identifier names were manually added to the **symbol table** during the **semantic analysis** phase). This way we **prevent** users to define functions with the same name, which will lead to **conflicts**. The auxiliary functions that we have defined in PostScript are the following:
- ***turtle_forward(length: real)*** - tells the turtle to move forward for a distance equal to
length
2
- ***turtle_left(amount: real)*** - tells the turtle to rotate its angle for amount degrees to the
left (counter clockwise)
- ***turtle_right(amount: real)*** - tells the turtle to rotate its angle for amount degrees to
the right (clockwise)
- ***turtle_move_to(x: real, y: real)*** - tells the turtle to move to the point on the canvas
with coordinates x and y
- ***turn_pen_on()*** - turns the pen on (turtle will draw a line upon movement)
- ***turn_pen_off()*** - turns the pen off (turtle will not draw a line upon movement)
- ***set_pen_color(r: real, g: real, b: real)*** - sets the rgb values for the color (values are
between 0 and 1)
- ***set_pen_line_width(width: real)*** - sets the line width to be equal to the argument
width
- ***print_number(number: real, length: int)*** - prints the number given as an argument
with a length number of digits
- ***print_bool(boolean: bool)*** - prints the boolean value given as an argument
- ***print_string(string: str)*** - prints the string given as an argument

## Example Programs
This section gives a couple of examples highlighting different features of the language (loops, conditional statements, functions, procedures, recursion, error printing, turtle functionality etc.). The examples show source code, as well as the corresponding output.

### 1. Koch Curve
#### Source code
```C
fn koch_curve(level: int, length: int) = {
    if (level == 0){
        turtle_forward(length);
    }
    else {
        koch_curve(level-1, length);
        turtle_left(90);
        koch_curve(level-1, length);
        turtle_right(90);
        koch_curve(level-1, length);
        turtle_right(90);
        koch_curve(level-1, length);
        turtle_left(90);
        koch_curve(level-1, length);
    }
}

fn main() = {
	turn_pen_off();
	turtle_move_to(150, 300);
	turn_pen_on();
	koch_curve(4, 5);
}
```
#### Output
![koch curve](https://github.com/Pepton21/turtle-graphics-compiler/master/images/koch_curve.png)

### 2. Koch Snowflake
#### Source code
```C
fn draw_koch(level: int, len: int) = {
    if (level == 0){
        turtle_forward(len);
    }
    else {
        draw_koch(level-1, len/3);
        turtle_right(60);
        draw_koch(level-1, len/3);
        turtle_left(60);
        turtle_left(60);
        draw_koch(level-1, len/3);
        turtle_right(60);
        draw_koch(level-1, len/3);
    }
}

fn koch_snowflake(level: int, len: int) = {
    if (level > 0) {
        draw_koch(level-1, len);
        turtle_left(60);
        turtle_left(60);
        draw_koch(level-1, len);
        turtle_left(60);
        turtle_left(60);
        draw_koch(level-1, len);
    }
}

fn main() = {
	koch_snowflake(5, 100);
}

/*
Level 1: F--F--F
Level 2: F+F--F+F--F+F--F+F--F+F--F+F
Level 3: F+F--F+F+F+F--F+F--F+F--F+F+F+F--F+F--F+F--F+F+F+F--F+F--F+F--F+F+F+F--F+F--F+F--F+F+F+F--F+F--F+F--F+F+F+F--F+F
*/
```
#### Output
![koch snowflake](https://github.com/Pepton21/turtle-graphics-compiler/master/images/koch_snowflake.png)

### 3. Cantor Set
#### Source code
```C
fn cantor_set(level: int, length: int) = {
    if (level == 0){
        turtle_forward(length);
    }
    else {
        cantor_set(level-1, length/3);
		turn_pen_off();
        turtle_forward(length/3);
		turn_pen_on();
        cantor_set(level-1, length/3);
    }
}

fn main() = {
    cantor_set(4, 300);
}
```
#### Output
![cantor set](https://github.com/Pepton21/turtle-graphics-compiler/master/images/cantor_set.png)

### 4. For loop
#### Source code
```C
fn main() = {
    a: int = 60;
    b: int = 100;
    for (i: int = 0; i<6; i++) {
        turtle_left(a);
        turtle_forward(b);
    }	
}
```
#### Output
![pentagon](https://github.com/Pepton21/turtle-graphics-compiler/master/images/pentagon.png)

### 5. While loop
#### Source code
```C
fn main() = {
    a: int = 60;
    b: int = 100;
    i: int;
    while (i < 100) {
        turtle_forward(b);
        turtle_left(a);
        b --;
        i+=1;
    }	
}
```
#### Output
![pyramid](https://github.com/Pepton21/turtle-graphics-compiler/master/images/pyramid.png)

### 6. Recursive factorial
#### Source code
```C
fn factorial(n: int):int = {
    p: int;
    if (n > 0){
        p = n * factorial(n-1);
    } else {
        p = 1;
    }
} returns p;

fn main() = {
    a: int = 6;
    b: int = factorial(a);
    print_number(b,3);	
}
```
#### Output
```
720
```

### 7. Operation precedence
#### Source code
```C
fn main() = {
    a: int = 5 + 2*3;
    b: int = 3*(5+5);
    print_string("Result from 5 + 2*3: ");
    print_number(a,2);
    print_string("\n");
    print_string("Result from 3*(5 + 5): ");
    print_number(b,2);
}
```
#### Output
```
Result from 5 + 2*3: 11
Result from 3*(5 + 5): 30
```

### 8. Error printing
#### Source code
```C
fn main(arg: int): int = {
    a: int = 15.01;

    b: real = 3.45;
    c: str = "string";
    c: str = "duplicate";
    e: int = "integer";
    f: bool = True;
    [
    if ( a > 0 && a <= 5 ){
        print_number(a);
    } else if (a > 5 && a <= 10) {
        print_number(b,4);
    } else if (a > 10 && a <= 15) {
        print_strin(c);
    } else {
        print_string(d);
    }

    if ("aba" < "baba") {
        print_string(2);
    }
    b = 2 + d;
    if ( 5 < "aba" ){
        print_string("Semantic analysis error!");
    }

    if (f < 2){
        print_string("Semantic analysis error!");
    }
    c++;
} returns c;
```
#### Output
```
Invalid syntax on line 9: ’[’
error: Multiple declarations with same identifier "c"
error on line 7: can’t cast "string" into "int"
error on line 11: function "print_number" with 2 parameters is called with 1 arguments
error on line 15: Identifier "print_strin" was used before it was declared
error on line 17: Identifier "d" was used before it was declared
error on line 17: In call to function "print_string" argument #1 has wrong type (got "notDeclared" instead of "string")
error on line 21: In call to function "print_string" argument #1 has wrong type (got "int" instead of "string")
error on line 24: can’t compare "int" and "string"
error on line 28: can’t compare "bool" and "int"
error on line 28: invalid operator for type "boolean"
error on line 31: can’t use operator "++" for "string"
error on line 32: In function "main" returned type does not match (expected "int", but got "string")
warning: Identifier "arg" was declared, but never used
warning: Identifier "e" was declared, but never used
error on line 32: main function needs to be void
```

### 9. Turtle functions and printing
#### Source code
```C
fn main() = {
    turn_pen_on();
    set_pen_color(0.2, 0.5, 0.7);
    set_pen_line_width(4);
    turtle_move_to(500, 600);
    turn_pen_off();
    turtle_move_to(500, 600);
    turn_pen_on();
    turtle_move_to(200, 300);

    a: int = 1039;
    b: real = 13.6;
    c: bool = True;
    d: bool = False;
    e: str = "example";

    print_number(a,4);
    print_string("\n");
    print_number(b,4);
    print_string("\n");
    print_bool(c);
    print_string("\n");
    print_bool(d);
    print_string("\n");
    print_string(e);
    print_string("\n");
}
```
#### Output
![turtle](https://github.com/Pepton21/turtle-graphics-compiler/master/images/turtle.png)
```
1039
13.6
true
false
example
```

## References
1. Turtle Graphics, https://en.wikipedia.org/wiki/Turtle_graphics.
2. Adobe PostScript, http://www.adobe.com/products/postscript.html.
3. Flex - a lexer building tool, http://gnuwin32.sourceforge.net/packages/flex.htm
4. Bison - a parser building tool, https://www.gnu.org/software/bison/
5. The g++ compiler, http://www.cprogramming.com/g++.html
6. Ghostscript - an interpreter for the PostScript language and for PDF, https://www.ghostscript.com/
