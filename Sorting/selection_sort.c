#include "array_io.h"

extern int size;
extern int* array;

void selection_sort(){

  int i, temp, j, min;

  for(i=0; i<size; i++){
    for(j=i+1 ; j<size; j++){
      if(array[j] < array[i]){
        min = j;
      }
      swap_elements(&array[min], &array[i]);
    }
  }

}
