#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n) {
   // because fibonacci #1 is "0"
   if(n == 1)
      return 0;
   // base case
   if(n == 2)
      return 1;
   // add previous two numbers to progress sequence
   if(n != 2)
      return fibonacci(n - 1) + fibonacci(n - 2);
   // in case any errors occur (and get rid of warning)
   return -1;
}

int main(int argc, char *argv[]) {
   // open file and read echoed number
   FILE* f = fopen(argv[3], "r");
   char buffer[10];
   fgets(buffer, sizeof(buffer), f);

   // convert both strings to ints and add
   int n = atoi(argv[1]) + atoi(buffer);

   // initialize fib variables
   int fib = 1, fib_ = 1, temp;

   // recursive approach
   if(strcmp(argv[2], "r")) 
      fib = fibonacci(n);
   
   // iterative approach
   else
      for(int i = 3; i < n; i++) {
         temp = fib;
         fib += fib_;
         fib_ = temp;
      }

   // output result
   printf("%i\n", fib);

   // close file
   fclose(f);
   
   return 0;
}