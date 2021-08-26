//7. Reverse linked list
struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
 struct ListNode* temp = head;
    
if (left != right) 
{
  for (int i = 1; i < left - 1; ++i)
  {
    temp = temp->next; // it stores previous of the start from where list is to be rev
  }
  struct ListNode* fr = NULL;
  struct ListNode* prev = temp;
  struct ListNode* Right = temp->next;
      
  temp = temp->next;
      
  for (int j = left; j <= right; j++)
  {
      // reversing the sublist
    fr = temp->next;
    temp->next = prev;
    prev = temp;
    temp = fr;
  }
 

  head->next = prev;
  Right->next = temp;
      
  return head;
}
else 
    return head;
}
