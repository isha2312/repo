//9 Rotate the linked list
struct ListNode* rotateRight(struct ListNode* head, int k)
{
 
    // If list is empty
    if (!head)
        return head;

    
    struct ListNode* temp = head;
    
    int c = 1;  // c for storing length of the list
    
    while (temp->next != NULL) 
    {
        temp = temp->next;
        c++;
    }
  // temp is pointing to the last node now

    
 
    // If size of list<k then taking the modulus
    if (k > c)
        k = k % c;
 
    // Subtracting k from length to convert it to left rotations
    k = c - k;
 
    // If no rotation needed then returning head
    if (k == 0 || k == c)
        return head;

    
    struct ListNode* current = head;
    int count = 1;
    while (count < k && current != NULL) 
    {
        current = current->next;
        count++;
    }
    //current points to kth node now or to NULL
    
 
    // If current = NULL then it means k = count of nodes
    if (current == NULL)
        return head; //no change in this case
    
 
    // If current points to the k node
    struct ListNode* knode = current;
 
    // Change next of last node to previous head
    temp->next = head;
 
    // Change head to (k+1)th node
    head = knode->next;
 
    // Change next of kth node to NULL
    knode->next = NULL;
 
    // Return the updated head 
    return head;
  
    
}
