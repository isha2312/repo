//2 Implementing queue using linked list

#include <stdio.h>
#include<stdlib.h>
struct node   
{  
    int data;   
    struct node *next;  
}; 

struct node *front;  
struct node *rear;   
 
 
int is_empty()
{
   if(front == NULL)  
    {  
        return 1;  
    } 
    else
    {
        return 0;
    }
    
}

int peek()
{
    return front->data;
}

void enqueue()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node)); 
    
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
         
    } 
    
    else  
    {   
        printf("\nEnter value:\n");  
        scanf("%d",&item);  
        // inserting value
        ptr -> data = item; 
        
        // if queue is empty
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        } 
         //otherwise add elements at end of queue
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}  

void dequeue ()  
{  
    struct node *ptr; 
    
    // if queue is empty
    if(is_empty())  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    } 
    
    // otherwise store the front and move front one node ahead
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
} 


void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(is_empty())  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting elements of queue:\n");  
        while(ptr != NULL)   
        {  
            printf("%d ",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
    
    printf("\nElement at peek: %d",peek());
} 

int main ()  
{  
    int choice;   
    while(choice != 4)   
    {     
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice :");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:  
            enqueue();  
            break;  
            case 2:  
            dequeue();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:  
            return;  
            break;  
            default:   
            printf("\nEnter valid choice\n");  
        }  
    }  
    return 0;
}
