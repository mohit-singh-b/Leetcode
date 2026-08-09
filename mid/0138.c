/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
  typedef struct Hash{
    struct Node *s , *c ;
    UT_hash_handle hh;
 }Hash;

struct Node* copyRandomList(struct Node* head) {
	Hash *hash = NULL , *temp = NULL ;
    struct Node *c = head , *h = NULL , *p = NULL, *c2 = NULL ;

    if ( head == NULL)
        return NULL;

    while( c != NULL ){
        c2 = malloc(sizeof(struct Node));
        temp = malloc(sizeof(Hash));
        c2->val = c->val ;

        temp->s = c;
        temp->c = c2;
        HASH_ADD_PTR(hash,s,temp);
        
        if ( p != NULL)
            p->next = c2;

        if( h == NULL )
            h = c2;
        
        p = c2;
        c2 = NULL;
        c = c->next;
    }

    p->next = NULL;

    c = head;
    c2= h;
    temp = NULL;
    while(c!= NULL){

        if ( c->random == NULL){
            c2->random = NULL;
            c = c->next;
            c2=c2->next;
            continue;
        }

        HASH_FIND_PTR(hash,&(c->random),temp);
        c2->random  = temp->c;
        c = c->next;
        c2 = c2->next;

    }

    return h;


}