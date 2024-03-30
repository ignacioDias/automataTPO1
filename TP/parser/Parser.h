#ifndef TPOB1_PARSER_H
#define TPOB1_PARSER_H
#pragma once
#include <bits/stdc++.h>
#include <vector>
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"

using  namespace std;

class Parser {
public:
    static void identifyFormat(const string& line);
    Parser();
    ~Parser();
    bool validateTextFile(vector<string> lines);

        void addInitialStateFromInitialStateLine(string line);
        void addFinalStateFromFinalStateLine(string line);
        void addAutomataInformationFromTransitionLine(string line);
        void fileManagement(string line);
        NotDeterministicFiniteAutomata getNDA();
        static bool validateInitialStateLine(string line);
        static bool validateFirstLine(string line);
        static bool validateLastLine(string line);
        bool validateTransitionLine(string line);
        bool validateFinalStateLine(string line);
        bool isRankdirLine(string line);


private:
    static bool checkDelta(const string& line);
    NotDeterministicFiniteAutomata nda; 
    bool readLastLine; 
};



#endif //TPOB1_PARSER_H
