#ifndef TPOB1_AUTOMATAINTERFACE_H
#define TPOB1_AUTOMATAINTERFACE_H
#include <bits/stdc++.h>
#include "../auxiliarmethods/CollectionsOperators.h"
using namespace std;

class AutomataInterface {
private:
    vector<int> K;
    vector<int> E;
    int q0;
    vector<int> F;
public:
    void setE(const std::vector<int>& E);
    void setK(const std::vector<int>& K);

    void setInitialState(int q0);
    void setF(const std::vector<int>& F) ;

    void addPath(int node, int arc, int destination) ;
};

#endif
