// Write a program in C++ that converts miles to kilometers. Your program should
// have a reasonable prompt for the user to enter a number of miles.
// Hint: There are 1.609 kilometers to the mile.

// NOTE: I have changed this exercise (as a small challenge) to ask the user
// which way they want to convert (kilomoters to miles or vice versa).

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter 'M' if you wish to convert to miles and 'K' if you wish to convert to kilometers.";
    string output_unit;
    cin >> output_unit;
    double distance;
    double updated_distance;
    if (output_unit == "M") {
        cout << "Value in kilometers: ";
        cin >> distance;
        updated_distance = distance / 1.609;
        cout << distance << " kilometers is equal to " << updated_distance << " miles.";
    }
    else if (output_unit == "K") {
        cout << "Value in miles: ";
        cin >> distance;
        updated_distance = distance * 1.609;
        cout << distance << " miles is equal to " << updated_distance << " kilometers.";
    }
    keep_window_open();
    return 0;
}