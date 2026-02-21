// Chapter 5 Calculator (PPP3-style) — no std_lib_facilities.h needed
// Features: + - * /, parentheses, unary +/-, ';' to print, 'q' to quit

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;

//Token kinds
constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char prompt = '>';
constexpr char result = '=';

const char name = 'a';
const char let = 'L';
const string declarkey = "let";

struct Token {
    char kind;      // what kind of token
    double value;   // for numbers
    string name;

    Token() :kind{0}{}
    Token(char ch) :kind{ch} { }

    Token(char ch, double val) : kind{ch}, value{val} {}
    Token(char ch, string n) : kind{ch}, name{n} {}
};

// handing variables
class Variable{
    public:
        string name;
        double value;
};

vector<Variable> var_table;

double get_value(string s)
    // return the value of the variable named s
{
    for(const Variable& v: var_table)
        if (v.name == s)
            return v.value;
    throw runtime_error("trying to read undefined variable " + s);
}

void set_value(string s, double d){
    // set the variable named s to d

    for(Variable& v : var_table)
        if (v.name == s){
            v.value = d;
            return;
        }
    throw runtime_error("trying to write undefined varibale " + s);
}



class Token_stream {
public:
    Token_stream() : full(false), buffer(0) {}
    Token get();
    void putback(Token t);
    void ignore(char c);

private:
    bool full;
    Token buffer;
};

void Token_stream::putback(Token t) {
    if (full) throw runtime_error("putback() into a full buffer");
    buffer = t;
    full = true;
}

void Token_stream::ignore(char c)
    // c represents the  kind of token
{
    if (full && c== buffer.kind){
        full = false;
        return;
    }

    full = false;

    // now search input
    char ch = 0;
    while (cin >> ch)
        if (ch == c)
            return;
}

Token Token_stream::get() 
    // read characters from cin and compose a token
{

    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch; // skip whitespace

    switch (ch) {
    case quit:   
    case print:  
    case '(': case ')':
    case '+': case '-': case '*': case '/': case '%': case '=':
        return Token(ch); // let each character represent itself

    case '.':             // a floating-point-literal can start with a dot
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9': {
        cin.putback(ch);           // put digit back intothe input stream
        double val;
        cin >> val;         // read a floarting-point number
        return Token{number , val};   
    }

    default:
        if (isalpha(ch)){
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                s+=ch;
            if (cin) cin.putback(ch);
            if (s == declarkey)
                return Token{let};
            return Token{name,s};
        }
        throw runtime_error("Bad token");
    }
}

Token_stream ts;

// Forward declarations
double expression();
double term();
double primary();

// Primary: numbers, parentheses, unary +/-
double primary() {
    Token t = ts.get();
    switch (t.kind) {
    case '(' : {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') throw runtime_error("')' expected");
        return d;
    }
    case number:
        return t.value;

    case '-':
        return -primary();

    case '+':
        return primary();

    default:
        throw runtime_error("primary expected");
    }
}

// Term: handles * and /
double term() {
    double left = primary();

    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '*':
            left *= primary();
            break;

        case '%':
        {
            double d = primary();
            if (d == 0) throw runtime_error("divide by zero");
            // this is the floating point module from cmath
            left = fmod(left, d);
            t = ts.get();
            break;
        }

        case '/': {
            double d = primary();
            if (d == 0) throw runtime_error("divide by zero");
            left /= d;
            break;
        }

        default:
            ts.putback(t);
            return left;
        }
    }
}

// Expression: handles + and -
double expression() {
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
            ts.putback(t);
            return left;
        }
    }
}

//

bool is_declared(string var)
 // is var already in va_table?
{
    for(const Variable& v : var_table)
        if (v.name == var)
            return true;
    return false;        
}

double define_name(string var, double val)
// add {var,val} to var_table
{
    if(is_declared(var))
        throw runtime_error(var + " declared twice");

    var_table.push_back(Variable{var,val});
    return val;

}

double declaration()
    // handle: name = expression
    // 
{
    Token t = ts.get();
    if (t.kind != name)
        throw runtime_error("name expected in declaration");

    Token t2 = ts.get();
    if (t2.kind != '=')
        throw runtime_error("= missing in declaration of " + t.name);

    
    double d = expression();
    define_name(t.name,d);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case let:
        return declaration();
    
    default:
        ts.putback(t);
        return expression();
    }
}



void clean_up_mess(){
    ts.ignore(print);
}

void calculate()
{

    while (cin)
    {
        try
        {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
                break;

            ts.putback(t);
            cout << result << statement() << '\n';
        }
        catch (exception &e)
        {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
}

int main() {
    // predefine names
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);


    cout << "Calculator: + - * / ( )\n";
    cout << "Type ';' to print, 'q' to quit.\n";
    try {  
        
        calculate();
        return 0;
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch(...){
        cerr << "exception /n";
        return 2;
    }
}