#include <bits/stdc++.h>
#include "../dfa/DeterministicFiniteAutomata.h"
#include "../../auxiliarmethods/CollectionsOperators.h"
#include "NotDeterministicFiniteAutomata.h"
#include "../AutomataInterface.h"

using namespace std;

NotDeterministicFiniteAutomata :: NotDeterministicFiniteAutomata() : K(), E(), d(), q0(0), F() {
}
set<int> NotDeterministicFiniteAutomata :: getK() {
    return K;
}
set<int> NotDeterministicFiniteAutomata :: getE() {
    return E;
}
int NotDeterministicFiniteAutomata :: getInitialState() {
    return q0;
}
set<int> NotDeterministicFiniteAutomata :: getF() {
    return F;
}
void NotDeterministicFiniteAutomata :: setK(set<int> states) {
    this->K = states;
}
void NotDeterministicFiniteAutomata :: setE(set<int> alphabet) {
    this->E = alphabet;
}
void NotDeterministicFiniteAutomata :: setInitialState(int q) {
    this->q0 = q;
}
void NotDeterministicFiniteAutomata :: setF(set<int> final) {
    this->F = final;
}
void NotDeterministicFiniteAutomata :: addK(int state) {
    this->K.insert(state);
}
void NotDeterministicFiniteAutomata :: addE(int state) {
    this->E.insert(state);
}
void NotDeterministicFiniteAutomata :: addPath(int node, int arc, int destination) { //TODO: CHECKEAR QUE NODE Y ARC SEAN VÁLIDOS
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