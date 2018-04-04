#include <stdio.h>
#include <stdlib.h>

void conquer(int *,int, int, int);
void divide(int *, int,int);

int n, *tmparr;

int main(){

  int i;
  printf("How many elements you want to sort? ");
  scanf("%d",&n);
  int arr[n];

  tmparr = (int*)malloc(n*sizeof(int));

  printf("Enter the elements\n");

  for(i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }

  //funtion call to divide()
  divide(arr,0,n-1);

  printf("After sorting\n");

  for(i=0; i<n; i++){
    printf("%d  ",arr[i]);
  }

  printf("\n");
  return 0;

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
