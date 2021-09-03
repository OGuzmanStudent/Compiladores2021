#include <iostream>
#include <iterator>
#include <map>

using namespace std;
class AutomatonState {
public:
    string nodeName;
    //Este mapa representa al conjunto de estados conectado a este por un simbolo
    //en la transicion
    map<char, AutomatonState*> NextStates;
};
class ThompsonConstruction {
public:
    AutomatonState initialState;
    string alphabet;
    string regex;
    AutomatonState* automaton;
    ThompsonConstruction(string expression, string alphabet);
    AutomatonState* UnionCase(string expression);
    AutomatonState* ConcatCase(string expression);
    AutomatonState* KleeneClosureCase(string expression);
    AutomatonState* GroupingCase(string expression);
    void evaluate();
    bool preprocess();
    void writeAutomaton();

};
