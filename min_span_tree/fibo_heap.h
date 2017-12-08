#ifndef FIBO_HEAP_H_INCLUDED
#define FIBO_HEAP_H_INCLUDED



 //  Declaration for the node
struct node
{
    public:
    int value;
    node* parent;
    node* child;
    node* Right;
    node* Left;
    int degree; // Degree of the node
    bool mark;  // Is it marked or not
};

// Creating a class function for heap initialization
// Also for Fibonacci heap initialization
class fheap
{
    public:
    int no;         //  no of nodes
    node* hmin;     // pointer to node structure
   // Fibonacci heap representation
    public:
       //  fheap(void);                   //constructor for initialization of Fibonacci heap
         node * Fibo_heap_min(void);    //Node pointer to the minimum of Fibonacci heap
         void Fibo_heap_insert(int val); // Insert a node into heap
         void Init_fheap(void);  // Initialize a heap using a Function
         void Fib_heap_union(fheap ,fheap ); //Union of 2 heaps
         int Fib_heap_extract_min(void);  // Extract min operation
         node * consolidate(fheap );         // Consolidate after the extract min operation
         void fib_heap_link(fheap ,node *,node *); //Link heap it means to make a node child of another node
         void print_heap(void );
         void print_tree(node *);
         void Fib_heap_decrease_key(int, int);
         node * Find(int,node *);
         node * node_find(node *,int);
         void Cut(node *,node *,node *);
         void Cascading_cut(node *,node *);
         void Fib_Delete(int);

};

#endif // FIBO_HEAP_H_INCLUDED
