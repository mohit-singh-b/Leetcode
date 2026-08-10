/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
typedef struct Node Node;
typedef struct Hash{
    Node *c , *s ;
    UT_hash_handle hh;
}Hash;


struct Node *cloneGraph(struct Node *s) {
	Hash *hash = NULL , *temp = NULL;
    Node *pop ,*nebor, *copy , *h; 
    Node *queue[100] ;
    int i , j ,head = 0 , tail = 0; 

    if ( s == NULL )
        return NULL;
        
    queue[tail++] = s;
    copy = malloc(sizeof(Node));
    h = copy;

    temp = malloc(sizeof(Hash));
    temp->s = s;
    temp->c = copy;
    HASH_ADD_PTR(hash,s,temp);
    while( head != tail){
        
        pop = queue[head++];

        HASH_FIND_PTR(hash,&pop,temp);
        copy = temp->c;
        copy->val = pop->val;
        copy->numNeighbors = pop->numNeighbors;
        copy->neighbors = malloc((copy->numNeighbors)*sizeof(Node*));

        for ( i = 0 ; i < pop->numNeighbors ; i++){
            
            nebor = pop->neighbors[i];
            if ( nebor == NULL ){
                (copy->neighbors)[i] = NULL;
                continue;}
            HASH_FIND_PTR(hash,&nebor,temp);
            if ( temp == NULL ){
                queue[tail++] = nebor;
                temp = malloc(sizeof(Hash));
                temp->c = malloc(sizeof(Node));
                temp->s = nebor;
                HASH_ADD_PTR(hash,s,temp);
            }         

            (copy->neighbors)[i] = temp->c;
            
        }

    }

    return h;
}