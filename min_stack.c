// Min stack



typedef struct {
    int top; //keeps track of topmost elements
    int *min_val; //array to store min elements with min at top
    int *stack; 
    
} MinStack;

/** initialize your data structure here. */


MinStack* minStackCreate()
{
    MinStack *m= (MinStack *)malloc(sizeof(MinStack)); //out minstack
    
    m->top=0;//initial
    
    m->min_val= (int *)malloc(sizeof(int) * 3000); //considering all 3000 calls are push
    
    m->stack= (int *)malloc(sizeof(int)*3000); 
    
    return m; 
    
}

void minStackPush(MinStack* obj, int val) 

{
    if(obj->top==0 || val<obj->min_val[obj->top-1] ) 
        obj->min_val[obj->top]=val; //bringing element at top if val is lesser
    else
        
        obj->min_val[obj->top]=obj->min_val[obj->top-1]; //else just repeating prev element
    obj->stack[obj->top]=val; //normal stack 
    obj->top++; //incrementing top for next element
        
  
}

void minStackPop(MinStack* obj) {
    obj->top--; //pop gives topmost element but top is initially one ahead due to top++
  
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top-1]; //top -1 is currently topmost
  
}

int minStackGetMin(MinStack* obj) {
    return obj->min_val[obj->top-1]; //top -1 is currently topmost
  
}



void minStackFree(MinStack* obj) {
  free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
