cmake_minimum_required(VERSION 3.27)
project(tpOb1)

set(CMAKE_CXX_STANDARD 14)

add_executable(tpOb1
        TP/automata/ndfa/NotDeterministicFiniteAutomata.cpp
        TP/automata/dfa/DeterministicFiniteAutomata.cpp
        TP/automata/dfa/DeterministicFiniteAutomata.h
        TP/automata/ndfa/NotDeterministicFiniteAutomata.h
        TP/auxiliarmethods/CollectionsOperators.h
        TP/auxiliarmethods/CollectionsOperators.cpp
        TP/parser/Parser.h
        TP/parser/Parser.cpp
        TP/automata/convertion/ConvertionOfAutomatas.h
        TP/automata/convertion/ConvertionOfAutomatas.cpp
        TP/testing/fileToNdfa.cpp
        TP/testing/fileToNdfa.cpp
        TP/testing/fileToNdfa.cpp
        TP/testing/ndfaToFile.cpp
        TP/testing/testClausuraLambda.cpp
        TP/testing/testMover.cpp
        TP/testing/testParserFunctions.cpp
        TP/parser/automata-to-string/ndfa/NDFAToString.h
        TP/parser/automata-to-string/ndfa/NDFAToString.cpp
        TP/ejemplos_documentados/ex1_file_creation.cpp
        TP/ejemplos_documentados/ex1_file_read_and_string_validation.cpp
        TP/ejemplos_documentados/ex2_file_creation.cpp
        TP/ejemplos_documentados/ex2_file_read_and_string_validation.cpp
        TP/ejemplos_documentados/ex2_file_creation.cpp
        TP/parser/automata-to-string/dfa/DFAToString.h
        TP/parser/automata-to-string/dfa/DFAToString.cpp
        TP/auxiliarmethods/AutomataOperations.cpp
        TP/auxiliarmethods/AutomataOperations.h
        TP/testing/TestRename.h
        TP/testing/TestRename.cpp
        TP/testing/TestUnion.cpp
)
