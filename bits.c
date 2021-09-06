// Assignment-3
// Bits and Bytes

#include <stdio.h>

//1 BitAnd
int bitAnd (int a, int b) 
{
   int k;
   k= ~a | ~b;
   return (~k);
} 




//2 bitXor
int bitXor(int a, int b) 
{
    int k,y;
  k= ~(~a & ~b);
  y=  ~(a & b);
  return (k&y);
}




//3 Sign
//return 1 if positive, 0 if zero, and -1 if negative
int sign(int x) 
{
     return ((!!x) | (x >> 31)); 
     
     //(!!x)= Converts x to a boolean value
     //(x>>31) gives either 000..0000 or  111...111 
}



//4 GetByte
//extract byte n from word x
int getByte(int x, int n)
{
   return ((x>>(n<<3))&(0xFF)); 
   
   //n<<3=8 (For 1st byte= shift x by 8, for 2nd byte= shift by 16 and so on)
   // then and with 0xff to get the original back
}



//5 logical shift
int logicalShift(unsigned int x, int n) 
{
   return (x>>n);  
}



//6. conditional  x ? y : z
int conditional(int x, int y, int z) 
{
  // Converts x to a boolean value
   x = !(!x); 
 // Nonzero = 1
 // Zero = 0
 
   int b = ~a +0x01;
   
   // if 0 then it cuts off y and value of y is returned and is not zero then cuts off z
   return (b & y) | (~b & z);
}




//7.Bang
int bang(int x) 
{
  
  int inv = ~x;                  //if x==0, then -1
  int neg = inv + 1;              //if x==0, then 0
  return ((~neg & inv)>>31) & 1;    //if x was 0, then MSB is 1, so MSB>>31 & 1 = 1

}



//8 invert
int invert(unsigned int x, int n,int p)
{
    
    return (x ^ (~((~0) << n) << (p + 1 - n)));
    
  /*8 = 0000 1000 [from 3rd postion, inverting 3 bits]
  
    ~(~0 << n) = ~(~0 << 3)
                  = ~(1111 1111 << 3)
              = ~(1 1111 000 << 3)
                  = ~(1111 1000)
                  = 0000 0111
      This sets the last n bits to 1 and rest to 0
      
      For the position 3:
       ~(~0 << n) << (p+1 -n)  = 0000 0111 << (3+1 -3)
                    = 0000 0111 << 1
                    = 000 0111 0
                    
        Now with xor =    0000 1000 ^ 0000 1110
                     =    0000 0110*/
}

  
int main()
{
    int x,y,n,b,z;
     
    //scanning inputs 
    printf("Enter first number ");
    scanf("%d",&x);
    
    printf("Enter second number ");
    scanf("%d",&y);
    
    //calling functions
    int s1=bitAnd(x,y);
    printf("BitAnd of %d and %d is= %d",x,y,s1);
    
    
    int s2=bitXor(x,y);
    printf("\nBitXor of %d and %d is= %d",x,y,s2);
    
    
    int s3=sign(x);
    //if(s3>0)
    printf("\nFor number x=%d sign func returns:",x);
    printf("\n%d",s3);
    
    
    
    printf("\n1st byte from word 0x12345678 is:");
    printf("\n0x%x",getByte(0x12345678, 1));
    
    
    
    printf("\nLogical shift of 0x87654321 by 4:");
    printf("\n0x%x",logicalShift(0x87654321, 4));
    
    
    printf("\nEnter third no ");
    scanf("%d",&z);
    int s6=conditional(x,y,z);
    printf("for %d ? %d:%d Conditional operator returns:\n%d",x,y,z,s6);
    
    
    int s7=bang(x);
    printf("\nBang of %d is:\n%d",x,s7);
    
    printf("\nInvert of 8 from 3rd postion onwards to 3 bits:");
    printf("\n%d",invert(8,3,3));
    
    
    
     return 0;
}
