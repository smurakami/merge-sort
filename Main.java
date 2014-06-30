public class Main {

  public static int gArray[] = {6, 2, 7, 1, 9, 8, 0, 5, 3, 4};

  public static void printArray(int array[]) {
    for (int i = 0; i < array.length; i++) {
      System.out.print(array[i] + " ");
    }
    System.out.println();
  }

  public static void printSpaces(int num) {
    for (int i = 0; i < num; i++) {
      System.out.print(" ");
    }
  }

  public static void merge(int array[], int array_a[], int array_b[]) {
    int i_a = 0;
    int i_b = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < array.length; i++){
      if (i_a < array_a.length) {
        a = array_a[i_a];
      }
      if (i_b < array_b.length) {
        b = array_b[i_b];
      }
      if ((i_b >= array_b.length) || ((i_a < array_a.length) && (a < b))){
        array[i] = a;
        i_a++;
      } else {
        array[i] = b;
        i_b++;
      }
    }
  }

  public static int depth = 0;

  public static void merge_sort(int array[]) {

    // printSpaces(depth * 2);
    // printArray(array);

    if (array.length == 1) return;
    int size_a = array.length / 2;
    int size_b = array.length - size_a;
    int array_a[] = new int[size_a];
    int array_b[] = new int[size_b];

    System.arraycopy(array, 0, array_a, 0, size_a);
    System.arraycopy(array, size_a, array_b, 0, size_b);

    depth++;
    merge_sort(array_a);
    merge_sort(array_b);
    depth--;

    merge(array, array_a, array_b);

    // printSpaces(depth * 2);
    // printArray(array);
  }

  public static void main (String[] args){
    // System.out.println("Hello World!");
    printArray(gArray);
    merge_sort(gArray);
    printArray(gArray);
  }
}



