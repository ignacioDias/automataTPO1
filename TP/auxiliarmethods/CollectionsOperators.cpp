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
bool CollectionsOperators :: setContained(const set<set<int>>& firstSet, const set<int>& biggerSet) {
    for(const auto& currentSet : firstSet) {
        if(currentSet == biggerSet || contained(currentSet, biggerSet))
            return true;
    }
    return false;
}
void CollectionsOperators :: insertAll(set<int>& setToBeModify, const set<int>& otherSet) {
    for(auto elem : otherSet) {
        setToBeModify.insert(elem);
    }
}

string CollectionsOperators::to_string_set(const set<int>& set) {
    stringstream ss;
    for (auto it = set.begin(); it != set.end(); ++it) {
        if (it != set.begin())
            ss << ",";
        ss << *it;
    }
    return ss.str();
}
string CollectionsOperators::to_string_set_of_sets(const set<set<int>>& setOfSets) {
    stringstream ret;
    for (const auto & setOfSet : setOfSets) {
        ret << to_string_set(setOfSet);
    }
    return ret.str();
}
set<set<int>> CollectionsOperators::difference(const set<set<int>>& set1, const set<set<int>>& set2) {
    set<set<int>> finalSet;
    for(const auto& elem : set2) {
        if(!containedSetInSet2(elem, set1))
            finalSet.insert(elem);
    }
    return finalSet;
}

bool CollectionsOperators::containedSetInSet2(const set<int>& set1, const set<set<int>> &set2) {
    for(const auto& elem : set2) {
        if(elem == set1)
            return true;
    }
    return false;
}
