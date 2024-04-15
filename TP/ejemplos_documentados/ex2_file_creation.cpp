/**
 * En este programa se probará la función de cargar un automata
 * por medio de la clase DeterministicFiniteAutomata y guardarlo en un archivo.
 * El automata de ejemplo y las instrucciones de compilación está descrito en ex2_readme.txt
 * El archivo de salida será automata2.dot
*/

#include <bits/stdc++.h>
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "../parser/Parser.h"

int main() {
    string filename = "TP/ejemplos_documentados/automata2.dot";

    NotDeterministicFiniteAutomata ndfa;
    ndfa.setAlphabet({0,1}); //a, b
    ndfa.setStates({3, 4});
    ndfa.setInitialState(3);
    ndfa.addPath(3,0,4);
    ndfa.addPath(3,1,4);
    ndfa.addPath(4,0,4);
    ndfa.addPath(4,1,3);
    ndfa.addFinalState(4);

    string content = Parser::ndfaToString(ndfa);
    Parser::writeToFile(filename, content);
    return 0;
}

