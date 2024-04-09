#include <bits/stdc++.h>
#include "../automata/dfa/DeterministicFiniteAutomata.h"
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "../parser/Parser.h"
using namespace std;

const string filename = "TP/testing/input.txt";

int main() {
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

    //NotDeterministicFiniteAutomata nda = parser.getNDA(); 
    //nda.show(); //TODO: IMPLEMENTAR 
}