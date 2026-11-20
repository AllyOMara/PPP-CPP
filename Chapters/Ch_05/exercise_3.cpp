// Absolute zero is the lowest temperature than can be reached; it is -273.15°C,
// or 0K. The above program (from exercise_2.cpp), even when corrected, will
// produce erroneous results when given a temperature below this. Place a check
// in the main program that will produce an error if a temperature is given
// below -273.15°C.

#include "std_lib_facilities.h"


class badTemp {};

double ctok(double c) // converts Celsius to Kelvin
{
    double k = c + 273.15;
    return k;
}


int main()
try {

    double c;
    cin >> c;
    if (c < -273.15) throw badTemp{};
    double k = ctok(c);
    cout << k << "\n" ;
    keep_window_open();
    return 0;
}
catch (badTemp) {
    cout << "Bad input value for temperature.\n";
    keep_window_open();
}