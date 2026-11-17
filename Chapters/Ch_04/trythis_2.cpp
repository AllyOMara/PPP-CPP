// Rewrite your currency converter program from the previous Try this to use a
// switch-statement. Add conversions from yuan and kroner. Which version of the
// program is easier to write, understand, and modify? Why?


#include "std_lib_facilities.h"

int main()
{
    // Get amount and unit
    cout << "Please enter the amount and the unit (yen ('y'), kroner ('k'), pounds ('p'), or yuan ('u')).\n";
    double amount;
    char unit;
    cin >> amount >> unit;

    // Initialise conversion rates
    constexpr double yen_to_usd = 0.0063;
    constexpr double kroner_to_usd = 0.1036;
    constexpr double pounds_to_usd = 1.318;
    constexpr double yuan_to_usd = 0.1500;

    // Conversion into dollars (USD)
    // NOTE: Conversion rates are as of 17/11/2026 (around 11am)
    switch (unit) {
        case 'y':
            cout << amount << " yen in dollars is $" << amount * yen_to_usd;
            break;
        case 'k':
            cout << amount << " kroner in dollars is $" << amount * kroner_to_usd;
            break;
        case 'p':
            cout << amount << " pounds in dollars is $" << amount * pounds_to_usd;
            break;
        case 'u':
            cout << amount << " yuan in dollars is $" << amount * yuan_to_usd;
            break;
        default:
            cout << "Invalid input.";
            break;
    }

    cout << "\n";
    keep_window_open();
    return 0;
}