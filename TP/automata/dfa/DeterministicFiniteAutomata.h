#ifndef TPOB1_DETERMINISTICFINITEAUTOMATA_H
#define TPOB1_DETERMINISTICFINITEAUTOMATA_H
#pragma once
#include <bits/stdc++.h>
#include "../AutomataInterface.h"

using namespace std;

class DeterministicFiniteAutomata {
private:
    set<set<int>> K;
    set<int> E;
    map<pair<set<int>,int>, int> d;
    set<int> q0;
    set<set<int>> F;

public:
    DeterministicFiniteAutomata();
    void setE(set<int> alphabet);
    void setK(set<set<int>> states);
    void setInitialState(set<int> q);
    void setF(set<set<int>> final);
    int calculateDelta(pair<set<int>,int> key);
    void addPath(set<int> node, int arc, int destination);
    bool repOk();
    void setQ0(set<int> q0);
};
#endif // DETERMINISTICFINITEAUTOMATA_H
