//Graph ADT for the implementation of Prims algorithm
//Includes the code implementation for the graph data structure defined in the graph header file.

#include<iostream>
#include"graph.h"

using namespace std;

//Function in order to find the total no of edges.
//Result: This program outputs the total no of edges.
//Input: Null
//Output: No of edges
 int Graph::edge_no(void)
 {
     int no=0; //No of edges
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
        if((C[i][j]!=0)&&(C[i][j]!=-1))
        {
            no++;
        }
     }
 }
 //I have divided the no of edges by 2 because it was counted twice
 return no/2;
 }
//Print function of the graph
//This function prints the graph.
//Input: Null
//Output: NUll

void Graph :: print (void)
{

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    {
                    cout<<C[i][j]<<" ";
                    }
                    cout<<"\n";
            }
}

//Graph conversion function
//In the beginning of the graph, all edges are removed
//In this case, all the edges have weight -1 for no edge between them
//Result: This program converts cost matrix in a better form.
//Input: Null
//Output: NUll

void Graph ::graphconv(void)
{
//Graph conversion
//This graph converts the graph so as to signify that the not connected edges
for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        {
            if((i!=j)&&(C[i][j]==0))
            {
                //-1 represents the not connected edges between the graph.
                C[i][j]=-1;
            }
        }
    }
}
// Print edge function
//In order to print the edges of the graph given
//Result: This program prints the edges of the Spanning tree graph
//Input: Null
//Output: NUll

void Graph:: print_edge(void)
{

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
                {
                    if((C[i][j]!=0)&&(C[i][j]!=-1))
                    {
                        //Here i+1 and j+1 because of the reason
                        //that the for loops start form 0
                        cout<<"( "<<i+1<<","<<j+1<<" )"<<"\n";
                    }
                }
        }
}
//Add the edge to the graph
//Result: The edge to be added in the new graph
//Input: location of the edges and values of the edge to be added
//Output: Null
void Graph:: addedge(int i ,int j,int val)
{
    C[i][j]=val;
    C[j][i]=val;
}
//Sum function in order to find the total cost of the spanning tree
//Result: This program prints the cost matrix of the graph
//Input: Null
//Output: Total cost of the spanning tree

int Graph :: sum(void)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(C[i][j]!=-1)
            sum=sum+C[i][j];
    }
    //Here sum/2 because the sum was calculated twice.
    return sum/2;
}
// Default constructor which initializes the cost matrix to zero.
//Result: This program prints the cost matrix of the graph
//Input: No of the vertex
//Output: NUll

Graph :: Graph(int no)
    {
        n=no;   //No of vertex
        larg=0;
     C=new int*[n];        // Array of pointers
    for(int i=0;i<n;i++)
        {
        C[i]=new int[n];    //Array of elements created by each pointer
        for(int j=0;j<n;j++)
            {
            C[i][j]=0;
            }
        }
    }
//Constructor function which initializes the cost matrix according to input
//Result: This program prints the cost matrix of the graph
//Input: Pointer to the cost matrix ,No of vertex
//Output: NUll

 Graph :: Graph(int** c,int m)
{
    larg=0;
    n=m;//No of vertices
     C=new int*[m];        // Array of pointers
    for(int i=0;i<m;i++){
        C[i]=new int[m];    //Array of elements created by each pointer
    for(int j=0;j<m;j++){
        C[i][j]=c[i][j];
        //Finding the largest value of the cost
        if(larg<c[i][j])
        {
            larg=c[i][j];
        }
    }
     }
}
