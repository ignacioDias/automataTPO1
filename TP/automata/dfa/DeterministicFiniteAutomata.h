#ifndef TPOB1_DETERMINISTICFINITEAUTOMATA_H
#define TPOB1_DETERMINISTICFINITEAUTOMATA_H
#pragma once
#include <bits/stdc++.h>
using namespace std;

class DeterministicFiniteAutomata {
private:
    set<set<int>> K;
    set<int> E;
    map<pair<set<int>,int>, set<int>> d;
    set<int> q0;
    set<set<int>> F;

public:
    DeterministicFiniteAutomata();
    void setAlphabet(set<int> alphabet);
    set<int> getAlphabet();
    void setStates(set<set<int>> states);
    set<set<int>> getStates();
    set<int> getInitialState();
    void setInitialState(set<int> q);
    set<set<int>> getFinalStates();
    void setFinalStates(set<set<int>> final);
    set<int> calculateDelta(const pair<set<int>,int>& key);
    void addPath(const set<int>& node, int arc, set<int> destination);
    bool repOk();
    bool checkValidString(const string& numbers);
    void insertSate(const set<int>& state);
    set<int> calculateWaysToGo(const set<int>& set1, const set<int>& set2);

private:
    bool isFinalNode(const set<int>& node);
};
#endif // DETERMINISTICFINITEAUTOMATA_H
