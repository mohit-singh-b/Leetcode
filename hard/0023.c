/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge(struct ListNode*,struct ListNode* );
struct ListNode* mergeall(struct ListNode** lists, int n);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *res = NULL;

    if ( listsSize == 0)
        return NULL;
    if(listsSize == 1)
        return lists[0];
    res = mergeall(lists,listsSize);
    return res;

    
}

struct ListNode* merge( struct ListNode* a , struct ListNode* b){
    struct ListNode* c , *temp=NULL , *temp2=NULL ,*head ;

    if ( a == NULL)
        return b;
    if(b == NULL)
        return a;

    if ( a->val <= b->val){
        c = a;
        temp = b;
        head= a;
    }
    else{
        c = b;
        temp = a;
        head = b;
    }

    while(c->next != NULL){


        if ( c->next->val <= temp->val){
            c = c->next;
        }
        else {
            temp2 = c->next ;
            c->next = temp;
            c=temp;
            temp = temp2;
        }
    }
    c->next = temp;

    return head;
}

struct ListNode* mergeall(struct ListNode** lists, int n){


    if ( n == 2){
        printf("(%d ,%d)\n",n);
        return  merge(lists[0],lists[1]);
    }
    int i = 0;


    for (  i = 0 ; i < n-1 ; i+=2){
        
        lists[i/2] = merge(lists[i],lists[i+1]);
    }
    if ( n%2 == 1){
        lists[i/2] = lists[n-1];
        n = i/2+1;}
    else 
        n=i/2;

        return mergeall(lists,n);
}
