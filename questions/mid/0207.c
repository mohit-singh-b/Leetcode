#define DEBUG

#ifdef DEBUG
  #define dbg(x)          printf(#x " = %d\n", (int)(x))
  #define dbgp(x)          printf(#x " = %p\n", (int*)(x))
  #define dbgf(x)        printf(#x " = %f\n", (double)(x))
  #define dbgs(x)        printf(#x " = %s\n", (char*)(x))
  #define dbga(arr, n) do { \
      printf(#arr " = ["); \
      for(int _i=0; _i<(n); _i++) printf("%d ", (arr)[_i]); \
      printf("]\n"); \
  } while(0)
#else
  #define dbg(x)          ((void)0)
  #define dbgf(x)        ((void)0)
  #define dbgs(x)        ((void)0)
  #define dbga(arr, n) ((void)0)
#endif


typedef struct Node{
    int val ;
    int size ;
    bool visited;
    bool completed;
    struct Node **nb;
}Node;
bool dep(Node *h);
bool canFinish(int n, int** prerequisites, int pn, int* prerequisitesColSize) { 

    int i , j=0 ,head = 0 , tail = 0 ,c1 , c2 ; 
    Node  *h, *t,*c,*pop;
    Node **node = calloc(n,sizeof(Node*));

    if ( pn == 0 || n == 0)
        return true;
    
    for ( i = 0 ; i < pn ; i ++){
        c1 = prerequisites[i][0];
        c2 = prerequisites[i][1];

        if ( c1 == c2 )
            return false ;

        if ( node[c1] == NULL){
            node[c1] = calloc(1,sizeof(Node));
            node[c1]->nb = malloc(n*sizeof(Node*));
            node[c1]->val = c1;            
        }
        if ( node[c2] == NULL){
            node[c2] = calloc(1,sizeof(Node));
            node[c2]->nb = malloc(n*sizeof(Node*));
            node[c2]->val = c2;            
        }


        (node[c1]->nb)[(node[c1]->size)++] = node[c2];
    }


    
    for ( i = 0 ; i < pn ; i ++){
        h = node[prerequisites[i][0]];
            if(dep(h) == false)
                return false;
        
    }

    return true ;
    
}

bool dep(Node *h){

    
    Node *nb ;
    if ( h->visited )
        return false;
    if( h->completed)
        return true;

    h->visited = true;

    for ( int i =0 ; i < h->size ; i++){
        nb = h->nb[i];
        if(dep(nb) == false)
            return false;
        

    }
    h->visited = false;
    h->completed = true;
    return true;
}