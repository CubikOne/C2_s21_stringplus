#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  s21_size_t i = 0;

  while ((i != n)) {
    result = *(unsigned char *)str1 - *(unsigned char *)str2;
    if (result != 0)
      i = n;
    else {
      str1++;
      str2++;
      i++;
    }
  }

  return result;
}
