// Provide an assignment operator, =, so that you can change the value of a
// variable after you introduce it using let. Discuss why that can be useful and
// how it can be a source of problems.


#include "std_lib_facilities.h"


class negativeSquareRoot{};
class negativeFactorial{};
class factorialOfNonInt{};
class missingEquals{};


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
const char fact = '!';
const char print = ';';
const char power = 'p';
const char number = '8';
const char squareRoot = 's';


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
	case ',':
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
	case '#':
		return Token(let);
    case '!':
        return Token(fact);
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.unget();
			if (s == "pow") return Token(power);
			if (s == "quit" | s == "exit") return Token(quit);
            if (s == "sqrt") return Token(squareRoot);
            if (s == "let") return Token(let);
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


double getSquareRoot()
{
	Token open = ts.get();  // Gets an open bracket
	if (open.kind != '(') error("'(' expected");
	double expr = expression();
	Token t = ts.get();
	if (t.kind != ')') error("')' expected");
	if (expr < 0) throw negativeSquareRoot{};  // Tried to get square root of a negative number
	return sqrt(expr);
}


double primary();


double getPower()
{
	Token open = ts.get();
	double x = expression();
	Token comma = ts.get();
	double i = expression();
	Token close = ts.get();
	double answer = x;

	if (open.kind != '(') error ("'(' expected");
	if (comma.kind != ',') error("Comma expected when calling pow(x, i)");
	if (int(i) != i) error("Can not evaluate a fractional power");
	if (close.kind != ')') error ("')' expected");
	
	for (int j = 1; j < i; ++j) {
		answer *= x;
	}
	return answer;
}


bool canFactorial = true;


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
            canFactorial = false;
			return -primary();
		case number:
        {   Token t1 = ts.get();
            if (t1.kind == fact && canFactorial && int(t.value) == t.value) return factorial(t.value);
			if (t1.kind == fact && canFactorial && int(t.value) != t.value) throw factorialOfNonInt{};

            if (t1.kind == fact && !canFactorial) throw negativeFactorial{};
            else {ts.unget(t1); return t.value;}  // return the number's value
        }
		case name:
			return get_value(t.name);
		case squareRoot:  // Handles square roots
		{
			return getSquareRoot();
		}
		case power:  // Handles power (i.e. pow(x, i))
			return getPower();
		default:
			error("primary expected");
			return 0;
	}
	return 0;
}


// Handles *, /, and %
double term()
{
	double left = primary();
    canFactorial = true;
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
		case '%':
		{	int firstInt = int(left);
			int secondInt = int(primary());
			return (firstInt % secondInt);
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}


// Handles + and -
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


double updateVarVal(string name) {
    for (int i = 0; i < names.size(); ++i) {
        if (names[i].name == name) {
            Token t2 = ts.get();
            if (t2.kind != '=') throw missingEquals{};
            double d = expression();
            names[i].value = d;  // Update value
            return d;
        }
    }
    error("Failed to rename variable");
    return 0.0;
}


double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) {
        double d = updateVarVal(name);
        return d;
    } else {
        Token t2 = ts.get();
        if (t2.kind != '=') error("= missing in declaration of ", name);
        double d = expression();
        names.push_back(Variable(name, d));
        return d;
    }
    error("Invalid declaration");
    return 0.0;
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
		else ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
	catch (negativeSquareRoot) {
		cerr << "tried to get square root of a negative number\n";
		clean_up_mess();
	}
    catch (negativeFactorial) {
        cerr << ("Can not get factorial of negative number.\n");
		canFactorial = true;
        clean_up_mess();
    }
	catch (factorialOfNonInt) {
		cerr << ("Can not get factorial of a non-integer number.\n");
		clean_up_mess();
	}
    catch (missingEquals) {
        cerr << ("= missing when updating ", name);
        clean_up_mess();
    }
}


void introduction()
{
	cout << "Welcome to the calculator!\n\n~ ~ ~ ~ ~ ~ ~\n\n";
	cout << "The following operations are supported:\n";
	cout << "Basic arithmetic: +, -, *, /, % (modulo), and ! (factorial)\n";
	cout << "Variable assignment: let [var name] = [value / expression] (including updating variable values)\n";
	cout << "Basic functions: sqrt(expression / value) and pow(x, i) (= x^i)\n";
	cout << "Basic constants: k (= 1000), pi, and e\n";
    cout << "Please enter 'quit' or 'exit' to quit.\n\n";
	cout << "~ ~ ~ ~ ~ ~ ~\n\n";
}



void predefineVars()
{
    // List of predefined variables
    names.push_back(Variable("k", 1000));
    names.push_back(Variable("pi", 3.14159));
	names.push_back(Variable("e", 2.71828));
}


int main()
try {
    predefineVars();
	introduction();
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}