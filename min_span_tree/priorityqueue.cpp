//Priority queue ADT for the implementation of kruskal's  algorithm
//Includes the code implementation for the priority data structure defined in the priority header file.

#include"priorityqueue.h"
#include<iostream>

using namespace std;
// Function to print the Priority Queue
//Input: NUll
//Output: Null
    void pri_queue::print_prique(void)//Printing the priority queue
{
for(int i=0;i<n;i++)
{
    cout<<"i = "<<i<<endl;
    cout<<"VERTEX 1 = "<<e[i]->v1<<endl;
    cout<<"VERTEX 2 = "<<e[i]->v2<<endl;
    cout<<"Value = "<<e[i]->pri_val<<endl<<endl;

}

}

//Function to delete the minimum edge from the heap
//Input:Null
//Output: Minimum edge of the heap
    edge * pri_queue::delete_min(void)
{
    int i,j;                 //Integers
    edge *temp=new edge;     //Facilitates the exchange of the heap
    edge * minimum=new edge; //Helps in returning the minimum of the heap

   //If priority queue is empty ,print it and exit
    if(last==-1)
    {
     cout<<"Priority queue is empty";
    }else
    {
        //Getting the value of the minimum edge form the heap
        minimum->pri_val=e[0]->pri_val;
        minimum->v1=e[0]->v1;
        minimum->v2=e[0]->v2;
        e[0]=e[last];       //Pointer change of the last and the first element
        last=last-1;        //Removing the last element from the queue
        i=0;                //value of last element is present at i=0
        //push old last element down tree
        while(i<last/2)
        {
            //j will be the child of i having the smaller priority
             //or if 2*(i+1)-1 = A.last, then j is the only child of i
             //Here because of the starting of the node from the 0 .
             //we have to make some calculations.
            if(((e[(i+1)*2-1]->pri_val)<(e[(i+1)*2]->pri_val))||(last==(2*(i+1)-1)))
            {
            j=(i+1)*2-1;
            }
            else
            {
                j=(i+1)*2;
            }
            //Interchanging the value of the i and j priority
            if((e[i]->pri_val)>(e[j]->pri_val))
            {
                temp=e[i];
                e[i]=e[j];
                e[j]=temp;
                i=j;
            }else
            {
                //cannot push further

            return minimum;
            }
        }
//pushed all the way to a leaf

        return minimum;
    }

}

//Function to insert an edge into the priority queue
//Input: An edge to be input into the priority queue
//Output: Null
    void pri_queue :: insert_edge(edge e1)
{
    int i;
    edge* temp =new edge;
    if(last>=n-1)
    {
    cout<<"Priority queue is full";
//    exit(1);
    }
    else
    {
          //Adding an edge into the priority heap
    last=last+1;

    e[last]->pri_val=e1.pri_val;
    e[last]->v1=e1.v1;
    e[last]->v2=e1.v2;


    //i is the index of the current position of added edge
    i=last;

//comparing and interchanging the edge so
//that lower priority edges reach the top most point
        while((i>0)&&(e[i]->pri_val<e[((i+1)/2)-1]->pri_val))
        {
        temp=e[i];
        e[i]=e[((i+1)/2)-1];
        e[((i+1)/2)-1]=temp;
        i=((i+1)/2)-1;
        }
    }
}


//Function to make the array of pointer to the edges = null
//Result: Edges are removed from the priority queue
//Input: NULL
//Output: NULL

    void pri_queue :: make_null(void)
{
    //Here last represents the location of element of the queue
    //Initializing the queue
    last=-1;

}

//Constructor
//Initializes the priority queue such that the an array of
//edges is created equal to the size of the total no of vertex
//Input: No of edges
//Output : Null
    pri_queue:: pri_queue(int no)
    {

        n=no;
    e=new edge*[n];
    for(int i=0;i<n;i++)
      {
        e[i]=new edge;
      }
    }
