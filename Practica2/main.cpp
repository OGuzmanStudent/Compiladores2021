#include <iostream>
#include "regextoafn.h"
using namespace std;
const string alphabet = "abcdefghijklmno    pqrstuvwxyz";
int main() {
  string re;
	cin>>re;


	AF automaton;
	automaton = ThompsonConstruction(re,alphabet).evaluate(re);
	automaton.writeToDot();

	return 0;
}
