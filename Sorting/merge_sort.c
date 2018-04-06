#include <stdlib.h>
#include "array_io.h"

void conquer(int *,int, int, int);
void divide(int *, int,int);

int *tmparr;
extern int size;
extern int* array;

void merge_sort(){

  int i;

  tmparr = (int*)malloc(size*sizeof(int));

  //funtion call to divide()
  divide(array,0,size-1);

}

void divide(int *a, int low, int high){

  int mid = (low+high)/2;

  if(low <  high){

      //recursive calls to divide()
      divide(a,low, mid );
      divide(a, mid+1, high);

      //conqueris called only for non-leaf elements of recursion-tree
      conquer(a,low,mid,high);

  }

}

void conquer(int *unsorted, int l, int m, int h){
  int i,j,k;

  i=l; j=m+1; k=l;

  while(i<=m && j<=h){

    //compare elements on location [0,m] with [m+1, h] and store sorted elements in tmparr[]
    if(unsorted[i] < unsorted[j]){
      tmparr[k] = unsorted[i];
      i++;
    }

    else{
      tmparr[k] = unsorted[j];
      j++;
    }
    k++;
  }

  //store remaining elements of [0,m] after first comparision
  while(i <= m){
    tmparr[k]= unsorted[i];
    i++;
    k++;
  }
  //store remaining elements of [m+1,h] after first comparision
  while(j <= h){
    tmparr[k]= unsorted[j];
    j++;
    k++;
  }

  //overwrite the input array with sorted values
  for(i=l; i<=h; i++){
    unsorted[i]=tmparr[i];
  }
}
