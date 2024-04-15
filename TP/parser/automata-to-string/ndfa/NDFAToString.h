//
// Created by ignaciodias on 15/04/24.
//

#ifndef TPOB1_NDFATOSTRING_H
#define TPOB1_NDFATOSTRING_H
#include "../../../automata/ndfa/NotDeterministicFiniteAutomata.h"

class NDFAToString {
public:
    static string ndfaToString(NotDeterministicFiniteAutomata ndfa);
private:
    static void NDFATransitionsToString(NotDeterministicFiniteAutomata ndfa, string& ret);
    static void toStringFinalStateNDFA(NotDeterministicFiniteAutomata ndfa, string& ret);

};


#endif //TPOB1_NDFATOSTRING_H
