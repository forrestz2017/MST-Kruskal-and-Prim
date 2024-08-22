/***********************************************************
 * Graph.h
 * Programmer: Forrest Zhang
 * Date: 8/11/2024
 * Header file for the Graph class, containing methods to
 * represent a graph, add edges, and compute the MST using
 * Kruskal's and Prim's algorithms.
 ***********************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>

class Graph {
public:
    int V;  // Number of vertices in the graph
    std::vector<std::vector<std::pair<int, int>>> adjList; // Adjacency List representation of the graph

    // Constructor: Initializes the graph with V vertices
    Graph(int V);

    // Function to add an edge between vertex u and vertex v with a given weight
    void addEdge(int u, int v, int weight);

    // Function to compute the MST using Kruskal's algorithm and write to kruskalout.txt
    void kruskalMST();

    // Function to compute the MST using Prim's algorithm and write to primout.txt
    void primMST();
};

#endif
