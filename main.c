#include <stdio.h>
// #include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

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

// ********************
//     Read Array
// ********************

char * gString = "4 5 1 6 7 3 8 2 0 9";

int readArray(char * string, int * array){
  char buffer[100]; // 100桁の数字までいける
  int buffer_i = 0;
  int array_i = 0;
  int i = 0;
  while (1) {
    char c = string[i];
    if ((c == ' ') || (c == '\0') || (c == '\n')) {
      buffer[buffer_i] = '\0';
      int val = atoi(buffer);
      array[array_i] = val;
      array_i++;
      buffer_i = 0;
      if ((c == '\0') || (c == '\n')) break;
    } else {
      buffer[buffer_i] = c;
      buffer_i++;
    }
    i++;
  }
  return array_i; // size of array
}

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
  // printSpaces((depth) * 2);
  // printf("in:  ");
  // printArray(array, size);

  if (size == 1) {
    return;
  }
  int size_a = size/2;
  int size_b = size - size_a;
  int * array_a = array;
  int * array_b = array + size_a;

  depth++;
  merge_sort(array_a, size_a);
  merge_sort(array_b, size_b);
  depth--;

  merge(array, size);

  // printSpaces(depth * 2);
  // printf("out: ");
  // printArray(array, size);
}

int main() {
  int array[BUFFER_SIZE];
  int size = readArray(gString, array);

  printf("in:  ");
  printArray(array, size);
  merge_sort(array, size);
  printf("out: ");
  printArray(array, size);

  return 0;
}