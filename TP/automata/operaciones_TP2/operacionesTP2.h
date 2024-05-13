#include "../ndfa/NotDeterministicFiniteAutomata.h"
#include "../dfa/DeterministicFiniteAutomata.h"

class AutomataOperations{
public: 
    static NotDeterministicFiniteAutomata nfaUnion(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2);
    static NotDeterministicFiniteAutomata nfaConcatenation(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2);
    static NotDeterministicFiniteAutomata kleeneClosure(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2);

    static DeterministicFiniteAutomata minimization(DeterministicFiniteAutomata dfa); 
};