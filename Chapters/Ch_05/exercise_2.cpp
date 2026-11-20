// The following program takes in a temperature value in Celsius and converts it
// to Kelvin. This code has many errors in it. Find the errors, list them, and
// correct the code.

// ~~~~~~~

// List:
// x. Did not include "std_lib_facilities.h"
// x. ctok: - k should be a double (to return a double), not an int
//          - did not add ";" after return statement
//          - should return "k" not "int"
// x. main: - "c", when declared, doesn't need to be assigned a value since we assign it the value of the user's input
//          - cin should write to "c" not "d"
//          - when calling ctok, "c" should not be written as ""c"" but instead as just "c"
//          - "cout" should not have a capital "c" at the beginning
//          - should be "\n", not '/n'
//          - should add "keep_window_open();" so we can see the result
//          - main() should return an int, so we should add "return 0;" to the end

#include "std_lib_facilities.h"


double ctok(double c) // converts Celsius to Kelvin
{
    double k = c + 273.15;
    return k;
}


int main()
{
    double c; // declare input variable
    cin >> c; // retrieve temperature to input variable
    double k = ctok(c); // convert temperature
    cout << k << "\n" ; // print out temperature
    keep_window_open();
    return 0;
}