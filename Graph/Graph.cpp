
#include "Graph.h"
#include <algorithm>
#include <list>

void Graph::insertElement(int a, int b)
{

    Node node1,node2;
    node1.vertice = a;
    node1.neighboors.push_back(b);
    node2.vertice = b;
    node2.neighboors.push_back(a);
    numOfEdges++; // we increase the counter by 1 for each insertion
    if (adjacencyList.empty())
    {
        adjacencyList.push_back(node1);
        adjacencyList.push_back(node2);
    } else {
        bool flag1 = false, flag2 = false; // they are indicators that the incoming vertices are (not) exist in the adjacency list
        for (int i=0; i< adjacencyList.size(); i++)
        {
            // case 1 : vertice a already exist in our vector so we add 1 neighboor to its vector
            // and add to the adjacency list the b vertice
            if(adjacencyList[i].vertice == a)
            {
                adjacencyList[i].neighboors.push_back(b);
                //adjacencyList.push_back(node2);
                flag1 = true;
            // case 2 : vertice b already exist in our vector so we do the same as in case 1
            } else if (adjacencyList[i].vertice == b)
            {
                adjacencyList[i].neighboors.push_back(a);
                //adjacencyList.push_back(node1);
                flag2 = true;
            }
        }
        // case 3: brand new entry (both vertices are not exist in the list)
        if (!flag1 && !flag2)
        {
            adjacencyList.push_back(node1);
            adjacencyList.push_back(node2);
        } else if (flag1 && !flag2)
        {
            adjacencyList.push_back(node2);
        } else if (!flag1 && flag2)
        {
            adjacencyList.push_back(node1);
        }
    }
}

void Graph::deleteElement(int a, int b)
{
    bool flag = false; // it becomes true only if the given edge exists
    int indexA = -1, indexB = -1; // variables that keep the indexes of a and b vertices in adjacencyList vector
    for (int i=0; i< adjacencyList.size(); i++)
    {
        if(adjacencyList[i].vertice == a)
        {
            for (int j = 0; j< adjacencyList[i].neighboors.size(); j++)
            {
                if (adjacencyList[i].neighboors[j] == b){
                    indexA = i;
                    flag = true;
                    break;
                }

            }
        }
        if (adjacencyList[i].vertice == b)
        {
            indexB = i;
        }
    }

    if (flag)
    {
        numOfEdges--;
        // we should delete from the neighboors of a the b vertice and vice versa
        vector<int> *neighA = &adjacencyList[indexA].neighboors;
        neighA->erase(remove(neighA->begin(), neighA->end(), b), neighA->end());
        vector<int> *neighB = &adjacencyList[indexB].neighboors;
        neighB->erase(remove(neighB->begin(), neighB->end(), a), neighB->end());
    }

}

void Graph::printGraph() {
    for (int i = 0; i < adjacencyList.size(); i++) {
        // print current vertex number
        cout << adjacencyList[i].vertice << " --> ";

        // print all neighboring vertices of vertex i
        for (int v : adjacencyList[i].neighboors)
            cout << v << " ";
        cout << endl;
    }
}

int Graph::countConnectedComponents() {
    int num = 1;
    bool * visited = new bool[adjacencyList.size()];
    for(int v = 0 ; v < adjacencyList.size(); v++){
        visited[v] = false;
    }
    for (int i = 0; i < adjacencyList.size(); i++) {
        int counter = 0;
        if (adjacencyList[i].neighboors.empty()) {
            num++;
        }
        else if(visited[i] == false && !adjacencyList[i].neighboors.empty()){
            DFS(i , visited);
            for (int k = 0; k < adjacencyList.size() ; k++){
                if (visited[k]){
                    counter++;
                }
            }
            if (counter < adjacencyList.size()){
                num ++ ;
            }
        }
    }
    return num;
}

void Graph::DFS(int i, bool *visited) {
    visited[i] = true;
    int index;
    for (int j = 0; j < adjacencyList[i].neighboors.size(); j++) {
       index =  findIndex(adjacencyList[i].neighboors[j]);
        if(!visited[index]){
            DFS(index,visited);
        }
    }
}

/**
 *
 * @param a the value of the vertice
 * @return The corresponded index of the given vertice in adjacencyList vector otherwise -1(Not found convention)
 */
int Graph:: findIndex(int a)
{
    for (int i = 0; i < adjacencyList.size(); i++) {
        if(adjacencyList[i].vertice == a) {
            return i;
        }
    }
    return -1;
}


int Graph::findShortestPath(int src, int dest)
{
    bool * visited = new bool[adjacencyList.size()];
    for(int v = 0 ; v < adjacencyList.size(); v++){
        visited[v] = false;
    }
    shortestPath = 1000;
    int parentIndex = findIndex(src);
    //visited[parentIndex] = true;
    calculateShortestPath(0,parentIndex, visited,dest);
    return shortestPath;
}

void Graph::calculateShortestPath(int cost, int index,bool *visited, int dest){
   visited[index] = true;
    int currentCost = cost;
    for(int n: adjacencyList[index].neighboors){
        currentCost = cost;
        if (n == dest && shortestPath > currentCost){
            shortestPath = currentCost + 1;
        }
        int index2 = findIndex(n);
        if (!visited[index2]){
            currentCost+=1;
            calculateShortestPath(currentCost, index2, visited, dest);
        }
    }

}

