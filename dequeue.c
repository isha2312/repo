//3. Implement a double ended queue (deque).

#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*first=NULL;


void atHead(struct Node *p, int element)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    struct Node *f=first;
    t->data=element;
    
    if(p==NULL)
    {
        first=t;
        first->prev=NULL;
        first->next=NULL;
    }
    else
    {
        f->prev=t;
        t->next=f;
        first=t;
        first->prev=NULL;
    }
}


void atTail(struct Node *p, int element)
{
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=element;
    if(p==NULL)
    {
        first=t;
        first->prev=NULL;
        first->next=NULL;
    }
    else
    {
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=t;
    t->prev=p;
    t->next=NULL;
    }
}

int peekTail(struct Node *p)
{
    if(p==NULL)
    {
        printf("EMPTY\n ");
        return -1;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        return p->data;
    }
}

int peekHead(struct Node *p)
{
    if(p)
    return p->data;
    else
    {
        printf("EMPTY DEQUE !\n");
        return -1;
    }
}

int remFromhead(struct Node *p)
{
    int x=-1;
    struct Node *f;
    if(p==NULL)
    {
        printf("ALREADY EMPTY !! \n");
    }
    else
    {
        f=first;
        first=first->next;
        first->prev=NULL;
        x=f->data;
        free(f);
    }
    return x;
}

int isPresent(struct Node *p, int element)
{
    while(p!=NULL)
    {
        if(element==p->data)
        return 1;
        p=p->next;
    }
    return 0;
}

int remFromTail(struct Node *p)
{
    int x=-1;
    struct Node *q;
    if(p==NULL)
    {
        printf("ALREADY EMPTY !! \n");
    }
    else
    {
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        x=p->data;
        q->next=NULL;
        free(p);
    }
    return x;
}

void display(struct Node *p)
{
    int x;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    
     printf("Element at Peekhead = %d \n",peekHead(first));
    printf("Elemnt at Peektail = %d \n",peekTail(first));
    
    printf("\nEnter element to search in queue: ");
    scanf("%d",&x);
    
    if(!isPresent(first,x))
    printf("Not present\n");
    else
    printf("Present\n");
}


int main()
{
    
    int data, ch;
        
        while (1) {
                printf("1. Enqueue at front\n2. Enqueue at rear\n");
                printf("3. Dequeue at front\n4. Dequeue at rear\n");
                printf("5. Display\n6. Exit\n");
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter the data to insert:");
                                scanf("%d", &data);
                                atHead(first,data);
                                break;

                        case 2:
                                printf("Enter ur data to insert:");
                                scanf("%d", &data);
                                atTail(first,data);
                                break;

                        case 3:
                                remFromhead(first);
                                break;

                        case 4:
                                remFromTail(first);
                                break;

                        case 5:
                                display(first);
                                break;

                        case 6:
                                return 0;

                        default:
                                printf("Please enter correct option\n");
                                break;
                }
        }

    return 0;
}
