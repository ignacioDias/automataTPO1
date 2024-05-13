#include "operacionesTP2.h"
#define LAMBDA -1


NotDeterministicFiniteAutomata AutomataOperations::nfaUnion(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2)
{
    NotDeterministicFiniteAutomata newAutomata = NotDeterministicFiniteAutomata();
    
    //generate new initial state
    int sumLenghtAutomatas = a1.getSates().size() + a2.getSates().size(); 
    int newInitialState = sumLenghtAutomatas;
    while (a1.getSates().count(newInitialState) > 0 || a2.getSates().count(newInitialState) > 0) {
            newInitialState++;
    }

    newAutomata.addState(newInitialState);
    newAutomata.setInitialState(newInitialState); 

    //add states of a1 and a2
    for(int state: a1.getSates()){
        newAutomata.addState(state); 
    }
    for(int state: a1.getSates()){
        newAutomata.addState(state); 
    }
    //add paths from new state
    newAutomata.addPath(newInitialState,LAMBDA,a1.getInitialState());
    newAutomata.addPath(newInitialState,LAMBDA,a2.getInitialState());

    //set final states
    for(int state: a1.getFinalSates()){
        newAutomata.addFinalState(state);
    }
    for(int state: a2.getFinalSates()){
        newAutomata.addFinalState(state);
    }
    
    return newAutomata; 
}

NotDeterministicFiniteAutomata AutomataOperations::nfaConcatenation(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2)
{
    //TODO
    return NotDeterministicFiniteAutomata();
}

NotDeterministicFiniteAutomata AutomataOperations::kleeneClosure(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2)
{
    //TODO
    return NotDeterministicFiniteAutomata();
}

DeterministicFiniteAutomata AutomataOperations::minimization(DeterministicFiniteAutomata dfa)
{
    //TODO
    return DeterministicFiniteAutomata();
}