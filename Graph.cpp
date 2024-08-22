/***********************************************************
 * Graph.cpp
 * Implementation of the Graph class methods, including
 * methods for adding edges and computing MST using
 * Kruskal's and Prim's algorithms.
 ***********************************************************/

#include "Edge.h"       
#include "Graph.h"
#include "DisjointSet.h"
#include <algorithm>
#include <fstream>


 // Constructor for the Graph class
Graph::Graph(int V) : V(V) {
    // Initialize the adjacency list to hold V vectors, one for each vertex
    adjList.resize(V);
}

// Function to add an edge to the graph
void Graph::addEdge(int u, int v, int weight) {
    // Add the edge from u to v with the specified weight
    adjList[u].push_back({ v, weight });

    // Since the graph is undirected, also add the edge from v to u with the same weight
    adjList[v].push_back({ u, weight });
}

// Function to compute the Minimum Spanning Tree (MST) using Kruskal's algorithm
void Graph::kruskalMST() {
    std::vector<Edge> edges;  // Vector to store all edges of the graph

    // Convert the adjacency list to an edge list
    for (int u = 0; u < V; ++u) {
        for (auto& [v, weight] : adjList[u]) {
            if (u < v) {  // To avoid duplicate edges, only add if u < v
                edges.push_back({ u, v, weight });
            }
        }
    }

    // Sort the edges by weight in non-decreasing order
    std::sort(edges.begin(), edges.end());

    // Initialize Disjoint Set to manage connected components
    DisjointSet ds(V);

    // Open the output file to write the result of Kruskal's algorithm
    std::ofstream kruskalOut("kruskalout.txt");

    // Iterate over the sorted edges and build the MST
    for (const auto& edge : edges) {
        int u = edge.u;  // Vertex u of the edge
        int v = edge.v;  // Vertex v of the edge

        // Find the root of the sets containing u and v
        int setU = ds.find(u);
        int setV = ds.find(v);

        // If u and v are in different sets, adding this edge will not form a cycle
        if (setU != setV) {
            // Write the edge (u, v) to the output file
            kruskalOut << u << " " << v << " ";

            // Union the sets containing u and v to merge the components
            ds.unionSets(setU, setV);
        }
    }

    // Close the output file after writing all edges in the MST
    kruskalOut.close();
}

// Function to compute the Minimum Spanning Tree (MST) using Prim's algorithm
void Graph::primMST() {
    std::vector<bool> inMST(V, false);  // Boolean array to keep track of vertices included in the MST
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    // Priority queue to select the edge with the minimum weight (min-heap)

    // Open the output file to write the result of Prim's algorithm
    std::ofstream primOut("primout.txt");

    // Start with the first vertex (assuming vertex 0) and push it to the priority queue with weight 0
    pq.push({ 0, 0 }); // (weight, vertex)

    while (!pq.empty()) {
        // Extract the vertex with the smallest edge weight
        int u = pq.top().second;
        pq.pop();

        // If the vertex is already in the MST, skip it
        if (inMST[u]) continue;
        inMST[u] = true;

        // Iterate over all adjacent vertices of u
        for (auto& [v, weight] : adjList[u]) {
            // If v is not in the MST, consider the edge (u, v) for inclusion in the MST
            if (!inMST[v]) {
                // Push the adjacent vertex and its edge weight to the priority queue
                pq.push({ weight, v });
                // Write the edge (u, v) to the output file
                primOut << u << " " << v << " ";
            }
        }
    }

    // Close the output file after writing all edges in the MST
    primOut.close();
}
