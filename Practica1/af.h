#include <iostream>
#include <vector>
using namespace std;
class TransitionPair {
public:
  char simbol;
  int toState;
  int fromState;
  TransitionPair(char s, int fromState, int toState);
};
class AF {
public:
  int statesCount;
  vector<int> states;
  vector<int> finalStates;
  vector<TransitionPair> transitionsTable;
  AF();
};
class NFA : public AF {
public:
  vector<int> getNextStates(int fromState, char c);
  NFA();
};
class DFA : public AF {
public:
  int getNextState(int fromState, char c);
  DFA();
};
