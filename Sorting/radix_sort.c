#include <stdio.h>
#include "sorting_functions.h"
#include "array_io.h"

extern int max;
extern int size;
extern int* array;

void radix_sort(){

  printf("radix_sort\n");

  int i, j, m, no_of_digits=0, digit_position=1;

  find_max();

  while(max > 0){
    no_of_digits++;
    max/=10;
  }

  printf("%d", no_of_digits);

  for(i=1; i<=no_of_digits; i++){
    counting_sort(array, digit_position);
    digit_position*=10;

  }

}
