Se probará la entrada, salida y aceptación de cadenas con el siguiente 
automata finito deterministico (AFND):

A = < K, E, D, q0, F > 
donde: 
    K = {3, 4}
    E = {0, 1}
    D = {
        d(3,0) = 4
        d(3,1) = 4
        d(4,1) = 3
        d(4,0) = 4
    }
    q0 = 3
    F = {4}
El automata lee expresiones regulares de la forma (0|1)+0.
Ejemplos de cadenas que acepta son: 
- 0010
- 010
- 110110

----------------------------------------------
COMPILACIÓN 
---------------------------------------------
(1) Para compilar ex1_file_creation.cpp, desde la carpeta del repositorio 
g++ TP/ejemplos_documentados/ex2_file_creation.cpp  TP/automata/dfa/DeterministicFiniteAutomata.cpp TP/automata/ndfa/NotDeterministicFiniteAutomata.cpp TP/parser/Parser.cpp TP/auxiliarmethods/CollectionsOperators.cpp

(2) Para compilar ex2_file_read_and_string_validation.cpp, desde el mismo directorio
g++ TP/ejemplos_documentados/ex2_file_read_and_string_validation.cpp  TP/automata/dfa/DeterministicFiniteAutomata.cpp TP/automata/ndfa/NotDeterministicFiniteAutomata.cpp TP/parser/Parser.cpp TP/auxiliarmethods/CollectionsOperators.cpp TP/automata/convertion/ConvertionOfAutomatas.cpp