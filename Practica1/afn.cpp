#include <iostream>
#include <vector>
using namespace std;
class TransitionPair {
public:
  char simbol;
  int toState;
  int fromState;
  TransitionPair(char s, int fromState, int toState)
      : simbol(s), toState(toState), fromState(fromState){};
};
class AF {
public:
  int statesCount;
  vector<int> states;
  vector<int> finalStates;
  vector<TransitionPair> transitionsTable;
  AF(){};
};
class NFA : public AF {
public:
  vector<int> getNextStates(int fromState, char c) {
    vector<int> resultStates;
    int tableSize = transitionsTable.size();
    for (int i = 0; i < tableSize; i++) {
      if (transitionsTable[i].fromState == fromState &&
          transitionsTable[i].simbol == c)
        resultStates.push_back(transitionsTable[i].toState);
    }
    return resultStates;
  };
  NFA(){};
};
class DFA : public AF {
public:
  int getNextState(int fromState, char c) {
    int tableSize = transitionsTable.size();
    for (int i = 0; i < tableSize; i++) {
      if (transitionsTable[i].fromState == fromState &&
          transitionsTable[i].simbol == c)
        return transitionsTable[i].toState;
    }
    return -1;
  };
  DFA(){};
};
