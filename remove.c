//6. Remove nth node from end of list
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
  struct ListNode*curr=head;
    int l=0;

    while(curr!=NULL)
    {
        l++;
        curr=curr->next;
    }
    // n > length, then we can't remove node
    if (n > l)
    {
        return head;
    }
     
    // if to remove head node
    else if (n == l) 
    {
      return head->next; // returning null
         
    }
    
    // Remove len-n th node from starting
    int index=l-n;
    
    
    
    struct ListNode* p=head;
        struct ListNode*q=head->next;
    
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    
    p->next=q->next;
    free(q);
    
    return head;
    
    
}
