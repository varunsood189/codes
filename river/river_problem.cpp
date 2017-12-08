//Program: A person is traveling with a wolf, a goat, and a bag of cabbages.
//Coming to a river, the person finds a small boat, capable of holding only him/her,
//and one more animal or item: the wolf, the goat, or the cabbage sack. The animals
//are well-behaved when the person is with them i.e., the wolf doesn't try to think
//of the goat when it comes to getting hungry, and the goat is least interested in the
// cabbages in a similar situation. However, the person would not dare to leave these
//pairs on one side of the river to themselves, lest anarchy rule. In how many ways
//can the river crossing be done?

// --------------------------------------------------------------------------------------------

//  I have found out about the multiple paths possible for the person
//Output will be give below

//Representation

//[Person Cabbage Goat Wolf] = [0 0 0 0]

//Here 0 denotes one side of the river and 1 denotes second side of the river.

//above statement means that the person is on one side of the river and he needs to go to the
//other side of the river with his animals

//constraints

//person cannot leave the goat and the cabbage on one side without his supervision
//person cannot leave the goat and the wolf on one side without his supervision

//First Path

//[Person Cabbage Goat Wolf] = [0 0 0 0]
//[Person Cabbage Goat Wolf] = [1 0 1 0]
//[Person Cabbage Goat Wolf] = [0 0 1 0]
//[Person Cabbage Goat Wolf] = [1 1 1 0]
//[Person Cabbage Goat Wolf] = [0 1 0 0]
//[Person Cabbage Goat Wolf] = [1 1 0 1]
//[Person Cabbage Goat Wolf] = [0 1 0 1]
//[Person Cabbage Goat Wolf] = [1 1 1 1]

//Second Path

//[Person Cabbage Goat Wolf] = [0 0 0 0]
//[Person Cabbage Goat Wolf] = [1 0 1 0]
//[Person Cabbage Goat Wolf] = [0 0 1 0]
//[Person Cabbage Goat Wolf] = [1 0 1 1]
//[Person Cabbage Goat Wolf] = [0 0 0 1]
//[Person Cabbage Goat Wolf] = [1 1 0 1]
//[Person Cabbage Goat Wolf] = [0 1 0 1]
//[Person Cabbage Goat Wolf] = [1 1 1 1]

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int no=2;
int l=1;

//For the elements of boat that is person, cabbage, wolf, goat
struct node
{
    bool per;                    //Man
    bool cab;                    //cabbage
    bool goat;                  //goat
    bool wolf;                   //wolf
    };

//Class river for the declaration of the function
 class river
{
    public:
    int  event[4]={1,2,3,4};
    //4 elements of array correspond to 4 events
    // Event 1 we are sendend the man back,
    //Event 2 we are sending the man with the goat
    //Event 3 , we are sending the man with the cabbage,
    //Event 4, we are sending the man with the wolf;
    node * next=new node;
    node * previous=new node;
    node * present=new node;
    river *r;
    river *p;
    river *n;
    //function declarations
    void Init_river(void);
    river()
    {
        next=NULL;
        Init_river();
        previous=NULL;
        n=NULL;
        p=NULL;
    }
    void name(river*);
    void print(void);
    bool valid(int eve);
    void next_state(int eve,river* r4);
    void nameloop(river *,int,int);
    bool final_st(river* r2);
    void display(river *);
   };

//Displays the sequence taken by the loop
//Input: Input the river pointer to transverse the loop
//Output: void
void river :: display(river* r3)
{
    river *r1;
    r1=r3;

    if(r3->p!=NULL)
    { r3=r3->p;
      r3->display(r3);
    if(no==2)
    {
        r3->n->print();
    }
    if(no==1)
    {
        if((r3->n->present->per==0)&&(r3->n->present->cab==0)&&(r3->n->present->goat==1)&&(r3->n->present->wolf==0)&&l==1)
           {
               l=l-1;
           }
        else if((r3->n->present->per==1)&&(r3->n->present->cab==1)&&(r3->n->present->goat==1)&&(r3->n->present->wolf==0))
    {

    }
    else{
r3->n->print();
    }
    }
    }else
    {
        r3->print();
    }

}

//Checks if the final state is reached or not
//Input: River pointer on which to check if final state is here
//Output: Boolean if the output is reached or not
bool river ::final_st(river* r2)
 {
     river* r3=new river;
     r3->present->cab=1;
     r3->present->goat=1;
     r3->present->per=1;
     r3->present->wolf=1;
     if((r2->present->cab==r3->present->cab)&&(r2->present->per==r3->present->per)&&(r2->present->wolf==r3->present->wolf)&&(r2->present->goat==r3->present->goat))
     {
         return 0;
     }
     else
     {return 1;
     }
 }
// Finding the path through the loop
//Input: River pointer to transverse the path
//     : Alpha tells the no of events
//      :previous for the previous state
//Output: void
void river :: nameloop(river* r2,int alpha,int previous)
{
    river r;
    //getting the river element form input
    r=*r2;
   // r4=r;
    river* r3=new river;
    river* r4=new river;
    r3->present->cab=r2->present->cab;
    r3->present->per=r2->present->per;
    r3->present->goat=r2->present->goat;
    r3->present->wolf=r2->present->wolf;
        bool b,final_state;

        for(int i=1;i<=alpha;i++)
        {
            if(i!=previous)
            {
            b=r.valid(i);
            if(b==1)
            {
                b=0;
                    r.next_state(i,r3);

                    r3->p=r2;
                    r2->n=r3;

                    final_state=r.final_st(r3);
                if(final_state!=0)
                {
//                    r3->print();
//                    cout<<"\n";
                    nameloop(r3,alpha,i);
                }
                else
                {
                    final_state=1;

                    r.display(r3);
                    no=no-1;
                    if(no==1)
                    {
                    cout<<"\nSecond Path\n";
                    }
                    if(no==0)
                    {
                    exit(1);
                    }

                }

            }
        }else
        {
        previous=0;
        }
    }

}
//Next state is returning me the next state of the river in the pointer
//Input is the present state and the event
void river :: next_state(int eve,river* r4)
    {
     switch(eve)
       {
           // Person travels alone
        case 1:
                r4->present->per=!r4->present->per;
               //cout<<"Person crosses the river alone\n";
                break;

                //person travels with cabbage
        case 2:if(r4->present->per==r4->present->cab)
               {
                r4->present->per=!r4->present->per;
                r4->present->cab=!r4->present->cab;
               //cout<<"Person crosses the river with cabbage\n";
               }
                break;

                 //person travels with goat
        case 3: if(r4->present->per==r4->present->goat)
               {
                r4->present->per=!r4->present->per;
                r4->present->goat=!r4->present->goat;
               //cout<<"Person crosses the river with goat\n";
               }

                break;
                //person travels with wolf
        case 4:
            if(r4->present->per==r4->present->wolf)
               {
                r4->present->per=!r4->present->per;
                r4->present->wolf=!r4->present->wolf;
               // cout<<"Person crosses the river with wolf\n";
               } break;
        default:
                break;
       }
    }

//Prints the present state
//Input: void
//Output: void
void river :: print(void)
    {
        //cout<<"Initial state 0";
        cout<<"[Person Cabbage Goat Wolf] = ["<<present->per;
        cout<<" "<<present->cab<<" ";
        cout<<present->goat<<" ";
        cout<<present->wolf<<"]\n";
    }
//Checks the validity of the present state
//Input: eve :event
//Output: ret
//        Ret =1 valid
//        Ret=0 not valid

bool river :: valid(int eve)
    {

        river r1;
        bool ret=1,security=0; //Here eve is the event
         //invalid state for the graph for stooping the exec


        if((present->per==0)&&(present->cab==0)&&(present->goat==1)&&(present->wolf==0))
        {
        if(eve==3&&no==1)
        {
//            cout<<no<<"\n";
//            cout<<eve<<"\n";
        ret = 0 ;
        security=1;
        }
//       if(no==1&&eve==4)
//       {
//  //         cout<<"eve  "<<eve;
//            ret= 1;
//            //cout<<"event =   "<<present->per<<present->cab<<present->goat<<present->wolf<<"\n";
//
//            security=1;
//       }
      // person invalid
       if(eve==1)
       {
           ret= 0;
           security=1;
       }

   }

//     if((present->per==1)&&(present->cab==0)&&(present->goat==1)&&(present->wolf==0))
//        {
//   if(eve==)
//       {
//           ret= 0;
//           security=1;
//       }
//
//   }
//       if((present->per==1)&&(present->cab==1)&&(present->goat==1)&&(present->wolf==0))
//        {
//        if(eve==2)
//        {
//            ret =0;
//            security=1;
//
//        }
//        }


                  if((present->per==1)&&(present->cab==1)&&(present->goat==0)&&(present->wolf==1))
        {
                if(eve==2||eve==4)
                {
           //cout<<"event =   "<<eve<<"\n";
            ret =0;
            security=1;
                }
       }

       if(security!=1)
       {

       //DO what happens in the event
       r1.present->cab=present->cab;
       r1.present->goat=present->goat;
       r1.present->wolf=present->wolf;
       r1.present->per=present->per;

   switch(eve)
       {
           // Person travels alone
        case 1:
                present->per=!present->per;
               // cout<<"Person crosses the river\n";
                break;
                //person travels with cabbage
        case 2:

            if(present->per==present->cab)
               {
                present->per=!present->per;
                present->cab=!present->cab;
                //cout<<"Person crosses with cabbage\n";
               }else
               {
                   ret=0;
               }
//        }
                break;

          //person travels with goat
        case 3:
               if(present->per==present->goat)
               {
                present->per=!present->per;
                present->goat=!present->goat;
                //cout<<"Person crosses with goat\n";
               }else
               {
                   ret=0;
               }
                break;

                //person travels with wolf
        case 4:
            if(present->per==present->wolf)
               {
                present->per=!present->per;
                present->wolf=!present->wolf;
                //cout<<"Person crosses with wolf\n";

               }else
               {
                   ret=0;
               }
                break;
        default:
                break;
       }
if(ret!=0)
{
       //See if the event is valid or not
            if(present->per!=present->goat)
            {
             if((present->goat==present->cab)||(present->goat==present->wolf))
            {
                ret=0;                      //Error in the implementation
            }else
            {
                ret=1;
            }
            }
            else
            {
                ret=1;                       // Fine in implementation
            }
}
        present->cab=r1.present->cab;
        present->goat=r1.present->goat;
        present->wolf=r1.present->wolf;
        present->per=r1.present->per;
    }

        return ret;
    }
// Initialization for finding the path through the loop
//Input: void
//Output: void
    void river :: name(river* r1)
    {
        bool bo;
        river r;
      //  river r4;
        river* r2=new river;
        //Getting the elements of r1(recieved river object)
        r=*r1;
        //r2=&r;
        cout<<"Here 0 denotes one side of the river and 1 denotes second side of the river.\n\n";
        cout<<"First Path\n\n";

        int loop=sizeof(r1->event)/sizeof(r1->event[1]);
            for(int i=1;i<=loop;i++)
            {
            //check the boolean
            bo=r.valid(i);
            if(bo==1)//works just fine
                {

        //present state is in r,next state is in r2
                r.next_state(i,r2);
        //assigning the previous pointer of the river r2 to the r4
        //assigning the next pointer of the river r4 to the r2
                   // r2->print();
                    r2->p=r1;
                    r1->n=r2;
                    nameloop(r2,loop,i);
                }
            }
}
//Initialization for the river object
//All the elements are on one side of the river.
//Input: void
//Output: void
void river :: Init_river(void)
{       //present=new node;
        present->cab=0;
        present->wolf=0;
        present->per=0;
        present->goat=0;
}
int main()
{
    river r;
    river* r1=new river;
    r1=&r;
    r.name(r1);
    return 0;
}
