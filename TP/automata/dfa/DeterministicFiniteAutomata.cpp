#include <bits/stdc++.h>

#include <utility>
#include "DeterministicFiniteAutomata.h"
#include "../../auxiliarmethods/CollectionsOperators.h"
using namespace std;

DeterministicFiniteAutomata::DeterministicFiniteAutomata() : states(), alphabet(), delta(), initialState(), finalStates() {
}
void DeterministicFiniteAutomata::setAlphabet(set<int> alphabet) {
    this->alphabet = std::move(alphabet);
}
set<int> DeterministicFiniteAutomata::getAlphabet() {
    return this->alphabet;
}
void DeterministicFiniteAutomata :: setStates(set<set<int>> states) {
    this->states = std::move(states);
}
void DeterministicFiniteAutomata :: addState(const set<int>& state) {
    this->states.insert(state);
}
void DeterministicFiniteAutomata :: addFinalState(const set<int>& state) {
    this->finalStates.insert(state);
}
set<set<int>> DeterministicFiniteAutomata :: getStates() {
    return this->states;
}
void DeterministicFiniteAutomata :: insertSate(const set<int>& state) {
    this->states.insert(state);
}

void DeterministicFiniteAutomata :: setInitialState(set<int> q) {
    this->initialState = std::move(q);
    this->states.insert(getInitialState());
}
set<int> DeterministicFiniteAutomata :: getInitialState() {
    return this->initialState;
}
void DeterministicFiniteAutomata :: setFinalStates(set<set<int>> final) {
    this->finalStates = std::move(final);
}
set<set<int>> DeterministicFiniteAutomata :: getFinalStates() {
    return this->finalStates;
}
set<int> DeterministicFiniteAutomata :: calculateDelta(const pair<set<int>,int>& key) {
    return delta[key];
}
void DeterministicFiniteAutomata :: addPath(const set<int>& node, int arc, set<int> destination) {
    pair<set<int>,int> path = make_pair(node, arc);
    if(delta.count(path) == 0)
        delta[path] = std::move(destination);
}
bool DeterministicFiniteAutomata :: repOk() {
    bool invariant = true;
    for(const auto& currentSet : states) {
        invariant &= CollectionsOperators::setContained(this->finalStates, currentSet);
        invariant &= CollectionsOperators::contained(this->initialState, currentSet);
    }
    return invariant;
}
set<int> DeterministicFiniteAutomata::calculateWaysToGo(const set<int>& set1, const set<int>& set2) {
    set<int> ret;
    for (int letter : this->alphabet) {
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
    set<int> currentNode = initialState;
    for(char ch : numbers) {
        pair<set<int>, int> key;
        key.first = currentNode;
        key.second = stoi(string(1, ch));
        if(delta.count(key) == 0)
            return false;
        currentNode = calculateDelta(key);
    }
    return isFinalNode(currentNode);
}




