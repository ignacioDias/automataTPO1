#ifndef TPOB1_NOTDETERMINISTICFINITEAUTOMATA_H
#define TPOB1_NOTDETERMINISTICFINITEAUTOMATA_H

#include <bits/stdc++.h>
#include "../dfa/DeterministicFiniteAutomata.h"
#include "../AutomataInterface.h"
#include "../../auxiliarmethods/CollectionsOperators.h"

using namespace std;


class NotDeterministicFiniteAutomata : public AutomataInterface {
private:
    vector<int> K;
    vector<int> E;
    map<pair<int,int>, set<int>> d;
    int q0;
    vector<int> F;

public:
    NotDeterministicFiniteAutomata();
    vector<int> getK();
    vector<int> getE();
    int getInitialState();
    vector<int> getF();
    void setK(vector<int> states);
    void setE(vector<int> alphabet);
    void setInitialState(int q);
    void setF(vector<int> final);
    void addPath(int node, int arc, int destination);
    set<int> calculateDelta(pair<int,int> key);
    bool repOk();
    DeterministicFiniteAutomata nfaToDfa();
};
#endif //TPOB1_NOTDETERMINISTICFINITEAUTOMATA_H
