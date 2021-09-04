#include <iostream>
#include <list>
#include "regextoafn.h"
using namespace std;
class AutomatonGroup {
public:
    char operatorSimbol;
    int operatorWeight;
    int startParenthesis;
    int endParenthesis;
    //Ya que la concatenacion se produce con dos simbolos del alfabeto
    //seguidos, considero que se trata de un 'operador intermedio' o implicito,
    //almacenare este indice como un double para utilizar los indices enteros
    //para hacer referencia a los operandos
    double operatorIndex;
    AutomatonGroup()
    {
    };
};

ThompsonConstruction::ThompsonConstruction(string expression,string
        alphabet):regex(expression), alphabet(alphabet) {}
// alphabet = "abcdefghijklmnopqrstuvwxyz";
const char epsylon = 'E';
const char operator_kleene = '*';
const char operator_union = '|';
const char operator_open_parenthesis = '(';
const char operator_close_parenthesis = ')';
bool ThompsonConstruction::preprocess() {
    int matchParethesis = 0;
    list<AutomatonGroup> operaciones;
    //< O P E R A T O R  ~ P R E C E D E N C E >
    //->Grouping () val =4
    //->Single-character-ERE duplication * + ? {m,n} val=3
    //->Concatenation val = 2
    //->Alternation | ni val= 1
    int index = 0;
    for (char symbol : regex) {
        switch(symbol) {
        case '(':
//            operaciones.push_back()
            matchParethesis++;
            break;
        case ')':
            matchParethesis--;
            break;
        case '*':
            break;
        case '|':
            break;
        default:
            //Este caso seria la concatenacion ya que es lo que se representa con
            //dos miembros del alfabeto consecutivos
            break;
        }
        index++;
    }
    bool isValidExpression = matchParethesis == 0;
    return isValidExpression;
}
