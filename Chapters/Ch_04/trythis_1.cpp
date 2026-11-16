// Make a program that converns yen ('y'), kroner ('k'), and pounds ('p') into
// dollars.

#include "std_lib_facilities.h"

int main()
{
    // Get amount and unit
    cout << "Please enter the amount and the unit (yen ('y'), kroner ('k'), or pounds ('p')).\n";
    double amount;
    string unit;
    cin >> amount >> unit;

    // Conversion into dollars (USD)
    // NOTE: Conversion rates are as of 17/11/2026
    if (unit == "y") {
        cout << amount << " yen in dollars is $" << amount * 0.0063;
    } else if (unit == "k") {
        cout << amount << " kroner in dollars is $" << amount * 0.1036;
    } else if (unit == "p") {
        cout << amount << " pounds in dollars is $" << amount * 1.318;
    } else {
        cout << "Invalid input.";
    }

    cout << "\n";
    keep_window_open();
    return 0;
}