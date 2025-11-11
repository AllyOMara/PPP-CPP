// This program displays the user's inputted name, and their age in months

#include"std_lib_facilities.h"

int main()
{

    cout << "Please enter your name, and your age.\n";
    string userName;
    double userAge;
    cin >> userName >> userAge;
    double userAgeMonths = userAge * 12;
    cout << "Hello, " << userName << "! You are currently " << userAgeMonths << " months old.\n";
    keep_window_open();
    return 0;

}