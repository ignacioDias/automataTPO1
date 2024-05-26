#include "TestRename.h"
int main() {
    NotDeterministicFiniteAutomata ndfa = *new NotDeterministicFiniteAutomata();
    ndfa.setInitialState(9);
    ndfa.addState(2);
    ndfa.addState(1);
    ndfa.addState(9);
    ndfa.addState(12);
    ndfa.addPath(9, 1, 12);
    ndfa.addPath(2, 0, 1);
    ndfa.addPath(12, 0, 2);
    ndfa.setFinalState({2});
    ndfa.setAlphabet({0,1});

    std::cout << NDFAToString::ndfaToString(ndfa) << std::endl;

    AutomataOperations::renameAutomata(&ndfa, 1);

    std::cout << NDFAToString::ndfaToString(ndfa) << std::endl;

}
