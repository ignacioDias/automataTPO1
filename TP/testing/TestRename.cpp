#include "TestRename.h"
int main() {
    NotDeterministicFiniteAutomata ndfa = *new NotDeterministicFiniteAutomata();
    ndfa.setInitialState(9);
    ndfa.addState(2);
    ndfa.addState(18);
    ndfa.addState(9);
    ndfa.addState(12);
    ndfa.addPath(9, 0, 12);
    ndfa.addPath(12, 0, 18);
    ndfa.addPath(18, 0, 2);
    ndfa.setFinalState({2});
    ndfa.setAlphabet({0});
    cout << NDFAToString::ndfaToString(ndfa);
    AutomataOperations::renameAutomata(&ndfa, 0);
    cout << NDFAToString::ndfaToString(ndfa);

}
