/**
 * En este programa se probará la función de cargar un automata 
 * por medio de la clase NotDeterministicFiniteAutomata y guardarlo en un archivo. 
 * El automata de ejemplo y las instrucciones de compilación está descrito en ex1_readme.txt 
 * El archivo de salida será automata1.dot 
*/

#include <bits/stdc++.h>
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "../parser/Parser.h"

int main() {
    const int lambda = -1; 
    string filename = "TP/ejemplos_documentados/automata1.dot"; 

    NotDeterministicFiniteAutomata ndfa; 
    ndfa.setAlphabet({0,1}); //a, b
    ndfa.setStates({3,4,5});
    ndfa.setInitialState(3);
    ndfa.addPath(3,0,4);
    ndfa.addPath(3,0,3);
    ndfa.addPath(3,1,3);
    ndfa.addPath(4,lambda,3);
    ndfa.addPath(4,1,5);
    ndfa.addFinalState(5);

    string content = Parser::ndfaToString(ndfa);
    Parser::writeToFile(filename, content);
    return 0;
} 

