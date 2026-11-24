
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/

// Now supports '(', ')', '{', and '}'. (exercise 2)
// Now supports the factorial operator ('!') (exercise 3)

#include "std_lib_facilities.h"


//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) {}
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) {}
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
    case '{': case '}': case '!':
        return Token{ch};        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token{'8', val};  // let '8' represent "a number"
    }
    default:
        error("Bad token");
        return Token('0');
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

int factorial(int x)
{
    if (x == 0 || x == 1) return 1;
    if (x < 0) error("Factoral of a negative number");
    int ans = 1;
    int i = 1;
    while (i <= x) {
        ans *= i;
        ++i;
    }
    return ans;
}


// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
                return d;
        }
        case '{':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') error("'}' expected");
                return d;
        }
        case '8':            // we use '8' to represent a number
        {
            Token t1 = ts.get();
            if (t1.kind == '!') {return factorial(t.value);}
            else {ts.putback(t1); return t.value;}  // return the number's value
        }
        default:
        {
            error("primary expected");
            return 0.0;
        }
    }
}


// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }

        case '=':
            ts.putback(t);
            return left;
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Welcome to our simple calculator.\n";
    cout << "Please enter expressions using floating-point numbers.\n";
    cout << "~ ~ ~ ~ ~ ~ ~\n";
    cout << "Please enter a character to continue. For a quick tutorial, please enter 't'.\n";
    char tutorial;
    cin >> tutorial;
    if (tutorial == 't') {
        cout << "\n~ ~ ~ ~ ~ ~ ~\n\n";
        cout << "This program supports +, -, *, /, ! (factorial), and brackets (both '(' and '{').\n";
        cout << "To get your answer printed, please conclude your statement with '='.\n";
        cout << "To quit, please enter 'x'.\n\n";
        cout << "Example input:\n";
        cout << "x. 1+2*3= \nx. 4+5+6*7= \nx. 9/3= \nx. 100*(3/5)= \nx. 55*{3!}/(2+6/4)=";
        cout << "\n\n~ ~ ~ ~ ~ ~ ~\n\n";
    }
    
    cout << "The calculator has started. Please enter your input below.\n";
    double val = 0.0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'x') break; // 'q' for quit (changed, step 2)
        if (t.kind == '=')        // ';' for "print now" (changed, step 3)
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
    keep_window_open("Thank you for using the calculator.\n");
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

//------------------------------------------------------------------------------