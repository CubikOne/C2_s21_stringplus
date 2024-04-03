#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  void *res = dest;

  while (n != 0) {
    *(unsigned char *)res = *(unsigned char *)src;
    res++;
    src++;
    n--;
  }

  return dest;
}
