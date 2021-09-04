#include <stdio.h>
#define MAX 10
int stack [MAX];   // declaring stack
int top=-1;


char pop() 
{
   // after returning the top element, value of top changes for next call
    return stack[top--];
   
}  


void push(char data) 
{
    
       top = top + 1;   
      stack[top] = data;  //placing the incoming bracket to the top
}

int match(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}


void balance(char *s) 
{
    
    char l,k;
     int n,i,o;
     
  for(i=0;s[i]!='\0';i++)
  {
      n++;
  }
  
 
  for(i=0;i<n;i++)
  {
      //traversing the string and we pushed the opening braces to a stack
      if(s[i]=='(' || s[i]=='{' || s[i]=='[')
      {
          push(s[i]);
          
      }
      
      //when we have a closing brace we pop from the stack
     else if(s[i]==')' || s[i]=='}' || s[i]==']')
     {
         
            l=s[i];

            k=pop();

            //printf("%c %c",k,l);
            
            //then calling match function to check balanced paranthesis
            o=match(k,l);
            
            
            if(o==0)// if first brackets doesn't only match then break 
            break;
            
     } 
     
     
     
  }
  
  //if all the brackets matches and stack is empty then it is valid
  if(o==1)
     printf("true");
  else
     printf("false");

  
}

int main()
{
  
    char str[50];
    int p;
    
    //scanning string
  printf("Enter string ");
  scanf("%s",str);
  
  balance(str);
  return 0;
}
