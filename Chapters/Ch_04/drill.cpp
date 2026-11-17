// Write a program that takes user input (terminating if "|" is entered) and
// does various things to it (explained below).

#include "std_lib_facilities.h"

// Step 9
double convert_to_meters(int value, string unit)
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

    double new_num;
    double smallest_num = INFINITY;
    double largest_num = -INFINITY;
    string num_unit; // Step 7
    double sum_of_values = 0;

    while (cin >> new_num >> num_unit) {
        if (num_unit == "cm" || num_unit == "m" || num_unit == "in" || num_unit == "ft") {
            cout << "Number inputted: " << new_num << "\n";
            cout << "Unit inputted: " << num_unit << "\n";
            if (new_num < smallest_num) {
                cout << "The smallest so far\n";
                smallest_num = new_num;
            }
            if (new_num > largest_num) {
                cout << "The largest so far\n";
                largest_num = new_num;
            }
            // Step 9
            double new_num_in_m = convert_to_meters(new_num, num_unit);
            sum_of_values += new_num_in_m;
            cout << "The sum of all values so far is: " << sum_of_values << ".\n";

        } else { // Step 8
            cout << "Unit is not recognised. Please enter a value with an accepted unit.";
        }

    }
}