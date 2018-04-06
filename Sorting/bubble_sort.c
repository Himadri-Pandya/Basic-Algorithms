//modifes standard algorithm to reduce the best case complexity
extern int size;
extern int *array;

void bubble_sort(){

  int i, temp, j;
  int flag = 0;

  for(i=0; i<size; i++){
    //initiialize the flag
    flag = 0;
    for(j=1 ; j<size-i; j++){
      if(array[j] < array[j-1]){
        //if any pair of element in descending order, set the flag and swap them
        flag = 1;
        temp = array[j];
        array[j] = array[j-1];
        array[j-1] = temp;
      }
    }
    //if no such pairs found,i.e the array is already sorted, no need for proceeding further, break the loop
    if(flag==0)break;
  }
}
