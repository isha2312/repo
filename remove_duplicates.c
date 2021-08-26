//5 . Remove duplicate from sorted list
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    // creating a temp node that points to original head
   struct ListNode temp = (struct ListNode)malloc(sizeof(struct ListNode));
     temp->next = head;
     
    
    struct ListNode *prev=temp;   // node for pointing to last node which has no duplicate
   struct ListNode *current=head; // node for traversing linked list
    
     while(current!=NULL)
     {
         
       while(current->next!= NULL && current->val == current->next->val)
        current=current->next; //if duplicate numbers then increase the current till last duplicate
         
    
// if no duplicate value then prev will increase
         if(prev->next==current)
             prev=prev->next;
    
        
      // if duplicate values then move the prev to next of the last duplicate value   
         else
             prev->next=current->next;
         
         current=current->next;
     }
    
    // to also remove the repeating values at starting we return temp->next
    return temp->next;
   
}
