#ifndef TPOB1_DETERMINISTICFINITEAUTOMATA_H
#define TPOB1_DETERMINISTICFINITEAUTOMATA_H
#pragma once
#include <bits/stdc++.h>
#include "../AutomataInterface.h"

using namespace std;

class DeterministicFiniteAutomata {
private:
    vector<int> K;
    vector<int> E;
    map<pair<int,int>, int> d;
    int q0;
    vector<int> F;

public:
    DeterministicFiniteAutomata();
    void setE(vector<int> alphabet);
    void setK(vector<int> states);
    void setInitialState(int q);
    void setF(vector<int> final);
    int calculateDelta(pair<int,int> key);
    void addPath(int node, int arc, int destination);
    bool repOk();
};
#endif // DETERMINISTICFINITEAUTOMATA_H
