Kruskals and Prims Algorithm for Minimum Spanning Tree (MST)
Programmer: Forrest Zhang
Date: 8/11/2024

This program implements Kruskal's and Prim's algorithms to find the Minimum Spanning Tree (MST) of an undirected, positively weighted graph. The input graph is read from a file named "graphin.txt", and the resulting MSTs are written to "kruskalout.txt" and "primout.txt".

Prerequisites
-------------
- A C++ compiler that supports C++17 or later.
- "make" utility if using the provided Makefile for compilation.


project directory


    |-- Edge.h               
    |-- Edge.cpp              
    |-- Graph.h              
    |-- Graph.cpp            
    |-- DisjointSet.h         
    |-- DisjointSet.cpp      
    |-- main.cpp              
    |-- graphin.txt          
    |-- Makefile              
    |-- README.txt           

Compiling the Program
------------------------------------------------------------------------------------------
There are two ways to compile the program:

Option 1: Using Makefile (Recommended)
1. Open a terminal or command prompt.
2. Navigate to the project directory where the "Makefile" is located.
3. Run the following command to compile the program:

   make

   This will compile all the source files and produce an executable named "main".
------------------------------------------------------------------------------------------
Option 2: Manual Compilation
If you prefer to compile the program manually, you can use the following command:

   g++ -std=c++17 -o main main.cpp Graph.cpp DisjointSet.cpp Edge.cpp

   Make sure all the source files are located in the current directory.
------------------------------------------------------------------------------------------
Running the Program
1. make sure the input file "graphin.txt" is present in the project directory.
2. Run the compiled executable:

   ./main   # On Linux/MacOS
   main.exe # On Windows

3. The program will produce two output files:
   - "kruskalout.txt": Contains the MST computed using Kruskal's algorithm.
   - "primout.txt": Contains the MST computed using Prim's algorithm.
------------------------------------------------------------------------------------------
Input File Format ("graphin.txt")
---------------------------------
The "graphin.txt" file should be in the following format:

1: 2 10 3 20
2: 1 10 3 5 4 15
3: 1 20 2 5 4 10 5 30
4: 2 15 3 10 5 20
5: 3 30 4 20

- Each line represents a vertex and its neighbors.
- The first number is the vertex label.
- Pairs of numbers following the vertex label represent the neighboring vertex and the weight of the edge connecting them.
-
Cleaning Up
------------------------------------------------------------------------------------------
To remove the compiled object files and executable, run:

   make clean

This will delete all object files (*.o) and the executable ("main").
