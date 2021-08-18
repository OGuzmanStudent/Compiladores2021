#include <iostream>
#include <map>
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
    TransitionPair transitionsTable[];
      Af(int cs,bool e, TransitionPair* tt): currentState(cs),
    transitionsTable(tt), end(e) {};
};
void main () {
  Af[] afd = [
    Af(0, false, [TransitionPair('a', 1),TransitionPair('b', 0) ]), 
    Af(1, true, [TransitionPair('a', 0),TransitionPair('b', 0) ]), 
  ];
  
}
