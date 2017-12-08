//graph ADT  header file

#include<iostream>

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

class Graph
{
public:
    int n;          //No of vertex of the graph
    int ** C;       //Pointer to the array of pointers
    int larg=0;     //Largest value of the matrix

//Function declaration
    Graph(int );                 //constructor for graph for null initialization
    Graph(int** ,int );          //constructor for graph with given cost function
    void print (void);          //print cost function
    int sum(void);              //Total cost of the spanning tree
    void print_edge(void);      //Printing the edges of the spanning tree
    void graphconv(void);       //conversion of the graph
    void addedge(int,int,int);  //Add an edge
    int edge_no(void);          //No of edges in a graph
};

#endif // GRAPH_H_INCLUDED
