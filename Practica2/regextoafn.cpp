#include <iostream>
#include "regextoafn.h"
using namespace std;
class TransitionPair {
public:
    char simbol;
    TransitionPair* toState;

    TransitionPair (char s) : simbol(s)
    {
    };
};
class Af {
public:
    bool end;
    int tableSize;
    TransitionPair* transitionsTable;
    Af(bool e, int ts, TransitionPair* tt):transitionsTable(tt), end(e), tableSize(ts) {};
    TransitionPair* getNextState(char c) {
        for (int i=0; i<tableSize; i++) {
            if(transitionsTable[i].simbol == c) return transitionsTable[i].toState;
        }
        return NULL;
    };
};

    ThompsonConstruction::ThompsonConstruction(string expression,string
    alphabet):regex(expression), alphabet(alphabet){}
    // alphabet = "abcdefghijklmnopqrstuvwxyz";
    const char epsylon = 'E';
    const char operator_kleene = '*';
    const char operator_union = '|';
    const char operator_open_parenthesis = '(';
    const char operator_close_parenthesis = ')';
//    void process;

