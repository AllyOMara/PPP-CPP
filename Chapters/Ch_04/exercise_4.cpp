// Write a program to play a numbers guessing game. The user thinks of a number
// between 1 and 100 and your program asks questions to figure our what the
// number is (e.g. "is the number you are thinking of less than 50?"). Your
// program should be able to identify the number after asking no more than seven
// questions. Hint: Use the < and <= operators and the if-else construct.

#include "std_lib_facilities.h"

int main()
{
    cout << "Welcome to the number guessing game.\n";
    cout << "Please think of a number, and I will try to guess it within seven guesses.\n";
    cout << "For each question, please answer (y)es or (n)o.\n\n";
    cout << "Are you ready?\n";
    char userAns; // A placeholder is here as I am unsure (at this point) how to 
    cin >> userAns; //just have user input do nothing other than progress the program.
    if (userAns == 'n') {
        cout << "See ya! Come back soon!\n";
        keep_window_open();
        return 0;
    } else if (userAns != 'y') {
        cout << "\nYou broke the rules!\n\nSelf destruct sequence engaged.\n\n";
        keep_window_open();
        return 0;
    }
    int upperBound = 100;
    int lowerBound = 0;
    int middle;
    double target;
    while (upperBound != lowerBound) {
        target = (upperBound + lowerBound) / 2.0;
        middle = ceil(target);
        cout << "Is your number less than " << middle << "?\n";
        cin >> userAns;
        if (userAns == 'y') {
            upperBound = middle - 1;
        } else if (userAns == 'n') {
            lowerBound = middle;
        }
    }
    cout << "\nAha! Is your number " << ceil((upperBound + lowerBound) / 2) << "?\n";
    cin >> userAns;
    if (userAns == 'y') {
        cout << "I win!\n";
    } else if (userAns == 'n') {
        cout << "\nThat can't be right... Please let the author know!\n\n...well, what are you waiting for? GO!!\nNOW!!!!!\n\n";
    }
    
    keep_window_open();
    return 0;

}