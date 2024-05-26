#include <bits/stdc++.h>

#include <utility>
#include "../dfa/DeterministicFiniteAutomata.h"
#include "../../auxiliarmethods/CollectionsOperators.h"
#include "NotDeterministicFiniteAutomata.h"
#define LAMBDA -1
using namespace std;

NotDeterministicFiniteAutomata :: NotDeterministicFiniteAutomata() : states(), alphabet(), delta(), initialState(0), finalStates() {
}
set<int> NotDeterministicFiniteAutomata :: getStates() {
    return states;
}
set<int> NotDeterministicFiniteAutomata :: getAlphabet() {
    return alphabet;
}
int NotDeterministicFiniteAutomata :: getInitialState() {
    return initialState;
}
set<int> NotDeterministicFiniteAutomata :: getFinalStates() {
    return finalStates;
}
void NotDeterministicFiniteAutomata :: setStates(set<int> states) {
    this->states = std::move(states);
}
void NotDeterministicFiniteAutomata :: setAlphabet(set<int> alphabet) {
    this->alphabet = std::move(alphabet);
}
void NotDeterministicFiniteAutomata :: setInitialState(int q) {
    this->initialState = q;
}
void NotDeterministicFiniteAutomata::setFinalState(set<int> final) {
    this->finalStates = std::move(final);
}
void NotDeterministicFiniteAutomata :: addState(int state) {
    if(!CollectionsOperators::belongs(state, states))
        this->states.insert(state);
    else
        cout << "Nodo ya existente";
}
void NotDeterministicFiniteAutomata :: addSymbolToAlphabet(int state) {
    this->alphabet.insert(state);
}
void NotDeterministicFiniteAutomata ::addFinalState(int state) {
    this->finalStates.insert(state);
}
void NotDeterministicFiniteAutomata :: changeValueState(int oldValue, int newValue) {
    if(CollectionsOperators::belongs(oldValue, states)) {
        if(oldValue == initialState)
            initialState = newValue;
        pair<int,int> pairToChange;
        pairToChange.first = oldValue;
        states.erase(oldValue);
        states.insert(newValue);
        for(auto letter : alphabet) {
            pairToChange.second = letter;
            for(auto destination : calculateDelta(pairToChange))
                if(destination == oldValue)
                    addPath(newValue, letter, newValue);
                else
                    addPath(newValue, letter, destination);
            for(auto node : states) {
                pair<int,int> pairTemp = make_pair(node, letter);
                if(CollectionsOperators::belongs(oldValue, calculateDelta(pairTemp))) {
                    delta[pairTemp].erase(oldValue);
                    addPath(node, letter, newValue);
                }
            }
        }
        for(auto letter : alphabet) {
            pairToChange.second = letter;
            delta.erase(pairToChange);
        }
        if(CollectionsOperators::belongs(oldValue, finalStates)) {
            finalStates.insert(newValue);
            finalStates.erase(oldValue);
        }
    } else {
        cout << "Nodo ya existente!!\n";
    }
}

void NotDeterministicFiniteAutomata :: addPath(int node, int arc, int destination) { //TODO: CHECKEAR QUE NODE Y ARC SEAN VÁLIDOS
    if(CollectionsOperators::belongs(node, states) && CollectionsOperators::belongs(arc, alphabet) && CollectionsOperators::belongs(destination, states));
    pair<int,int> path;
    path.first = node;
    path.second = arc;
    delta[path].insert(destination);
}
set<int> NotDeterministicFiniteAutomata :: calculateDelta(pair<int,int> key) {
    if(delta.find(key) == delta.end())
        return {};
    return delta[key];
}

set<int> NotDeterministicFiniteAutomata :: calculateWaysToGo(int from, int destination) {
    set<int> ret;
    set<int> symbols = this->alphabet;
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

map<pair<int, int>, set<int>> NotDeterministicFiniteAutomata::getTransitions() {
    return delta;
}

void NotDeterministicFiniteAutomata::setTransitions(map<pair<int, int>, set<int>> map1) {
    delta = std::move(map1);
}
