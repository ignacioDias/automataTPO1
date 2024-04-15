#include "Parser.h"
#include <regex> 
#include <utility>
#include <bits/stdc++.h>
#include "../automata/dfa/DeterministicFiniteAutomata.h"
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"
#include "automata-to-string/ndfa/NDFAToString.h"
#include "automata-to-string/dfa/DFAToString.h"

using namespace std;

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
    regex regex(R"(\d+\s*->\s*\d+\s*\[label\s*=\s*("[^"]*"|_)(,"[^"]*"|_)*\])");
    return regex_search(line, regex);
}

bool Parser::validateInitialStateLine(string line){
    regex regex(R"(inic\[shape\s*=\s*point\];\s*inic\s*->\s*\d+;)"); //ej: inic[shape = point];inic-> 000;
    return regex_search(line, regex);
}

bool Parser::validateFinalStateLine(const string& line){
    regex regex(R"(\d+\[shape\s*=\s*doublecircle\];)"); //ej: 111[shape = doublecircle];
    return regex_search(line, regex);
}

void Parser::addInitialStateFromInitialStateLine(const string& line){
    regex regex(R"(\d+)");
    smatch match;
    regex_search(line, match, regex);
    nda.setInitialState(stoi(match[0])); // stoi convierte string a int
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
    std::regex regex(R"(\d+|_)");
    std::sregex_iterator iter(line.begin(), line.end(), regex);
    std::sregex_iterator end;

    std::smatch match = *iter;
    int stateFrom = std::stoi(match.str());
    ++iter;

    match = *iter;
    int stateTo = std::stoi(match.str());
    ++iter;
    
    for (; iter != end; ++iter) {
        match = *iter;
        std::string symbol = match.str();
        if (symbol == "_"){
            nda.addSymbolToAlphabet(LAMBDA);
            nda.addPath(stateFrom, LAMBDA, stateTo);
        } else{
            nda.addSymbolToAlphabet(std::stoi(symbol));
            nda.addPath(stateFrom, std::stoi(symbol), stateTo);
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
    }else if(line == "}" && !readLastLine){
        readLastLine = true; 
    } else if (line == "}" && readLastLine)  throw runtime_error("Ya se ha detectado el fin del archivo");
    else if(!isRankdirLine(line)) throw runtime_error("Linea no reconocida: " + line);
}
string Parser::dfaToString(DeterministicFiniteAutomata dfa) {
    return DFAToString::dfaToString(std::move(dfa));
}

string Parser::ndfaToString(NotDeterministicFiniteAutomata ndfa) {
    return NDFAToString::ndfaToString(std::move(ndfa));
}

void Parser::writeToFile(const string& filename, const string& content){
    ofstream outputFile(filename); // Create an ofstream object for writing
    if (outputFile.is_open()) { // Check if file opening succeeded
        outputFile << content; // Write the content to the file
        outputFile.close(); // Close the file
        cout << "Content has been written to the file successfully." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
}