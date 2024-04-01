#include "Parser.h"
#include <regex> 
#include <bits/stdc++.h>
#include "../automata/dfa/DeterministicFiniteAutomata.h"
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"

using namespace std;

void Parser :: identifyFormat(const string& line) {
// q− > r[label = a]
    cout << "implement";
   // if(checkDelta(line))
//        NotDeterministicFiniteAutomata::addPath();
}

bool Parser :: checkDelta(const string& line) {
    return true; //TODO: IMPLEMENTAR
}

Parser::Parser() {
    NotDeterministicFiniteAutomata nda;
    bool readLastLine = false;
}

bool Parser::validateFirstLine(const string& line){
    return line == "digraph{"; 
}
bool Parser::validateLastLine(const string& line){
    return line == "}";
}

bool Parser::validateTransitionLine(const string& line){
    regex regex(R"(\d+ -> \d+ \[label = (\d+|_)(,\d+|_)*\])"); //ej: 000 -> 111 [label = _]
    return regex_search(line, regex);
}

bool Parser::validateInitialStateLine(string line){
    regex regex(R"(inic\[shape = point\];inic-> \d+;)"); //ej: inic[shape = point];inic-> 000;
    return regex_search(line, regex);
}

bool Parser::validateFinalStateLine(const string& line){
    regex regex(R"(\d+\[shape = doublecircle\];)"); //ej: 111[shape = doublecircle];
    return regex_search(line, regex);
}

void Parser::addInitialStateFromInitialStateLine(const string& line){
    regex regex("(\\d+)");
    smatch match;
    regex_search(line, match, regex);
    nda.setInitialState(stoi(match[1])); // stoi convierte string a int
}

bool Parser:: isRankdirLine(const string& line){
    return line == "rankdir=LR;";
}

void Parser::addFinalStateFromFinalStateLine(const string& line){
    regex regex("(\\d+)");
    smatch match;
    regex_search(line, match, regex);
    nda.addFinalState(stoi(match[1]));
}

void Parser::addAutomataInformationFromTransitionLine(string line){
    int const LAMBDA = -1; 
    regex regex(R"(\d+ -> \d+ \[label = (\d+|_)(,\d+|_)*\])"); // regex("\\d+ -> \\d+ \\[label = (\\d+|_)\\]"); //ej: 000 -> 111 [label = _]
    smatch match;
    regex_search(line, match, regex);
    int stateFrom = stoi(match[1]);
    int stateTo = stoi(match[2]);

    for(int i = 3; i < match.size(); i++){
        string symbol = match[i];
        if (symbol == "_"){
            nda.addSymbolToAlphabet(LAMBDA);
            nda.addPath(stateFrom, LAMBDA, stateTo);
        } else{
            nda.addSymbolToAlphabet(stoi(symbol));
            nda.addPath(stateFrom, stoi(symbol), stateTo);
        }
    }
    nda.addState(stateFrom);
    nda.addState(stateTo);
}

NotDeterministicFiniteAutomata Parser::getNDA(){
    return nda;
}

void Parser::fileManagement(const string& line) {
    if (validateTransitionLine(line))
        addAutomataInformationFromTransitionLine(line);
    else if (validateInitialStateLine(line))
        addInitialStateFromInitialStateLine(line);
    else if (validateFinalStateLine(line)) {
        addFinalStateFromFinalStateLine(line);
        readLastLine = true; 
    } else if(!isRankdirLine(line) || line == "}" && readLastLine)
        throw runtime_error("Formato invalido del archivo.");
}
