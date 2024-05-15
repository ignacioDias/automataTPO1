#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "../automata/dfa/DeterministicFiniteAutomata.h"

class AutomataOperations {
public: 
    static NotDeterministicFiniteAutomata nfaUnion(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2);
    static NotDeterministicFiniteAutomata nfaConcatenation(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2);
    static void kleeneClosure(NotDeterministicFiniteAutomata a1);
    static DeterministicFiniteAutomata minimization(DeterministicFiniteAutomata dfa);
private:
    static int renameAutomata(NotDeterministicFiniteAutomata a1, int counter);
};