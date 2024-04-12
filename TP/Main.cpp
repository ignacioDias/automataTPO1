#include <bits/stdc++.h>
#include "automata/dfa/DeterministicFiniteAutomata.h"
#include "automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "parser/Parser.h"
#include "automata/convertion/ConvertionOfAutomatas.h"
using namespace std;

int main() {
    /**
    string filename = "archivo.txt"; // Nombre del archivo
    ifstream file(filename);     // Abrir el archivo
    Parser parser = *new Parser();

    if (!file.is_open()) {     // Verificar si el archivo se abrió correctamente
        cerr << "No se pudo abrir el archivo." << endl;
        return -1;
    }

    string line;

    if (!getline(file, line)) { // Leer la primera línea
        cerr << "No se pudo leer la primera línea." << endl;
        return -1;
    }
    if(!Parser::validateFirstLine(line)){
        cerr << "Formato invalido del archivo." << endl;
        return -1;
    }

    while (getline(file, line)) {
        parser.fileManagement(line);
    }

    file.close();
    */

    NotDeterministicFiniteAutomata ndfa; 
    ndfa.setInitialState(10);
    ndfa.setAlphabet({-1, 1, 2}); //a, b
    ndfa.setStates({10, 11, 12, 13});
    ndfa.addPath(10,1,11);
    ndfa.addPath(11,2,11);
    ndfa.addPath(11,2,12);
    ndfa.addPath(11,1,13);
    ndfa.addPath(13,1,13);
    ndfa.addPath(13,2,13);
    ndfa.addFinalState(12);
//    cout << Parser::ndfaToString(ndfa);
    ConvertionOfAutomatas convertor;
    convertor.setNDFA(ndfa);
    convertor.convertFromNDFA();
    cout << Parser::dfaToString(convertor.getDFA());
return 0;
}
