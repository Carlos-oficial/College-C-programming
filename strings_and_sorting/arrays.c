#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printArr(int v[], int N) {
  for (int i = 0; i < N; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int ordenado(int v[], int N) {
  if (N < 2)
    return 1;
  for (int i = 1; i < N; i++) {
    if (v[i] < v[i - 1])
      return 0;
  }
  return 1;
}

void swapInt(int *n1, int *n2) {
  int temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

void merge(int a[], int na, int b[], int nb, int r[]) {
  int ia = 0, ib = 0, ir = 0;
  for (; ia < na && ib < nb; ir++) {
    if (a[ia] < b[ib]) {
      r[ir] = a[ia];
      ia++;
    } else {
      r[ir] = b[ib];
      ib++;
    }
  }
  if (ia < na) {
    for (; ia < na; ia++, ir++) {
      r[ir] = a[ia];
    }
  } else if (ib < nb) {

    for (; ib < nb; ib++, ir++) {
      r[ir] = b[ib];
    }
  }
}

int partition_Arr(int v[], int N, int x) {// partition with auxiliary arrays
  int *arr1 = malloc(sizeof(int) * N);
  int *arr2 = malloc(sizeof(int) * N);

  int n1 = 0, n2 = 0;
  for (int i = 0; i < N; i++) {
    if (v[i] <= x) {
      arr1[n1] = v[i];
      n1++;
    } else {
      arr2[n2] = v[i];
      n2++;
    }
  }
  for (int i = 0; i < n1; i++) {
    v[i] = arr1[i];
  }
  for (int i = n1; i < N; i++) {
    v[i] = arr2[i - n1];
  }
  free(arr1);
  free(arr2);
  return n1;
}
int partition_IP(int v[], int N, int x) { // partition in place
  int i = 0, j = N-1;
  while (i < j) {
    if (v[i] > x) {
      swapInt(v + i, v + j);
      j--;
    } else {
      i++;
    }
  }
  return N - j;
}

int main() {
  int arr1[] = {1, 3, 6, 7};
  int arr2[] = {2, 5, 9};
  int arr3[] = {9, 1, 7, 3, 1, 9, 0};
  //   merge(arr1, 4, arr2, 3, arr3);
  printArr(arr3, 7);
  printf("n: %d\n",partition_IP(arr3, 7, 5));
  printArr(arr3, 7);
  return 0;
}