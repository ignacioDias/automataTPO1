#ifndef TPOB1_NOTDETERMINISTICFINITEAUTOMATA_H
#define TPOB1_NOTDETERMINISTICFINITEAUTOMATA_H

#include <bits/stdc++.h>
#include "../dfa/DeterministicFiniteAutomata.h"
#include "../AutomataInterface.h"
#include "../../auxiliarmethods/CollectionsOperators.h"

using namespace std;


class NotDeterministicFiniteAutomata : public AutomataInterface {
private:
    set<int> K;
    set<int> E;
    map<pair<int,int>, set<int>> d;
    int q0;
    set<int> F;

public:
    NotDeterministicFiniteAutomata();
    set<int> getK();
    set<int> getE();
    int getInitialState();
    set<int> getF();
    void addState(int state);
    void addSymbolToAlphabet(int state);
    void setK(set<int> states);
    void setE(set<int> alphabet);
    void setInitialState(int q);
    void setF(set<int> final);
    void addFinalState(int state);
    void addPath(int node, int arc, int destination);
    set<int> calculateDelta(pair<int,int> key);
    bool repOk();
    DeterministicFiniteAutomata nfaToDfa();
private:
    set<int> getSymbolClosure(const set<int> Q, int symbol);
    set<int> move(const set<int>& Q, int a);
    set<set<int>> calculateFinal(set<set<int>> k);
    void calculateNewK(set<set<int>> newK);
};
#endif //TPOB1_NOTDETERMINISTICFINITEAUTOMATA_H
