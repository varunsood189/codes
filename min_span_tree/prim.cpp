//Prim Adt implementation file for prim algorithm
//Defines the function declared in the prim.h

#include <iostream>
#include"prim.h"
#include"graph.h"

//Function for prim
Graph * Prim(Graph g1)
{
    int no=g1.n;               //No of the vertex
    int mini,k;                //
    int lowcost[no];          //Lowest cost for the vertex in U that is closest to vertex in U-V
    int closest[no];          //vertex in U that is closest to vertex in U-V
    Graph *g2=new Graph(no); //Initialize a new graph for storing the edges

    //Here i is the vertex in V-U and closest[i] is vertex in U
    //Edges equal to -1 for no path between the vertex
    g2->graphconv();

    //Initialize the lowest cost and closest arrays
for(int i=0;i<no;i++)
{

closest[i]=0;                 //closest array tells which vertex is closest for the corresponding
                               //cost in the lowest cost
lowcost[i]=g1.C[0][i];        //lowest cost corresponding to the vertex in U that is closest to vertex in U-V
        //We know that the if no path exist the value of the edge is -1
        //So i have changed the value of the -1 to largest element in the matrix + 100
    if(lowcost[i]==-1)
    {

        lowcost[i]+=g1.larg+100;
    }

}

for(int i=1;i<no;i++)
{
    //Find the closest vertex k outside of U closest some vertex in U
    k=1;
    mini=lowcost[1];

    for(int j=2;j<no;j++)
    {
        //lowcost =-1 means no path or infinite length
        if(lowcost[j]<mini&&(lowcost[j]!=-1))
        {
            mini=lowcost[j];
            k=j;
        }

    }

// In order to save the edges of the minimum spanning tree
    g2->addedge(closest[k],k,mini);

    //print the output edge
    //low cost of the edge to be set to a very large value
    //Here the value was added to show that edge has been added to the U
    lowcost[k]=g1.larg+1000;
    //k is added to U
    //In order to find the path the graph
    //Path from i to k
    //Adjust cost to U

    for(int j=1;j<no;j++)
    {
        //Explanation of the conditions
        //(g1.C[k][j]<lowcost[j]) because if the next row of graph has less cost then the present one
        //lowcost[j]<g1.larg+1000  Not repalcing already added edge in set U
        if((g1.C[k][j]<lowcost[j])&&(lowcost[j]<g1.larg+1000)&&(g1.C[k][j]!=-1))
        {
            lowcost[j]=g1.C[k][j];
            closest[j]=k;
        }
    }
}

return g2;
}

