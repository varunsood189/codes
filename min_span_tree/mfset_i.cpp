//Mfset ADT for the implementation of Prims algorithm
//Includes the code implementation for the Mfset data structure defined in the Mfset header file.


#include<iostream>
#include"mfset_i.h"
using namespace std;

//constructor for the mfset
//Input: No of vertex of the graph
//Output: Null
mfset::mfset(int no)
{
n=no;
//Initializes the array of n components
a=new int[n];

}

//Initialization for the Mfset
//Here the nodes are assigned different components
//Input: Null
//Ouput:Null
void mfset ::mfset_Init(void)
{
for(int i=0;i<n;i++)
    a[i]=i;
}

//Finds the component of the x element
//Input  : Node no
//Output : Component of the node.

int mfset::find_mfset(int x)
{
return a[x];
}

//merges 2 different components
//Input: 2 different component names
//Output: Null
void mfset::merge_mfset(int A, int B)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==B)
        {
            a[i]=A;
        }
    }
}

//Prints the mfset , component with the the node no
//Input: Null
//output: Null

   void mfset:: print_mfset(void)
{
        for(int i=0;i<n;i++)
            {
            cout<<"i = "<<i+1<<", component = "<<a[i]+1<<endl;
            }

}
