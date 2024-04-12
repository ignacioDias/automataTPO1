//
// Created by ignaciodias on 12/04/24.
//
#define LAMBDA -1
#include "ConvertionOfAutomatas.h"
ConvertionOfAutomatas :: ConvertionOfAutomatas() : ndfa(), dfa(){
}
void ConvertionOfAutomatas :: setNDFA(NotDeterministicFiniteAutomata ndfa) {
    this->ndfa = ndfa;
}
void ConvertionOfAutomatas :: setDFA(DeterministicFiniteAutomata dfa) {
    this->dfa = std::move(dfa);
}
DeterministicFiniteAutomata ConvertionOfAutomatas :: getDFA() {
    return dfa;
}
void ConvertionOfAutomatas :: convertFromNDFA() {
    set<int> q0AsSet;
    q0AsSet.insert(ndfa.getInitialState());
    set<int> Q0 = getSymbolClosure(q0AsSet);
    dfa.setInitialState(Q0);
    set<set<int>> newK;
    newK.insert(Q0);

    dfa.setAlphabet(ndfa.getAlphabet());

    dfa.setStates(newK);
    calculateNewK();
    dfa.setFinalStates(calculateFinal(dfa.getStates()));
}
void ConvertionOfAutomatas::calculateNewK() {
    set<set<int>> unvisitedNodes = dfa.getStates();
    while(!unvisitedNodes.empty()) {
        auto currentNode = *unvisitedNodes.begin();
        for (auto currentNumber : ndfa.getAlphabet()) {
            set<int> currentSet = move(currentNode, currentNumber);
            currentSet = getSymbolClosure(currentSet);
            if (dfa.getStates().count(currentSet) <= 0) {
                dfa.insertSate(currentSet);
                unvisitedNodes.insert(currentSet);
                dfa.addPath(currentNode, currentNumber, currentSet);
            }
        }
        unvisitedNodes.erase(currentNode);
    }
}
set<int> ConvertionOfAutomatas::getSymbolClosure(const set<int>& Q) {
    set<int> result;
    set<int> visited_states;
    set<int> unvisited_states = Q;
    while (!unvisited_states.empty()) {
        int curr_state = *unvisited_states.begin();
        unvisited_states.erase(curr_state);
        visited_states.insert(curr_state);
        set<int> reachable_states = ndfa.calculateDelta({curr_state, LAMBDA});
        if(reachable_states.empty())
            result.insert(curr_state);
        for (int reachable_state : reachable_states) {
            result.insert(reachable_state);
            if (visited_states.find(reachable_state) == visited_states.end())
                unvisited_states.insert(reachable_state);
        }
    }
    return result;
}
set<int> ConvertionOfAutomatas :: move(const set<int>& Q, int a) {
    set<int> ret;
    for(auto elem : Q) {
        pair<int,int> actualPair;
        actualPair.first = elem;
        actualPair.second = a;
        set<int> actualSet = ndfa.calculateDelta(actualPair);
        if(!actualSet.empty())
            CollectionsOperators::insertAll(ret, actualSet);
    }
    return ret;
}

set<set<int>> ConvertionOfAutomatas :: calculateFinal(const set<set<int>>& k) {
    set<set<int>> newF;
    for(const auto& currentSet : k) {
        for(auto currentNumber : currentSet) {
            if(ndfa.getFinalSates().count(currentNumber) > 0) {
                newF.insert(currentSet);
                break;
            }
        }
    }
    return newF;
}
