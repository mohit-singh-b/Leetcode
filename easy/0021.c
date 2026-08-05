struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *temp,*temp2 , *curr=NULL,*head;  

    if ( list1 ==  NULL  )
        return list2;
    if (list2 == NULL)
        return list1;
    
    
    if ( list1->val <= list2->val){
        curr = list1;
        temp = list2;
        head = curr;
    }
    else {
        curr = list2 ;
        temp = list1;
        head = curr;
    }
    while(curr->next!= NULL ){
        

        if ( curr->next->val >= temp->val){
            temp2 = curr->next;
            curr->next = temp;
            curr = temp;
            temp = temp2;
            
        }
        else {
            curr = curr->next;
        }

    }

    if ( temp != NULL){
        curr->next = temp;
    }

    return head;

}