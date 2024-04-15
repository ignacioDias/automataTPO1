//
// Created by ignaciodias on 15/04/24.
//

#ifndef TPOB1_DFATOSTRING_H
#define TPOB1_DFATOSTRING_H
#include "../../../automata/dfa/DeterministicFiniteAutomata.h"

class DFAToString {
public:
    static string dfaToString(DeterministicFiniteAutomata dfa);
private:
    static void toStringStatesDFA(DeterministicFiniteAutomata dfa, string& ret);
    static void toStringFinalStateDFA(DeterministicFiniteAutomata dfa, string& ret);
};


#endif //TPOB1_DFATOSTRING_H
