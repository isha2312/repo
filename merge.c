//8. Merge two sorted list

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    
    struct ListNode* p1=l1; // pointing to first list
    struct ListNode* p2=l2;  // pointing to second list
    
   struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode)); //new dummy node
      struct ListNode* p3=dummy; // pointing to dummy node
  
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    
    
    while(p1!=NULL &&p2!=NULL)
    {
        if(p1->val < p2->val) // if p1 data is less than p2
        {
            p3->next=p1; // add p1 to dummy node
            p1=p1->next; // increase p1 
        }
        
        else
        {
            p3->next=p2; // otherwise add p2 to dummy node
            p2=p2->next; // and increase p2
        }
        // p3 will increase in both cases
        p3=p3->next;
       
    } 
      // if p2 reaches null then add rest of values of p1 to p3
        while(p1!=NULL)
        {
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        
       //if p1 reaches null then add rest of values of p12 to p3 untill p2 also reaches null
        while(p2!=NULL)
        {
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
    
        // returning the merged list
        return dummy->next;
        
    

}
