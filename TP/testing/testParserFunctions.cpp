#include <iostream>
#include <vector>
#include <string>
#include "../parser/Parser.h"

int main() {
    std::string line1 = "10 -> 11 [label = \"1\"];"; 
    std::string line2 = "13 -> 13 [label = \"1,2\"];";
    std::string line3 = "20 -> 10 [label = \"1,_\"]";
    std::vector<std::string> lines = {line1, line2, line3}; // Usando vector en lugar de array
    Parser parser; 
    for(std::string s : lines){
        if(parser.validateTransitionLine(s)){
            std::cout << "Valida"; 
            parser.addAutomataInformationFromTransitionLine(s); 
        } else {
            std::cout << "Invalida"; 
        }
    }
    return 0; // Asegúrate de devolver 0 al finalizar main
}