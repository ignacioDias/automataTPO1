#ifndef TPOB1_COLLECTIONSOPERATORS_H
#define TPOB1_COLLECTIONSOPERATORS_H

#include <bits/stdc++.h>

using namespace std;

class __attribute__((unused)) CollectionsOperators {
public:
    static bool contained(const set<int>& firstSet, const set<int>& biggerSet);
    static bool belongs(int elem, const set<int>& set);
    static bool setContained(const set<set<int>>& firstSet, const set<int>& biggerSet);
    static void insertAll(set<int>& setToBeModify, const set<int>& otherSet);
    static string to_string_set(const set<int>& set);
    static string to_string_set_of_sets(const set<set<int>>& setOfSets);

    static set<set<int>> difference(const set<set<int>> &set1, const set<set<int>> &set2);

    static bool containedSetInSet2(const set<int>& set1, const set<set<int>> &set2);
};

#endif //TPOB1_COLLECTIONSOPERATORS_H
