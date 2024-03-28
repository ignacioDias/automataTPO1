#include <bits/stdc++.h>

using namespace std;

class AutomataInterface {
private:
    vector<int> K;
    vector<int> E;
    int q0;
    vector<int> F;

public:
    virtual void setE(vector<int> E) = 0;
    virtual void setK(vector<int> K) = 0;
    virtual void setInitialState(int q0) = 0;
    virtual void setF(vector<int> K) = 0;
    virtual bool repOk() = 0;
    virtual void addPath(int node, int arc, int destination) = 0;

};
int main() {
    return 0;
}