#include  <stdio.h>

void quicksort(int*, int, int);
void swap(int*, int*);
int n;

int main(){

  int i;
  printf("How many elements you want to sort? ");
  scanf("%d",&n);
  int arr[n];

  printf("Enter the elements\n");
  for(i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }

  quicksort(arr,0, n-1);

  printf("After sorting\n");
  for(i=0; i<n; i++){
    printf("%d  ",arr[i]);
  }

  printf("\n");
  return 0;
}

void quicksort(int* arr,int l, int h){
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
        swap(&arr[i], &arr[j]);
        i++;
      }
    }
  }
  swap(&arr[pivot],&arr[j]);
  quicksort(arr,l,j-1);
  quicksort(arr,j+1,h);
}

void swap(int* x, int* y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
