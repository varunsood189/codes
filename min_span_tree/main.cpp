
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
#include"fibo_heap.h"

int main()
{           int n,val,Delete;
            fheap f1,f2,f;// Structure node object of 1st heap
            f1.Init_fheap();
            f2.Init_fheap();
            f.Init_fheap();
            node * match=new node;
            node * itr=new node;
            node* minimum= new node;
            match =f1.hmin;
            int bo,Old2,New2,condition,select;

    while(1)
    {
            cout<<"=======================================================\n";
            cout<<"*******************************************************\n";
            cout<<"     Please select the operation"<<"\n";
            cout<<"*******************************************************\n";
            cout<<"=======================================================\n";
            cout<<"Option 1: Select a node"<<"\n";
            cout<<"Option 2: Insert value to the heap"<<"\n";
            cout<<"Option 3: Display the root list"<<"\n";
            cout<<"Option 4: Display the entire heap "<<"\n";
            cout<<"Option 5: Display the minimum of the heap"<<"\n";
            cout<<"Option 6: To extract the minimum of the heap"<<"\n";
            cout<<"Option 7: For Union of 2 Heaps"<<"\n";
            cout<<"Option 8: Decreasing a node"<<"\n";
            cout<<"Option 9: Deleting a node"<<"\n";
            cout<<"Enter any another option to exit\n";
            cin>>n;
            cout<<"\n n = "<<n<<"\n";

     switch (n)
    {


     case 1:
                cout<<"Enter the heap to be Selected\n";
                cout<<"Select from First Heap Input = 0 \n";
                cout<<"Select from Second Heap Input = 1 \n";
                cin>>select;
                //Cond is to save the node address of the previous node while changing to next node

          if(condition==1)
            {
                f1.no=f.no;
                f1.hmin=f.hmin;
                condition=0;
            }else if(condition==2)
            {
                f2.hmin=f.hmin;
                f2.no=f.no;
                condition=0;
            }else
            {
            }

            if(select==0)
            {
                f.no=f1.no;
                f.hmin=f1.hmin;
                condition=1;
            }else if(select==1)
            {
                f.no=f2.no;
                f.hmin=f2.hmin;
                condition=2;
            }else
            {
                cout<<"Enter a valid option.";
            }

            break;
     case 2:
                cout<<"Input the value to be input to the heap"<<"\n";
                cin>>val;
                f.Fibo_heap_insert(val);
                cout<<"Value entered in the heap is "<<val<<"\n";
            break;
    case 3: // Display the root list
           if(f.hmin!=NULL)
           {
                match=f.hmin;
            do
                {
                cout<<match->value<<" ";
                match=match->Left;
            }while(match!=f.hmin);
                cout<<"\n";
           }
           else{
                cout<<"Insert the nodes first";
           }
            break;
    case 4: // For heap
            if(f.hmin!=NULL)
            {
                f.print_heap();
            }
            else
            {
                cout<<"No heap present";
            }
            break;

    case 5: // Display the minimum of the heap
        if(f.hmin!=NULL){
            minimum=f.Fibo_heap_min();
            cout<<"minimum value is "<<minimum->value<<"\n";
        }else
        {
            cout<<"Heap is empty";
        }
            break;
    case 6: // To extract the minimum value of the heap
            if(f.no!=0)
            {
            if(f.no>1)
            {
                int Min;
                Min=f.Fib_heap_extract_min();  // Extract min operation
                cout<<"Min = "<<Min<<"\n";
            }
            else{
                cout<<"Min="<<f.hmin->value<<"\n";
                f.no=f.no-1;
                f.hmin=NULL;
            }
            }
            else{
                cout<<"Heap is empty";
            }
            break;

    case 7: // For Union of 2 Heaps

          if(condition==1)
            {
                f1.no=f.no;
                f1.hmin=f.hmin;
                condition=0;
            }else if(condition==2)
            {
                f2.hmin=f.hmin;
                f2.no=f.no;
                condition=0;
            }else
            {
            }

           if((f1.hmin!=NULL)&&(f2.hmin!=NULL))
           {
                fheap f3;
                f3.Init_fheap();
                f3.Fib_heap_union(f1,f2);
                f3.print_heap();
            }
            else if((f1.hmin!=NULL)&&(f2.hmin==NULL))
            {
                f1.print_heap();
                cout<<"Second heap is empty. So, the First heap is the union of both the heaps.";
            }
            else if((f1.hmin==NULL)&&(f2.hmin!=NULL))
            {
                f2.print_heap();
                cout<<"First heap is empty. So, the second heap is the union of both the heaps.";
            }
            else
                {
                cout<<"Both heaps are empty.";
                }
            break;
    case 8://For decreasing the key vlue at an element
            if(f.hmin!=NULL)
            {
                cout<<"Enter the element to be Decreased = ";
                cin>>Old2;
                cout<<"Enter the new element to be Entered = ";
                cin>>New2;
                f.Fib_heap_decrease_key(Old2,New2);
            }else
            {
                cout<<"Heap is Empty";
            }
            break;
    case 9:
            if(f.hmin!=NULL)
            {
                cout<<"Enter a value to be deleted from the node =";
                cin>>Delete;
                f.Fib_Delete(Delete);
                    }
            else
            {
                cout<<"Heap is Empty";
            }
            break;

    default: // code to be executed if n doesn't match any cases
                exit(1);

        }
        cout<<"\n";
    }

return 0;
}
