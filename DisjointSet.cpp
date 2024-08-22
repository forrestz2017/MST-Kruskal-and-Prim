/***********************************************************
 * main.cpp
 * Main driver program to read the input graph, and to run
 * Kruskal's and Prim's algorithms for finding the MST.
 ***********************************************************/

#include "Graph.h"
#include <fstream>

int main() {
    std::ifstream infile("graphin.txt");  // Open the input file graphin.txt to read the graph

    int V;  // Number of vertices in the graph
    infile >> V;  // Read the number of vertices from the input file

    // Create a Graph object with V vertices
    Graph g(V);

    // Read the adjacency list from the input file and add edges to the graph
    int u, v, weight;
    while (infile >> u) {
        // Read neighbors and weights
        char colon;
        infile >> colon; // Read the colon ':'
        while (infile >> v >> weight) {
            g.addEdge(u - 1, v - 1, weight); // Add the edge to the graph (convert 1-based index to 0-based)
        }
    }

    // Close the input file after reading
    infile.close();

    // Run Kruskal's algorithm and write the MST to kruskalout.txt
    g.kruskalMST();

    // Run Prim's algorithm and write the MST to primout.txt
    g.primMST();

    return 0; // Return 0 to indicate successful execution
}
