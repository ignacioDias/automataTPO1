#include <bits/stdc++.h>
#include "../dfa/DeterministicFiniteAutomata.h"
#include "../../auxiliarmethods/CollectionsOperators.h"
#include "NotDeterministicFiniteAutomata.h"
#include "../AutomataInterface.h"

using namespace std;

NotDeterministicFiniteAutomata :: NotDeterministicFiniteAutomata() : K(), E(), d(), q0(0), F() {
}
vector<int> NotDeterministicFiniteAutomata :: getK() {
    return K;
}
vector<int> NotDeterministicFiniteAutomata :: getE() {
    return E;
}
int NotDeterministicFiniteAutomata :: getInitialState() {
    return q0;
}
vector<int> NotDeterministicFiniteAutomata :: getF() {
    return F;
}
void NotDeterministicFiniteAutomata :: setK(vector<int> states) {
    this->K = states;
}
void NotDeterministicFiniteAutomata :: setE(vector<int> alphabet) {
    this->E = alphabet;
}
void NotDeterministicFiniteAutomata :: setInitialState(int q) {
    this->q0 = q;
}
void NotDeterministicFiniteAutomata :: setF(vector<int> final) {
    this->F = final;
}
void NotDeterministicFiniteAutomata :: addPath(int node, int arc, int destination) {
    pair<int,int> path;
    path.first = node;
    path.second = arc;
    d[path].insert(destination);
}
set<int> NotDeterministicFiniteAutomata :: calculateDelta(pair<int,int> key) {
    return d[key];
}
bool NotDeterministicFiniteAutomata :: repOk() {
    bool invariant = CollectionsOperators::contained(this->K, this->E);
    invariant &= CollectionsOperators::contained(this->F, this->K);
    invariant &= CollectionsOperators::belongs(this->q0, this->K);
    return invariant;
}
DeterministicFiniteAutomata NotDeterministicFiniteAutomata :: nfaToDfa() {
    DeterministicFiniteAutomata convertedAutomata = *new DeterministicFiniteAutomata();
    return convertedAutomata;
}