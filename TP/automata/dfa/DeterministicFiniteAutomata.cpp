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
void DeterministicFiniteAutomata::setQ0(set<int> q0) {
    this->q0 = q0;
}

void DeterministicFiniteAutomata :: setK(set<set<int>> states) {
    this->K = states;
}
void DeterministicFiniteAutomata :: setInitialState(set<int> q) {
    this->q0 = q;
}
void DeterministicFiniteAutomata :: setF(set<set<int>> final) {
    this->F = final;
}
int DeterministicFiniteAutomata :: calculateDelta(pair<set<int>,int> key) {
    if (d.count(key))
        return d[key];
    throw std::out_of_range("La clave no tiene un valor asociado.");

}
void DeterministicFiniteAutomata :: addPath(set<int> node, int arc, int destination) {
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

