//
// Created by ignaciodias on 15/04/24.
//

#include "DFAToString.h"
#include "../../../auxiliarmethods/CollectionsOperators.h"

string DFAToString::dfaToString(DeterministicFiniteAutomata dfa) {
    string ret = "digraph{\ninic[shape=point];\ninic->";
    ret += "\"" + CollectionsOperators::to_string_set(dfa.getInitialState()) + "\";\n";
    toStringStatesDFA(dfa, ret);
    toStringFinalStateDFA(dfa, ret);
    ret += "\n}";
    return ret;
}
void DFAToString::toStringStatesDFA(DeterministicFiniteAutomata dfa, string &ret) {
    for(const auto& set1 : dfa.getStates()) {
        if(set1.empty())
            continue;
        for(const auto& set2 : dfa.getStates()) {
            if(set2.empty())
                continue;
            set<int> label = dfa.calculateWaysToGo(set1, set2);
            if(!label.empty()) {
                ret += "\"" + CollectionsOperators::to_string_set(set1) + "\" -> \"" + CollectionsOperators::to_string_set(set2) + "\" [label = \"";
                for(auto elem : label)
                    ret += to_string(elem) + ",";
                ret.pop_back();
                ret += "\"];\n";
            }
        }
    }
}
void DFAToString::toStringFinalStateDFA(DeterministicFiniteAutomata dfa, string& ret) {
    ret += "\"" + CollectionsOperators::to_string_set_of_sets(dfa.getFinalStates()) + "\" [shape=doublecircle];\n";
    ret.pop_back();
}