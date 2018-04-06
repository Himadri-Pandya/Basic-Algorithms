#include <stdlib.h>
#include <stdio.h>
#include "array_io.h"

extern int* array;
extern int max;
extern int size;

void counting_sort(int* arr, int digit){

  int  i=0, j=0, *output, *index;

  output = (int*)malloc(size*sizeof(int));
  if(output==NULL) printf("error\n");

  find_max();

  //declare index[] for holding no. of occurances of each element in input[]

  if(digit == 0){

    index = (int*)malloc((max+1)*sizeof(int));
    if(index==NULL) printf("error\n");

    for(i=0; i<=max; i++){
      //initialize index[]
      index[i] = 0;
    }

    for(i=0; i<size; i++){
      //count and store each occurance of array[] in index[]
      index[array[i]]++;
    }

    for(i=1; i<=max; i++){
      //adjust index[] to hold correct postions of array[] instances
      index[i]+=index[i-1];
    }

    for(i=size-1 ; i >=0; i--){
      //store each array[]-element at it's correct position in output[]
      output[index[array[i]]-1]=array[i];
      //decrement the index[] to reflect it
      index[array[i]]--;
    }

  }
  else{
    printf("counting_sort\n");
    //for using with radix sort

    int var;

    //declare and initialize index[]
    index = (int*)malloc((10)*sizeof(int));
    if(output==NULL) printf("error\n");
    for(i=0; i<10; i++){
      index[i]=0;
    }

    for(i=0; i<size; i++){
      //count and store each occurance of an array[] element at digit-th position in index[]
      index[(array[i]/digit)%10]++;
    }

    for(i=1; i<=10; i++){
      //adjust index[] to hold correct postions of array[] instances
      index[i]+=index[i-1];
    }

    for (i = size - 1; i >= 0; i--) {
        //store this value in var for faster retrieval
        var = (array[i] / digit) % 10;
        //counting sort logic for particular digit postion
        output[index[var] - 1] = array[i];
        index[var]--;
    }
  }

  //overwrite array[] with sorted/partially-sorted(in case of radix_sort) output[]
  for(i=0; i<size; i++){
    array[i]=output[i];
  }

  //for avoiding possible stack-smash
  free(output);
  free(index);
}
