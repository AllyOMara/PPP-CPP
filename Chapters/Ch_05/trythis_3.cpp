// Test this program (see below) with a variety of values. Print out the values
// of area1, area2, area3, and ratio. Insert more tests until all errors are
// caught. How do you know that you caught all errors? This is not a trick
// question; in this particular example you can give a valid argument for having
// caught all errors.

#include "std_lib_facilities.h"

int area(int length, int width)
{
    if (length <= 0 || width <= 0) return -1;
    return length * width;
}


int framed_area(int x, int y)
{
    constexpr int frame_width = 2;
    if (x - frame_width <=0 || y - frame_width <=0) error("non-positive area() argument called by framed_area()");
    return area(x - frame_width, y - frame_width);
}


int f(int x, int y, int z)
{
    int area1 = area(x,y);
    if (area1<=0) error("non-positive area");
    int area2 = framed_area(1,z); // Error: the first argument is 1. 1 - frame_width <=0, thus always returning an error
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;
    cout << "area1: " << area1 << "\n";
    cout << "area2: " << area2 << "\n";
    cout << "area3: " << area3 << "\n";
    cout << "ratio: " << ratio << "\n";
    return 0;
}


int main()
{
    int x;
    int y;
    int z;
    cin >> x >> y >> z;
    f(x, y, z);
    keep_window_open();
    return 0;
}