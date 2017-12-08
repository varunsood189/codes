
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
#include"fibo_heap.h"

void fheap :: Fib_Delete(int x)
{  fheap f4;
    int Delete;
    f4.Init_fheap();
    f4.no=no;
    f4.hmin=hmin;
    if(f4.hmin->value==x)
    {
            if(f4.no>1)
            {int Min;
            Min=f4.Fib_heap_extract_min();  // Extract min operation
            cout<<"Min = "<<Min<<"\n";
            }
            else{
            cout<<"Min="<<f4.hmin->value<<"\n";
            f4.no=f4.no-1;
            f4.hmin=NULL;
            }
            no=f4.no;
            hmin=f4.hmin;
    }else{
    f4.Fib_heap_decrease_key(x,f4.hmin->value-1);
    if((f4.no!=0)&&(f4.no>1))
        {
            if(f4.no>1)
            {int Min;
            Min=f4.Fib_heap_extract_min();  // Extract min operation
            cout<<"Min = "<<Min<<"\n";
            }
            else{
            cout<<"Min="<<f4.hmin->value<<"\n";
            f4.no=f4.no-1;
            f4.hmin=NULL;
            }
            no=f4.no;
            hmin=f4.hmin;
            }
            else{
                cout<<"Heap is empty";
            }
            }
}
//Cascading a node
        void fheap:: Cascading_cut(node *h,node *y)
        {
        node * z=new node;
        z=y->parent;
        if(z!=NULL)
        {
            if(y->mark==0)
            {
                y->mark=1;
            }
            else
                {
                Cut(h,y,z);
                Cascading_cut(h,z);
                }
        }
        }

//Cutting the value of the node from the root list
        void fheap :: Cut(node *h ,node *x,node *y)
        {
            //Remove the x from the child list of y,decrementing the degree of y;
           node * temp=new node;
           //When y points to the child x
           if(y->child==x)
           {
               // if x is the only child
               if(x->Left==x)
               {
                   y->child=NULL;
               }//If x has a neighbor
               else
               {
                   y->child=x->Left;
                   //Removing x from the child list of y
                   (x->Left)->Right=x->Right;
                   (x->Right)->Left=x->Left;
               }
           }
           //When y does not point to x
           //So, there must be more than 1 children of y
           else{
           if(x->Left!=x)
           {
                    (x->Left)->Right=x->Right;
                    (x->Right)->Left=x->Left;
           }
           }
           y->degree=y->degree-1;
           //add x to root list of Heap;
            temp=h->Right;
            h->Right=x;
            temp->Left=x;
            x->Left=h;
            x->Right=temp;
           //use h=hmin
           x->parent=NULL;
           x->mark=0;
        }

//Location of the Old key
   node* fheap :: node_find(node *p,int old2)
   {
            node* loc=new node;
            loc=NULL;
            int key=p->value;
//            cout<<"loc is      "<<loc<<"\n";
//            cout<<"key is      "<<key<<"\n";
//            cout<<"old2 is       "<<old2<<"\n";
        if(key!=old2)
        {
//            cout<<"key is      "<<key<<"\n";
//            cout<<"old2 is       "<<old2<<"\n";
          node * chi=new node;
         node * x=new node;
         chi=p->child; // children of the present node
         x = chi;
         if((chi!=NULL)&&(loc==NULL))//Checking if the node y has a child or not
        {
        do
        {
        loc=node_find(chi,old2);
        chi=chi->Left;
        }
        while((chi!=x)&&(loc==NULL));
        }
        }
        else
            {
                loc=p;
                return loc;

        }
        return loc;
   }


node * fheap :: Find(int old1,node *h)
    {
    node *loc=new node;
    node *cd=new node;
    node *temp=new node;
    loc=NULL;
    cd=hmin;
    temp=cd;
        do{
//
//            cout<<"loc is      "<<loc<<"\n";
//        cout<<"in node find    "<<"\n";
        loc=node_find(cd,old1);
//        cout<<"out of node find    "<<"\n";
//            cout<<"loc is      "<<loc<<"\n";
        cd=cd->Left;
         }
        while((cd!=temp)&&(loc==NULL));
    return loc;
    }
// Decrease the key value
        void fheap :: Fib_heap_decrease_key(int Old,int New)
        {
            //If new value is less than old value
            if(New<Old)
            {
          node * loc=new node;
          node * par=new node;
          loc=Find(Old,hmin);
          if(loc!=NULL)
              {
              loc->value=New;
              par=loc->parent;// Getting the value of the parent
              if((par!=NULL)&&(loc->value)<(par->value))
              {
               Cut(hmin,loc,par);
               Cascading_cut(hmin,par);
              }
              if((loc->value)<(hmin->value))
              {
                  hmin=loc;
              }
    //varun
    //        if(loc!=NULL)
    //        {
    //        cout<<"Key found="<<loc;
    //        }
    //        else
    //        {
    //            cout<<"Key not found";
    //        }
            //varun
                }else
                {
                    cout<<"Node not found";
                }
            }
            else
            {
cout<<"new key is larger than the old one";
            }
        }
//Print instruction for the heap root list
//Calling the function recursively
        void fheap:: print_heap(void )
        {
            node * x= new node;
            x=hmin;
              do
                {
                    cout<<"parent = ";
                print_tree(x);// Calling the tree to print the node along with the children
                x=x->Right; //Iteration which direction to move
               cout<<"\n";
               }while(x!=hmin);// Check if we have reached at the staring node
        }
//
        void fheap :: print_tree(node *y)
        {
         int key=y->value;
         //cout<<"\n"<<key<<" "; // printing the root
         node * chi=new node;
         node * x=new node;
         chi=y->child; // children of the present node
         x = chi;
         cout<<key<<" ";
        if(chi!=NULL)//Checking if the node y has a child or not
        {
            int i=1;
        do
        { if(i>0)
        {
        cout<<"(";
        i--;
        }else
        {
            cout<<", ";
        }
        print_tree(chi);

        chi=chi->Left;
        }
        while(chi!=x);
        cout<<")";
        }
        }

// Fheap node heap link
// This makes the node y a child of node x in the heap f4
//Input : heap f4, 2 node pointers x,y
//output: none
void fheap :: fib_heap_link(fheap f4, node *y, node *x)
         {
    // Initializing the node
            node * temp=new node;
            node * temp2=new node;
            node * chd=new node;
            node * chd2=new node;
            temp=y->Left;
            temp2=y->Right;
   //Remove node 'y' from the root list of Heap
            temp->Right=temp2;
            temp2->Left=temp;
    //Make 'y' a child of 'x', increment x degree
    // No child of node 'x'
            if(x->child==NULL)
            {
                x->child=y;
                y->Left=y;
                y->Right=y;

            }

            else if((x->child->Left)==(x->child))
            {
            chd=x->child;
            y->Right=chd;
            y->Left=chd;
            chd->Left=y;
            chd->Right=y;
            }
    // more than 1 child of 'x'
            else
            {

            chd=x->child;
            chd2=chd->Left;
            chd->Left=y;
            chd2->Right=y;
            y->Left=chd2;
            y->Right=chd;
            }
            y->parent=x;
            x->degree=x->degree+1;
            y->mark=0;

         }
// Consolidate is done after the extract min operation
// Input : heap h3
//Output :a consolidated heap
node* fheap :: consolidate(fheap h3)
{
    int d = log(h3.no)/log(2);
    // Initializing an node array
    node * a[d] ;// = new node[d];
    for(int i=0;i<=d;i++)
    {
        a[i] = NULL; // node pointer to the array
    }
    int value=0;
    node * temp= new node;
    node * x= new node;
    node * y= new node;
    node * itr= new node;
    x=h3.hmin;

    //for each node in the root list of heap
    itr=h3.hmin->Left;
    value=value+1;

    while(itr!=h3.hmin)
    {
        value=value+1;
        itr=itr->Left;
    }
    // for each node w in the root list of H
    for(int q=0;q<value;q++)
    {
        x=x->Right;// Iterating example
        int d=x->degree; //Getting degree of the x node.
        while(a[d]!=NULL)
        {
            y=a[d];

            // Exchange x and y pointer if the value
            // at the x pointer is more than that of y
            if((x->value)>(y->value))
            {
                temp=x;
                x=y;
                y=temp;
            }

            //Fibonacci heap link in order to combine
            //the x and y linked heaps
            fib_heap_link(h3,y,x);

            a[d]=NULL;
            d=d+1;
        }

        //After increasing the degree and linking the node to another node of heap
        // we can add the node to the array of nodes at updated degree location
        a[d]=x;// Storing the pointer to the heap of degree d
    }
    h3.hmin=NULL;

//     Creating a heap using the elements of the array of nodes
    for(int i=0;i<=d;i++)
{
        if(a[i]!=NULL)
        {
            if(h3.hmin==NULL)
            {
        //creating a root list with just a[i]
            h3.hmin=a[i];
            a[i]->Left=a[i];
            a[i]->Right=a[i];
            }
            //if h3.hmin is the only element in root list
            else if(h3.hmin==h3.hmin->Left)
            {
            a[i]->Left=h3.hmin;
            a[i]->Right=h3.hmin;
            h3.hmin->Left=a[i];
            h3.hmin->Right=a[i];
            }
           // for the case when we have more than 2 nodes in the root list.
            else
            {
            node * temp= new node;
            temp=h3.hmin->Left;
            a[i]->Left=temp;
            a[i]->Right=h3.hmin;
            h3.hmin->Left=a[i];
            temp->Right=a[i];
            }

            if((a[i]->value)<(h3.hmin->value))
            {
                h3.hmin=a[i];
               }
        }
}
return h3.hmin;
// no need to return any value or pointer to heap because the input heap will
//store the updated heap with the pointer in it hmin

}

// To extract the minimum of the heap
//Input is a heap
// output is the minimum element,consolidated heap
int fheap :: Fib_heap_extract_min(void)
{
    node * h =new node;
    h = hmin;
   //Head is not null
    if(h!=NULL)
    {
        //Initialization of nodes
        node * temp=new node;
        node * temp2=new node;
        node * chd=new node;
        node * chd2=new node;
        node * itr=new node;
        chd=h->child;
        //Adding the children into the root list of the heap
        // It has Atleast 1 child
    if(chd!=NULL)
    {
            temp=h->Left;
             // temp is in the root list Neighbor of hmin
            // it has Atleast 1 neighbor
            if(temp!=temp->Right)
            {
                    chd2=chd->Left;
                if(chd2!=chd2->Right)
                    {
                    h->Left=chd;
                    temp->Right=chd2;
                    chd->Left=h;
                    chd2->Right=temp;
                    }
                else
                    {
                    //chd is empty only 1 child
                    h->Left=chd;
                    temp->Right=chd;
                    chd->Right=h;
                    chd->Left=temp;
                    }
            }
    //Hmin has no neighbor in the root list
            else
            {
                 chd2=chd->Left;
                 //no neighbor more than 2 children
                if(chd2!=chd2->Right)
                    {
                    h->Left=chd2;
                    h->Right=chd;
                    chd->Left=h;
                    chd2->Right=h;
                    }
                else
                    {// 1 child no neighbor
                    //chd is empty only 1 child
                    h->Left=chd;
                    h->Right=chd;
                    chd->Right=h;
                    chd->Left=h;
                    }

            }
    }
    //It has no child
    //so no need to add anything to the root.

//    // removing the pointer from child to parent and the pointer from parent to child
//        itr=h->Left;
//        h->child=NULL;
//        node * q=new node;
//        q=itr;
//        itr=itr->Left;
//        while(itr!=q)
//        {
//             itr->parent=NULL;
//             itr=itr->Left;
//        }
//    // removing the hmin form the root list
        temp=h->Right;
        temp2=h->Left;
        temp2->Right=temp;
        temp->Left=temp2;
        //For a heap having only 1 element
        if(h!=h->Right)
        {
        hmin= h->Right;

        fheap h2;
        h2.Init_fheap();
        h2.no=no;
        h2.hmin=hmin;
        node * valu=consolidate(h2);
        h2.hmin=valu;
        no=h2.no;
        hmin=h2.hmin;
        no=no-1;
        return hmin->value;
        }
        else
        {
            hmin=NULL;
            cout<<"Heap is empty\n";
            return 0;
        }

    }

    else
    {
    cout<<"Heap is already empty\n";
    return 0;
    }
   // return 0;

}

//Union of 2 Fibonacci heaps.
         void fheap :: Fib_heap_union(fheap f1,fheap f2)
{
    fheap f;        // creating an empty heap
    f.Init_fheap(); // Initialize it
    f.hmin=f1.hmin; // assigning  it the minimum of the heap 1;
    node * temp1 = new node; // Initializing a new node;
    node * temp2 = new node; // Initializing a new node;
   // Taking the address of the left elements of the the heap
    temp1=f.hmin->Left;
    temp2=f2.hmin->Left;
    //concatenating the 2 heaps
    f1.hmin->Left=temp2;
    temp2->Right=f1.hmin;
    temp1->Right=f2.hmin;
    f2.hmin->Left=temp1;
    // finding out the hmin of the 2 heaps
    if((f1.hmin==NULL)||(f2.hmin!=NULL)&&(f1.hmin>f2.hmin))
    {
        f.hmin=f2.hmin;
    }
     f.no=f1.no+f2.no;
//     return f;
no=f.no;
hmin=f.hmin;
}

//Fibonacci Heap node insert
void fheap :: Fibo_heap_insert(int val)
{   //Initialization of a node with a value
    node* a = new node; // space given to a new node
    node * temp= new node;        // creating a temp node
    a->value=val;       // setting value
    a->degree=0;        // degree equal to zero
    a->parent=NULL;     //parent equal to null as no parent
    a->child=NULL;      // child equal to null as no child
    a->Left=a;          // Left and Right pointer to itself because
    a->Right=a;         //it is only node in a double linked list
    a->mark=0;          //set mark equal to zero
    //CONCATINATING HEAP IN THE ROOT LIST
    // Here we are inserting node between Hmin and temp
    // There will be 3 cases
    // 1st case
    // if root list is empty
    if (hmin==NULL)
    {
        hmin=a;
    }
    //2nd case
    // If root list has only one element
    else if(hmin->Left==NULL)
    {
        hmin->Left=a;
        hmin->Right=a;
        a->Right=hmin;
        a->Left=hmin;
    }
    //3rd case
    // If root list has more than one element
    else
    {
    temp=hmin->Left; // left of minimum node
    a->Right=temp->Right;
    a->Left=hmin->Left;
    hmin->Left=a;
    temp->Right=a;
    }
    if((no==0)||a->value<hmin->value)
    {
        hmin=a;
    }
    no=no+1;        // Increment the no of nodes
}
//Initialization of Fibonacci heap
 //fheap :: fheap(void)// constructor
 // Initialize using a function instead of constructor although both methods are feasible
  void fheap :: Init_fheap(void)
    {   no=0;
        hmin=NULL;
    }

// Return the pointer to minimum node

    node * fheap :: Fibo_heap_min(void)
    {
        if (hmin==NULL)
        {
            cout<<"String is empty";
            return NULL;
        }
        return hmin;
    }

