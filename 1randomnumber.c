#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   int i, n;
   time_t t;

   n = 20;


   srand((unsigned) time(&t));

   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 200);
   }

   return(0);
}
