// Try to compile those examples (i.e. those examples of errors) and see how the
// compiler responds. Try thinking of a few more errors yourself, and try those.
// (Type errors).

#include "std_lib_facilities.h"


int area(int length, int width)
{
    return length * width;
}


int main()
{
    // Given examples
    int x0 = arena(7);
    int x1 = area(7);
    int x2 = area("seven", 2);

    // Own examples
    int x3 = area(7, "2");
    int x4 = areea(7, 2);
    int x5 = area(7, "too");
}