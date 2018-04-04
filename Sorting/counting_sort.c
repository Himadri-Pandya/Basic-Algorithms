#include <stdio.h>

int main(){

  int n, i, j, k;
  i=j=k=0;

  printf("How many elements ? \n" );
  scanf("%d",&n);

  int input[n], output[n];

  printf("Enter the elements\n");
  for(i=0 ; i <n; i++){
    scanf("%d",&input[i]);
  }

  for(i=0; i<n; i++){
    //get value of the maximum element in array input[i]
    if(input[i]>k) k = input[i];
  }

  //declare index[] for holding no. of occurances of each element in input[]
  int index[k+1] ;

  for(i=0; i<=k; i++){
    //initialize index[]
    index[i] = 0;
  }

  for(i=0; i<n; i++){
    //count and store each occurance of input[] in index[]
    index[input[i]]++;
  }

  for(i=1; i<=k; i++){
    //adjust index[] to hold correct postions of input[] instances
    index[i]+=index[i-1];
  }

  for(i=n-1 ; i >=0; i--){
    //store each input[]element at it's correct position in output[]
    output[index[input[i]]-1]=input[i];
    //decrement the index[] to reflect it
    index[input[i]]--;
  }

  printf("After sorting\n");
  for(i=0; i<n; ++i){
    printf("%d\n",output[i] );
  }
  return 0;
}
