//Priority queue header file
//Declaration of the edge and priority queue structures


#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

//Priority queue implementation using array min heap
//data structure for the edge
struct edge
{
public:
    int v1;
    int v2;//Vertex v1 and v2
    int pri_val;//Weight of the edge
};

//Structure of the priority queue
//Along with the function declarations

class pri_queue
{
public:
    int last;                         //last the last element of the edge present in the array
    int n;                           //Total No of Edges
    edge ** e;
    //    Function declaration
    pri_queue(int);                  //constructor
    void make_null(void);           //To signify that the array is empty, last is set to -1
    void insert_edge(edge);         //Insert an edge into the priority queue
    edge * delete_min(void);        //Delete the minimum value of the heap
    void print_prique(void);        //Printing the priority queue
};


#endif // PRIORITYQUEUE_H_INCLUDED
