#include <bits/stdc++.h>
#include "automata/dfa/DeterministicFiniteAutomata.h"
#include "automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "parser/Parser.h"
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
    ndfa.setInitialState(0);
    ndfa.setE({1,2});
    ndfa.setK({0,1,2,3});
    ndfa.addPath(0,1,1); 
    ndfa.addPath(1,2,1);
    ndfa.addPath(1,2,2); 
    ndfa.addPath(1,1,3);
    ndfa.addPath(3,1,3);
    ndfa.addPath(3,2,3); 
    ndfa.addFinalState(2); 
    
    Parser parser; 
    std::cout << parser.ndfaToFile(ndfa); 

    return 0;
} 