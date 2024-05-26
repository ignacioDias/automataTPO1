#include "AutomataOperations.h"
#define LAMBDA (-1)


NotDeterministicFiniteAutomata AutomataOperations::nfaUnion(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2) {
    NotDeterministicFiniteAutomata newAutomata;
    int counter = renameAutomata(&a1, 1);
    renameAutomata(&a2, counter);
    int newInitialState = 0;
    newAutomata.addState(newInitialState);
    newAutomata.setInitialState(newInitialState);
    for(auto s: a1.getAlphabet())
        newAutomata.addSymbolToAlphabet(s);
    for(auto s: a2.getAlphabet())
        newAutomata.addSymbolToAlphabet(s);
    newAutomata.addPath(newInitialState, LAMBDA, a1.getInitialState());
    newAutomata.addPath(newInitialState, LAMBDA, a2.getInitialState());
    for(auto state : a1.getStates())
        newAutomata.addState(state);
    for(auto state : a2.getStates())
        newAutomata.addState(state);
    for(const auto& [from, destinations] : a1.getTransitions()) {
        for(auto destination : destinations)
            newAutomata.addPath(from.first, from.second, destination);
    }
    for(const auto& [from, destinations] : a2.getTransitions()) {
        for(auto destination : destinations)
                newAutomata.addPath(from.first, from.second, destination);
    }
    for(auto state : a1.getFinalStates())
        newAutomata.addFinalState(state);
    for(auto state : a2.getFinalStates())
        newAutomata.addFinalState(state);
    return newAutomata;
}
int AutomataOperations::renameAutomata(NotDeterministicFiniteAutomata *a1, int counter) {
    for(auto node : a1->getStates()) {
        if(CollectionsOperators::belongs(counter, a1->getStates())) {
            a1->changeValueState(counter, node + 200); //solución horrible, no se me ocurrió una mejor, si el usuario pone 201 y 1, se rompe
            a1->changeValueState(node + 200, counter);
        } else
            a1->changeValueState(node, counter);
        counter++;
    }
    return counter;
}
NotDeterministicFiniteAutomata AutomataOperations::nfaConcatenation(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2) {
    int counter = renameAutomata(&a1, 0);
    NotDeterministicFiniteAutomata newAutomata = NotDeterministicFiniteAutomata();
    newAutomata.setInitialState(a1.getInitialState());
    for(int s: a1.getAlphabet()){
        newAutomata.addSymbolToAlphabet(s); 
    }
    for(int s: a2.getAlphabet()){
        newAutomata.addSymbolToAlphabet(s); 
    }
    for(int state: a1.getStates()){
        newAutomata.addState(state); 
    }
    renameAutomata(&a2, counter);
    for(int state: a2.getStates()){
        newAutomata.addState(state); 
    }
    for(int finalStateOfA1: a1.getFinalStates()){
        newAutomata.addPath(finalStateOfA1, LAMBDA, a2.getInitialState());
    }
    newAutomata.setFinalState(a2.getFinalStates());
    for(const auto& [from, destinations] : a1.getTransitions()) {
        for(auto destination : destinations) {
            newAutomata.addPath(from.first, from.second, destination);
        }
    }
    for(const auto& [from, destinations] : a2.getTransitions()) {
        for(auto destination : destinations) {
            newAutomata.addPath(from.first, from.second, destination);
        }
    }
    return newAutomata;
}

void AutomataOperations::kleeneClosure(NotDeterministicFiniteAutomata *a1) {
    NotDeterministicFiniteAutomata kleeneNDA = *new NotDeterministicFiniteAutomata();
    int cant = renameAutomata(a1, 1);
    int newQ0 = 0;
    a1->addState(newQ0);
    a1->addPath(newQ0, LAMBDA, a1->getInitialState());
    a1->setInitialState(newQ0);
}
DeterministicFiniteAutomata AutomataOperations::minimization(DeterministicFiniteAutomata dfa) {
    DeterministicFiniteAutomata minimizedAutomata = *new DeterministicFiniteAutomata();
    vector<set<set<int>>> states;
    set<set<int>> dfaFinalStates = dfa.getFinalStates();
    states.push_back(CollectionsOperators::difference(dfa.getStates(), dfaFinalStates));
    states.push_back(dfaFinalStates);
    vector<set<set<int>>> statesPrime;
    bool changePartition = false;
    while(!changePartition) {
        for(const auto& state : states) { //X = state
            for(const auto& elem : state) { // e = elem
                set<set<int>> xPrime = {elem};
                for(const auto& elemPrime : state) {
                    bool equalDeltas = true;
                    for (auto letter: dfa.getAlphabet()) {
                        if (checkSameEquivalenceClass(dfa.calculateDelta(make_pair(elem, letter)),dfa.calculateDelta(make_pair(elemPrime, letter)), states)) {
                            equalDeltas = false;
                            break;
                        }
                    } //for letter in alphabet
                    if (equalDeltas)
                        xPrime.insert(elemPrime);
                } // for e' in state
                statesPrime.push_back(xPrime);
            } // for e in X
            if(states != statesPrime) {
                states = statesPrime;
                statesPrime = {};
            } else {
                changePartition = true;
            }
        } //for state in states
    } //while
    for(auto elem : states) {
        set<int> actualState = CollectionsOperators::getElem(elem);
        if(CollectionsOperators::setContained(elem, dfa.getInitialState()))
            minimizedAutomata.setInitialState(actualState);
        if(CollectionsOperators::setOfSetContainedInOther(elem, dfa.getFinalStates()))
            minimizedAutomata.addFinalState(actualState);
        minimizedAutomata.addState(actualState);
        for(const auto& elem2 : states) {
            set<int> destinationState = CollectionsOperators::getElem(elem2);
            set<int> letters = dfa.calculateWaysToGo(actualState, destinationState);
            for(auto letter : letters) {
                minimizedAutomata.addPath(actualState, letter, destinationState);
            }
        }
    }
    minimizedAutomata.setAlphabet(dfa.getAlphabet());
    return minimizedAutomata;
}
bool AutomataOperations :: checkSameEquivalenceClass(const set<int>& delta1, set<int> delta2, const vector<set<set<int>>>& states) {
    for(const auto& state : states) {
        if(CollectionsOperators::setContained(state, delta1) && !CollectionsOperators::setContained(state, delta2))
            return false;
        if(CollectionsOperators::setContained(state, delta2) && !CollectionsOperators::setContained(state, delta1))
            return false;
    }
    return true;
}



