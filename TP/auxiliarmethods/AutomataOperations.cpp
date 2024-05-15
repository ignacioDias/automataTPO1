#include "AutomataOperations.h"
#define LAMBDA (-1)


NotDeterministicFiniteAutomata AutomataOperations::nfaUnion(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2)
{
    NotDeterministicFiniteAutomata newAutomata = NotDeterministicFiniteAutomata();
    
    int counter = renameAutomata(a1, 1);
    renameAutomata(a2, counter);

    int newInitialState = 0;
    newAutomata.addState(newInitialState);
    newAutomata.setInitialState(newInitialState); 
    for(auto s: a1.getAlphabet()){
        newAutomata.addSymbolToAlphabet(s); 
    }
    for(auto s: a2.getAlphabet()){
        newAutomata.addSymbolToAlphabet(s); 
    }
    newAutomata.addPath(newInitialState, LAMBDA, 1);
    newAutomata.addPath(newInitialState,LAMBDA,a2.getInitialState());
    for(auto state : a1.getSates())
        newAutomata.addState(state);
    for(auto state : a2.getSates())
        newAutomata.addState(state);
    for(int state: a1.getFinalSates()){
        newAutomata.addFinalState(state);
    }
    for(int state: a2.getFinalSates()){
        newAutomata.addFinalState(state);
    }
    return newAutomata;
}
int AutomataOperations::renameAutomata(NotDeterministicFiniteAutomata a1, int counter) {
    for(auto node : a1.getSates()) {
        if(CollectionsOperators::belongs(counter, a1.getSates())) {
            a1.changeValueState(counter, node);
        } else {
            a1.changeValueState(node, counter);
        }
        counter++;
    }
    return counter;
}
NotDeterministicFiniteAutomata AutomataOperations::nfaConcatenation(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2) {

    int counter = renameAutomata(a1, 0);
    NotDeterministicFiniteAutomata newAutomata = NotDeterministicFiniteAutomata();
    newAutomata.setInitialState(a1.getInitialState());
    for(int s: a1.getAlphabet()){
        newAutomata.addSymbolToAlphabet(s); 
    }
    for(int s: a2.getAlphabet()){
        newAutomata.addSymbolToAlphabet(s); 
    }
    for(int state: a1.getSates()){
        newAutomata.addState(state); 
    }
    renameAutomata(a2, counter);
    for(int state: a2.getSates()){
        newAutomata.addState(state); 
    }
    for(int finalStateOfA1: a1.getFinalSates()){
        newAutomata.addPath(finalStateOfA1, LAMBDA, a2.getInitialState());
    }
    newAutomata.setFinalState(a2.getFinalSates()); 
    return newAutomata;
}

void AutomataOperations::kleeneClosure(NotDeterministicFiniteAutomata a1) {
    NotDeterministicFiniteAutomata kleeneNDA = *new NotDeterministicFiniteAutomata();
    int cant = renameAutomata(a1, 1);
    int newQ0 = 0;
    a1.addState(newQ0);
    a1.addPath(newQ0, LAMBDA, a1.getInitialState());
    a1.setInitialState(newQ0);
}

DeterministicFiniteAutomata AutomataOperations::minimization(DeterministicFiniteAutomata dfa) {
    DeterministicFiniteAutomata kleeneDFA = *new DeterministicFiniteAutomata();
    vector<set<set<int>>> states;
    set<set<int>> dfaFinalStates = dfa.getFinalStates();
    states.push_back(CollectionsOperators::difference(dfa.getStates(), dfaFinalStates));
    states.push_back(dfaFinalStates);
    int previousSize;
    do {
        previousSize = states.size();
        for(auto elem : states) {
            dfa.calculateDelta(auto, letter);
        }
    } while(states.size() != previousSize);
    return kleeneDFA;
}



