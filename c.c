#include <stdio.h>

typedef struct uint1024_t
{
   unsigned long int digits[32];

} uint1024_t;

uint1024_t from_uint(unsigned int x)
{
   
   uint1024_t number;
   
   int temp = 1000000000;
   
   for (int i = 0; i <= 32; i++)
   {
      number.digits[i] = 0;
   }
   
   if (x / temp > 0)
   {
     
      number.digits[31] = x % temp;  
      number.digits[30] = x / temp;

   }

   else
   {
      number.digits[31] = x;
      
   }
   
   return number;
}

void printf_value(uint1024_t x)
{
   uint1024_t number = x;

   for (int i = 0; i < 32; i++)
   {
     
      printf("%d", number.digits[i]);
      if (number.digits[i]!= 0 && number.digits[i + 1] == 0 && number.digits[i + 1] != NULL )
      {
         printf("00000000");
         
      }
      
      

   }
}

uint1024_t add_op(uint1024_t x, uint1024_t y)
{
   
   uint1024_t result;

   for (int i = 31; i >= 0; i--)
   {
      result.digits[i] = x.digits[i] + y.digits[i];
   }
   for (int i = 31; i >= 0; i--)
   {
      if (result.digits[i] >= 1000000000){
         result.digits[i] = 0;
         result.digits[i-1] += 1;
      }
   }
   
   return result;
}

uint1024_t subtr_op(uint1024_t x, uint1024_t y)
{
    uint1024_t result;
    

   for (int i = 0; i < 32; i++)

   {
      result.digits[i] = x.digits[i] - y.digits[i];
     
   }

   
   return result;


}


/*void scanf_value()
{
   
   char str[1024];
   scanf("%s", str);
   int i = 0;
    
   unsigned long long mas[1024];

   while(str[i] != 0){
        mas[i] = str[i] - '0';
        i++;

   printf("%d", mas[0]);
 
   
  
    
}*/

uint1024_t mult_op(uint1024_t x, uint1024_t y)
{
   uint1024_t result;

  for (int i = 31; i >= 0; i--)
   {
      result.digits[i] = x.digits[i] * y.digits[i];
      if (result.digits[i] >= 100000000 || result.digits[i] < 0)
      {
         
      }
   }

  


   return result;
}




int main()
{  
   uint1024_t c;
   uint1024_t b;
   uint1024_t a;
   
   c = from_uint(240);
   b = from_uint(4504);

   a = mult_op(c,b);
   printf_value(a);
   

   return 0;
}