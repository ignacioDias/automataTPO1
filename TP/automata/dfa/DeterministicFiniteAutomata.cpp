#include <bits/stdc++.h>
#include "DeterministicFiniteAutomata.h"
#include "../AutomataInterface.h"
#include "../../auxiliarmethods/CollectionsOperators.h"
using namespace std;

DeterministicFiniteAutomata::DeterministicFiniteAutomata() : K(), E(), d(), q0(), F() {
}
void DeterministicFiniteAutomata::setE(set<int> alphabet) {
    this->E = alphabet;
}
set<int> DeterministicFiniteAutomata::getE() {
    return this->E;
}

void DeterministicFiniteAutomata :: setK(set<set<int>> states) {
    this->K = states;
}
set<set<int>> DeterministicFiniteAutomata :: getK() {
    return this->K;
}
void DeterministicFiniteAutomata :: setInitialState(set<int> q) {
    this->q0 = q;
}
set<int> DeterministicFiniteAutomata :: getInitialState() {
    return this->q0;
}
void DeterministicFiniteAutomata :: setF(set<set<int>> final) {
    this->F = final;
}
set<set<int>> DeterministicFiniteAutomata :: getF() {
    return this->F;
}
set<int> DeterministicFiniteAutomata :: calculateDelta(const pair<set<int>,int>& key) {
    return d[key];
}
void DeterministicFiniteAutomata :: addPath(set<int> node, int arc, set<int> destination) {
    pair<set<int>,int> path;
    path.first = std::move(node);
    path.second = arc;
    auto it = d.find(path);
    if (it == d.end())
        d[path] = destination;
    else
        throw runtime_error("El nodo ya tiene asignado un destino con dicho arco");
}
bool DeterministicFiniteAutomata :: repOk() {
    bool invariant = CollectionsOperators::setContained(this->K, this->E);
    for(auto currentSet : K) {
        invariant &= CollectionsOperators::setContained(this->F, currentSet);
    }
    for(auto currentSet : K) {
        invariant &= CollectionsOperators::contained(this->q0, currentSet);
    }
    return invariant;
}
bool DeterministicFiniteAutomata :: belongs(string numbers) {
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
bool DeterministicFiniteAutomata :: isFinalNode(const set<int>& node) {
    for(const auto& currentNode : getF()) {
        if(currentNode == node)
            return true;
    }
    return false;
}



