// implement stacks using queue


// 1. Implement stack operations

#include <stdio.h>

struct node {
    int data;
    struct node *next;
}*top;
 
/*
Initialize an empty stack
*/
void initialize() 
{
    top = NULL;
} 
 
/*
Checks if Stack is empty or not
*/
int isEmpty() 
{
    if (top == NULL) 
        return 1;
    else
        return 0;
}
 
/*
Returns the top element of Stack
*/
int peek() 
{
    return top->data;
}
 

// Push an Element in Stack 
void push(int num) 
{
    struct node *temp;
    temp =(struct node *)malloc(1*sizeof(struct node));

    temp->data = num;
     
    if (top == NULL)
     {
        top = temp;
        top->next = NULL;
    } 
    else
     {
        temp->next = top;
        top = temp;
    }
}
 

//Pop Operation: Removes Top Element of the Stack

void pop() 
{
    struct node *temp;
    if (isEmpty(top))
     {
        printf("\nStack is Empty\n");
        return;
    } '
    else
     {
        temp = top;
        top = top->next;
        printf("Removed  Element : %d\n", temp->data);   
        free(temp); 
    }
}
 
/*
 Prints the linked list representation of a stack  
*/
void printStack(struct node *node) 
{
  while (node != NULL) 
  {
     printf("%d", node->data);
     nodePtr = node->next;
     if(node!= NULL)
         printf(" ");
  }
  printf("\n");
}
 
int main() 
{
   /* Initialize Stack */
   initialize();

   /* Push Elements in stack */
   push(1);
   push(2);
   push(3);
   push(4);

   /* Printing top element of Stack */
   printf("\nTop Element : %d\n", peek());

   /* Printing Stack */
   printf("Stack as linked List\n");

   printStack(top);

   /* Removing elements from stack */
   pop();
   pop();
   pop();
   pop();
   pop();

   printStack(top);
    
   return 0;
}
