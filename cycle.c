// 10. Return nth node from where cycle begins in linked list
struct ListNode *detectCycle(struct ListNode *head) {
    
        if (!head || !head->next)
            return 0;
    
        struct ListNode *hare= head, *tortoise = head;
    
    while(hare!=NULL && tortoise!=NULL)
    {
        tortoise=tortoise->next; //move by one step
        hare=hare->next->next;  //move by 2 steps
        
        if(hare==tortoise)
        {
            // if they meet then taking one pointer to head postion
            tortoise=head;
            
            while (tortoise != hare)
            {   
                //until they meet again, move by one-one step
                 hare = hare->next;
                 tortoise = tortoise->next;
            }
            //meets at location where cycle starts and returning that loc
            return tortoise; 
        }
        
    }
    return 0;
}
