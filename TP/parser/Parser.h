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

        bool validateFirstLine(std::string line);
        bool validateLastLine(std::string line);
        bool validateTransitionLine(std::string line);
        bool validateInitialStateLine(std::string line);
        bool validateFinalStateLine(std::string line);
        bool isRankdirLine(std::string line);

        void addInitialStateFromInitialStateLine(std::string line);
        void addFinalStateFromFinalStateLine(std::string line);
        void addAutomataInformationFromTransitionLine(std::string line);

private:
    static bool checkDelta(const string& line);
    NotDeterministicFiniteAutomata nda; 
};



#endif //TPOB1_PARSER_H
