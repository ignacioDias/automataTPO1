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
    virtual void setE(const std::vector<int>& E) = 0;
    virtual void setK(const std::vector<int>& K) = 0;
    virtual void setInitialState(int q0) = 0;
    virtual void setF(const std::vector<int>& F) = 0;
    virtual bool repOk() const = 0;
    virtual void addPath(int node, int arc, int destination) = 0;
};

#endif
