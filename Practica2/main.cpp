#include <iostream>
#include "regextoafn.h"
using namespace std;
const string alphabet = "abcdefghijklmno    pqrstuvwxyz";
int main () {
    string input;
    cin>>input;
    cout<<input;
    ThompsonConstruction t(input, alphabet);
    cout<<t.alphabet[3];
    return EXIT_SUCCESS;
}
