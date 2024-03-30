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
}

Parser::~Parser() {
}

bool Parser::validateFirstLine(string line){
    return line == "digraph{"; 
}
bool Parser::validateLastLine(string line){
    return line == "}";
}

bool Parser::validateTransitionLine(string line){
    regex regex("\\d+ -> \\d+ \\[label = (\\d+|_)\\]"); //ej: 000 -> 111 [label = _]
    return regex_search(line, regex);
}

bool Parser::validateInitialStateLine(string line){
    regex regex("inic\\[shape = point\\];inic-> \\d+;"); //ej: inic[shape = point];inic-> 000;
    return regex_search(line, regex);
}

bool Parser::validateFinalStateLine(string line){
    regex regex("\\d+\\[shape = doublecircle\\];"); //ej: 111[shape = doublecircle];
    return regex_search(line, regex);
}

void Parser::addInitialStateFromInitialStateLine(string line){
    regex regex("(\\d+)");
    smatch match;
    regex_search(line, match, regex);
    nda.setInitialState(stoi(match[1])); // stoi convierte string a int
}

bool Parser:: isRankdirLine(string line){
    return line == "rankdir=LR;";
}
        
void Parser::addFinalStateFromFinalStateLine(string line){
    regex regex("(\\d+)");
    smatch match;
    regex_search(line, match, regex);
    nda.addFinalState(stoi(match[1]));
}

void Parser::addAutomataInformationFromTransitionLine(string line){
    int const LAMBDA = -1; 
    regex regex("(\\d+) -> (\\d+) \\[label = (\\d+|_)\\]"); // regex("\\d+ -> \\d+ \\[label = (\\d+|_)\\]"); //ej: 000 -> 111 [label = _]
    smatch match;
    regex_search(line, match, regex);
    string symbol = match[3];
    int stateFrom = stoi(match[1]);
    int stateTo = stoi(match[2]);

    if (symbol == "_"){
        nda.addPath(stateFrom, LAMBDA, stateTo);
    } else {
        nda.addPath(stateFrom, stoi(symbol), stateTo);
        nda.addSymbolToAlphabet(stoi(symbol));
    }
    nda.addState(stateFrom);
    nda.addState(stateTo);
}

NotDeterministicFiniteAutomata Parser::getNDA(){
    return nda;
}
