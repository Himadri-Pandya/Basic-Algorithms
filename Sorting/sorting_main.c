#include <stdio.h>
#include "array_io.h"
#include "sorting_functions.h"

extern int* array;

void select_algorithm();

int main(){

  scan_array();

  select_algorithm();

  print_sorted_array();

}

void select_algorithm(){

  int choice;
  printf("Enter the Key to choose the sorting Algorithm\n---------------------------------------------\n1 - Bubble Sort\n2 - Bucket Sort\n3 - Counting Sort\n4 - Heap Sort\n5 - Insertion Sort\n6 - Merge Sort\n7 - Quick Sort\n8 - Radix Sort\n9 - Selection Sort\n---------------------------------------------\n" );

  scanf("%d", &choice);

  switch(choice){

    case 1: bubble_sort();
      break;
    case 2: bucket_sort();
      break;
    case 3: counting_sort(array, 0);
      break;
    case 4: heap_sort();
      break;
    case 5: insertion_sort();
      break;
    case 6: merge_sort();
      break;
    case 7: quick_sort();
      break;
    case 8: radix_sort();
      break;
    case 9: selection_sort();
      break;
    default: printf("\nInvalid Choice. Try again!\n");
      select_algorithm();
  }
}
