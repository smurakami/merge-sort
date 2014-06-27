#include <stdio.h>
#define BUFFER_SIZE 10

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
  depth++;
  for (int i = 0; i < depth - 1; i++) {
    printf("  ");
  }
  printf("in: ");
  for (int i = 0; i < size; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
  if (size <= 1) {
    depth--;
    return;
  }
  int size_a = size/2;
  int size_b = size - size_a;
  // printf("size_a = %d\n", size_a);
  // printf("size_b = %d\n", size_b);
  // printf("array[0] = %d\n", array[0]);
  // printf("(array+size_a)[0] = %d\n", (array+size_a)[0]);
  merge_sort(array, size_a);
  merge_sort((array + size_a), size_b);
  merge(array, size);
  for (int i = 0; i < depth - 1; i++) {
    printf("  ");
  }
  printf("out: ");
  for (int i = 0; i < size; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
  depth--;
}

int main() {
  merge_sort(gArray, BUFFER_SIZE);
  for (int i = 0; i < BUFFER_SIZE; i++) {
    printf("%d, ", gArray[i]);
  }

  printf("\n");

  return 0;
}