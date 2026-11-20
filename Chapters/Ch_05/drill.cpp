// Below are 25 code fragments. Each has zero or more errors. Your task is to
// find and remove all errors in each program. When you have removed those bugs,
// the resulting program will compile, run, and write “Success!” Even if you
// think you have spotted an error, you still need to enter the (original,
// unimproved) program fragment and test it; you may have guessed wrong about
// what the error is, or there may be more errors in a fragment than you
// spotted.

#include "std_lib_facilities.h"

int main()
try {
    
    cout << "Success!\n"; // Cout capitalised when should be cout
    cout << "Success!\n"; // no terminating quotation after \n
    cout << "Success" << "\n"; // should be "\n" not !\n", missing ;
    cout << "success" << "\n"; // no variable 'success', should be "success", '\n' should be "\n"
    int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n"; // vector is of type int, res is of type string (should be int)
    vector<int> v2(10); v2[5] = 7; if (v2[5]==7) cout << "Success!\n"; // v is already declared (changed to v2) v(5) should be v[5] to access index 5, should be == instead of !=
    if (true) cout << "Success!\n"; else cout << "Fail!\n"; // cond (within if statement) should be true
    bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n"; // c should be true, not false
    string s = "ape"; c = "fool"<s; if (!c) cout << "Success!\n"; // type "boo" does not exist (c does not need to be re-declared), if should test !c instead of c
    s = "fool"; if (s=="fool") cout << "Success!\n"; // s is already declared, s should be = "fool"
    s = "fool"; if (s=="fool") cout << "Success!\n"; // s is already declared, s should be = "fool", should be "cout << ...", not "cout < ..."
    s = "fool"; if (s=="fool") cout << "Success!\n"; // s is already declared, s should be = "fool", if statement should check "s == "fool"" not "s+"fool"", should be "cout << ...", not "cout < ..."
    vector<char> v1(5); for (int i=0; i<v1.size(); ++i); cout << "Success!\n"; // v is already declared (changed to v1), 0 should be i in for statement
    vector<char> v3(5); for (int i=0; i<=v3.size(); ++i); cout << "Success!\n"; // v is already declared (changed to v3)
    s = "Success!\n"; for (int i=0; i<8; ++i) cout << s[i]; // s is already declared, 6 should be 8
    if (true) cout << "Success!\n"; else cout << "Fail!\n"; // incorrect format for if statement, does not need "then" after condition
    int x = 2000; int c1 = x; if (c1==2000) cout << "Success!\n"; // c is already declared, c should be an int (changed to int c1)
    s = "Success!\n"; for (int i=0; i<8; ++i) cout << s[i]; // s is already declared, i should be limited to 8 (not 10) in the for loop
    vector<int> v4(5); for (int i=0; i<=v4.size(); ++i) ; cout << "Success!\n"; // v is already declared (changed to v4), vector contents not defined, should be i < v3.size() not i <= v3.size()a
    int i=0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success!\n"; // while loop should increment i, not j
    x = 2; double d = 5/(x- (8.0/9)); if (d==2*x+0.5) cout << "Success!\n"; // x is already declared, divide by zero error, 2 should be 8/9
    s = "Success!\n"; for (int i=0; i<=7; ++i) cout << s[i]; // s is already declared, <char> not needed after string, i should be less than or equal to 7
    i = 0; while (i < 11) ++i; if (j<i) cout << "Success!\n"; // i is already declared, while should have the condition "i < 11" not "j < 10"
    x = 4; d = 5 / (x - (58.0 / 17)); if (d=2*x+0.5) cout << "Success!\n"; // x and d are already declared, d should be = 5 / (x - (58.0 / 17))
    cout << "Success!\n"; // cin should be cout

    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}