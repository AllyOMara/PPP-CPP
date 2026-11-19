// Find a pair of values so that the pre-condition of this version of area
// holds, but the post-condition doesn't.

#include "std_lib_facilities.h"

int area(int length, int width)
{
    if (length <= 0 || width <= 0) {error("area() pre-condition");}
    int a = length * width;
    if (a <= 0) {error ("area() post-condition");}
    return a;
}


int main()
{
    int length;
    int width;
    cin >> length >> width;
    cout << area(length, width);
    keep_window_open();
    return 0;
}

// Example: 999999999999999999999999999999 and 99999999999999999