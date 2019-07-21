#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include "AvlTree/AvlTree.h"
#include "Heaps/Heap.h"
#include "HashTable/HashTable.h"
#include "Graph/Graph.h"

using namespace std;
using namespace std::chrono;

int main() {
    ifstream commands;
    ofstream out;
    out.open("output.txt" , ios::out );
    commands.open("commands.txt");
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = stop - start;
    Heap minHeap(true);
    Heap maxHeap(false);
    AvlTree avl;
    Graph graph;
    HashTable hashTable;
    start = high_resolution_clock::now();
    while (!commands.eof()) {
        string a, b, c, d; // We declare 4 strings because each line will not contain  more than 4 parameters
        commands >> a;
        commands >> b;

//============================= MINHEAP ============================================
        if (b == "MINHEAP") {
            if (a == "BUILD") {
                commands >> c;
                ifstream input1( c );
                while(!input1.eof()){
                    string a;
                    input1 >> a;
                    if(a!="")
                    {
                        minHeap.insertElement(stoi(a));
                    }
                }
                input1.close();
                out << "Build of MinHeap completed!" << endl;
            } else if (a == "GETSIZE") {
                out <<"Size of MinHeap: " << minHeap.size() << endl;
            } else if (a == "FINDMIN") {
                out <<"Minimum element of MinHeap: " << minHeap.getTopElement() << endl;
            } else if (a == "INSERT") {
                commands >> c;
                minHeap.insertElement(stoi(c));
                out << "Element "<< c << " inserted in Minheap" << endl;
            } else if (a == "DELETE") {
                minHeap.deleteElement();
                out << "Root element deleted from Minheap" << endl;
            }
        }
//============================ MAXHEAP ==============================================
        else if (b == "MAXHEAP") {
                if (a == "BUILD") {
                    commands >> c;
                    ifstream input1(c);
                    while (!input1.eof()) {
                        string a;
                        input1 >> a;
                        if (a != "") {
                            maxHeap.insertElement(stoi(a));
                        }
                    }
                    input1.close();
                    out << "Build of MaxHeap completed!" << endl;
            } else if (a == "GETSIZE") {
                    out <<"Size of MaxHeap: " <<  maxHeap.size() << endl;
                } else if (a == "FINDMAX") {
                    out <<"Maximum element of MaxHeap: "<< maxHeap.getTopElement() << endl;
                } else if (a == "INSERT") {
                    commands >> c;
                    maxHeap.insertElement(stoi(c));
                    out << "Element "<< c << " inserted in MaxHeap" << endl;
                } else if (a == "DELETE") {
                    maxHeap.deleteElement();
                    out << "Root element deleted from Maxheap" << endl;
                }

        }
// ===============================  AVLTREE  ==============================================
        else if (b == "AVLTREE") {
            if (a == "BUILD") {
                commands >> c;
                ifstream input1( c );
                while(!input1.eof()){
                    string a;
                    input1 >> a;
                    if(a!="")
                    {
                       avl.root = avl.insert(avl.root,stoi(a));
                    }
                }
                input1.close();
                out << "Build of AvlTree completed!" << endl;
            } else if (a == "GETSIZE") {
                out <<"Size of AvlTree: "<< avl.getSizeOfAvlTree()<< endl;
                //avl.display(avl.root,1);
            } else if (a == "FINDMIN") {
                out <<"Minimum element of AvlTree: " << avl.findMin(avl.root)->data<< endl;
            } else if (a == "INSERT") {
                commands >> c;
                avl.insert(avl.root,stoi(c));
                out << "Element "<< c << " inserted in AvlTree" << endl;
            } else if (a == "DELETE") {
                commands >> c;
                avl.deleteElement(stoi(c),avl.root);
                out << "Element" << c <<" deleted from AvlTree" << endl;
            } else if (a == "SEARCH") {
                commands >> c;
                if (avl.findElement(avl.root,stoi(c)) == NULL)
                {
                    out<< "FAILURE"<< endl;
                } else
                {
                    out<< "SUCCESS"<< endl;
                }
            }
        }
// ============================== GRAPH  ==============================================
        else if (b == "GRAPH") {
            if (a == "BUILD") {
                commands >> c;
                ifstream input1( c );
                while(!input1.eof()){
                    string a , b;
                    input1 >> a;
                    input1 >> b;
                    if(a!="" && b!="")
                    {
                        graph.insertElement(stoi(a),stoi(b));
                    }
                }
                input1.close();
                out << "Build of Graph completed!" << endl;
            } else if (a == "GETSIZE") {
                out <<"Number of vertices: "<< graph.getNumOfVerices() << " Number of edges: " << graph.getNumOfEdges() << endl;
                graph.printGraph();
            } else if (a == "COMPUTESHORTESTPATH") {
                commands >> c;
                commands >> d;
                out<<"Shortest's path cost: " << graph.findShortestPath(stoi(c),stoi(d))<< endl;
            } else if (a == "COMPUTESPANNINGTREE") {
                out<<"Not fuctional"<< endl;
            } else if (a == "FINDCONNECTEDCOMPONENTS") {
                cout << graph.countConnectedComponents() <<endl;
            } else if (a == "INSERT") {
                commands >> c;
                commands >> d;
                graph.insertElement(stoi(c),stoi(d));
                out << "Element "<< c <<"-"<< d << " inserted in Graph" << endl;
            } else if (a == "DELETE") {
                commands >> c;
                commands >> d;
                graph.deleteElement(stoi(c),stoi(d));
                out << "Element "<< c <<"-"<< d << " deleted from Graph" << endl;
            }
        }
// ============================= HASHTABLE  ===============================================
        else if (b == "HASHTABLE") {
            if (a == "BUILD") {
                commands >> c;
                ifstream input1( c );
                while(!input1.eof()){
                    string a;
                    input1 >> a;
                    if(a!="")
                    {
                        hashTable.insertElement(stoi(a),stoi(a));
                    }
                }
                input1.close();
                out << "Build of HashTable completed!" << endl;
            } else if (a == "GETSIZE") {
                out <<"Size of HashTable: "<< hashTable.getSizeOhHashTable()<< endl;
            } else if (a == "SEARCH") {
                commands >> c;
                if (hashTable.searchElement(stoi(c)) == -1)
                {
                    out<< "FAILURE"<< endl;
                } else
                {
                    out<< "SUCCESS"<< endl;
                }
            } else if (a == "INSERT") {
                commands >> c;
                hashTable.insertElement(stoi(c),stoi(c));
                out << "Element "<< c << " inserted in HashTable" << endl;
            }
        }
    }
    stop = high_resolution_clock::now();
    duration = stop - start;
    out << "Execution time (in milliseconds): "<< chrono::duration <double, milli> (duration).count() << endl;
    commands.close();
    out.close();
    return 0;
}

