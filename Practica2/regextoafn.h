#include <iostream>
#include <iterator>
#include <map>

using namespace std;
class AutomatonState{
  public:
  string nodeName;
  map<char, AutomatonState*> NextStates;
};
class ThompsonConstruction{
  public: 
    string alphabet;
    string regex;
    AutomatonState* automaton;
    ThompsonConstruction(string expression, string alphabet);
    bool preprocess();
    void writeAutomaton();


};
