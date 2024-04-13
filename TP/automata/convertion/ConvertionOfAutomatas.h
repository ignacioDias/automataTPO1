//
// Created by ignaciodias on 12/04/24.
//

#ifndef TPOB1_CONVERTIONOFAUTOMATAS_H
#define TPOB1_CONVERTIONOFAUTOMATAS_H
#include "../dfa/DeterministicFiniteAutomata.h"
#include "../ndfa/NotDeterministicFiniteAutomata.h"

class ConvertionOfAutomatas {
private:
    DeterministicFiniteAutomata dfa;
    NotDeterministicFiniteAutomata ndfa;
public:
    ConvertionOfAutomatas();
    void setNDFA(NotDeterministicFiniteAutomata ndfa);
    void setDFA(DeterministicFiniteAutomata dfa);
    void convertFromNDFA();
    DeterministicFiniteAutomata getDFA();
    set<int> calculateDelta(const set<int>& state, int symbol);
    set<int> getLambdaClosure(const set<int>& Q);
    set<int> getLambdaReachableStates(int state);
    set<int> move(set<int> states, int symbol);
    set<set<int>> calculateFinal(const set<set<int>>& k);
    void showStates(set<set<int>> states);
};


#endif //TPOB1_CONVERTIONOFAUTOMATAS_H
