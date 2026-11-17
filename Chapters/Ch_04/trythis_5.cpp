// Implement square() without using the multiplication operator; that is, do
// the x*x by repeated addition (start a variable result at 0 and add x to it x
// times). Then run some version of "the first program" using that square().

#include "std_lib_facilities.h"

int square_using_addition(int x)
{
    int result = 0;
    for (int i = 0; i < x; ++i) {
        result += x;
    }
    return result;
}


int main()
{
    for (int i = 0; i < 100; ++i) {
        cout << i << "\t" << square_using_addition(i) << "\n";
    }
    keep_window_open();
    return 0;
}