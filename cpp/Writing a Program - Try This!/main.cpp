#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::exception;
//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//


//------------------------------------------------------------------------------
class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

class TokenStream {
    bool full;
    Token buffer;
public:
    TokenStream();
    Token get();
    void putback(Token t);
};

TokenStream::TokenStream():full(false), buffer(0) { }

void TokenStream::putback(Token t) {
    if (full) throw std::runtime_error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token TokenStream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch(ch) {
    case ';':
    case 'q':
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token{ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{'8', val};
    }
    default:
        throw std::runtime_error("Bad Token");
    }
}


//------------------------------------------------------------------------------

TokenStream ts;

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') throw std::runtime_error("')' expected");
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        throw std::runtime_error("primary expected");
    }
}
//------------------------------------------------------------------------------

int main() {
    cout << "Calculator 01: \n" << "Enter an expression (e.g.: \"2\", \"2+3\", \"25.3*3\")\nEnd with \';\': ";
    try {
        double val = 0;
        while (cin) {
            Token t = ts.get();

            if (t.kind == 'q') break;
            if (t.kind == ';')
                cout << "= " << val << '\n';
            else
                ts.putback(t);
            val = expression();
        }
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "exception \n";
        return 2;
    }
    return 0;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();     // get the next token
    while(true) {
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();     // get the next token

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
                double d = primary();
                if (d == 0) throw std::runtime_error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
        default:
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

