//Kruskal Adt implementation file for Kruskal algorithm
//Defines the function declared in the Kruskal.h

#include<iostream>
#include"kruskal.h"
#include"priorityqueue.h"
#include"mfset_i.h"
using namespace std;
//Function implementation for a graph
Graph * kruskal(Graph g1)
{
    //Initializing the graph
    int  no=g1.n;
   // g1.print();
    Graph *g3=new Graph(no);      //Initialize a new graph for storing the edges
    g3->graphconv();             //Setting the edge weight -1 for not connected and 0 for same vertex
    int noEdge=g1.edge_no();     // No of edges

//    edge * e1=new edge;         //new edge creation
    int ncomp=g1.n;             //Total no of vertex is equal to no of components

    //Initializing a priority queue
    pri_queue edges(noEdge);    //Here edges is the priority queue data type for the no of edges
    edges.make_null();          //Here the no of elements will be set to zero

    //Creation of the mfset
    mfset components(g1.n);     //here components are mfset type
    //Initialize all the vertex as different component
    components.mfset_Init();

    //Insert the edges in the priority queue
    edge e;
    int count1=0;

    //inserting the edges in the priority queue
    for(int i=0;i<no;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((g1.C[i][j]!=0)&&(g1.C[i][j]!=-1))
            {
                e.v1=i+1;
                e.v2=j+1;
                e.pri_val=g1.C[i][j];
                count1++;
                edges.insert_edge(e);  //Calling the function to insert the edge.
                                        //Here. edges is the priority queue
            }
        }
    }


edge* e2;
int ucomp,vcomp;
int value=0;
            //Consider the next edge
while(ncomp>1)
{
    e2=edges.delete_min();

   ucomp=components.find_mfset(e2->v1-1);   //vertex one
   vcomp=components.find_mfset(e2->v2-1);   //vertex two
        if(ucomp!=vcomp)
        {
            //If the components, the vertex belong to are not equal
            //merge the vertex into 1 component
            components.merge_mfset(ucomp,vcomp);
//            Saving the edges in a graph
            g3->C[e2->v2-1][e2->v1-1]=e2->pri_val;
            g3->C[e2->v1-1][e2->v2-1]=e2->pri_val;
            value++;
            ncomp--;
        }

}

    return g3;      //Return the graph
}
