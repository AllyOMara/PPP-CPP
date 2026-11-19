// Get this program to run. Check that our input really does produce that
// output. Try to "break" the program (i.e. get it to give wrong results) by
// giving it other input sets. What is the least amount of input you can give it
// to get it to fail?

#include "std_lib_facilities.h"

int main()
{
    vector<double> temps;

    for (double temp; cin >> temp;) {
        temps.push_back(temp);
    }

    double sum = 0;
    double highTemp = 0;
    double lowTemp = 0;

    for (double x : temps) {
        if (x > highTemp) {
            highTemp = x;
        }
        if (x < lowTemp) {
            lowTemp = x;
            sum += x;
        }
    }

    cout << "High temperature: " << highTemp << "\n";
    cout << "Low temperature: " << lowTemp << "\n";
    cout << "Average temperature: " << sum / temps.size() << "\n";
    keep_window_open();
    return 0;
}