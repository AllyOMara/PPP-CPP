// Modify the program from exercise 8 (exercise_8.cpp) to write out an error if
// the result cannot be represented as an int.

#include "std_lib_facilities.h"

class outOfRange{};
class doesNotFit{};

int main()

try {

    int MIN_INT = -2147483647 - 1;
    int MAX_INT = 2147483647;

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
            double newSum = sum + numberList[i] * 1.0;
            if (newSum > MAX_INT || newSum < MIN_INT) {throw doesNotFit{};}
            sum = newSum;
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
catch (doesNotFit) {
    cerr << "Result cannot be represented as an int.\n";
    keep_window_open();
}
catch (...) {
    cerr << "Exception: something went wrong.\n";
    keep_window_open();
}