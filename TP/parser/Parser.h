#ifndef TPOB1_PARSER_H
#define TPOB1_PARSER_H
#include <bits/stdc++.h>
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"

using  namespace std;

class Parser {
public:
    static void identifyFormat(const string& line);
    Parser();
        ~Parser();

        bool validateFirstLine(string line);
        bool validateLastLine(string line);
        bool validateTransitionLine(string line);
        bool validateInitialStateLine(string line);
        bool validateFinalStateLine(string line);
        bool isRankdirLine(string line);

        void addInitialStateFromInitialStateLine(string line);
        void addFinalStateFromFinalStateLine(string line);
        void addAutomataInformationFromTransitionLine(string line);
        NotDeterministicFiniteAutomata getNDA();


private:
    static bool checkDelta(const string& line);
    NotDeterministicFiniteAutomata nda; 
};



#endif //TPOB1_PARSER_H
