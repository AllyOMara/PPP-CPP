// Write a program that reads and stores a series of integers and then computes
// the sum of the first N integers.

#include "std_lib_facilities.h"

class outOfRange{};


int main()
try {
    int numValues;
    vector<int> numberList;
    int sum = 0;

    cout << "Number of values to sum: ";
    cin >> numValues;

    cout << "Please enter some integers (press '|' to stop): ";
    for (int num; cin >> num;) {
        numberList.push_back(num);
    }
    if (numValues > numberList.size()) {
        throw outOfRange{};
    } else {
        for (int i = 0; i < numValues; ++i) {
            sum += numberList[i];
        }
    }

    cout << "The sum is: " << sum << "." << endl;
    keep_window_open();
    return 0;
}
catch (outOfRange) {
    cerr << "Number of values to sum exceeds the number of inputted values.\n";
    keep_window_open();
}
catch (...) {
    cerr << "Exception: something went wrong\n";
    keep_window_open();
}