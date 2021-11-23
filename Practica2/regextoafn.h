#include <iostream>
#include <vector>
using namespace std;
class TransitionPair {
public:
  char symbol;
  int toState;
  int fromState;
  TransitionPair(char s, int fromState, int toState);
  TransitionPair();
};
class AF {
public:
  int statesCount;
  vector<int> states;
  int finalState;
  int tableSize;
  vector<TransitionPair> transitionsTable;
  AF();
  void addStates(int statesNumber);
  int getNextState(int fromState, char c);
  void addTransitionPair(char symbol, int fromState, int toState);
};
class ThompsonConstruction {
public:
  string alphabet;
  string regex;
  ThompsonConstruction(string expression, string alphabet);
  AF UnionCase(vector<AF> options, int optionsNumber);
  AF ConcatCase(AF a, AF b);
  AF KleeneClosureCase(AF a);
  AF GroupingCase(string expression);
  AF evaluate(string regularExpression);
  bool preprocess();
  void writeAutomaton();
};
