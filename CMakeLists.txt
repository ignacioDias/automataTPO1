cmake_minimum_required(VERSION 3.27)
project(tpOb1)

set(CMAKE_CXX_STANDARD 14)

add_executable(tpOb1
        TP/DFA/AutomataInterface.cpp
        TP/DFA/NotDeterministicFiniteAutomata.cpp
        TP/DFA/DeterministicFiniteAutomata.cpp)
