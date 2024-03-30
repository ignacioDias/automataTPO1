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

bool Parser::validateFirstLine(std::string line){
    return line == "digraph{"; 
}
bool Parser::validateLastLine(std::string line){
    return line == "}";
}

bool Parser::validateTransitionLine(std::string line){
    std::regex regex("\\d+ -> \\d+ \\[label = (\\d+|_)\\]"); //ej: 000 -> 111 [label = _]
    return std::regex_search(line, regex);
}

bool Parser::validateInitialStateLine(std::string line){
    std::regex regex("inic\\[shape = point\\];inic-> \\d+;"); //ej: inic[shape = point];inic-> 000;
    return std::regex_search(line, regex);
}

bool Parser::validateFinalStateLine(std::string line){
    std::regex regex("\\d+\\[shape = doublecircle\\];"); //ej: 111[shape = doublecircle];
    return std::regex_search(line, regex);
}

void Parser::addInitialStateFromInitialStateLine(std::string line){
    std::regex regex("(\\d+)");
    std::smatch match; 
    std::regex_search(line, match, regex);
    nda.setInitialState(std::stoi(match[1])); // stoi convierte string a int
}

bool Parser:: isRankdirLine(std::string line){
    return line == "rankdir=LR;";
}
        
void Parser::addFinalStateFromFinalStateLine(std::string line){
    std::regex regex("(\\d+)");
    std::smatch match; 
    std::regex_search(line, match, regex);
    nda.addFinalState(std::stoi(match[1]));
}

void Parser::addAutomataInformationFromTransitionLine(std::string line){
    int const LAMBDA = -1; 
    std::regex regex("(\\d+) -> (\\d+) \\[label = (\\d+|_)\\]"); // regex("\\d+ -> \\d+ \\[label = (\\d+|_)\\]"); //ej: 000 -> 111 [label = _]
    std::smatch match; 
    std::regex_search(line, match, regex);
    string symbol = match[3];
    int stateFrom = std::stoi(match[1]);
    int stateTo = std::stoi(match[2]);

    if (symbol == "_"){
        nda.addPath(stateFrom, LAMBDA, stateTo);
    } else {
        nda.addPath(stateFrom, std::stoi(symbol), stateTo);
        nda.addSymbolToAlphabet(std::stoi(symbol));
    }
    nda.addState(stateFrom);
    nda.addState(stateTo);
}

NotDeterministicFiniteAutomata Parser::getNDA(){
    return nda;
}
