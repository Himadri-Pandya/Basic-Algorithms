//modifes standard algorithm to reduce the best case complexity

#include <stdio.h>

int main(){

  int n, i, temp, j;
  int flag = 0;
  printf("How many elements ? \n" );
  scanf("%d",&n);

  int arr[n];

  printf("Enter the elements\n");
  for(i=0 ; i <n; i++){
    scanf("%d",&arr[i]);
  }

  for(i=0; i<n; i++){
    //initiialize the flag
    flag = 0;
    for(j=1 ; j<n-i; j++){
      if(arr[j] < arr[j-1]){
        //if any pair of element in descending order, set the flag and swap them
        flag = 1;
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      }
    }
    //if no such pairs found,i.e the array is already sorted, no need for proceeding further, break the loop
    if(flag==0)break;
  }

  printf("After sorting\n");
  for(int i=0 ; i <n; i++){
    printf("%d \n",arr[i]);
  }
  return 0;
}
