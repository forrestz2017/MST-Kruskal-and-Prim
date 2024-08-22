/***********************************************************
 * Edge.h
 * Header file for the Edge struct, which represents an edge
 * in the graph with its two endpoints and the weight.
 ***********************************************************/

#ifndef EDGE_H
#define EDGE_H

struct Edge {
    int u, v, weight;  // u and v are the vertices, and weight is the cost of the edge

    // Comparison operator to compare edges by their weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

#endif
