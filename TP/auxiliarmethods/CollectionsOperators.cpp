#include <bits/stdc++.h>
#include "CollectionsOperators.h"

using namespace std;

bool CollectionsOperators :: contained(const set<int>& firstVector, const set<int>& biggerVector) {
    if(biggerVector.size() < firstVector.size())
        return false;
    for(int elem : firstVector) {
        if (!belongs(elem, biggerVector))
            return false;
    }
    return true;
}
bool CollectionsOperators :: belongs(int elem, const set<int>& vector) {
    for(int vCurrentElem : vector) {
        if (elem == vCurrentElem)
            return true;
    }
    return false;
}
