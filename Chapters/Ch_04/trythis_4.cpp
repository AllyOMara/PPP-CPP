// Rewrite the character value example from the previous Try this to use a
// for-statement. Then modify your program to also write out a table of the
// integer values for uppercase letters and digits.

#include "std_lib_facilities.h"

int main()
{
    // Lower case letters
    for (int i = 0; i < 26; ++i) {
        cout << char('a' + i) << "\t" << int('a') + i << "\n";
    }
    cout << "\n";

    // Upper case letters
    for (int i = 0; i < 26; ++i) {
        cout << char ('A' + i) << "\t" << int('A') + i << "\n";
    }
    cout << "\n";

    // Digits
    for (int i = 0; i < 10; ++i) {
        cout << i << "\n";
    }
    cout << "\n";

    keep_window_open();
    return 0;
}