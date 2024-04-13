#include <bits/stdc++.h>
#include "../automata/dfa/DeterministicFiniteAutomata.h"
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "../parser/Parser.h"
using namespace std;

int main() {
    string filename = "TP/testing/output.txt"; 

    NotDeterministicFiniteAutomata ndfa; 
    ndfa.setInitialState(10);
    ndfa.setE({1,2}); //a, b
    ndfa.setK({10,11,12,13});
    ndfa.addPath(10,1,11);
    ndfa.addPath(11,2,11);
    ndfa.addPath(11,2,12);
    ndfa.addPath(11,1,13);
    ndfa.addPath(13,1,13);
    ndfa.addPath(13,2,13);
    ndfa.addFinalState(12);


    string content = Parser::ndfaToString(ndfa);
    Parser::writeToFile(filename, content);
    return 0;
} 