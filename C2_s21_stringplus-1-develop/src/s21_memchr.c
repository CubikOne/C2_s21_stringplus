#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = S21_NULL;

  while (n != 0) {
    if (*(unsigned char *)str == c) {
      res = (void *)str;
      n = 0;
    } else {
      str++;
      n--;
    }
  }
  return res;
}
