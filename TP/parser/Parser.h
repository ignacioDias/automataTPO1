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

    void addInitialStateFromInitialStateLine(const string& line);
    void addFinalStateFromFinalStateLine(const string& line);
    void addAutomataInformationFromTransitionLine(string line);
    void fileManagement(const string& line);
    NotDeterministicFiniteAutomata getNDA();
    static bool validateInitialStateLine(string line); //priv?
    static bool validateFirstLine(const string& line);
    static bool validateLastLine(const string& line);
    static bool validateTransitionLine(const string& line);
    static bool validateFinalStateLine(const string& line);
    bool isRankdirLine(const string& line);
    static string ndfaToString(NotDeterministicFiniteAutomata ndfa);
    static string dfaToString(DeterministicFiniteAutomata dfa);
    static void writeToFile(const string& filename, const string& content);

private:
    static bool checkDelta(const string& line);
    NotDeterministicFiniteAutomata nda; 
    bool readLastLine;
    static void NDFATransitionsToString(NotDeterministicFiniteAutomata ndfa, string& ret);
    static void toStringFinalStateNDFA(NotDeterministicFiniteAutomata ndfa, string& ret);
    static void toStringStatesDFA(DeterministicFiniteAutomata dfa, string& ret);
    static void toStringFinalStateDFA(DeterministicFiniteAutomata dfa, string& ret);
    static string toStringSet(const set<int>& set);
};



#endif //TPOB1_PARSER_H
