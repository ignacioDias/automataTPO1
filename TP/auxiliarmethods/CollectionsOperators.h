#ifndef TPOB1_COLLECTIONSOPERATORS_H
#define TPOB1_COLLECTIONSOPERATORS_H

#include <bits/stdc++.h>

using namespace std;

class __attribute__((unused)) CollectionsOperators {
public:
    static bool contained(const set<int>& firstSet, const set<int>& biggerSet);
    static bool belongs(int elem, const set<int>& set);
    static bool setContained(set<set<int>> firstSet, set<int> biggerSet);
    static void insertAll(set<int> setToBeModify, const set<int>& otherSet);
    };

#endif //TPOB1_COLLECTIONSOPERATORS_H
