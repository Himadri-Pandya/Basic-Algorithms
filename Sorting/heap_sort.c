#include <stdio.h>

int n;

void heapify(int *, int);
void swap(int*, int*);

int main(){

  int i,j, size;
  printf("How many elements you want to sort? ");
  scanf("%d",&n);
  int arr[n],sorted[n];

  //storing n in size as n gets modifies further in the program
  size = n;

  printf("Enter the elements\n");
  for(i=0; i<n; i++){
    scanf("%d",&arr[i]);
    //creating min heap
    heapify(arr,i);
  }

  printf("After heapifying\n");
  for(i=0; i<n; i++){
    printf("%d  ",arr[i]);
  }

  printf("\n");

  for(i=0; n>0; i++){

    //swap first(min) element with last element in heap
    swap(&arr[0],&arr[n-1]);
    //insert the last element in sorted output array
    sorted[i]=arr[n-1];
    //delete the last node in heap
    n--;

    //adjusting the heap after performing above operations
    for(j=0; j <n; j++){
      heapify(arr,j);
    }
  }

  printf("After sorting\n");
  for(i=0; i<size; i++){
    printf("%d  ",sorted[i]);
  }

  printf("\n");
  return 0 ;
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
      swap(&unsorted[index], &unsorted[parent]);
      heapify(unsorted,parent);
    }

}

void swap(int* x, int* y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
