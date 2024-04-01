#include <bits/stdc++.h>
#include "CollectionsOperators.h"

using namespace std;

bool CollectionsOperators :: contained(const set<int>& firstSet, const set<int>& biggerSet) {
    if(biggerSet.size() < firstSet.size())
        return false;
    for(int elem : firstSet) {
        if (!belongs(elem, biggerSet))
            return false;
    }
    return true;
}
bool CollectionsOperators :: belongs(int elem, const set<int>& set) {
    for(int sCurrentElem : set) {
        if (elem == sCurrentElem)
            return true;
    }
    return false;
}
bool CollectionsOperators :: setContained(set<set<int>> firstSet, set<int> biggerSet) {
    bool ret = true;
    for(auto currentSet : firstSet) {
        if(!contained(currentSet,biggerSet))
            return false;
    }
    return true;
}
void CollectionsOperators :: insertAll(set<int> setToBeModify, const set<int>& otherSet) {
    for(auto elem : otherSet) {
        setToBeModify.insert(elem);
    }
}

