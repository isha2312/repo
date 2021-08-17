//2. Infix to postfix

#include <stdio.h>
#include<ctype.h>
#define MAX 10
int stack [MAX];   // declaring stack
int top=-1;


void push(char x)
{
    top=top+1;
    stack[top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(') // priority is least
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/') // priority is highest
        return 2;
    return 0;
}


void check(char *s) 
{
    int i;
    char x;
    while(s[i] != '\0')
    {
    
        // if it is alphanumeric character
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            printf("%c ",s[i]); // then print it
            
            
        else if(s[i] == '(')
            push(s[i]);// if open brace then push to stack
            
            
        else if(s[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        
        // if an operator
        else
        {
            while(priority(stack[top]) >= priority(s[i]))// if priority of operator is high then pop from stack and print
                {
                  printf("%c ",pop());
                }
            //otherwise push to stack    
            push(s[i]);
        }
        i++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }   
    
}

int main()
{
  
    char str[50];
    int p;
    
    //scanning string
  printf("Enter string ");
  scanf("%s",str);
  
  check(str);
  return 0;
}
