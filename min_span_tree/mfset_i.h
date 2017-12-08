//Mfset ADT header file.
//Function declaration

#ifndef MFSET_I_H_INCLUDED
#define MFSET_I_H_INCLUDED

class mfset
{
public:
    int n;                           //No of vertex
    int *a;                          //Pointer to the array to store the mfset in
    //function implementation
    mfset(int);                      //constructor
    void mfset_Init(void);          // Initialization
    void  merge_mfset(int,int);     //Merges the mfset
    int find_mfset(int);            //Finds the component of the mfset
    void print_mfset(void);          //Print the mfset
};

#endif // MFSET_I_H_INCLUDED
