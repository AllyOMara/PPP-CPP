
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/


#include "std_lib_facilities.h"


class negativeSquareRoot{};


class Token {
public:
    char kind;  // What kind of token (e.g. '+', '*', etc.)
	double value;  // Token value for numbers
	string name;  // For variables
	Token(char ch) :kind(ch), value(0) {}
	Token(char ch, double val) :kind(ch), value(val) {}
    Token(char ch, string n) :kind{ch}, name{n} {}
};


class Token_stream {
private:
    bool full = false;  // Indicates if there is a Token in the buffer
	Token buffer;  // Holds a Token (which was put back using unget())
public:
	Token_stream() :full(0), buffer(0) {}  // Make the token stream

    Token get();  // Gets the next token
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};


// 'Kind' values for Tokens
const char let = 'L';
const char name = 'a';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char squareRoot = 's';


Token Token_stream::get()
{
	if (full) { full = false; return buffer; }  // Returns Token in buffer (if there exists one)
	char ch;
	cin >> ch;  // Waits for the next input
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);  // Let each character represent itself
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();  // Put digit back into the input stream
	double val;
	cin >> val;  // read a floating-point number
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
			if (s == "let") return Token(let);
			if (s == "quit") return Token(quit);
            if (s == "sqrt") return Token(squareRoot);
			return Token(name, s);
		}
		error("Bad token");
        return Token(quit);
	}
    return Token(quit);
}


void Token_stream::ignore(char c)
{
    // "Cleans up" the input, removing all input until a terminating ";" (for
    // print) is reached

	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}


class Variable {
    // Represents a user-defined variable
public:
    string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};


vector<Variable> names;


double get_value(string s)
{
    // Retrieves the value of the inputted user-defined variable
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
    return 0;
}


void set_value(string s, double d)
{
    // Stores the value of a user-defined variable
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}


bool is_declared(string s)
{
    // Checks if a user-defined varible has been declared
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}


Token_stream ts;


double expression();


double primary()
{
	Token t = ts.get();
	switch (t.kind) {
		case '(':  // handle '(' expression ')'
		{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		break;
		}
		case '-':
			return -primary();
		case number:
			return t.value;
		case name:
			return get_value(t.name);
		case squareRoot:  // Handles square roots
		{
			Token open = ts.get();  // Gets an open bracket
			if (open.kind != '(') error("'(' expected");
			double expr = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			if (expr < 0) throw negativeSquareRoot{};  // Tried to get square root of a negative number
			return sqrt(expr);
		}
		default:
			error("primary expected");
			return 0;
	}
	return 0;
}


double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}


double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}


double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}


double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}


void clean_up_mess()
{
	ts.ignore(print);
}


const string prompt = "> ";
const string result = "= ";


void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		if (t.kind == squareRoot) ts.unget(Token{squareRoot});
		else ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}


void predefineVars()
{
    // List of predefined variables
    names.push_back(Variable("k", 1000));
    names.push_back(Variable("pi", 3.14159));
}


int main()
try {
    predefineVars();
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (negativeSquareRoot) {
	cerr << "tried to get square root of a negative number";
	clean_up_mess();
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}