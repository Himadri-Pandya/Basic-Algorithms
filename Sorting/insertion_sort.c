#include "array_io.h"

extern int size;
extern int* array;

void insertion_sort(){

  int i, temp, j;

  for(i=1; i<size; i++){
    temp = array[i];
    j = i-1;
    //while element exists at left side of current element
    while(j>=0){
      //if it's less than current element
      if(temp<array[j]){
        //swap it with element to it's right
        swap_elements(&array[j], &array[j+1]);
        }
      //to compare the current element with remaining right side elements
      temp=array[j];
      j--;
    }
  }
}
