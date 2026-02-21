#include <iostream>
#include <stdexcept>
using namespace std;


class Token{
    public:
        char kind;
        double value;
        Token(char k) :kind{k}, value{0.0}{}
        Token(char k , double v) :kind{k}, value{v}{}
};

class Token_stream {
    public:
        Token get();
        void putback(Token t);
    private:
        bool full = false;
        Token buffer;
};

void Token_stream::putback(Token t){

    if(full)
        throw runtime_error("putback inot a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get(){
    if (full){
        full = false;
        return buffer;
    }
    char ch = 0;
    if (!(cin >> ch))
        throw runtime_error("No input");
    switch (ch)
    {
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token{ch};
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);
        double val = 0;
        cin >> val;
        return Token{'8', val}; // '8' means number
    }
    default:
        throw runtime_error("Bad token");
    }
}


Token_stream ts;
double expression();





// page 13 5.5.2.3s
double expression(){
    double left = term();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
       
        default:
            ts.putback(t);
            return left;
        }
    }
    
};
double term(){
    double left = primary();
    Token t = ts.get();
    while (true){
         switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            //error for Num / 0!
            if (d == 0)
                throw runtime_error("divide by zero");
            left /= d;
            t = ts.get();
            break;  
        }
           

        default:
            ts.putback(t);
            return left;
        }
    }
};
double primary(){
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':{
        double d = expression();
        t = ts.get();
        if (t.kind !=')')
            throw runtime_error("primary expected");
        return d;
    }
    case '8':
        return t.value;
    
    default:
        throw runtime_error("primary expected");
    }
}



int main(){
        try{
            double val = 0;
            while(cin) {
                    Token t = ts.get();
                    if (t.kind == 'q')
                    break;
                if (t.kind == ';')
                {
                    cout << "=" << val << "\n";
                }
                else
                    ts.putback(t);
                val = expression();
            }
        }
        catch (runtime_error& e) {
            cerr << "Error " << e.what() << endl;
            return 1;
        }
    }



