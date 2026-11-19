// Try to compile those examples (i.e. those examples of errors) and see how the
// compiler responds. (Syntax errors).

#include "std_lib_facilities.h"


int area(int length, int width)
{
    return length * width;
}


int main()
{
    // Examples of potential sources of errors
    int s1 = area(7;
    int s2 = area(7)
    Int s3 = area(7);
    int s4 = area('7);
}