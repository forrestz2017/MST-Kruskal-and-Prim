/***********************************************************
 * DisjointSet.h
 * Programmer: Forrest Zhang
 * Date: 8/11/2024
 * Header file for the DisjointSet class, containing methods
 * to perform union and find operations for Kruskal's
 * algorithm.
 ***********************************************************/

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <vector>

class DisjointSet {
public:
    std::vector<int> parent, rank; // Arrays to store parent pointers and ranks of the sets

    // Constructor: Initializes n disjoint sets (one for each vertex)
    DisjointSet(int n);

    // Function to find the root of the set containing vertex u, with path compression
    int find(int u);

    // Function to unite two sets containing u and v, using union by rank
    void unionSets(int u, int v);
};

#endif
