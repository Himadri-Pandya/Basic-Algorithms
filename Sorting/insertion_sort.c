#include <stdio.h>

int main(){

  printf("How many elements you want to sort? ");
  int n, i, temp, j;
  scanf("%d",&n);
  int arr[n];

  printf("Enter the elements\n");
  for(i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }

  for(i=1; i<n; i++){
    temp = arr[i];
    j = i-1;
    //while element exists at left side of current element
    while(j>=0){
      //if it's less than current element
      if(temp<arr[j]){
        //swap it with element to it's right
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp ;
        }
      //to compare the current element with remaining right side elements
      temp=arr[j];
      j--;
    }
  }

  printf("Sorted array \n");
  for(i=0; i<n; i++){
    printf("%d  ",arr[i]);
  }

  printf("\n");
  return 0;
}
