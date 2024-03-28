#include <bits/stdc++.h>
#include "DeterministicFiniteAutomata.h"
#include "AutomataInterface.h"
#include "NotDeterministicFiniteAutomata.h"

using namespace std;

class DeterministicFiniteAutomata : public AutomataInterface {
private:
    vector<int> K;
    vector<int> E;
    map<pair<int,int>, int> d;
    int q0;
    vector<int> F;

public:
    DeterministicFiniteAutomata() : K(), E(), d(), q0(0), F() {

    }
    void setE(vector<int> E) {
        this->E = E;
    }
    void setK(vector<int> K) {
        this->K = K;
    }
    void setInitialState(int q0) {
        this->q0 = q0;
    }
    void setF(vector<int> K) {
        this->K = K;
    }
    int calculateDelta(pair<int,int> key) {
        return d[key];
    }
    void addPath(int node, int arc, int destination) {
        pair<int,int> path;
        path.first = node;
        path.second = arc;
        auto it = d.find(path);
        if (it == d.end())
            d[path] = destination;
        else
            throw runtime_error("El nodo ya tiene asignado un destino con dicho arco");
    }

};
int main() {
    return 0;
}