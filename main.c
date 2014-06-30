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

void merge(int * array, int size){
  int size_a = size/2;
  int size_b = size - size_a;
  int buffer[BUFFER_SIZE];
  int i_a = 0;
  int i_b = 0;
  int i = 0;
  while (i < size) {
    int a = array[i_a];
    int b = array[size_a + i_b];
    if (a < b) {
      buffer[i] = a;
      i_a++;
      i++;
      if (i_a == size_a) break;
    } else {
      buffer[i] = b;
      i_b++;
      i++;
      if (i_b == size_b) break;
    }
  }

  while (i < size) {
    if (i_a < size_a) {
      buffer[i] = array[i_a];
      i_a++;
    }
    if (i_b < size_b) {
      buffer[i] = array[size_a + i_b];
      i_b++;
    }
    i++;
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
  printSpaces((depth - 1) * 2);
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