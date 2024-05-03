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
  /* char tem = 0; */
  /* tem += 256; */
  /* std::cout << (int)tem; */
  Exc<int>();
  Exc<float>();
  Exc<double>();
  Exc<char>();
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
