#ifndef TPOB1_DETERMINISTICFINITEAUTOMATA_H
#define TPOB1_DETERMINISTICFINITEAUTOMATA_H
#pragma once
#include <bits/stdc++.h>
#include "../AutomataInterface.h"

using namespace std;

class DeterministicFiniteAutomata {
private:
    set<int> K;
    set<int> E;
    map<pair<int,int>, int> d;
    int q0;
    set<int> F;

public:
    DeterministicFiniteAutomata();
    void setE(set<int> alphabet);
    void setK(set<int> states);
    void setInitialState(int q);
    void setF(set<int> final);
    int calculateDelta(pair<int,int> key);
    void addPath(int node, int arc, int destination);
    bool repOk();
};
#endif // DETERMINISTICFINITEAUTOMATA_H
