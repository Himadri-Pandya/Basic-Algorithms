#include <stdio.h>

int main(){

  int n, i, j, k;
  i=j=k=0;

  printf("How many elements ? \n" );
  scanf("%d",&n);

  int input[n], sorted[n];

  printf("Enter the elements\n");
  for(i=0 ; i <n; i++){
    scanf("%d",&input[i]);
  }

  for(i=0; i<n; i++){
    //getting max element from input[]
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

  for(int i=0 ; i <=k; i++){
    //remembering no. of occurances of input[i] for faster retrieval;
    int x = index[i];
    //while occurances exist
    while(x){
      //store the element at proper position and increment position variable j
      sorted[j]= i;
      j++;
      //decrement no. of occurances
      x--;
    }
  }

  printf("After sorting\n");
  for(i=0; i<n; i++){
    printf("%d  ",sorted[i] );
  }

  printf("\n");
  return 0;
}
