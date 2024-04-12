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
private:
    set<int> calculateDelta(const set<int>& state, int symbol);
    set<int> getSymbolClosure(const set<int>& Q);
    set<int> move(const set<int>& Q, int a);
    set<set<int>> calculateFinal(const set<set<int>>& k);
    void calculateNewK();
};


#endif //TPOB1_CONVERTIONOFAUTOMATAS_H
