#include <bits/stdc++.h>

#include <utility>
#include "DeterministicFiniteAutomata.h"
#include "../AutomataInterface.h"
#include "../../auxiliarmethods/CollectionsOperators.h"
using namespace std;

DeterministicFiniteAutomata::DeterministicFiniteAutomata() : K(), E(), d(), q0(), F() {
}
void DeterministicFiniteAutomata::setAlphabet(set<int> alphabet) {
    this->E = std::move(alphabet);
}
set<int> DeterministicFiniteAutomata::getAlphabet() {
    return this->E;
}
void DeterministicFiniteAutomata :: setStates(set<set<int>> states) {
    this->K = std::move(states);
}
set<set<int>> DeterministicFiniteAutomata :: getStates() {
    return this->K;
}
void DeterministicFiniteAutomata :: insertSate(const set<int>& state) {
    this->K.insert(state);
}

void DeterministicFiniteAutomata :: setInitialState(set<int> q) {
    this->q0 = std::move(q);
    this->K.insert(getInitialState());
}
set<int> DeterministicFiniteAutomata :: getInitialState() {
    return this->q0;
}
void DeterministicFiniteAutomata :: setFinalStates(set<set<int>> final) {
    this->F = final;
}
set<set<int>> DeterministicFiniteAutomata :: getFinalStates() {
    return this->F;
}
set<int> DeterministicFiniteAutomata :: calculateDelta(const pair<set<int>,int>& key) {
    return d[key];
}
void DeterministicFiniteAutomata :: addPath(const set<int>& node, int arc, set<int> destination) {
    pair<set<int>,int> path = make_pair(node, arc);
    if(d.count(path) == 0)
        d[path] = std::move(destination);
}
bool DeterministicFiniteAutomata :: repOk() {
    bool invariant = true;
    for(auto currentSet : K) {
        invariant &= CollectionsOperators::setContained(this->F, currentSet);
        invariant &= CollectionsOperators::contained(this->q0, currentSet);
    }
    return invariant;
}
set<int> DeterministicFiniteAutomata::calculateWaysToGo(const set<int>& set1, const set<int>& set2) {
    set<int> ret;
    for (int letter : this->E) {
        set<int> delta = calculateDelta(make_pair(set1, letter));
        if (!delta.empty() && CollectionsOperators::contained(set2, delta)) //{2,3} {2,3,4}
            ret.insert(letter);
    }
    return ret;
}
bool DeterministicFiniteAutomata :: isFinalNode(const set<int>& node) {
    for(const auto& currentNode : getFinalStates()) {
        if(currentNode == node)
            return true;
    }
    return false;
}

bool DeterministicFiniteAutomata :: checkValidString(const string& numbers) {
    set<int> currentNode = q0;
    for(char ch : numbers) {
        pair<set<int>, int> key;
        key.first = currentNode;
        key.second = stoi(string(1, ch));
        if(d.count(key) == 0)
            return false;
        currentNode = calculateDelta(key);
    }
    return isFinalNode(currentNode);
}




