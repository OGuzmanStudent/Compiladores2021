#include "regextoafn.h"
#include <iostream>
#include <list>
#include <stack>
using namespace std;
TransitionPair::TransitionPair(char s, int fromState, int toState)
    : symbol(s), toState(toState), fromState(fromState){}
TransitionPair::TransitionPair(){}
AF::AF() {
  AF::statesCount = 0;
  AF::tableSize = 0;
}
void AF::addStates(int statesNumber) {
  for (int stateCounter = 0; stateCounter < statesNumber; stateCounter++) {
    states.push_back(stateCounter);
    statesCount++;
  }
}
int AF::getNextState(int fromState, char c) {
  for (int i = 0; i < tableSize; i++) {
    if (transitionsTable[i].fromState == fromState &&
        transitionsTable[i].symbol == c)
      return transitionsTable[i].toState;
  }
  return -1;
}
void AF::addTransitionPair(char symbol, int fromState, int toState) {
  TransitionPair newTransitionPair(symbol, fromState, toState);
  transitionsTable.push_back(newTransitionPair);
  tableSize++;
}
ThompsonConstruction::ThompsonConstruction(string expression, string alphabet)
    : regex(expression), alphabet(alphabet){}
// alphabet = "abcdefghijklmnopqrstuvwxyz";
const char epsylon = 'E';
const char operator_kleene = '*';
const char operator_union = '|';
const char operator_concat = '^';
const char operator_open_parenthesis = '(';
const char operator_close_parenthesis = ')';
AF ThompsonConstruction::UnionCase(vector<AF> options, int optionsNumber) {
  AF result;
  int statesCount = 2;
  int optionCounter;
  int transitionCounter;
  AF helper;
  TransitionPair newTransitionPair;

  for (AF option : options) {
    statesCount += option.statesCount;
  }

  result.addStates(statesCount);

  int toState = 1;

  for (optionCounter = 0; optionCounter < optionsNumber; optionCounter++) {
    result.addTransitionPair(operator_concat, 0, toState);
    helper = options.at(optionCounter);
    for (TransitionPair helperTransition : helper.transitionsTable) {
      result.addTransitionPair(helperTransition.symbol,
                               helperTransition.fromState + toState,
                               helperTransition.toState + toState);
    }
    toState += helper.statesCount;

    result.addTransitionPair(operator_concat, toState - 1, statesCount - 1);
  }

  result.finalState = statesCount - 1;

  return result;
}
AF ThompsonConstruction::ConcatCase(AF a, AF b) {
  AF result;
  result.addStates(a.statesCount + b.statesCount);
  TransitionPair newTransitionPair;

  for (TransitionPair aTransition : a.transitionsTable) {
    newTransitionPair = aTransition;
    result.addTransitionPair(newTransitionPair.symbol,
                             newTransitionPair.fromState,
                             newTransitionPair.toState);
  }

  result.addTransitionPair(operator_concat, a.finalState, a.statesCount);

  for (TransitionPair bTransition : b.transitionsTable) {
    newTransitionPair = bTransition;
    result.addTransitionPair(newTransitionPair.symbol,
                             newTransitionPair.fromState + a.statesCount,
                             newTransitionPair.toState + a.statesCount);
  }

  result.finalState = a.statesCount + b.statesCount - 1;

  return result;
}
AF ThompsonConstruction::KleeneClosureCase(AF a) {
  AF result;
  TransitionPair newTransitionPair;
  result.addStates(a.statesCount + 2);
  result.addTransitionPair(operator_concat, 0, 1);

  for (TransitionPair aTransition : a.transitionsTable) {
    newTransitionPair = aTransition;
    result.addTransitionPair(newTransitionPair.symbol,
                             newTransitionPair.fromState + 1,
                             newTransitionPair.toState + 1);
  }

  result.addTransitionPair(operator_concat, a.statesCount, a.statesCount + 1);
  result.addTransitionPair(operator_concat, a.statesCount, 1);
  result.addTransitionPair(operator_concat, 0, a.statesCount + 1);

  result.finalState = a.statesCount + 1;

  return result;
}
AF ThompsonConstruction::evaluate(string regularExpression) {
  stack<char> operators;
  stack<AF> operands;
  char operatorSymbol;
  int operatorsCount;
  AF *newSymbol;

  for (char currentSymbol : regularExpression) {
    if ( //si no es un operador, caso simbolo
      currentSymbol != operator_open_parenthesis
      && currentSymbol != operator_close_parenthesis
      && currentSymbol != operator_kleene 
      && currentSymbol != operator_union 
      && currentSymbol != operator_concat
      ) {
      newSymbol = new AF();
      newSymbol->addStates(2);
      newSymbol->addTransitionPair(currentSymbol,0, 1);
      newSymbol->finalState=1;
      operands.push(*newSymbol);
      delete newSymbol;
    } else {
      if (currentSymbol == operator_kleene) {
        AF starOperator = operands.top();
        operands.pop();
        operands.push(KleeneClosureCase(starOperator));
      } else if (currentSymbol == operator_concat) {
        operators.push(currentSymbol);
      } else if (currentSymbol == operator_union) {
        operators.push(currentSymbol);
      } else if (currentSymbol == operator_open_parenthesis) {
        operators.push(currentSymbol);
      } else {
        operatorsCount = 0;
        char c;
        operatorSymbol = operators.top();
        if (operatorSymbol == operator_open_parenthesis)
          continue;
        do {
          operators.pop();
          operatorsCount++;
        } while (operators.top() != '(');
        operators.pop();
        AF op1;
        AF op2;
        vector<AF> selections;
        if (operatorSymbol == '.') {
          for (int i = 0; i < operatorsCount; i++) {
            op2 = operands.top();
            operands.pop();
            op1 = operands.top();
            operands.pop();
            operands.push(ConcatCase(op1, op2));
          }
        } else if (operatorSymbol == '|') {
          selections.assign(operatorsCount + 1, AF());
          int tracker = operatorsCount;
          for (int i = 0; i < operatorsCount + 1; i++) {
            selections.at(tracker) = operands.top();
            tracker--;
            operands.pop();
          }
          operands.push(UnionCase(selections, operatorsCount + 1));
        } else {
        }
      }
    }
  }

  return operands.top();
}
// AutomatonGroup::
// bool ThompsonConstruction::preprocess() {
//  int matchParethesis = 0;
//  list<AutomatonGroup> operaciones;
//< O P E R A T O R  ~ P R E C E D E N C E >
//->Grouping () val =4
//->Single-character-ERE duplication * + ? {m,n} val=3
//->Concatenation val = 2
//->Alternation | ni val= 1
// int index = 0;
//  for (char symbol : regex) {
//  switch (symbol) {
// case '(':
//            operaciones.push_back()
// matchParethesis++;
//      break;
//  case ')':
//  matchParethesis--;
//      break;
//  case '*':
//      break;
//  case '|':
//  break;
//    default:
// Este caso seria la concatenacion ya que es lo que se representa con
// dos miembros del alfabeto consecutivos
//    break;
//}
//    index++;
//}
//  bool isValidExpression = matchParethesis == 0;
// return isValidExpression;
//}
