// Write a program that takes user input (terminating if "|" is entered) and
// does various things to it (explained below).

#include "std_lib_facilities.h"

// Step 9
double convertToMeters(int value, string unit)
{
    if (unit == "cm") {
        return value / 100;
    } else if (unit == "m") {
        return value;
    } else if (unit == "in") {
        return value * 0.0254;
    } else if (unit == "ft") {
        return value * 0.3048; 
    }
    return 0.0;
}


int main()
{

/*
    // Step 1
    cout << "Please enter your two numbers below.\n";
    double num_1; // Step 4 (changed to doubles instead of ints)
    double num_2;

    while (cin >> num_1 >> num_2) {
        cout << "\n";

        // Step 2
        if (num_1 < num_2) {
            cout << "The smaller value is: " << num_1 << "\n";
            cout << "The larger value is: " << num_2 << "\n";
            if (num_2 - num_1 <= 1.0/100) {
                cout << "The numbers are almost equal." << "\n"; // Step 5
            }
        } else if (num_1 > num_2) {
            cout << "The smaller value is: " << num_2 << "\n";
            cout << "The larger value is: " << num_1 << "\n";
            if (num_1 - num_2 <= 1.0/100) {
                cout << "The numbers are almost equal." << "\n"; // Step 5
            }
        }

        // Step 3
        else if (num_1 == num_2) {
            cout << "The numbers are equal" << "\n";
        }


    }
*/

    // Step 6
    cout << "Please enter the value followed by the unit. Permitted units include:\n";
    cout << "x. Centimeters (cm)\n";
    cout << "x. Meters      (m)\n";
    cout << "x. Inches      (in)\n";
    cout << "x. Feet        (ft)\n\n";

    int numInputted = 0;
    double newNum;
    double smallestNum = INFINITY;
    double largestNum = -INFINITY;
    string numUnit; // Step 7
    double sumOfNums = 0;
    vector<double> allNums; // Step 10

    while (cin >> newNum >> numUnit) {
        if (numUnit == "cm" || numUnit == "m" || numUnit == "in" || numUnit == "ft") {
            cout << "Number inputted: " << newNum << "\n";
            cout << "Unit inputted: " << numUnit << "\n";
            if (newNum < smallestNum) {
                cout << "The smallest so far\n";
                smallestNum = newNum;
            }
            if (newNum > largestNum) {
                cout << "The largest so far\n";
                largestNum = newNum;
            }
            // Step 9
            double newNumInMeters = convertToMeters(newNum, numUnit);
            sumOfNums += newNumInMeters;
            cout << "The sum of all values so far is: " << sumOfNums << ".\n";
            ++numInputted;
            cout << "The number of inputted values is: " << numInputted << ".\n";

        } else { // Step 8
            cout << "Unit is not recognised. Please enter a value with an accepted unit.";
        }
    
    // Step 9
    cout << "The smallest value is: " << smallestNum << " meters.\n";
    cout << "The largest value is: " << largestNum << " meters.\n";
    cout << "The number of values inputted is: " << numInputted << ".\n";
    cout << "The total sum of all inputted values (so far) is: " << sumOfNums << " meters.\n";
    }
}