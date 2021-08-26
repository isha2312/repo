//6. Remove nth node from end of list
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
  int len = 0,i;
   struct ListNode* temp = head;
    
    // finding length of list
    while (temp != NULL) 
    {
        len++;
        temp = temp->next;
    }
     
    // n > length, then we can't remove node
    if (n > len)
    {
        return head;
    }
     
    // if to remove head node
    else if (n == len) 
    {
      return head->next; // returning null
         
    }
    else
    {
        // Remove len-n th node from starting
        int diff = len - n;   
        
        struct ListNode* prev= NULL;      
        struct ListNode* curr = head;
        
        for(i = 0;i<diff;i++)
        {
            prev = curr;           
            curr = curr->next;     
        }
        
        prev->next = curr->next;
        return head;
    }
}
