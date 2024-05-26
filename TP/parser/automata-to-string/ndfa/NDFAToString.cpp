//
// Created by ignaciodias on 15/04/24.
//

#include "NDFAToString.h"

string NDFAToString::ndfaToString(NotDeterministicFiniteAutomata ndfa) {
    string ret = "digraph{\ninic[shape=point];inic -> ";
    ret += to_string(ndfa.getInitialState()) + ";\n";
    NDFATransitionsToString(ndfa, ret);
    toStringFinalStateNDFA(ndfa, ret);
    ret += "\n}";
    return ret;
}
void NDFAToString::NDFATransitionsToString(NotDeterministicFiniteAutomata ndfa, string& ret) {
    const int LAMBDA = -1;
    for(int number : ndfa.getStates()) {
        for(int number2 : ndfa.getStates()) {
            set<int> label = ndfa.calculateWaysToGo(number,number2);
            if(!label.empty()) {
                ret += to_string(number) + " -> " + to_string(number2) + " [label = \"";
                for(int elem : label){
                    if(elem == LAMBDA){
                        ret += ("_,");
                    } else ret += to_string(elem) + ",";
                }
                ret.pop_back();
                ret += "\"];\n";
            }
        }
    }
}
void NDFAToString::toStringFinalStateNDFA(NotDeterministicFiniteAutomata ndfa, string& ret) {
    for(int finalState : ndfa.getFinalStates())
        ret += to_string(finalState) + "[shape=doublecircle];\n";
    ret.pop_back();
}

