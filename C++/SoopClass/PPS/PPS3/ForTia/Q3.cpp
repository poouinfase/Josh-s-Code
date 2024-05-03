#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <stdio.h>

template <typename T> void shift_Left(T *arr, size_t len) {
  for (int i = 0; i < len - 1; i++) {
    arr[i] = arr[i + 1];
  }
}

template <typename T> int Remove_element(T *arr, size_t len, T elem) {
  int rem = len;
  while (len > 0) {
    if (*arr == elem) {
      shift_Left(arr, len);
      rem--;
    }
    len--;
    arr++;
  }
  return rem;
}

template <typename T> inline int isch() {
  T a = 0;
  a += 256;
  return a == 0;
}

template <typename T> void Exc() {
  int len = 5;
  std::cin >> len;
  T *arr = (T *)malloc(len * sizeof(T));
  for (int i = 0; i < len; i++) {
    std::cin >> arr[i];
  }
  T rem = 0;
  std::cin >> rem;
  len = Remove_element(arr, len, rem);
  if (isch<T>())
    for (int i = 0; i < len; i++) {
      std::cout << arr[i];
    }
  else
    for (int i = 0; i < len; i++) {
      std::cout << arr[i] << " ";
    }
  std::cout << std::endl;
  free(arr);
}

int main() {
  int len = 5;
  std::cin >> len;
  int *arri = (int *)malloc(len * sizeof(int));
  for (int i = 0; i < len; i++) {
    std::cin >> arri[i];
  }
  int rem = 0;
  std::cin >> rem;
  len = Remove_element(arri, len, rem);
  for (int i = 0; i < len; i++) {
    std::cout << arri[i] << " ";
  }
  std::cout << std::endl;
  free(arri);

  for (int i = 0; i < 2; i++) {
    std::cin >> len;
    float *arrf = (float *)malloc(len * sizeof(float));
    for (int i = 0; i < len; i++) {
      std::cin >> arrf[i];
    }
    float rem = 0;
    std::cin >> rem;
    len = Remove_element(arrf, len, rem);
    for (int i = 0; i < len; i++) {
      std::cout << arrf[i] << " ";
    }
    std::cout << std::endl;
    free(arrf);
  }

  std::cin >> len;
  char *arrc = (char *)malloc(len * sizeof(char));
  for (int i = 0; i < len; i++) {
    std::cin >> arrc[i];
  }
  char rem = 0;
  std::cin >> rem;
  len = Remove_element(arrc, len, rem);
  for (int i = 0; i < len; i++) {
    std::cout << arrc[i];
  }
  std::cout << std::endl;
  free(arrc);
}

/*
std::cin >> len;
T *arr = (T *)malloc(len * sizeof(T));
for (int i = 0; i < len; i++) {
  std::cin >> arr[i];
}
T rem = 0;
std::cin >> rem;
len = Remove_element(arr, len, rem);
for (int i = 0; i < len; i++) {
  std::cout << arr[i] << " ";
}
std::cout << std::endl;
*/
