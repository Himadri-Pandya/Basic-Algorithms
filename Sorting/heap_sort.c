#include <stdio.h>
#include "array_io.h"

extern int size;
extern int* array;

void heapify(int *, int);

void heap_sort(){

  int i,j, n, sorted[size];

  //storing size in n as n gets modifies further in the program
  n = size;

  for(i=0; i<size ; i++){
    //creating min heap
    heapify(array,i);
  }

  printf("After heapifying\n");
  print_array();

  for(i=0; size>0; i++){

    //swap first(min) element with last element in heap
    swap_elements(&array[0],&array[size-1]);
    //insert the last element in sorted output array
    sorted[i]=array[size-1];
    //delete the last node in heap
    size--;

    //adjusting the heap after performing above operations
    for(j=0; j <size; j++){
      heapify(array,j);
    }
  }

  for(i=0; i<n; i++){
    array[i]=sorted[i];
  }

  size = n;
}

void heapify(int* unsorted, int index){
//creates min heap using recursion

  //end condition for recursion for rootnode
  if (index == 0){
    return;
  }

  int i;
  int parent = (index -1)/2;

  //if child is smaller than parent, swap and do this recursively in bottom-up manner until we reach to the rootnode
  if(unsorted[index] < unsorted[parent]){
      swap_elements(&unsorted[index], &unsorted[parent]);
      heapify(unsorted,parent);
    }
}
