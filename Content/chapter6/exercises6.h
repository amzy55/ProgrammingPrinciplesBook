#pragma once

#include "../std_lib_facilities.h"
namespace exercises6
{
    namespace calculator00
    {
        //------------------------------------------------------------------------------

        class Token {
        public:
            char kind;        // what kind of token
            double value;     // for numbers: a value 
            Token(char ch)    // make a Token from a char
                :kind(ch), value(0) {
            }
            Token(char ch, double val)     // make a Token from a char and a double
                :kind(ch), value(val) {
            }
        };

        //------------------------------------------------------------------------------

        Token get_token()    // read a token from cin
        {
            char ch;
            cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

            switch (ch) {
                //not yet   case ';':    // for "print"
                //not yet   case 'q':    // for "quit"
            case '(': case ')': case '+': case '-': case '*': case '/':
                return Token(ch);        // let each character represent itself
            case '.':
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);         // put digit back into the input stream
                double val;
                cin >> val;              // read a floating-point number
                return Token('8', val);   // let '8' represent "a number"
            }
            default:
                error("Bad token");
            }
        }

        //------------------------------------------------------------------------------

        double expression();  // read and evaluate a Expression

        //------------------------------------------------------------------------------

        double term();        // read and evaluate a Term

        //------------------------------------------------------------------------------

        double primary()     // read and evaluate a Primary
        {
            Token t = get_token();
            switch (t.kind) {
            case '(':    // handle '(' expression ')'
            {
                double d = expression();
                t = get_token();
                if (t.kind != ')') error("')' expected");
                return d;
            }
            case '8':            // we use '8' to represent a number
                return t.value;  // return the number's value
            default:
                error("primary expected");
            }
        }

        //------------------------------------------------------------------------------

        double expression()
        {
            double left = term();      // read and evaluate a Term
            Token t = get_token();     // get the next token
            while (true) {
                switch (t.kind) {
                case '+':
                    left += term();    // evaluate Term and add
                    t = get_token();
                    break;
                case '-':
                    left -= term();    // evaluate Term and subtract
                    t = get_token();
                    break;
                default:
                    return left;       // finally: no more + or -: return the answer
                }
            }
        }

        //------------------------------------------------------------------------------

        double term()
        {
            double left = primary();
            Token t = get_token();     // get the next token

            while (true) {
                switch (t.kind) {
                case '*':
                    left *= primary();
                    t = get_token();
                    break;
                case '/':
                {
                    double d = primary();
                    if (d == 0) error("divide by zero");
                    left /= d;
                    t = get_token();
                    break;
                }
                default:
                    return left;
                }
            }
        }

        //------------------------------------------------------------------------------
    }

    namespace calculator01
    {

        //------------------------------------------------------------------------------

        class Token {
        public:
            char kind;        // what kind of token
            double value;     // for numbers: a value 
            Token(char ch)    // make a Token from a char
                :kind(ch), value(0) {
            }
            Token(char ch, double val)     // make a Token from a char and a double
                :kind(ch), value(val) {
            }
        };

        //------------------------------------------------------------------------------
        /*
        Token get_token()    // read a token from cin
        {
            char ch;
            cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

            switch (ch) {
         //not yet   case ';':    // for "print"
         //not yet   case 'q':    // for "quit"
            case '(': case ')': case '+': case '-': case '*': case '/':
                return Token(ch);        // let each character represent itself
            case '.':
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                {
                    cin.putback(ch);         // put digit back into the input stream
                    double val;
                    cin >> val;              // read a floating-point number
                    return Token('8',val);   // let '8' represent "a number"
                }
            default:
                error("Bad token");
            }
        }
        */
        //------------------------------------------------------------------------------

        class Token_stream {
        public:
            Token get();            // get a Token
            void putback(Token t);  // put a Token back
        private:
            bool full{ false };      // is there a Token in the buffer?
            Token buffer = { '0' };           // where we store a 'putback' Token
        };

        void Token_stream::putback(Token t)
        {
            if (full) error("putback() into a full buffer");
            buffer = t;         // copy t to buffer
            full = true;        // buffer is now full
        }

        Token Token_stream::get()
        {
            if (full) {
                full = false;
                return buffer;
            }
            char ch;
            cin >> ch;

            switch (ch) {
            case ';':       // for "print"
            case 'q':       // for "quit"
            case '(':
            case ')':
            case '+':
            case '-':
            case '*':
            case '/':
                return Token{ ch };   // let each character represent itself
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
            {
                cin.putback(ch);
                double val;
                cin >> val;
                return Token{ '8', val };
            }
            default:
                error("Bad Token");
            }
        }

        //------------------------------------------------------------------------------

        Token_stream ts;      // provides get() and putback()

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
                if (t.kind != ')') error("')' expected");
                return d;
            }
            case '8':            // we use '8' to represent a number
                return t.value;  // return the number's value
            default:
                error("primary expected");
            }
        }
        //------------------------------------------------------------------------------

        int main()
            try {
            while (cin)
                cout << expression() << '\n';
            keep_window_open("~0");
        }
        catch (exception& e) {
            cerr << e.what() << endl;
            keep_window_open("~1");
            return 1;
        }
        catch (...) {
            cerr << "exception \n";
            keep_window_open("~2");
            return 2;
        }

        //------------------------------------------------------------------------------

        double expression()
        {
            double left = term();      // read and evaluate a Term
            Token t = ts.get();        // get the next token
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
                default:
                    ts.putback(t);
                    return left;
                }
            }
        }

        //------------------------------------------------------------------------------

        void call_calculator()
        {
            double val = 0;
            while (cin) {
                Token t = ts.get();
                if (t.kind == 'q') break;
                if (t.kind == ';')
                    // ‘q’ for “quit”
                     // ‘;’ for “print now”
                    cout << "=" << val << '\n';
                else
                    ts.putback(t);
                val = expression();
            }
        }
    }

    namespace calculator02buggy
    {
        /*
        This file is known as calculator02buggy.cpp

        I have inserted 5 errors that should cause this not to compile
        I have inserted 3 logic errors that should cause the program to give wrong results

        First try to find an remove the bugs without looking in the book.
        If that gets tedious, compare the code to that in the book (or posted source code)

        Happy hunting!
        */

        //------------------------------------------------------------------------------

        class Token{
        public:
            char kind;        // what kind of token
            double value;     // for numbers: a value 
            Token(char ch)    // make a Token from a char
                :kind(ch), value(0) {
            }
            Token(char ch, double val)     // make a Token from a char and a double
                :kind(ch), value(val) {
            }
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
                return Token(ch);        // let each character represent itself
            case '.':
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9': // logic error 1 - forgot to add case for 8
            {
                cin.putback(ch);         // put digit back into the input stream
                double val;
                cin >> val;              // read a floating-point number
                return Token('8', val);   // let '8' represent "a number"
            }
            default:
                error("Bad token");
            }
        }

        //------------------------------------------------------------------------------

        Token_stream ts;        // provides get() and putback() 

        //------------------------------------------------------------------------------

        double expression();    // declaration so that primary() can call expression()

        //------------------------------------------------------------------------------

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
            case '8':            // we use '8' to represent a number
                return t.value;  // return the number's value
            default:
                error("primary expected");
            }
        }

        //------------------------------------------------------------------------------

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
                    break; // logic error 2 - forgot to add break
                case '/':
                {
                    double d = primary();
                    if (d == 0) error("divide by zero");
                    left /= d;
                    t = ts.get();
                    break;
                }
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
                    left -= term();    // evaluate Term and subtract // logic error 3 - '+' was used instead of '-'
                    t = ts.get();
                    break;
                default:
                    ts.putback(t);     // put t back into the token stream
                    return left;       // finally: no more + or -: return the answer
                }
            }
        }

        //------------------------------------------------------------------------------

        void call_calculator()
        {
            cout << "Welcome to our simple calculator.\n";
            cout << "Please enter expressions using floating-point numbers.\n";
            cout << "Supported operations are +, -, *, / and using parenthesis '()'.\n";
            cout << "Input '=' to print result and 'x' to quit the calculator.\n";
            double val = 0;
            while (cin) {
                Token t = ts.get();

                if (t.kind == 'x') break; // 'x' for quit
                if (t.kind == '=')        // '=' for "print now"
                    cout << "=" << val << '\n';
                else
                    ts.putback(t);
                val = expression();
            }
            keep_window_open();
        }
    }
}