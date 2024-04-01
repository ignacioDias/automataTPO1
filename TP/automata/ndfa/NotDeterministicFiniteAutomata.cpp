#include <bits/stdc++.h>
#include "../dfa/DeterministicFiniteAutomata.h"
#include "../../auxiliarmethods/CollectionsOperators.h"
#include "NotDeterministicFiniteAutomata.h"
#include "../AutomataInterface.h"
#define LAMBDA -1
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
void NotDeterministicFiniteAutomata :: addState(int state) {
    this->K.insert(state);
}
void NotDeterministicFiniteAutomata :: addSymbolToAlphabet(int state) {
    this->E.insert(state);
}
void NotDeterministicFiniteAutomata ::addFinalState(int state) {
    this->F.insert(state);
}
void NotDeterministicFiniteAutomata :: addPath(int node, int arc, int destination) { //TODO: CHECKEAR QUE NODE Y ARC SEAN VÁLIDOS
    pair<int,int> path;
    path.first = node;
    path.second = arc;
    d[path].insert(destination);
}
set<int> NotDeterministicFiniteAutomata :: calculateDelta(pair<int,int> key) {
    set<int> retEmpty;
    if(d.find(key) == d.end())
        return retEmpty;
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
set<int> NotDeterministicFiniteAutomata :: lambdaClosure(const set<int>& Q) { //TODO: BORRAR Y SIMULARLA CON UNA INVOCACIÓN DE MOVE CON LAMBDA
    set<int> ret;
    for(auto elem : Q) {
        pair<int,int> actualPair;
        actualPair.first = elem;
        actualPair.second = LAMBDA;
        set<int> actualSet = calculateDelta(actualPair);
        if(!actualSet.empty())
            insertAll(ret, actualSet);
    }
    return ret;
}
set<int> NotDeterministicFiniteAutomata :: move(const set<int>& Q, int a) {
    set<int> ret;
    for(auto elem : Q) {
        pair<int,int> actualPair;
        actualPair.first = elem;
        actualPair.second = a;
        set<int> actualSet = calculateDelta(actualPair);
        if(!actualSet.empty())
            insertAll(ret, actualSet);
    }
    return ret;
}
void NotDeterministicFiniteAutomata :: insertAll(set<int> setToBeModify, const set<int>& otherSet) {
    for(auto elem : otherSet) {
        setToBeModify.insert(elem);
    }
}
