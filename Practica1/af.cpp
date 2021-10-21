#include "af.h"
#include <iostream>
#include <vector>
using namespace std;
TransitionPair::TransitionPair(char s, int fromState, int toState)
    : simbol(s), toState(toState), fromState(fromState){};
AF::AF(){};
vector<int> NFA::getNextStates(int fromState, char c) {
  vector<int> resultStates;
  int tableSize = transitionsTable.size();
  for (int i = 0; i < tableSize; i++) {
    if (transitionsTable[i].fromState == fromState &&
        transitionsTable[i].simbol == c)
      resultStates.push_back(transitionsTable[i].toState);
  }
  return resultStates;
};
NFA::NFA(){};
int DFA::getNextState(int fromState, char c) {
  int tableSize = transitionsTable.size();
  for (int i = 0; i < tableSize; i++) {
    if (transitionsTable[i].fromState == fromState &&
        transitionsTable[i].simbol == c)
      return transitionsTable[i].toState;
  }
  return -1;
};
DFA::DFA(){};
