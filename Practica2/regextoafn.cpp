#include <iostream>
using namespace std;
class ThompsonConstruction {
public:
    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    const char epsylon = 'E';
    const char operator_kleene = '*';
    const char operator_union = '|';
    const char operator_open_parenthesis = '(';
    const char operator_close_parenthesis = ')';
    string regex;
    ThompsonConstruction(string r):regex(r) {};
//    void process;

    };
int main () {
    string input;
    cin>>input;
    cout<<input;
    ThompsonConstruction t(input);
    cout<<t.alphabet[3];
}
