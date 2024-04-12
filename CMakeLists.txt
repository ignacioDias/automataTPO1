cmake_minimum_required(VERSION 3.27)
project(tpOb1)

set(CMAKE_CXX_STANDARD 14)

add_executable(tpOb1
        TP/automata/ndfa/NotDeterministicFiniteAutomata.cpp
        TP/automata/dfa/DeterministicFiniteAutomata.cpp
        TP/automata/AutomataInterface.h
        TP/automata/dfa/DeterministicFiniteAutomata.h
        TP/automata/ndfa/NotDeterministicFiniteAutomata.h
        TP/auxiliarmethods/CollectionsOperators.h
        TP/auxiliarmethods/CollectionsOperators.cpp
        TP/Main.cpp
        TP/parser/Parser.h
        TP/parser/Parser.cpp
        TP/automata/convertion/ConvertionOfAutomatas.h
        TP/automata/convertion/ConvertionOfAutomatas.cpp)
