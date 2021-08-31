//4. palindrome linked list
bool isPalindrome(struct ListNode* head)
{

       struct ListNode* slow=head;
       struct ListNode* fast=head;
    
    // finding middle element by hare tortoise method
    while(slow!=NULL && fast!=NULL)
    {
        slow=slow->next;
           if(fast->next==NULL)
                  break;
        fast=fast->next->next;
    }
     // now slow stores the middle element of list
    
    //now reversing the list from mid to end
        struct ListNode* prev=NULL;
        struct ListNode* after;
        struct ListNode* curr=slow; //bcz list is to be reversed from slow postion
    
    while(curr!=NULL)
    {
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
    }
    
    fast=head; //fast points to head now
    
    //comparing data of both
     while(prev!=NULL) //prev is pointing to starting element of reversed list
     {
         if (fast->val!=prev->val)
             return false;
         fast=fast->next;
         prev=prev->next;
     }
    
    return true; 
    
    
}
