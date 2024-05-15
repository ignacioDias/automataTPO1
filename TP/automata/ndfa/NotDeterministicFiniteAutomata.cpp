#include <bits/stdc++.h>

#include <utility>
#include "../dfa/DeterministicFiniteAutomata.h"
#include "../../auxiliarmethods/CollectionsOperators.h"
#include "NotDeterministicFiniteAutomata.h"
#define LAMBDA -1
using namespace std;

NotDeterministicFiniteAutomata :: NotDeterministicFiniteAutomata() : K(), E(), d(), q0(0), F() {
}
set<int> NotDeterministicFiniteAutomata :: getSates() {
    return K;
}
set<int> NotDeterministicFiniteAutomata :: getAlphabet() {
    return E;
}
int NotDeterministicFiniteAutomata :: getInitialState() {
    return q0;
}
set<int> NotDeterministicFiniteAutomata :: getFinalSates() {
    return F;
}
void NotDeterministicFiniteAutomata :: setStates(set<int> states) {
    this->K = std::move(states);
}
void NotDeterministicFiniteAutomata :: setAlphabet(set<int> alphabet) {
    this->E = std::move(alphabet);
}
void NotDeterministicFiniteAutomata :: setInitialState(int q) {
    this->q0 = q;
}
void NotDeterministicFiniteAutomata::setFinalState(set<int> final) {
    this->F = std::move(final);
}
void NotDeterministicFiniteAutomata :: addState(int state) {
    if(!CollectionsOperators::belongs(state, K))
        this->K.insert(state);
    else
        cout << "Nodo ya existente";
}
void NotDeterministicFiniteAutomata :: addSymbolToAlphabet(int state) {
    this->E.insert(state);
}
void NotDeterministicFiniteAutomata ::addFinalState(int state) {
    this->F.insert(state);
}
void NotDeterministicFiniteAutomata :: changeValueState(int oldValue, int newValue) {
    if(!CollectionsOperators::belongs(newValue, K) && CollectionsOperators::belongs(oldValue, K)) {
        if(oldValue == q0)
            q0 = newValue;
        pair<int,int> pairToChange;
        pairToChange.first = oldValue;
        K.erase(oldValue);
        K.insert(newValue);
        for(auto letter : E) {
            pairToChange.second = letter;
            for(auto destination : calculateDelta(pairToChange))
                if(destination == oldValue)
                    addPath(newValue, letter, newValue);
                else
                    addPath(newValue, letter, destination);
            for(auto node : K) {
                pair<int,int> pairTemp = make_pair(node, letter);
                if(CollectionsOperators::belongs(oldValue, calculateDelta(pairTemp))) {
                    d[pairTemp].erase(oldValue);
                    addPath(node, letter, newValue);
                }
            }
        }
        for(auto letter : E) {
            pairToChange.second = letter;
            d.erase(pairToChange);
        }
        if(CollectionsOperators::belongs(oldValue, F)) {
            F.insert(newValue);
            F.erase(oldValue);
        }
    } else {
        cout << "Nodo ya existente";
    }
}

void NotDeterministicFiniteAutomata :: addPath(int node, int arc, int destination) { //TODO: CHECKEAR QUE NODE Y ARC SEAN VÁLIDOS
    if(CollectionsOperators::belongs(node, K) && CollectionsOperators::belongs(arc, E) && CollectionsOperators::belongs(destination, K));
    pair<int,int> path;
    path.first = node;
    path.second = arc;
    d[path].insert(destination);
}
set<int> NotDeterministicFiniteAutomata :: calculateDelta(pair<int,int> key) {
    if(d.find(key) == d.end())
        return {};
    return d[key];
}

set<int> NotDeterministicFiniteAutomata :: calculateWaysToGo(int from, int destination) {
    set<int> ret;
    set<int> symbols = this->E; 
    symbols.insert(LAMBDA); 
    for(int letter : symbols) {
        pair<int,int> pair;
        pair.first = from;
        pair.second = letter;
        set<int> delta = calculateDelta(pair);
        if(!delta.empty() && delta.count(destination) > 0)
            ret.insert(letter);
    }
    return ret;
}