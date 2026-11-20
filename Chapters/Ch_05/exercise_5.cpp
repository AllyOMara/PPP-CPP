// Add to the program (from exercise_2.cpp and exercise_3.cpp) so that it can
// also convert from Kelvin to Celsius.

#include "std_lib_facilities.h"


class badTemp {};

double ctok(double c) // converts Celsius to Kelvin
{
    double k = c + 273.15;
    return k;
}


double ktoc(double k) // converts Kelvin to Celsius
{
    double c = k - 273.15;
    return c;
}


int main()
try {
    cout << "Please input the value of the temperature you wish to convert, followed by whether you want to convert to (k)elvin or to (c)elsius.\n";
    double userValue;
    char userUnit;
    cin >> userValue >> userUnit;
    switch (userUnit) {
        case 'k':
            if (userValue < -273.15 && userUnit == 'k'){
                throw badTemp{};
            } else {
                cout << userValue << " in Kelvin is " << ctok(userValue);
            }
        case 'c':
            if (userValue < 0 && userUnit == 'c'){
                throw badTemp{};
            } else {
                cout << userValue << " in Celsius is " << ktoc(userValue);
            }
    }
    keep_window_open();
    return 0;
}
catch (badTemp) {
    cout << "Bad input value for temperature.\n";
    keep_window_open();
}