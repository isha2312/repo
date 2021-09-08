//9 Rotate the linked list
struct ListNode* rotateRight(struct ListNode* head, int k)
{
 
   if(head==NULL)
       return NULL;
    
    //finding length of the list
    struct ListNode* temp=head;
    int size=0;
     while(temp!=NULL)
     {
         size++;
         temp=temp->next;
     }
    
    k=k % size;
    
    struct ListNode* p1=head;
    struct ListNode* p2=head;
    
    //moving p2 by k nodes
    for(int i=0;i<k;i++)
    {
        p2=p2->next;
    }
    
    while(p2->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }
     
    p2->next=head;
    
    struct ListNode* newhead;
     newhead=p1->next;
     p1->next=NULL;
    
    return newhead;
    
    }
