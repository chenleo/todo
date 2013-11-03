//
//  main.cpp
//  graph
//
//  Created by Shibin Li on 11/2/13.
//  Copyright (c) 2013 Shibin Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
public:
    Graph(int n);       //?map with note n;
    ~Graph();
    int V();   // !Returns the number of vertices in the graph
    int E();   // !Returns the number of edges in the graph
    bool adjacent(int x, int y); // !test whether there is an edge from node x to node y;
    vector<int> neighbors(int x);  // !lists all nodes y such that there is an edge from x to y;
    void add(int x, int y);     //adds to G the edge from x to y, if it is not there.
    double get_node_value(int x);  //returns the value associated with the node x.
    void set_node_value(int x, double a); //sets the value associated with the node x to a.
    double get_edge_value(int x, int y); //returns the value associated to the edge(x,y).
    void set_edge_value(int x, int y, double v); //sets the value associated to the edge (x,y) to v.
                
private:
    vector< vector<bool> > G;
    vector< vector<double> > G_edge_values;
    vector<int> G_nodes;
    int vertices_number;
    int edges_number;
};
                
// Initialize graph G as n x n matrix, with every element equals -1 to indicate none connection.
Graph::Graph(int n)
:G(n,vector<bool>(n,false)), G_edge_values(n,vector<double> (n, -1)), G_nodes(n,INT_MAX)
   {
       G_nodes[0] = 0;
   }

Graph::~Graph()
{
}
int Graph::V()
{
    return vertices_number;
}

int Graph::E()
{
    return edges_number;
}

bool Graph::adjacent(int x, int y)
{
    return G[x][y] == true;
}

vector<int> Graph::neighbors(int x)
{
    vector<int> neighbors;
    for (int i = 0; i < V(); i++)
    {
        if (i != x-1 && adjacent(x,i+1))
            neighbors.push_back(i+1);
    }
    return neighbors;
}

void Graph::add(int x, int y)
{
    G[x-1][y-1] = true;
    G[y-1][x-1] = true;
}

double Graph::get_node_value(int x)
{
    return G_nodes[x-1];
}

void Graph::set_node_value(int x, double a)
{
    G_nodes[x-1] = a;
}

double Graph::get_edge_value(int x, int y)
{
    return G_edge_values[x-1][y-1];
}

void Graph::set_edge_value(int x, int y, double v)
{
    G_edge_values[x-1][y-1] = v;
    G_edge_values[y-1][x-1] = v;
}
                
class PriorityQueue : Graph
{
public:
    PriorityQueue();
    void chgPrioirity(？？，piroity);  //??changes the priority (node value) of queue element.
    void minPrioirty();    //removes the top element of the queue.
    bool contains(int queue_element);  //does the queue contain queue_element?
    void Insert(int queue_element);    //insert queue_element into queue
    int top();          //returns the top element of the queue.
    int size();         //return the number of queue_elements.
    
private:
    list<int> pq;
    //int pq_size;
    
};




                
class ShortestPath : Graph, PriorityQueue
{
public:
    ShortestPath();
    vector<int> vertices();     //list of vertices in G(V, E)
    vector<int> path(int u, int w);         //find shortest path between u-w and returns the sequence of
                    //vertices representing shortest path u-v1-v2-...-vn-w.
    double path_size(int u, int w);    //return the path cost associated with the shortest path.
};
    
    


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

