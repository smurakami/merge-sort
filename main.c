#include <stdio.h>
#define BUFFER_SIZE 10

// ********************
//      デバッグ用
// ********************
void printSpaces(int num) {
  for (int i = 0; i < num; i++){
    putchar(' ');
  }
}

void printArray(int * array, int size){
  for (int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  putchar('\n');
}

int gArray[BUFFER_SIZE] = {
  4,
  5,
  1,
  6,
  7,
  3,
  8,
  2,
  0,
  9,
};

// ********************
//     Merge Sort
// ********************

void merge(int * array, int size){
  int buffer[BUFFER_SIZE];
  int size_a = size/2;
  int size_b = size - size_a;
  int * array_a = array;
  int * array_b = array + size_a;
  int i_a = 0;
  int i_b = 0;

  for(int i = 0; i < size; i++){
    int a = array_a[i_a];
    int b = array_b[i_b];
    if ((i_a < size_a) && (a < b)) {
      buffer[i] = a;
      i_a++;
    } else {
      buffer[i] = b;
      i_b++;
    }
  }

  for (int i = 0; i < size; i++){
    array[i] = buffer[i];
  }
}

int depth;

void merge_sort(int * array, int size){
  printSpaces((depth) * 2);
  printf("in: ");
  printArray(array, size);

  if (size <= 1) {
    return;
  }
  int size_a = size/2;
  int size_b = size - size_a;
  depth++;
  merge_sort(array, size_a);
  merge_sort((array + size_a), size_b);
  depth--;
  merge(array, size);

  printSpaces(depth * 2);
  printf("out: ");
  printArray(array, size);
}

int main() {
  merge_sort(gArray, BUFFER_SIZE);
  for (int i = 0; i < BUFFER_SIZE; i++) {
    printf("%d, ", gArray[i]);
  }

  printf("\n");

  return 0;
}