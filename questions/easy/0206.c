/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode node;
struct ListNode* reverseList(struct ListNode* head) {
    
    node *prev=NULL ;
    node *nxt=NULL;

    while(head != NULL){
        nxt = head->next;
        head->next = prev;

        prev = head;
        head = nxt;


    }

    return prev;
}