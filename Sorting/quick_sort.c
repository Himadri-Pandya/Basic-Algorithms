#include "array_io.h"

extern int size;
extern int* array;

void sort(int*, int, int);

void quick_sort(){

  int i;

  sort(array,0, size-1);

}

void sort(int* arr,int l, int h){
  int pivot = l;
  int i = l+1;
  int j = h;

  if(l >= h) return;

  while(i<=h && j>=l && i<=j){
    if(arr[i] <= arr[pivot]){
      i++;
    }
    else{
      if(arr[j] >= arr[pivot]){
        j--;
      }
      else {
        swap_elements(&arr[i], &arr[j]);
        i++;
      }
    }
  }
  swap_elements(&arr[pivot],&arr[j]);
  sort(arr,l,j-1);
  sort(arr,j+1,h);
}
