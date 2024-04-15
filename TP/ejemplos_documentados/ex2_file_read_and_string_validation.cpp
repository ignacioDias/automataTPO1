/**
 * En este programa se probará la función de cargar un automata 
 * por medio de un archivo de texto y comprobará si algunas cadenas pertenecen al lenguaje. 
 * El automata de ejemplo está descrito en ex2_readme.txt
 * El archivo de entrada será automata2.dot
*/

#include <bits/stdc++.h>
#include "../automata/dfa/DeterministicFiniteAutomata.h"
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "../automata/convertion/ConvertionOfAutomatas.h"
#include "../parser/Parser.h"
using namespace std;

const string filename = "TP/ejemplos_documentados/automata2.dot";

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
    cout << "Automata leido correcamente"; 

    NotDeterministicFiniteAutomata nda = parser.getNDA();
    ConvertionOfAutomatas conversor; 
    conversor.setNDFA(nda);
    DeterministicFiniteAutomata dfa;
    conversor.setDFA(dfa); 
    conversor.convertFromNDFA();
    dfa = conversor.getDFA(); 

    vector<string> strings = {"0010", "010", "110110", "0001000"};
    for(string s: strings){
        if(dfa.checkValidString(s))
            cout << "La cadena " << s << " es aceptada por el automata." << endl; 
        else
            cout << "La cadena " << s << " no es aceptada por el automata." << endl; 
    }
}