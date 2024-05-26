Se probará la entrada, salida y aceptación de cadenas con el siguiente 
automata finito no deterministico (AFND): 

A = < states, alphabet, D, initialState, finalStates >
donde: 
    states = {3, 4, 5}
    alphabet = {0, 1}
    D = {
        delta(3,0) = 4
        delta(3,0) = 3
        delta(3,1) = 3
        delta(4,_) = 3
        delta(4,1) = 5
    }
    initialState = 3
    finalStates = {5}
El automata lee expresiones regulares de la forma ((0|1)*0)+1. 
Ejemplos de cadenas que acepta son: 
- 001
- 01 
- 1101101

----------------------------------------------
COMPILACIÓN 
---------------------------------------------
(1) Para compilar ex1_file_creation.cpp, desde la carpeta del repositorio 
g++ TP/ejemplos_documentados/ex1_file_creation.cpp  TP/automata/dfa/DeterministicFiniteAutomata.cpp TP/automata/ndfa/NotDeterministicFiniteAutomata.cpp TP/parser/Parser.cpp TP/auxiliarmethods/CollectionsOperators.cpp

(2) Para compilar ex1_file_read_and_string_validation.cpp, desde el mismo directorio
g++ TP/ejemplos_documentados/ex1_file_read_and_string_validation.cpp  TP/automata/dfa/DeterministicFiniteAutomata.cpp TP/automata/ndfa/NotDeterministicFiniteAutomata.cpp TP/parser/Parser.cpp TP/auxiliarmethods/CollectionsOperators.cpp TP/automata/convertion/ConvertionOfAutomatas.cpp