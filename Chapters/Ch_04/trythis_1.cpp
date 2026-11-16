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

    // Initialise conversion rates
    constexpr double yen_to_usd = 0.0063;
    constexpr double kroner_to_usd = 0.1036;
    constexpr double pounds_to_usd = 1.318;

    // Conversion into dollars (USD)
    // NOTE: Conversion rates are as of 17/11/2026
    if (unit == "y") {
        cout << amount << " yen in dollars is $" << amount * yen_to_usd;
    } else if (unit == "k") {
        cout << amount << " kroner in dollars is $" << amount * kroner_to_usd;
    } else if (unit == "p") {
        cout << amount << " pounds in dollars is $" << amount * pounds_to_usd;
    } else {
        cout << "Invalid input.";
    }

    cout << "\n";
    keep_window_open();
    return 0;
}