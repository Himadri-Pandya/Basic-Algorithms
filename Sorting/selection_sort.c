#include <stdio.h>

int main(){

  int n, i, temp, j, min;

  printf("How many elements ? \n" );
  scanf("%d",&n);

  int arr[n];

  printf("Enter the elements\n");

  for(i=0 ; i <n; i++){
    scanf("%d",&arr[i]);
  }

  for(i=0; i<n; i++){
    for(j=i+1 ; j<n; j++){
      if(arr[j] < arr[i]){
        min = j;
      }
      temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }

  printf("After sorting\n");
  for(int i=0 ; i <n; i++){
    printf("%d  ",arr[i]);
  }

  printf("\n");
  return 0;
}
