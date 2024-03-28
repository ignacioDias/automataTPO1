#include <bits/stdc++.h>
#include "DeterministicFiniteAutomata.h"
#include "AutomataInterface.h"
#include "NotDeterministicFiniteAutomata.h"

using namespace std;

class NotDeterministicFiniteAutomata {
private:
    vector<int> K;
    vector<int> E;
    map<pair<int,int>, set<int>> d;
    int q0;
    vector<int> F;

public:
    NotDeterministicFiniteAutomata() : K(), E(), d(), q0(0), F() {
    }
    vector<int> getK() {
        return K;
    }
    vector<int> getE() {
        return E;
    }
    int getInitialState() {
        return q0;
    }
    vector<int> getF() {
        return F;
    }
    void setK(vector<int> K) {
        this->K = K;
    }
    void setE(vector<int> E) {
        this->E = E;
    }
    void setInitialState(int q0) {
        this->q0 = q0;
    }
    void setF(vector<int> F) {
        this->F = F;
    }
    void addPath(int node, int arc, int destination) {
        pair<int,int> path;
        path.first = node;
        path.second = arc;
        d[path].insert(destination);
    }
    set<int> calculateDelta(pair<int,int> key) {
        return d[key];
    }
    bool repOk() {
        bool invariant = contained(this->K, this->E);
        invariant &= contained(this->F, this->K);
        invariant &= belongs(this->q0, this->K);
        return invariant;
    }
    /*DeterministicFiniteAutomata NFAtoDFA() {
        return ;
    }*/
private:
    static bool contained(vector<int> firstVector, vector<int> biggerVector) { //TODO: PASAR A OTRA CLASE
        if(biggerVector.size() < firstVector.size())
            return false;
        for(int elem : firstVector) {
            if (!belongs(elem, biggerVector))
                return false;
        }
        return true;
    }
    static bool belongs(int elem, vector<int> vector) {
        for(int vCurrentElem : vector) {
            if (elem == vCurrentElem)
                return true;
        }
        return false;
    }
};
int main() {

}