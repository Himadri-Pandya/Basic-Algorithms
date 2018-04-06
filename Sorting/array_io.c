#include <stdio.h>
#include <stdlib.h>
#include "array_io.h"

int size;
int* array;
int i;
int max;

void scan_array(){

  printf("How many elements ? \n" );
  scanf("%d",&size);

  array = (int*) malloc(size*sizeof(int));

  printf("Enter the elements\n");
  for(i=0 ; i <size; i++){
    scanf("%d",&array[i]);
  }
}

void print_array(){

  for(i=0 ; i <size; i++){
    printf("%d  ",array[i]);
  }
  printf("\n");
}

void print_sorted_array(){

  printf("After sorting\n");
  for(i=0 ; i <size; i++){
    printf("%d  ",array[i]);
  }
  printf("\n");
}

void find_max(){
  for(i=0; i<size; i++){
    //get value of the maximum element in array input[i]
    if(array[i]>max) max = array[i];
  }
}


void swap_elements(int* x, int* y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
