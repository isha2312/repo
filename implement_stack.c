// implement stacks using queue


typedef struct 
{
 int data;
    
} MyStack;

/* Initialize your data structure here. */

int size;
int front;
int end;

int size2;
int front2;
int end2;

int size3;
int front3;
int end3;


MyStack* myStackCreate() 
{    
     MyStack *queue = (MyStack *)calloc(1000 , sizeof(MyStack));
     size = 0;
     front = 0;
     end = 0;
     size3 = 0;
     front3 = 0;
     end3 = 0;
     return queue;
}

MyStack* myStackCreate2() 
{    
     MyStack *queue2 = (MyStack *)calloc(1000 , sizeof(MyStack));
     size2 = 0;
     front2 = 0;
     end2 = 0;
     return queue2;
}

MyStack *stack;

 void createstack() 
{    
     stack = (MyStack *)calloc(1000 , sizeof(MyStack));
     size3 = 0;
     front3 = 0;
     end3 = 0;
}

 

/** Push element x onto stack. */
void myStackPush(MyStack* queue, int x) 
{
    MyStack *queue2 = myStackCreate2();
    int pt=0;
    int sz=size3;
    
    for(int i=front;i<=end-1;i++)
    {
        queue2[pt++].data=queue[i].data;
    }
    
   
    createstack();
    myStackCreate();
    
    queue[end++].data = x;
    
    for(int i=0;i<sz;i++)
    {
        queue[end++].data=queue2[i].data;
    }
    
    int index=end-1;
    for(int i=0;i<end;i++)
    {
        stack[index--].data = queue[i].data;
    }
    
    
    size3=sz+1;
    end3=end;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* queue) 
{
    int ele = stack[end3-1].data;
    end3--;
    size3--;
    return ele;
}

/** Get the top element. */
int myStackTop(MyStack* queue)
{
    return stack[end3-1].data;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* queue) 
{
    return end3 == 0;  
}

void myStackFree(MyStack* queue) 
{
    free(queue);    
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
