#include <iostream>
#include <map>
using namespace std;
class TransitionPair {
public:
    char simbol;
    int toState;

    TransitionPair (char s, int ns) : simbol(s), toState(ns)
    {
    };
};
class Af {
public:
    int currentState;
    bool end;
    int tableSize;
    TransitionPair* transitionsTable;
    Af(int cs,bool e, int ts, TransitionPair* tt): currentState(cs),
        transitionsTable(tt), end(e), tableSize(ts) {};
    int getNextState(char c) {
        for (int i=0; i<tableSize; i++) {
            if(transitionsTable[i].simbol == c) return transitionsTable[i].toState;
        }
        return -1;
    };
};

int main () {
    TransitionPair r1[2]=
    {
        TransitionPair('a', 1),
        TransitionPair('b', 0)
    };
    TransitionPair r2[2]=
    {
        TransitionPair('a', 0),
        TransitionPair('b', 0)
    };
    Af afd[2] = {
        Af(0, false, 2, r1),
        Af(1, true, 2, r2),
    };
    string stringToEvaluate;
    int index = 0;
    cout << "Ingresa la cadena a evaular";
    cin >> stringToEvaluate;
    for (char c : stringToEvaluate) {
        index = afd[index].getNextState(c);
        if (index == -1)break;
    }
    if (index == -1 || !afd[index].end) {
        cout<<"Invalido";
    } else {
        cout<<"valido";
    }
    return 0;
}
