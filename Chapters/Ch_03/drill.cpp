// Write a program that produces a simple form letter based on user input.

#include "std_lib_facilities.h"

int main()
{
    // User details (input)
    cout << "What is your name? ";
    string your_name;
    cin >> your_name;
    cout << "Please enter the name of the person you want to write to. ";
    string first_name;
    cin >> first_name;
    cout << "What is their age? ";
    int age;
    cin >> age;
    if (age <= 0)
        simple_error("you're kidding!");
    if (age >= 110)
        simple_error("you're kidding!");
    cout << "Please enter the name of another friend. ";
    string friend_name;
    cin >> friend_name;
    cout << "Is this friend (m)ale or (f)emale? ";
    string friend_sex;
    cin >> friend_sex;

    // Letter
    cout << "Dear " << first_name <<",\n";
    cout << "How are you? I am fine. I miss you.\n";
    cout << "Today I played some video games. We should play together sometime!\n";
    if (friend_sex == "m")
        cout << "If you see " << friend_name << ", please ask him to call me.\n";
    if (friend_sex == "f")
        cout << "If you see " << friend_name << ", please ask her to call me.\n";
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";
    if (age < 12)
        cout << "Next year you will be " << age + 1 << ".\n";
    if (age == 17)
        cout << "Next year you will be able to vote.\n";
    if (age > 70)
        cout << "I hope you are enjoying retirement.\n";
    cout << "Yours sincerely, \n\n";
    cout << your_name << "\n";
    keep_window_open();
    return 0;
}