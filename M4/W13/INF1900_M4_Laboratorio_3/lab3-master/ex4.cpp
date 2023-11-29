#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  std::vector<int> left(n1);
  std::vector<int> right(n2);

  for (int i = 0; i < n1; i++) {
    left[i] = arr[l + i];
  }
  for (int i = 0; i < n2; i++) {
    right[i] = arr[m + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<int> &arr, int l, int r) {
  /*
    O algoritmo do Merge Sort separa divide o array em dois e ordena cada porção 
    separadamente. Depois, as duas porções são mergeadas de forma ordenada. 
  */
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main() {
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};

  std::cout << "Array antes da ordenação:" << std::endl;
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  mergeSort(arr, 0, arr.size() - 1);

  std::cout << "Array após a ordenação:" << std::endl;
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
