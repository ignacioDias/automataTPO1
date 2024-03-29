#include <bits/stdc++.h>
#include "DeterministicFiniteAutomata.h"
#include "../AutomataInterface.h"
#include "../../auxiliarmethods/CollectionsOperators.h"
using namespace std;

DeterministicFiniteAutomata::DeterministicFiniteAutomata() : K(), E(), d(), q0(0), F() {
}
void DeterministicFiniteAutomata::setE(vector<int> alphabet) {
    this->E = alphabet;
}
void DeterministicFiniteAutomata :: setK(vector<int> states) {
    this->K = states;
}
void DeterministicFiniteAutomata :: setInitialState(int q) {
    this->q0 = q;
}
void DeterministicFiniteAutomata :: setF(vector<int> final) {
    this->F = final;
}
int DeterministicFiniteAutomata :: calculateDelta(pair<int,int> key) {
    return d[key];
}
void DeterministicFiniteAutomata :: addPath(int node, int arc, int destination) {
    pair<int,int> path;
    path.first = node;
    path.second = arc;
    auto it = d.find(path);
    if (it == d.end())
        d[path] = destination;
    else
        throw runtime_error("El nodo ya tiene asignado un destino con dicho arco");
}
bool DeterministicFiniteAutomata :: repOk() {
    bool invariant = CollectionsOperators::contained(this->K, this->E);
    invariant &= CollectionsOperators::contained(this->F, this->K);
    invariant &= CollectionsOperators::belongs(this->q0, this->K);
    return invariant;
}
