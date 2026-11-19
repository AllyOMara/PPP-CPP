// To see what an uncaught exception error looks like, run a small program that
// uses error() without catching any exceptions.

#include "std_lib_facilities.h"


int main()
{
    double myDouble;
    cin >> myDouble;
    if (cin) {
        cout << myDouble;
    } else {
        error("Could not read a double.");
    }
}