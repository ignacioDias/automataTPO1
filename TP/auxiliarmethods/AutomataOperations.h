#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "../automata/dfa/DeterministicFiniteAutomata.h"

class AutomataOperations {
public: 
    static NotDeterministicFiniteAutomata nfaUnion(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2);
    static NotDeterministicFiniteAutomata nfaConcatenation(NotDeterministicFiniteAutomata a1, NotDeterministicFiniteAutomata a2);
    static void kleeneClosure(NotDeterministicFiniteAutomata *a1);
    static DeterministicFiniteAutomata minimization(DeterministicFiniteAutomata dfa);
    static int renameAutomata(NotDeterministicFiniteAutomata *a1, int counter);
private:
    static bool checkSameEquivalenceClass(const set<int>& delta1, set<int> delta2, const vector<set<set<int>>>& states);
};