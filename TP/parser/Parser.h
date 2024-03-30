#ifndef TPOB1_PARSER_H
#define TPOB1_PARSER_H
#include <bits/stdc++.h>
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"

using  namespace std;

class Parser {
public:
    static void identifyFormat(const string& line);
private:
    static bool checkDelta(const string& line);
};



#endif //TPOB1_PARSER_H
