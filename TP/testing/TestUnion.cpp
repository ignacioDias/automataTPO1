#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "../auxiliarmethods/AutomataOperations.h"
#include "../parser/automata-to-string/ndfa/NDFAToString.h"
int main() {
    NotDeterministicFiniteAutomata ndfa = *new NotDeterministicFiniteAutomata();
    ndfa.setAlphabet({0,1});
    ndfa.setInitialState(0);
    ndfa.setStates({0,1});
    ndfa.addPath(0, 1,1);
    ndfa.addPath(1,0,1);
    ndfa.addPath(1,1,1);
    ndfa.addFinalState(1);

    NotDeterministicFiniteAutomata ndfa2 = *new NotDeterministicFiniteAutomata();
    ndfa.setAlphabet({0,1});
    ndfa.setStates({0,1});
    ndfa.addPath(0, 1,1);

    NotDeterministicFiniteAutomata ndfaUnion = AutomataOperations::nfaConcatenation(ndfa, ndfa2);
    cout << NDFAToString::ndfaToString(ndfaUnion);

}