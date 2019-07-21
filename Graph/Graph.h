
#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int vertice;
    vector<int> neighboors;
};

class Graph {
public:
    Graph(){ numOfEdges = 0;};
    void insertElement(int a, int b);
    int getNumOfVerices(){return adjacencyList.size();}
    int getNumOfEdges(){return numOfEdges;}
    void deleteElement(int a,int b);
    int countConnectedComponents();
    int findShortestPath(int a, int b);
    void printGraph();

private:
    // construct a vector that contains  Node struct elements to represent an adjacency list
    vector <Node> adjacencyList;
    int numOfEdges;
    void DFS(int i, bool *visited);
    int findIndex(int a);
    int shortestPath;
    void calculateShortestPath(int cost, int index,bool *visited, int dest);
};

#endif //DATA_STRUCTURES_GRAPH_H
