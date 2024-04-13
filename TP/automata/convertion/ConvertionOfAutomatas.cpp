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
    using dfaState = set<int>;
    using ndfaState = int; 

    dfaState newInitialState = getLambdaClosure({ndfa.getInitialState()});
    dfa.setInitialState(newInitialState);
    dfa.setAlphabet(ndfa.getAlphabet());

    set<dfaState> unmarkedStates;
    set<dfaState> dfaStates;  

    unmarkedStates.insert(newInitialState);
    dfaStates.insert(newInitialState);  
    while(!unmarkedStates.empty()){
        for(auto it = unmarkedStates.begin(); it != unmarkedStates.end();) {
            dfaState S = *it; //evita segmentation fault 
            it = unmarkedStates.erase(it);
            for(int symbol: ndfa.getAlphabet()){
                dfaState M = getLambdaClosure(move(S, symbol));
                //if M not in T
                if(dfaStates.find(M) == dfaStates.end()){
                    unmarkedStates.insert(M); 
                    dfaStates.insert(M); 
                }
                dfa.addPath(S,symbol,M); 
            }
        }
    }
    dfa.setStates(dfaStates); 
    dfa.setFinalStates(calculateFinal(dfa.getStates()));
}

set<int> ConvertionOfAutomatas::getLambdaClosure(const set<int>& Q) {
    using state = int;
    set<state> result;
    set<state> visited_states;
    set<state> unvisited_states = Q;
    
    while (!unvisited_states.empty()) {
        int curr_state = *unvisited_states.begin();
        unvisited_states.erase(curr_state);
        visited_states.insert(curr_state);
        set<int> reachable_states = getLambdaReachableStates(curr_state);
        result.insert(curr_state);
        for (int reachable_state : reachable_states) {
            result.insert(reachable_state);
            if (visited_states.find(reachable_state) == visited_states.end())
                unvisited_states.insert(reachable_state);
        }
    }
    return result;
}

set<int> ConvertionOfAutomatas::getLambdaReachableStates(int state) {
    set<int> result;
    queue<int> to_visit;
    set<int> visited;

    to_visit.push(state);
    visited.insert(state);

    while (!to_visit.empty()) {
        int current_state = to_visit.front();
        to_visit.pop();
        set<int> lambda_reachable_states = ndfa.calculateDelta({current_state, LAMBDA});
        for (int lambda_reachable_state : lambda_reachable_states) {
            if (visited.find(lambda_reachable_state) == visited.end()) {
                result.insert(lambda_reachable_state);
                to_visit.push(lambda_reachable_state);
                visited.insert(lambda_reachable_state);
            }
        }
    }

    return result;
}

set<int> ConvertionOfAutomatas :: move(set<int> states, int symbol) {
    using state = int; 
    set<state> result;
    for(state s: states) {
        set<state> possibleMovements = ndfa.calculateDelta(make_pair(s,symbol));
        for(state s: possibleMovements){
            result.insert(s); 
        }
    }
    return result;
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

void showStates(set<set<int>> states){
    using dfaState = set<int>;
    using ndfaState = int; 
    using std::cout; 
    for(dfaState state: states){
        for(int substate: state){
            cout << substate << ' ';
        }
    }
}