// Write a program that can calculate x for a quadratic equation. Create a
// function that prints out the roots of a quadratic equation, given a, b, c.
// When the program detects an equation with no real roots, have it print out a
// message. How do you know that your results are plausible? Can you check that
// they are correct?
// NOTE: a, b, c are the values when the quadratic expression is in the form:
// a * x^2 + b * x + c

#include "std_lib_facilities.h"

class notReal {};

void checkReal(double a, double b, double c)
{
    if ((b*b) - (4*a*c) < 0) {
        throw notReal{};
    }
}


vector<double> getRoots(double a, double b, double c)
{
    vector<double> roots;
    double root_1 = (-b + sqrt((b*b) - (4*a*c))) / (2 * a);
    double root_2 = (-b - sqrt((b*b) - (4*a*c))) / (2 * a);
    if (root_1 == root_2) {
        roots.push_back(root_1);
    } else {
        roots.push_back(root_1);
        roots.push_back(root_2);
    }
}


int main()
try {
    cout << "Please enter the values for a, b, and c (in order) for your quadratic equation in general form.\n";
    double a;
    double b;
    double c;
    cin >> a >> b >> c;
    checkReal(a, b, c);
    vector<double> answers = getRoots(a, b, c);
    if (size(answers) == 1) {
        cout << "The root is: " << answers[0] << ".";
    } else {
        cout << "The roots are: " << answers[0] << " and " << answers[1] << ".";
    }
    keep_window_open();
    return 0;
}
catch (notReal) {
    cout << "There are no solutions for the inputted values.\n";
    keep_window_open();
}