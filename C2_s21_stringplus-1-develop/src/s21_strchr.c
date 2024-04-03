#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *result = S21_NULL;
  int stop = 0;

  while (*str != 0 && !stop) {
    if (*(unsigned char *)str == (unsigned char)c) {
      result = str;
      stop = 1;
    }
    str += 1;
  }
  if (*str == 0 && c == 0) {
    result = str;
  }

  return (char *)result;
}
