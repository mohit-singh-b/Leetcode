/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *f= head ,*nxt = NULL , *prev = NULL , *c = head , *s = head , *s2 = NULL,*sp = NULL;
    struct ListNode* *a = malloc(5000*sizeof(int*));
    int j = 0 ;
    if ( head == NULL || head->next == NULL|| k== 1)
        return head;

    for ( int i = 0 ; i < k-1 ; i ++)
        f=f->next;

    while(f != NULL){
        
        a[j++] = c;
        for ( int i = 0 ; i < k ; i++){
            if ( f!= NULL )
                 f=f->next;
            
            nxt = c->next;
            c->next = prev;
            prev = c ;
            c = nxt;
        } 
        if ( j == 1)
            head = prev;

        if ( j>1){
            a[j-2]->next = prev;
        }
        if ( c != NULL)
        a[j-1]->next = c;
        else 
            a[j-1]->next = NULL;
        
    }

    return head;

}