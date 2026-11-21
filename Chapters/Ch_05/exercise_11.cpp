// Write a program that writes out the first so many values of the Fibonacci
// series. Find the largest Fibonacci number that fits in an int.

#include "std_lib_facilities.h"

int main()
{
    constexpr int MAX_INT = 2147483647;
    vector<int> fibList = {1, 1};
    int firstIndex = 0;
    int secondIndex = 1;
    double nextFibDouble = fibList[firstIndex] + fibList[secondIndex] * 1.0;
    int nextFib;

    while (nextFibDouble < MAX_INT) {
        nextFib = int(nextFibDouble);
        fibList.push_back(nextFib);
        ++firstIndex;
        ++secondIndex;
        nextFibDouble = fibList[firstIndex] + fibList[secondIndex] * 1.0;
    }
    cout << endl << fibList[fibList.size() - 1] << endl;
    keep_window_open();
    return 0;
}