#include "../automata/dfa/DeterministicFiniteAutomata.h"
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "../automata/convertion/ConvertionOfAutomatas.h"

int main(){
    using std::cout; 
    NotDeterministicFiniteAutomata ndfa; 

    ConvertionOfAutomatas conversor;
    ndfa.setInitialState(10);
    ndfa.setAlphabet({1,2}); //a, b
    ndfa.setStates({10,11,12,13});
    ndfa.addPath(10,1,11);
    ndfa.addPath(10,-1,11);
    ndfa.addPath(11,-1,12); 
    ndfa.addPath(11,2,11);
    ndfa.addPath(11,2,12);
    ndfa.addPath(11,1,13);
    ndfa.addPath(13,1,13);
    ndfa.addPath(13,2,13);
    ndfa.addFinalState(12);
    conversor.setNDFA(ndfa);  

    set<int> clausura = conversor.move({11},2);
    for (int state : clausura){
        std::cout << state << ' ';
    }
}
