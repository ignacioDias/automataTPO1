#ifndef TPOB1_NOTDETERMINISTICFINITEAUTOMATA_H
#define TPOB1_NOTDETERMINISTICFINITEAUTOMATA_H

#include <bits/stdc++.h>
#include "../dfa/DeterministicFiniteAutomata.h"
#include "../../auxiliarmethods/CollectionsOperators.h"

using namespace std;

class NotDeterministicFiniteAutomata {
private:
    set<int> states;
    set<int> alphabet;
    map<pair<int,int>, set<int>> delta;
    int initialState;
    set<int> finalStates;

public:
    NotDeterministicFiniteAutomata();
    set<int> getStates();
    set<int> getAlphabet();
    int getInitialState();
    set<int> getFinalStates();
    void addState(int state);
    void addSymbolToAlphabet(int state);
    void setStates(set<int> states);
    void setAlphabet(set<int> alphabet);
    void setInitialState(int q);
    void setFinalState(set<int> final);
    void addFinalState(int state);
    void addPath(int node, int arc, int destination);
    set<int> calculateDelta(pair<int,int> key);
    set<int> calculateWaysToGo(int from, int destination);
    void changeValueState(int oldValue, int newValue);
    map<pair<int, int>, set<int>> getTransitions();

    void setTransitions(map<pair<int, int>, set<int>> map1);
};
#endif //TPOB1_NOTDETERMINISTICFINITEAUTOMATA_H
