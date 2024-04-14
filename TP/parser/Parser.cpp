#include "Parser.h"
#include <regex> 
#include <bits/stdc++.h>
#include "../automata/dfa/DeterministicFiniteAutomata.h"
#include "../automata/ndfa/NotDeterministicFiniteAutomata.h"

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
    string ret = "digraph{\ninic[shape=point];\ninic->";
    ret += "{\"" + CollectionsOperators::to_string_set(dfa.getInitialState()) + "\"};\n";
    toStringStatesDFA(dfa, ret);
    toStringFinalStateDFA(dfa, ret);
    ret += "\n}";
    return ret;
}
void Parser::toStringStatesDFA(DeterministicFiniteAutomata dfa, string &ret) {
    for(const auto& set1 : dfa.getStates()) {
        if(set1.empty())
            continue;
        for(const auto& set2 : dfa.getStates()) {
            if(set2.empty())
                continue;
            set<int> label = dfa.calculateWaysToGo(set1, set2);
            if(!label.empty()) {
                ret += "\"" + CollectionsOperators::to_string_set(set1) + "\" -> \"" + CollectionsOperators::to_string_set(set2) + "\" [label = \"";
                for(auto elem : label)
                    ret += to_string(elem) + ",";
                ret.pop_back();
                ret += "\"];\n";
            }
        }
    }
}
void Parser :: toStringFinalStateDFA(DeterministicFiniteAutomata dfa, string& ret) {
        ret += "\"" + CollectionsOperators::to_string_set_of_sets(dfa.getFinalStates()) + "\" [shape=doublecircle];\n";
        ret.pop_back();
}
string Parser::ndfaToString(NotDeterministicFiniteAutomata ndfa) {
    string ret = "digraph{\ninic[shape=point];inic -> ";
    ret += to_string(ndfa.getInitialState()) + ";\n";
    NDFATransitionsToString(ndfa, ret);
    toStringFinalStateNDFA(ndfa, ret);
    ret += "\n}";
    return ret;
}
void Parser::NDFATransitionsToString(NotDeterministicFiniteAutomata ndfa, string& ret) {
    const int LAMBDA = -1; 
    for(int number : ndfa.getSates()) {
        for(int number2 : ndfa.getSates()) {
            set<int> label = ndfa.calculateWaysToGo(number,number2);
            if(!label.empty()) {
                ret += to_string(number) + " -> " + to_string(number2) + " [label = \"";
                for(int elem : label){
                    if(elem == LAMBDA){
                        ret += ("_,"); 
                    } else ret += to_string(elem) + ",";
                }     
                ret.pop_back();
                ret += "\"];\n";
            }
        }
    }
}
void Parser :: toStringFinalStateNDFA(NotDeterministicFiniteAutomata ndfa, string& ret) {
    for(int finalState : ndfa.getFinalSates())
        ret += to_string(finalState) + "[shape=doublecircle];\n";
    ret.pop_back();
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