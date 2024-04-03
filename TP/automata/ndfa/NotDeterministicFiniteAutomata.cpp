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
DeterministicFiniteAutomata NotDeterministicFiniteAutomata :: nfaToDfa() { //TODO: FLATA ADD PATH, LOS NODOS NO ESTÁN REALMENTE VINCULADOS
    DeterministicFiniteAutomata convertedAutomata = *new DeterministicFiniteAutomata();

    set<int> q0AsSet;
    q0AsSet.insert(getInitialState());
    set<int> Q0 = getSymbolClosure(q0AsSet, LAMBDA);
    convertedAutomata.setQ0(Q0);
    set<set<int>> newK;
    newK.insert(Q0);

    convertedAutomata.setE(getE());

    calculateNewK(newK, convertedAutomata);
    convertedAutomata.setK(newK);
    convertedAutomata.setF(calculateFinal(newK));
    return convertedAutomata;
}
void NotDeterministicFiniteAutomata :: calculateNewK(set<set<int>> newK, DeterministicFiniteAutomata dfa) {
    set<set<int>> unvisitedNodes = newK;
    for(const auto& currentNode : unvisitedNodes) {
        for (auto currentNumber: getE()) {
            set<int> currentSet = move(currentNode, currentNumber);
            currentSet = getSymbolClosure(currentSet, LAMBDA);
            newK.insert(currentSet);
            unvisitedNodes.insert((currentSet));
            dfa.addPath(currentNode, currentNumber,currentSet);
        }
        unvisitedNodes.erase(currentNode);
    }
}

set<set<int>> NotDeterministicFiniteAutomata :: calculateFinal(set<set<int>> k) {
    set<set<int>> newF;
    for(const auto& currentSet : k) {
        for(auto currentNumber : currentSet) {
            if(getF().count(currentNumber) > 0) {
                newF.insert(currentSet);
                break;
            }
        }
    }
    return newF;
}
set<int> NotDeterministicFiniteAutomata :: getSymbolClosure(const set<int> Q, int symbol) {
    set<int> result;
    set<int> visited_states;
    set<int> unvisited_states = Q;
    while (unvisited_states.size() > 0) {
        int curr_state = *unvisited_states.begin();
        unvisited_states.erase(curr_state);
        visited_states.insert(curr_state);
        set<int> reachable_states = calculateDelta({curr_state, symbol});
        for (int reachable_state : reachable_states) {
            result.insert(reachable_state);
            if (visited_states.find(reachable_state) == visited_states.end())
                unvisited_states.insert(reachable_state);
        }
    }
    return result;
}
set<int> NotDeterministicFiniteAutomata :: move(const set<int>& Q, int a) {
    set<int> ret;
    for(auto elem : Q) {
        pair<int,int> actualPair;
        actualPair.first = elem;
        actualPair.second = a;
        set<int> actualSet = calculateDelta(actualPair);
        if(!actualSet.empty())
            CollectionsOperators::insertAll(ret, actualSet);
    }
    return ret;
}